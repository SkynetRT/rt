include ../../Make.defs
SUBDIRS := elf flat
LIBS := elf/elf.a flat/flat.a
BUILD := ../../build
TARGET := $(BUILD)/libraries/loader.a
BLIBS := $(pathsubst %, $(BUILD)/libraries/%.a, $(SUBDIRS))
.PHONY: $(LIBS)
all: $(TARGET)
$(TARGET): $(LIBS)
	$(AR) rcs $@ $(BUILD)/loader/*.o
$(LIBS):
	@mkdir -p $(BUILD)/libraries $(BUILD)/loader
	$(MAKE) -C $(dir $@)
	mv $(dir $@)*.o $(BUILD)/loader
	mv $(dir $@)*.a $(BUILD)/libraries
clean:
	$(RM) -r $(BUILD)
