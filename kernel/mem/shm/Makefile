include ../../../Make.defs
INC = ../../..
OBJS := shmctl.o shmdt.o shmget.o shmat.o
.PHONY: all
all: shm.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
shm.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) shm.a *.d
