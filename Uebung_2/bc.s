	.file	"bc.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d %c %d"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"Wrong operator: %c\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
.L9:
	leaq	-12(%rbp), %rcx
	leaq	-13(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	-13(%rbp), %eax
	movsbl	%al, %eax
	cmpl	$43, %eax
	je	.L2
	cmpl	$43, %eax
	jg	.L3
	cmpl	$42, %eax
	je	.L4
	jmp	.L5
.L3:
	cmpl	$45, %eax
	je	.L6
	cmpl	$47, %eax
	je	.L7
	jmp	.L5
.L2:
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L6:
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L4:
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	imull	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L7:
	movl	-8(%rbp), %eax
	movl	-12(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -4(%rbp)
	jmp	.L8
.L5:
	movzbl	-13(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L8:
	jmp	.L9
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
