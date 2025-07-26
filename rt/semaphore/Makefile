AS  = arm-none-eabi-as
AR  = arm-none-eabi-ar
CC  = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD  = arm-none-eabi-ld
CFLAGS = -Wall -O2 -nostdinc -mthumb
CFLAGS += -I/usr/lib/gcc/arm-none-eabi/10.3.1/include -I../../include -D__KERNEL__
OBJECTS := sem_clockwait.o sem_destroy.o sem_holder.o sem_initialize.o sem_post.o sem_protect.o sem_recover.o sem_reset.o sem_rw.o sem_setprotocol.o sem_tickwait.o sem_timedwait.o sem_timeout.o sem_trywait.o sem_wait.o sem_waitirq.o
.PHONY: all
all: semaphore.a
%.o: %.c
	$(CC) -Wall -O2 -c $(CFLAGS) -o $@ $<
semaphore.a: $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)
.PHONY: clean
clean:
	$(RM) $(OBJECTS) semaphore.a *.d
