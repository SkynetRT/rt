include ../../Make.defs
SUBDIRS := heap iob shm kmm umm pager
LIBS := heap/heap.a iob/iob.a shm/shm.a kmm/kmm.a umm/umm.a pager/pager.a
BUILD := ../../build
TARGET := $(BUILD)/libraries/mem.a
BLIBS := $(pathsubst %, $(BUILD)/libraries/%.a, $(SUBDIRS))
.PHONY: $(LIBS)
all: $(TARGET)
$(TARGET): $(LIBS)
	$(AR) rcs $@ $(BUILD)/mem/*.o
$(LIBS):
	@mkdir -p $(BUILD)/libraries $(BUILD)/mem
	$(MAKE) -C $(dir $@)
	mv $(dir $@)*.o $(BUILD)/mem
	mv $(dir $@)*.a $(BUILD)/libraries
clean:
	$(RM) -r $(BUILD)
