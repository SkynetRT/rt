include ../../../Make.defs
INC = ../../..
OBJS := mempool.o mm_initialize.o mm_map.o mm_zalloc.o \
	mempool_multiple.o mm_extend.o mm_lock.o mm_memalign.o \
	mempool_procfs.o mm_foreach.o mm_mallinfo.o mm_memdump.o \
	mm_brkaddr.o mm_free.o mm_malloc.o mm_realloc.o \
	mm_calloc.o mm_heapmember.o mm_malloc_size.o mm_shrinkchunk.o \
	mm_checkcorruption.o vm_region.o
.PHONY: all
all: heap.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
heap.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) heap.a *.d
