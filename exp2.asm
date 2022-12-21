assume cs:code,ds:data
data segment
messageone db 0ah,"Enter the number$"
messagetwo db 0ah,"The number is:$"
data ends
code segment
start :mov ax,data
mov ds,ax
mov dx,offset messageone
mov ah,09h
int 21h
mov ah,01h
int 21h
sub al,30h
mov bh,0ah
mul bh
mov bh,al
mov ah,01h
int 21h
sub al,30h
add bh,al
mov dx,offset messagetwo
mov ah,09h
int 21h
mov cl,0ah
mov al,bh
mov ah,00h
div cl
mov bl,ah
add al,30h
mov dl,al
mov ah,02h
int 21h
add bl,30h
mov dl,bl
mov ah,02h
int 21h
mov ah,4ch
int 21h
code ends
end start