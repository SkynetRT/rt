CC  = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD  = arm-none-eabi-ld
CFLAGS += -I/usr/lib/gcc/arm-none-eabi/10.3.1/include  -I../../include

objects := sem_clockwait.o sem_destroy.o sem_holder.o sem_initialize.o sem_post.o sem_protect.o sem_recover.o sem_reset.o \
	sem_rw.o sem_setprotocol.o sem_tickwait.o sem_timedwait.o sem_timeout.o sem_trywait.o sem_wait.o sem_waitirq.o
.PHONY: all
all: $(objects)
%.o: %.c
	$(CC) -Wall -O2 $(CFLAGS) -o $@ $<
.PHONY: clean
clean:
	$(RM) $(objects) $(objects:.o=.d)
