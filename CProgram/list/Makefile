TARGET:=list

OBJS:=list.o

CROSS_COMPILE:=arm-none-linux-gnueabi-

OBJCOPY:=$(CROSS_COMPILE)objcopy

OBJDUMP:=$(CROSS_COMPILE)objdump

LD:=$(CROSS_COMPILE)ld

AS:=$(CROSS_COMPILE)as


all: $(TARGET)x86 $(TARGET)arm
	
$(TARGET)x86:	
	gcc $(TARGET).c -o $(TARGET)x86
	file $(TARGET)x86
	@echo "Compilation successfully done for x86"

$(TARGET)arm:$(TARGET).s
	$(CROSS_COMPILE)gcc -static $(TARGET)arm.s -o $(TARGET)arm
	file $(TARGET)arm
	@echo "Compilation successfully done for arm"
	
$(TARGET).s:
	$(CROSS_COMPILE)gcc -S -static $(TARGET).c -o $(TARGET)arm.s
		

clean:	
	rm $(TARGET)x86 $(TARGET)arm $(TARGET)arm.s
