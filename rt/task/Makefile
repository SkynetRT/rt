AR = arm-none-eabi-ar
CC = arm-none-eabi-gcc
ARM32	= -march=armv7-a -mthumb -mfloat-abi=hard -mfpu=vfpv4
ARM64	= -march=armv8-a
CFLAGS	= $(ARM32) -Wall -I../../include -nostdinc
OBJS := exit.o task_create.o task_exithook.o task_getppid.o task_join.o task_reparent.o task_spawnparms.o tls_dupinfo.o \
	task_activate.o task_delete.o task_fork.o task_gettid.o task_posixspawn.o task_restart.o task_start.o tls_initinfo.o \
	task_argvstr.o task_execve.o task_getgroup.o task_init.o task_prctl.o task_setup.o task_terminate.o \
	task_cancelpt.o task_exit.o task_getpid.o task_initinfo.o task_recover.o task_spawn.o task_uninitinfo.o
.PHONY: all
all: task.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
task.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) task.a *.d
