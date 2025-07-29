AR = arm-none-eabi-ar
CC = arm-none-eabi-gcc
ARM32	= -march=armv7-a -mthumb -mfloat-abi=hard -mfpu=vfpv4
ARM64	= -march=armv8-a
CFLAGS	= $(ARM32) -Wall -I../../include -nostdinc
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
