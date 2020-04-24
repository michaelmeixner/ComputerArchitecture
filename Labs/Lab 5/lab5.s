	.file	"lab5.c"
	.text
	.globl	compare
	.type	compare, @function
compare:
.LFB41:
	.cfi_startproc
#APP
# 8 "lab5.c" 1
	cmpl %edi, %esi
jg .L2
jl .L3
.L2:
cmpl %esi, %edx
jg .L4
jl .L5
.L3:
cmpl %edi, %edx
jg .L4
jl .L6
.L4:
movl %edx, %eax
.L5:
movl %esi, %eax
.L6:
movl %edi, %eax

# 0 "" 2
#NO_APP
	ret
	.cfi_endproc
.LFE41:
	.size	compare, .-compare
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB42:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	compare
	movl	%eax, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$8, %edx
	movl	$4, %esi
	movl	$5, %edi
	call	compare
	movl	%eax, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$5, %edx
	movl	$11, %esi
	movl	$9, %edi
	call	compare
	movl	%eax, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE42:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
