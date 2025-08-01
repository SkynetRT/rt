include ../../../Make.defs
INC = ../../..
OBJS := mm_granalloc.o mm_granfree.o mm_graninit.o mm_granreserve.o mm_pgalloc.o pg_worker.o \
	mm_grancritical.o mm_graninfo.o mm_granrelease.o mm_grantable.o pg_miss.o
.PHONY: all
all: pager.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
pager.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) pager.a *.d
