SOURCES= boot.o main.o common.o screen.o gdt_entry.o descrtables.o gdtptr.o gdt.o
CC = g++
CFLAGS=-ffreestanding -nostdlib -fno-rtti -fno-exceptions -fno-builtin 
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: 
	nasm boot.asm $(ASFLAGS)
	nasm gdt.asm $(ASFLAGS)
	$(CC) *.cpp $(CFLAGS) -c
	ld $(LDFLAGS) -o kernel $(SOURCES)
	

clean:
	-rm *.o kernel

.asm .o:
	nasm $(ASFLAGS) $<