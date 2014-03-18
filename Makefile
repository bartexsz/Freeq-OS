SOURCES= boot.o main.o common.o screen.o gdt_entry.o descrtables.o gdtptr.o gdt.o kernel_main.o
CC = g++
CFLAGS=-ffreestanding -nostdlib -fno-rtti -fno-exceptions -fno-builtin -m32
LDFLAGS=-Tlink.ld -melf_i386
ASFLAGS=-felf

all: 
	nasm src/boot.asm $(ASFLAGS)
	nasm src/gdt.asm $(ASFLAGS)
	$(CC) src/*.cpp $(CFLAGS) -c
	mv src/boot.o boot.o
	mv src/gdt.o gdt.o
	ld $(LDFLAGS) -o kernel.bin $(SOURCES)
	mkdir isodir
	mkdir isodir/boot
	cp kernel.bin isodir/boot/kernel.bin
	mkdir isodir/boot/grub
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o freeq.iso isodir
	rm -r isodir
	

clean:
	-rm *.o kernel.bin freeq.iso

.asm .o:
	nasm $(ASFLAGS) $<
