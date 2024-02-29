[ org 0x7c00 ]

call switch

jmp $						   ;  hang

%include "switch_16_to_32.asm"

times 512 - 2 - ($-$$) db 0    ;  zeroing everything between
dw 0xaa55                      ;  w - word = 2 bytes 
