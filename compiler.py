#!/usr/bin/python3
import os
import sys
import time
import random

def clear_terminal():
	if (os.name == "nt"):
		os.system("cls")
	else:
		os.system("clear")

def show_help():
	print ("Kernel compiler!")
	print ("Coded by: Kevin Jerebica 2021 April 16th")
	print ("\n--------------------------------------------")
	print ("argument 1: path for the assembly bootloader")
	print ("argument 2: path for the c kernel")
	print ("argument 3: path for the linker script")
	print ("argument 4: output file's name")
	print ("--------------------------------------------")

def main():
	bootloader = "bootloader.asm"
	kernel = "kernel.c"
	linker = "linker.ld"
	output = "system"



	# compile the bootloader - command
	compile_bootloader = "nasm -f elf32 " + bootloader + " -o ./output_files/" + (bootloader.replace(".asm", "")) + ".o"

	# compile the kernel - command
	compile_kernel = "gcc -m32 -c " + kernel + " -o ./output_files/" + kernel.replace(".c", "")

	# link the two files - command
	linking_command = "ld -m elf_i386 -T " + linker + " -o ./output_files/" + output  + " ./output_files/" + (bootloader.replace(".asm", "")) + ".o" + " ./output_files/" + kernel.replace(".c", "")

	# start the system - command
	start_system = "qemu-system-i386 -kernel ./output_files/" + output



	# executing prepared commands
#	clear_terminal()
	print ("[!!] Compiling the bootloader")
	os.system(compile_bootloader)

#	clear_terminal()
	print ("[!!] Compiling the c kernel")
	os.system(compile_kernel)

#	clear_terminal()
	print ("[!!] Linking the files")
	os.system(linking_command)

#	clear_terminal()
	print ("[!!] Starting the operating system")
	os.system(start_system)

#	clear_terminal()

	# das it
	# coded by: Kevin Jerebica 2021 April 16th

if __name__ == "__main__":
	main()
