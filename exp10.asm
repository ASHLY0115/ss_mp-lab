ASSUME CS:CODE,DS:DATA
DATA SEGMENT
MSG DB 0AH,'HELLO$'
MSGS DB 0AH,'SJCET$'
DATA ENDS
CODE SEGMENT
START:MOV AX,DATA
MOV DS,AX
MOV DX,OFFSET MSG
MOV AH,09H
INT 21H
MOV DX,OFFSET MSGS
INT 21H
MOV AH,4CH
INT 21H
CODE ENDS
END START