SOURCES=boot.o main.o common.o screen.o

CPPFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -fno-exceptions -fno-rtti
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link 

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.asm.o:
	nasm $(ASFLAGS) $<