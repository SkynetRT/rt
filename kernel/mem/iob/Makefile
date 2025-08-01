include ../../../Make.defs
INC = ../../..
OBJS := iob_add_queue.o iob_contig.o iob_free.o iob_get_queue_info.o iob_peek_queue.o iob_test.o \
	iob_alloc.o iob_copyin.o iob_free_chain.o iob_initialize.o iob_remove_queue.o iob_trimhead.o \
	iob_alloc_qentry.o iob_copyout.o iob_free_qentry.o iob_navail.o iob_reserve.o iob_trimhead_queue.o \
	iob_clone.o iob_count.o iob_free_queue.o iob_notifier.o iob_statistics.o iob_trimtail.o \
	iob_concat.o iob_dump.o iob_free_queue_qentry.o iob_pack.o iob_tailroom.o iob_update_pktlen.o
.PHONY: all
all: iob.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
iob.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) iob.a *.d
