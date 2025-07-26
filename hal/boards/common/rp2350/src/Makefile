CC = arm-none-eabi-gcc
CXX = arm-none-eabi-g++
LD = arm-none-eabi-ld

objects := rp23xx_appinit.o rp23xx_autoleds.o rp23xx_boardinitialize.o rp23xx_bringup.o rp23xx_buttons.o rp23xx_gpio.o rp23xx_userleds.o

.PHONY: all
all: $(objects)
%.o: %.c
	$(CXX) -Wall -O2 $(CFLAGS) -I../../../../../include -o $@ $<
	$(LD) -Wall -O2 $(CFLAGS) -o rp23xx.o $<
.PHONY: clean
clean:
	$(RM) $(objects) $(objects:.o=.d)
