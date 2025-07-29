AR = arm-none-eabi-ar
CC = arm-none-eabi-gcc
ARM32	= -march=armv7-a -mthumb -mfloat-abi=hard -mfpu=vfpv4
ARM64	= -march=armv8-a
CFLAGS	= $(ARM32) -Wall -I../../include -nostdinc
OBJS := sig_deliver.o sig_lowest.o sig_ppoll.o sig_releasependingsignal.o sig_timedwait.o \
	sig_action.o sig_dispatch.o sig_nanosleep.o sig_procmask.o sig_removependingsignal.o sig_unmaskpendingsignal.o \
	sig_allocpendingsigaction.o sig_findaction.o sig_notification.o sig_pselect.o sig_sleep.o sig_usleep.o \
	sig_cleanup.o sig_initialize.o sig_pause.o sig_queue.o sig_suspend.o sig_waitinfo.o \
	sig_default.o sig_kill.o sig_pending.o sig_releasependingsigaction.o sig_tgkill.o
.PHONY: all
all: signal.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
signal.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) signal.a *.d
