include ../../Make.defs
OBJS := sched_addblocked.o sched_getcpu.o sched_releasetcb.o sched_smp.o \
	sched_addreadytorun.o sched_getfiles.o sched_removeblocked.o sched_sporadic.o \
	sched_backtrace.o sched_getparam.o sched_removereadytorun.o sched_suspend.o \
	sched_getscheduler.o sched_reprioritize.o sched_suspendscheduler.o \
	sched_gettcb.o sched_reprioritizertr.o sched_sysinfo.o \
	sched_idletask.o sched_resumescheduler.o sched_timerexpiration.o \
	sched_critmonitor.o sched_lock.o sched_roundrobin.o sched_unlock.o \
	sched_dumponexit.o sched_lockcount.o sched_rrgetinterval.o sched_verifytcb.o \
	sched_foreach.o sched_mergepending.o sched_self.o sched_wait.o \
	sched_get_stackinfo.o sched_mergeprioritized.o sched_setaffinity.o sched_waitid.o \
	sched_get_stateinfo.o sched_process_delivered.o sched_setparam.o sched_waitpid.o \
	sched_get_tls.o sched_processtimer.o sched_setpriority.o sched_yield.o \
	sched_getaffinity.o sched_profil.o sched_setscheduler.o \
	sched_cpuload.o sched_cpuload_oneshot.o sched_cpuload_period.o
.PHONY: all
all: sched.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
sched.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) sched.a *.d
