VIDEOMEM    equ 0xb800
FORE_BACK   equ 0x0f
CHAR        equ 0x41      ;  ascii code for A
	
mov edx, VIDEOMEM
mov al, CHAR  	
mov ah, FORE_BACK 
mov [edx], ax    		  ;  writing directly to videomem


