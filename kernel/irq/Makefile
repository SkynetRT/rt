include ../../Make.defs
OBJS := irq_attach_thread.o irq_chain.o irq_dispatch.o irq_initialize.o irq_spinlock.o \
	irq_attach.o irq_attach_wqueue.o irq_csection.o irq_foreach.o irq_procfs.o irq_unexpectedisr.o
.PHONY: all
all: irq.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
irq.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) irq.a *.d
