	.file	"lab9.c"
	.text
	.globl	t1a
	.data
	.align 32
	.type	t1a, @object
	.size	t1a, 40
t1a:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.long	8
	.long	9
	.long	0
	.globl	t1b
	.align 32
	.type	t1b, @object
	.size	t1b, 40
t1b:
	.long	5
	.long	4
	.long	-3
	.long	0
	.long	1
	.long	-8
	.long	5
	.long	2
	.long	4
	.long	6
	.globl	t2a
	.align 16
	.type	t2a, @object
	.size	t2a, 28
t2a:
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.long	6
	.long	7
	.globl	t2b
	.align 16
	.type	t2b, @object
	.size	t2b, 28
t2b:
	.long	8
	.long	9
	.long	0
	.long	1
	.long	2
	.long	3
	.long	4
	.globl	t3a
	.align 32
	.type	t3a, @object
	.size	t3a, 44
t3a:
	.long	1
	.long	1
	.long	2
	.long	2
	.long	3
	.long	3
	.long	4
	.long	4
	.long	5
	.long	6
	.long	7
	.globl	t3b
	.align 32
	.type	t3b, @object
	.size	t3b, 44
t3b:
	.long	1
	.long	2
	.long	3
	.long	5
	.long	7
	.long	1
	.long	2
	.long	3
	.long	5
	.long	7
	.long	9
	.globl	t4a
	.align 32
	.type	t4a, @object
	.size	t4a, 52
t4a:
	.long	1
	.long	3
	.long	5
	.long	7
	.long	9
	.long	9
	.long	7
	.long	5
	.long	3
	.long	1
	.long	6
	.long	1
	.long	6
	.globl	t4b
	.align 32
	.type	t4b, @object
	.size	t4b, 52
t4b:
	.long	6
	.long	1
	.long	6
	.long	4
	.long	1
	.long	3
	.long	3
	.long	1
	.long	4
	.long	6
	.long	1
	.long	6
	.long	7
	.globl	t5a
	.align 32
	.type	t5a, @object
	.size	t5a, 36
t5a:
	.long	1
	.long	9
	.long	2
	.long	8
	.long	3
	.long	7
	.long	4
	.long	8
	.long	5
	.globl	t5b
	.align 32
	.type	t5b, @object
	.size	t5b, 36
t5b:
	.long	4
	.long	5
	.long	3
	.long	6
	.long	2
	.long	7
	.long	1
	.long	8
	.long	9
	.comm	t6a,40000000,32
	.comm	t6b,40000000,32
	.text
	.globl	inner
	.type	inner, @function
inner:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	%edx, -52(%rbp)
	movq	%rcx, -64(%rbp)
	movl	$0, -20(%rbp)
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L2
.L3:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, -20(%rbp)
	addl	$1, -24(%rbp)
.L2:
	movl	-24(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L3
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, (%rax)
	movl	-20(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	inner, .-inner
	.globl	inner2
	.type	inner2, @function
inner2:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	%edx, -52(%rbp)
	movq	%rcx, -64(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L6
.L7:
	movl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, -28(%rbp)
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-32(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, -24(%rbp)
	addl	$1, -32(%rbp)
	addl	$1, -32(%rbp)
.L6:
	movl	-32(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L7
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, (%rax)
	movl	-20(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	inner2, .-inner2
	.globl	inner5
	.type	inner5, @function
inner5:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movl	%edx, -52(%rbp)
	movq	%rcx, -64(%rbp)
	movl	$0, -20(%rbp)
	call	clock@PLT
	movq	%rax, -16(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L10
.L11:
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	imull	%eax, %edx
	movl	-20(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	-24(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rsi
	movq	-48(%rbp), %rax
	addq	%rsi, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, %ecx
	movl	-24(%rbp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	addq	$2, %rax
	leaq	0(,%rax,4), %rsi
	movq	-48(%rbp), %rax
	addq	%rsi, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, %ecx
	movl	-24(%rbp), %eax
	cltq
	addq	$3, %rax
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	addq	$3, %rax
	leaq	0(,%rax,4), %rsi
	movq	-48(%rbp), %rax
	addq	%rsi, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%eax, %ecx
	movl	-24(%rbp), %eax
	cltq
	addq	$4, %rax
	leaq	0(,%rax,4), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	addq	$4, %rax
	leaq	0(,%rax,4), %rsi
	movq	-48(%rbp), %rax
	addq	%rsi, %rax
	movl	(%rax), %eax
	imull	%edx, %eax
	addl	%ecx, %eax
	movl	%eax, -20(%rbp)
	addl	$5, -24(%rbp)
.L10:
	movl	-24(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L11
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	subq	-16(%rbp), %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, (%rax)
	movl	-20(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	inner5, .-inner5
	.section	.rodata
.LC1:
	.string	"%ld "
.LC3:
	.string	"\nAverage cycles = %lf\n"
.LC4:
	.string	"\nInner 2:"
.LC5:
	.string	"\nInner 5:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	movl	$10, %edx
	leaq	t1b(%rip), %rsi
	leaq	t1a(%rip), %rdi
	call	inner
	movl	%eax, -96(%rbp)
	leaq	-64(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rcx
	movl	$7, %edx
	leaq	t2b(%rip), %rsi
	leaq	t2a(%rip), %rdi
	call	inner
	movl	%eax, -92(%rbp)
	leaq	-64(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	movl	$11, %edx
	leaq	t3b(%rip), %rsi
	leaq	t3a(%rip), %rdi
	call	inner
	movl	%eax, -88(%rbp)
	leaq	-64(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rcx
	movl	$13, %edx
	leaq	t4b(%rip), %rsi
	leaq	t4a(%rip), %rdi
	call	inner
	movl	%eax, -84(%rbp)
	leaq	-64(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rcx
	movl	$9, %edx
	leaq	t5b(%rip), %rsi
	leaq	t5a(%rip), %rdi
	call	inner
	movl	%eax, -80(%rbp)
	leaq	-64(%rbp), %rax
	addq	$40, %rax
	movq	%rax, %rcx
	movl	$10000000, %edx
	leaq	t6b(%rip), %rsi
	leaq	t6a(%rip), %rdi
	call	inner
	movl	%eax, -76(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	$0, -108(%rbp)
	jmp	.L14
.L15:
	movl	-108(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-72(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	-108(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -108(%rbp)
.L14:
	cmpl	$5, -108(%rbp)
	jle	.L15
	movsd	-72(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	movl	$10, %edx
	leaq	t1b(%rip), %rsi
	leaq	t1a(%rip), %rdi
	call	inner2
	movl	%eax, -96(%rbp)
	leaq	-64(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rcx
	movl	$7, %edx
	leaq	t2b(%rip), %rsi
	leaq	t2a(%rip), %rdi
	call	inner2
	movl	%eax, -92(%rbp)
	leaq	-64(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	movl	$11, %edx
	leaq	t3b(%rip), %rsi
	leaq	t3a(%rip), %rdi
	call	inner2
	movl	%eax, -88(%rbp)
	leaq	-64(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rcx
	movl	$13, %edx
	leaq	t4b(%rip), %rsi
	leaq	t4a(%rip), %rdi
	call	inner2
	movl	%eax, -84(%rbp)
	leaq	-64(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rcx
	movl	$9, %edx
	leaq	t5b(%rip), %rsi
	leaq	t5a(%rip), %rdi
	call	inner2
	movl	%eax, -80(%rbp)
	leaq	-64(%rbp), %rax
	addq	$40, %rax
	movq	%rax, %rcx
	movl	$10000000, %edx
	leaq	t6b(%rip), %rsi
	leaq	t6a(%rip), %rdi
	call	inner2
	movl	%eax, -76(%rbp)
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	$0, -104(%rbp)
	jmp	.L16
.L17:
	movl	-104(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-72(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	-104(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -104(%rbp)
.L16:
	cmpl	$5, -104(%rbp)
	jle	.L17
	movsd	-72(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	movl	$10, %edx
	leaq	t1b(%rip), %rsi
	leaq	t1a(%rip), %rdi
	call	inner5
	movl	%eax, -96(%rbp)
	leaq	-64(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rcx
	movl	$7, %edx
	leaq	t2b(%rip), %rsi
	leaq	t2a(%rip), %rdi
	call	inner5
	movl	%eax, -92(%rbp)
	leaq	-64(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	movl	$11, %edx
	leaq	t3b(%rip), %rsi
	leaq	t3a(%rip), %rdi
	call	inner5
	movl	%eax, -88(%rbp)
	leaq	-64(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rcx
	movl	$13, %edx
	leaq	t4b(%rip), %rsi
	leaq	t4a(%rip), %rdi
	call	inner5
	movl	%eax, -84(%rbp)
	leaq	-64(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rcx
	movl	$9, %edx
	leaq	t5b(%rip), %rsi
	leaq	t5a(%rip), %rdi
	call	inner5
	movl	%eax, -80(%rbp)
	leaq	-64(%rbp), %rax
	addq	$40, %rax
	movq	%rax, %rcx
	movl	$10000000, %edx
	leaq	t6b(%rip), %rsi
	leaq	t6a(%rip), %rdi
	call	inner5
	movl	%eax, -76(%rbp)
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	$0, -100(%rbp)
	jmp	.L18
.L19:
	movl	-100(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-72(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	movl	-100(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -100(%rbp)
.L18:
	cmpl	$5, -100(%rbp)
	jle	.L19
	movsd	-72(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L20
	call	__stack_chk_fail@PLT
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1075314688
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
