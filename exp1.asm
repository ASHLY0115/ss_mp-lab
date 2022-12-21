assume cs : code,ds:data
data segment
message db "MY NAME IS RYANA$"
messagetwo db 0AH "hello world$"
data ends
code segment 
start:mov ax,data
mov ds,ax
mov dx,offset message
mov ah,09h 
int 21h
mov dx,offset messagetwo
mov ah,09h 
int 21h
mov ah,4ch
int 21h
code ends
end start