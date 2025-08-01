include ../Make.defs
SUBDIRS := clock semaphore timer irq env signal mqueue task thread crypto sched
LIBS := clock/clock.a semaphore/semaphore.a timer/timer.a irq/irq.a env/env.a \
	signal/signal.a mqueue/mqueue.a task/task.a thread/thread.a crypto/crypto.a sched/sched.a
BUILD := ../build
TARGET := $(BUILD)/libraries/kernel.a
BLIBS := $(pathsubst %, $(BUILD)/libraries/%.a, $(SUBDIRS)) $(BUILD)/libraries/loader.a $(BUILD)/libraries/mem.a
.PHONY: all
all: $(TARGET)
$(TARGET): $(BUILD)/libraries/loader.a $(BUILD)/libraries/mem.a $(LIBS)
	@for lib in $(BLIBS); do $(AR) -x $$lib; mv *.o $(BUILD)/kernel; done
	$(AR) rcs $@ $(BUILD)/kernel/*.o
$(BUILD)/libraries/loader.a:
	$(MAKE) -C loader
$(BUILD)/libraries/mem.a:
	$(MAKE) -C mem
$(LIBS):
	@mkdir -p $(BUILD)/libraries $(BUILD)/kernel $(BUILD)/loader $(BUILD)/mem
	$(MAKE) -C $(dir $@)
	mv $(dir $@)*.o $(BUILD)/kernel
	mv $(dir $@)*.a $(BUILD)/libraries
clean:
	$(RM) -r $(BUILD)
