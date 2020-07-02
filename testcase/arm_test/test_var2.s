	.file	"test_var2.c"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12  //sub stack point to save var
	mov	r3, #22
	str	r3, [fp, #-8]  //store var1 to stack
	mov	r3, #33
	str	r3, [fp, #-12] //store var2 to stack
	mov	r3, #1
	mov	r0, r3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr
