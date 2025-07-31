include ../../../Make.defs
INC = ../../..
OBJS := libnxflat_addrenv.o libnxflat_init.o libnxflat_read.o libnxflat_unload.o \
	libnxflat_bind.o libnxflat_load.o libnxflat_uninit.o libnxflat_verify.o
.PHONY: all
all: flat.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
flat.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) flat.a *.d
