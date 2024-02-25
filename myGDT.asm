gdt_start:

; 8-byte null dtor
dd 0x0
dd 0x0

;  8-byte code seg dtor (all structure parts must be defined separately, otherwise little endian will do things)
gdt_code:
;  limit and base
dw 1111111111111111b
dw 0000000000000000b
;  base, flags, limit, base
db 00000000b
db 10011010b
db 11001111b
db 00000000b

;  8-byte data seg dtor
gdt_data:
;  limit and base
dw 1111111111111111b
dw 0000000000000000b
;  base, flags, limit, base
db 00000000b
db 10010010b
db 11001111b
db 00000000b

gdt_end:

;  the most important label
my_gdt_dtor:
dw gdt_end - gdt_start - 1 
dd gdt_start

CSEG equ gdt_code - gdt_start
DSEG equ gdt_data - gdt_start
