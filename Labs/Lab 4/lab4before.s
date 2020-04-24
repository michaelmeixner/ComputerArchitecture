	.file	"lab4.c"
	.text
	.globl	inner
	.type	inner, @function
inner:
.LFB23:
	.cfi_startproc
	movl	$0, %ecx
	movl	$0, %eax
	jmp	.L2
.L3:
	imull	(%rsi,%r8,4), %edx
	addl	%edx, %eax
	addl	$1, %ecx
.L2:
	movslq	%ecx, %r8
	movl	(%rdi,%r8,4), %edx
	cmpl	$999, %edx
	jne	.L3
	rep ret
	.cfi_endproc
.LFE23:
	.size	inner, .-inner
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"a[%d] = %d   b[%d] = %d\n"
.LC1:
	.string	"Inner product is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$816, %rsp
	.cfi_def_cfa_offset 832
	movq	%fs:40, %rax
	movq	%rax, 808(%rsp)
	xorl	%eax, %eax
	movl	$0, %edx
	jmp	.L5
.L6:
	leal	1(%rdx), %ebx
	movslq	%edx, %rax
	movl	%ebx, (%rsp,%rax,4)
	movl	$9, %r9d
	subl	%edx, %r9d
	movl	%r9d, 400(%rsp,%rax,4)
	movl	%edx, %r8d
	movl	%ebx, %ecx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	%ebx, %edx
.L5:
	cmpl	$8, %edx
	jle	.L6
	movl	$999, 436(%rsp)
	movl	$999, 36(%rsp)
	movl	$10, %edi
	call	putchar@PLT
	leaq	400(%rsp), %rsi
	movq	%rsp, %rdi
	call	inner
	movl	%eax, %edx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	808(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L9
	addq	$816, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L9:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
