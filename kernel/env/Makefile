include ../../Make.defs
OBJS := env_dup.o env_foreach.o env_getenvironptr.o env_release.o env_setenv.o \
	env_clearenv.o env_findvar.o env_getenv.o env_putenv.o env_removevar.o env_unsetenv.o
.PHONY: all
all: env.a
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
env.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
.PHONY: clean
clean:
	$(RM) $(OBJS) env.a *.d
