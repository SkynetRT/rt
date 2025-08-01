/****************************************************************************
 * mm/mm_heap/mm_extend.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <assert.h>

#include <nuttx/mm/mm.h>

#include "mm.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define MIN_EXTEND (2 * MM_SIZEOF_ALLOCNODE)

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: mm_extend
 *
 * Description:
 *   Extend a heap region by add a block of (virtually) contiguous memory
 *   to the end of the heap.
 *
 ****************************************************************************/

void mm_extend(FAR struct mm_heap_s *heap, FAR void *mem, size_t size,
               int region)
{
  FAR struct mm_allocnode_s *oldnode;
  FAR struct mm_allocnode_s *newnode;
  uintptr_t blockstart;
  uintptr_t blockend;

  /* Make sure that we were passed valid parameters */

  DEBUGASSERT(heap && mem);
#if CONFIG_MM_REGIONS > 1
  DEBUGASSERT(size >= MIN_EXTEND && region >= 0 &&
              region < heap->mm_nregions);
#else
  DEBUGASSERT(size >= MIN_EXTEND && region == 0);
#endif

  /* Make sure that the memory region are properly aligned */

  blockstart = (uintptr_t)mem;
  blockend   = blockstart + size;

  DEBUGASSERT(MM_ALIGN_UP(blockstart) == blockstart);
  DEBUGASSERT(MM_ALIGN_DOWN(blockend) == blockend);

  /* Take the memory manager mutex */

  DEBUGVERIFY(mm_lock(heap));

  /* Get the terminal node in the old heap.  The block to extend must
   * immediately follow this node.
   */

  oldnode = heap->mm_heapend[region];
  DEBUGASSERT((uintptr_t)oldnode + MM_SIZEOF_ALLOCNODE == blockstart);

  /* The size of the old node now extends to the new terminal node.
   * This is the old size (MM_SIZEOF_ALLOCNODE) plus the size of
   * the block (size) minus the size of the new terminal node
   * (MM_SIZEOF_ALLOCNODE) or simply:
   */

  oldnode->size = size | (oldnode->size & MM_MASK_BIT);

  /* The old node should already be marked as allocated */

  DEBUGASSERT(MM_NODE_IS_ALLOC(oldnode));

  /* Get and initialize the new terminal node in the heap */

  newnode       = (FAR struct mm_allocnode_s *)
                  (blockend - MM_SIZEOF_ALLOCNODE);
  newnode->size = MM_SIZEOF_ALLOCNODE | MM_ALLOC_BIT;

  heap->mm_heapend[region] = newnode;

  /* Finally, increase the total heap size accordingly */

  heap->mm_heapsize += size;
  mm_unlock(heap);

  /* Finally "free" the new block of memory where the old terminal node was
   * located.
   */

  mm_free(heap, mem);
}
