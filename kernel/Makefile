include ../Make.defs
SUBDIRS := clock semaphore timer irq env signal mqueue task thread crypto sched
LIBS := clock/clock.a semaphore/semaphore.a timer/timer.a irq/irq.a env/env.a \
	signal/signal.a mqueue/mqueue.a task/task.a thread/thread.a crypto/nuttx/crypto.a sched/sched.a
BUILD := ../build
TARGET := $(BUILD)/libraries/kernel.a
BLIBS := $(pathsubst %, $(BUILD)/libraries/%.a, $(SUBDIRS))
.PHONY: $(LIBS)
all: $(TARGET)
$(TARGET): $(LIBS)
	@for lib in $(BLIBS); do $(AR) -x $$lib; mv *.o $(BUILD)/objects; done
	$(AR) rcs $@ $(BUILD)/objects/*.o
$(LIBS):
	@mkdir -p $(BUILD)/libraries $(BUILD)/objects
	$(MAKE) -C $(dir $@)
	mv $(dir $@)*.o $(BUILD)/objects
	mv $(dir $@)*.a $(BUILD)/libraries
clean:
	$(RM) -r $(BUILD)
