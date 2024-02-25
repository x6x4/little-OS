[ org 0x7c00 ]

call switch

[bits 32]

VIDEOMEM equ 0xb800
FORE_BACK   equ 0x0f
	
mov edx, VIDEOMEM+500
mov al, 0x41  				   ;  ascii code for A
mov ah, FORE_BACK 
mov [edx], ax    			   ;  writing directly to videomem

jmp $						   ;  hang

%include "switch_16_to_32.asm"
times 512 - 2 - ($-$$) db 0    ;  zeroing everything between
dw 0xaa55                      ;  w - word = 2 bytes 
