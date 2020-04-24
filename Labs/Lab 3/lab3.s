	.file	"lab3.c"
	.text
	.globl	lab3
	.type	lab3, @function
lab3:
.LFB23:
	.cfi_startproc
	movq	%rdi, %rax
	jmp	.L2
.L3:
	subq	%rsi, %rax
.L2:
	cmpq	%rsi, %rax
	je	.L6
	cmpq	%rsi, %rax
	jge	.L3
	movq	%rsi, %rdx
	subq	%rax, %rdx
	movq	%rdx, %rax
	jmp	.L2
.L6:
	rep ret
	.cfi_endproc
.LFE23:
	.size	lab3, .-lab3
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$4, %esi
	movl	$36, %edi
	call	lab3
	movq	%rax, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
