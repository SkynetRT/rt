include ../../Make.defs
OBJS := mq_initialize.o mq_msgqalloc.o mq_notify.o mq_receive.o mq_send.o mq_sndinternal.o msgctl.o msginternal.o msgsnd.o \
	mq_getattr.o mq_msgfree.o mq_msgqfree.o mq_rcvinternal.o mq_recover.o mq_setattr.o mq_waitirq.o msgget.o msgrcv.o
.PHONY: all
all: mqueue.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
mqueue.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) mqueue.a *.d
