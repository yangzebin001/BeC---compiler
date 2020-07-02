	.file	"test_funcall1.c"
	.arch armv7-a
	.text
	.align	2
	.global	main
	.arm
	.type	main, %function
main:
	push	{fp, lr}
	add	fp, sp, #4
	bl	foo
	pop	{fp, pc}
foo:
	str	fp, [sp, #-4]!	//add two line when no funcparam 
	add	fp, sp, #0
	mov	r3, #1
	mov	r0, r3
	add	sp, fp, #0	   //add two line when no funcparam 
	ldr	fp, [sp], #4 
	bx	lr
