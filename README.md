# OS
Simple DOS like operating system.
# Compiller:
Compile with this (Windows) - https://code.google.com/p/micron-sysv3/downloads/detail?name=i686-elf-gcc.rar
Add stdint.h, stdbool.h, stddef.h in /include and add only stdint.h in \lib\gcc\i686-elf\4.2.0\include.
# Compilation:
i686-elf-as boot.s -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T linker.ld -o osdev.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
# Run
You can use qemu to run this os. Run it with:
D:\OSDEV\qemu\qemu-system-i386 -kernel osdev.bin
Alternatively you can use grub to make .iso from .bin file and run it on real machine.
