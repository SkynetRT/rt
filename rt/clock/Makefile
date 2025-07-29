AR = arm-none-eabi-ar
CC = arm-none-eabi-gcc
ARM32	= -march=armv7-a -mthumb -mfloat-abi=hard -mfpu=vfpv4
ARM64	= -march=armv8-a
CFLAGS	= $(ARM64) -Wall -I../../include -nostdinc
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
