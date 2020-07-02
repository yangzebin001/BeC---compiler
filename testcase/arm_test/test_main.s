	.file	"test_main.c"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
	str	fp, [sp, #-4]! 	//add two line when no funcparam 
	add	fp, sp, #0
	mov	r3, #3
	mov	r0, r3
	add	sp, fp, #0  	//add two line when no funcparam 
	ldr	fp, [sp], #4
	bx	lr
