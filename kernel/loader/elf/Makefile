include ../../../Make.defs
INC = ../../..
OBJS := binfmt_copyactions.o binfmt_exec.o binfmt_exit.o binfmt_loadmodule.o binfmt_unregister.o nxflat.o \
	binfmt_copyargv.o binfmt_execmodule.o binfmt_globals.o binfmt_register.o builtin.o \
	binfmt_dumpmodule.o binfmt_execsymtab.o binfmt_initialize.o binfmt_unloadmodule.o elf.o
.PHONY: all
all: elf.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
elf.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) elf.a *.d
