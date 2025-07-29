AR = arm-none-eabi-ar
SUBDIRS := clock semaphore timer
LIBS := clock/clock.a semaphore/semaphore.a timer/timer.a irq/irq.a
BUILD := ../build
TARGET := $(BUILD)/libraries/rt.a
.PHONY: $(LIBS)
all: $(TARGET)
$(TARGET): $(LIBS)
	@echo $(LIBS)
	@mkdir -p $(BUILD)/libraries $(BUILD)/objects $(BUILD)/binaries
	@for lib in $(LIBS); do \
		$(AR) -x $$lib; \
		mv *.o $(BUILD)/objects; \
	done
	$(AR) rcs $@ $(BUILD)/objects/*.o
$(LIBS):
	$(MAKE) -C $(dir $@)
clean:
	$(RM) $(TARGET)
	$(RM) -r $(BUILD)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
