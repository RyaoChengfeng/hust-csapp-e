.686
.model flat, stdcall
 ExitProcess PROTO STDCALL :DWORD
 includelib  kernel32.lib  ; ExitProcess 在 kernel32.lib中实现
 printf      PROTO C :VARARG
 scanf		 PROTO C :VARARG
 includelib  libcmt.lib
 includelib  legacy_stdio_definitions.lib

.DATA
	fmt		db	"%s"
	buf1	db  'liuziqi',0
	buf2	db  10 dup(0)
	ans1	db	'OK!',0
	ans2	db	'Incorrect Password！',0
.STACK 200
.CODE


main proc c
   invoke scanf,ADDR fmt,ADDR buf2
   MOV  ESI,OFFSET buf1
   MOV  EDI,OFFSET buf2
L1:
   MOV  AL,[ESI]
   MOV  BL,[EDI]
   CMP  AL,BL
   JNZ  A2
   ADD  ESI,1
   ADD  EDI,1
   CMP  AL,0 		;如果AL == BL,继续判断是否为0,为0退出。
   JNZ  L1
   JZ	A1

A1:
   invoke printf,OFFSET ans1
   invoke ExitProcess, 0
A2:
   invoke printf,OFFSET ans2
   invoke ExitProcess, 0
main endp
END