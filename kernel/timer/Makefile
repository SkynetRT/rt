include ../../Make.defs
OBJS := timer_create.o timer_getitimer.o timer_gettime.o timer_release.o timer_settime.o \
	timer_delete.o timer_getoverrun.o timer_initialize.o timer_setitimer.o
.PHONY: all
all: timer.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
timer.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) timer.a *.d
