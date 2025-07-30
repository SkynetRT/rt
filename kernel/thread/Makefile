include ../../Make.defs
OBJS := pthread_condsignal.o pthread_findjoininfo.o pthread_mutexconsistent.o pthread_mutexunlock.o pthread_sigmask.o \
	pthread_cancel.o pthread_condwait.o pthread_getaffinity.o pthread_mutexdestroy.o pthread_release.o \
	pthread_completejoin.o pthread_create.o pthread_getschedparam.o pthread_mutexinit.o pthread_setaffinity.o \
	pthread_condbroadcast.o pthread_detach.o pthread_join.o pthread_mutextimedlock.o pthread_setschedparam.o \
	pthread_condclockwait.o pthread_exit.o pthread_mutex.o pthread_mutextrylock.o pthread_setschedprio.o
.PHONY: all
all: thread.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
thread.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) thread.a *.d
