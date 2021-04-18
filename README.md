# Basic Kernel
<hr>
This is my preset when making a new operating system from scratch. <br>
Before jumping into the code, please read the full documentation page to get a full understanding of this preset project. <br>
Thank you :D<br>
# Functionality of the kernel
 - 2x Output functions: sysout_line, sysout<br>
 - Basic scrolling system - when all the lines are filled with information,<br>
    the kernel deletes the first line and moves the rest of lines one line up<br>

# Project - Directory Structure
 ```/output_files/ ``` <- location of the compiled files<br>
 ```/includes/colors/ ``` <- files which include variables with color values<br>
 ```/includes/global/ ``` <- global variables like next possible line/column the kernel can use to print something to the screen,.. <br>
 
# Project - Important Files
```/compiler.py``` <- compiler program ( so far i don't have experience with making a Makefile )<br>
```/kernel.c``` <- the kernel written in c code<br>
```/bootloader.asm``` <- bootloader<br>
```/linker.ld``` <- linker script

# How to compile the project
It is as simple as just typing: <br>
```python3 compiler.py``` <- supposing you have already installed nasm, gcc, ld, qemu-system-x86_64 and qemu-system-i386 <br><br>

!If you want to compile it and run the kernel at the same time type: <br>
```python3 compiler.py compile-run``` <- supposing you have installed qemu-system-x86_64 and qemu-system-i386<br><br> 

# How to run the newly generated output kernel 
1) Move into the ```/output_files``` directory with ```cd ./output_files``` <br>
2) Run the qemu-system-i386 program on the outputted file ("system") ```qemu-system-i386 -kernel system``` 

## Warning 
If you have any questions or trouble in understanding the code you can shoot me a message on my instagram page or on my email, I should reply in a 1-3 days
