	.file	"1_pre_pro_dir.c"
	.section	.rodata
.LC1:
	.string	"Area:%f\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$0x4148f5c3, %eax
	movl	%eax, 28(%esp)
	flds	28(%esp)
	movl	$.LC1, %eax
	fstpl	4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
