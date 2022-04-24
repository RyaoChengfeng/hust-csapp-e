	.file	"2-1.c"
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
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$-65539, %r9d
	movl	$-65539, %r8d
	movl	$-65539, %ecx
	movl	$-65539, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$-65539, %ecx
	movl	$-65539, %edx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$-65539, %ecx
	movl	$-65539, %edx
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
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
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$32769, %r9d
	movl	$-32767, %r8d
	movl	$32769, %ecx
	movl	$-32767, %edx
	leaq	.LC3(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$32769, %ecx
	movl	$-32767, %edx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$32769, %ecx
	movl	$-32767, %edx
	leaq	.LC4(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addq	$8, %rsp
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
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$0, %eax
	call	int_representation
	movl	$0, %eax
	call	short_representation
	movl	$0, %eax
	addq	$8, %rsp
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
