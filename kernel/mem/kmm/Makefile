include ../../../Make.defs
INC = ../../..
OBJS := kmm_addregion.o kmm_calloc.o kmm_extend.o kmm_heapmember.o kmm_mallinfo.o kmm_malloc_size.o kmm_memalign.o kmm_realloc.o \
	kmm_brkaddr.o kmm_checkcorruption.o kmm_free.o kmm_initialize.o kmm_malloc.o kmm_map.o kmm_memdump.o kmm_zalloc.o
.PHONY: all
all: kmm.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
kmm.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) kmm.a *.d
