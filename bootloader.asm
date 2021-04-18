bits 32 ; read as 32 bit code
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002 ;magic number
        dd 0x00 ; flags 
        dd - (0x1BADB002 + 0x00) ; checksum

; set the start label to global
global start

extern main 

; start label
start:
	; disable interrupts
	cli
	;; call the extern main function ( kernel.c )
	call main
	; halt the cpu - like a while(1); loop in C
	hlt

; bss section 
section .bss
