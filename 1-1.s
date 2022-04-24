	.file	"1-1.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"16\350\277\233\345\210\266 %x %x ; \345\215\201\350\277\233\345\210\266\357\274\232 %d %d\n"
	.align 8
.LC1:
	.string	"\346\234\211\347\254\246\345\217\267\346\225\260 %d ; \346\227\240\347\254\246\345\217\267\346\225\260 %u \n"
	.align 8
.LC2:
	.string	"\346\227\240\347\254\246\345\217\267\346\225\260 %u ; \346\234\211\347\254\246\345\217\267\346\225\260 %d \n"
	.text
	.globl	int_representation
	.type	int_representation, @function
int_representation:
.LFB23:
	.cfi_startproc
	endbr64
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	r9d, -65539
	mov	r8d, -65539
	mov	ecx, -65539
	mov	edx, -65539
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	ecx, -65539
	mov	edx, -65539
	lea	rsi, .LC1[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	ecx, -65539
	mov	edx, -65539
	lea	rsi, .LC2[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	int_representation, .-int_representation
	.section	.rodata.str1.8
	.align 8
.LC3:
	.string	"16\350\277\233\345\210\266 %08x %08x ; \345\215\201\350\277\233\345\210\266\357\274\232 %d %d\n"
	.align 8
.LC4:
	.string	"\346\227\240\347\254\246\345\217\267\346\225\260 %hu ; \346\234\211\347\254\246\345\217\267\346\225\260 %hd \n"
	.text
	.globl	short_representation
	.type	short_representation, @function
short_representation:
.LFB24:
	.cfi_startproc
	endbr64
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	r9d, 32769
	mov	r8d, -32767
	mov	ecx, 32769
	mov	edx, -32767
	lea	rsi, .LC3[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	ecx, 32769
	mov	edx, -32767
	lea	rsi, .LC1[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	ecx, 32769
	mov	edx, -32767
	lea	rsi, .LC4[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	short_representation, .-short_representation
	.globl	float_representation
	.type	float_representation, @function
float_representation:
.LFB25:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE25:
	.size	float_representation, .-float_representation
	.globl	string_representation
	.type	string_representation, @function
string_representation:
.LFB26:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE26:
	.size	string_representation, .-string_representation
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	endbr64
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	eax, 0
	call	int_representation
	mov	eax, 0
	call	short_representation
	mov	eax, 0
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
