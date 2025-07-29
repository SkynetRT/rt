include ../../Make.defs
OBJS := clock_dow.o clock_perf.o clock_systime_ticks.o clock.o clock_gettime.o \
	clock_realtime2absticks.o clock_systime_timespec.o clock_adjtime.o \
	clock_initialize.o clock_settime.o clock_timekeeping.o
.PHONY: all
all: clock.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
clock.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) clock.a *.d
