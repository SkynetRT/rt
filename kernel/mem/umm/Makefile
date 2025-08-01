include ../../../Make.defs
INC = ../../..
OBJS := umm_addregion.o umm_calloc.o umm_extend.o umm_globals.o umm_initialize.o umm_malloc.o \
	umm_memalign.o umm_realloc.o umm_zalloc.o umm_brkaddr.o umm_checkcorruption.o umm_free.o \
	umm_heapmember.o umm_mallinfo.o umm_malloc_size.o umm_memdump.o umm_sbrk.o
.PHONY: all
all: umm.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
umm.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) umm.a *.d
