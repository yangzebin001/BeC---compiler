	.arch armv7-a
	.file	"test_fun2.c"
	.text
	.align	2
	.global	foo
	.arch armv7-a
	.arm
	.type	foo, %function
foo:
	push	{fp, lr}
	add	fp, sp, #4
	bl	coo
	nop
	mov	r0, r3
	pop	{fp, pc}
	.size	foo, .-foo
	.align	2
	.global	coo
	.arm
	.type	coo, %function
coo:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	nop
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	coo, .-coo
	.align	2
	.global	main
	.arm
	.type	main, %function
main:
	push	{fp, lr}
	add	fp, sp, #4

	sub	sp, sp, #4   //a = 20
	mov	r3, #20
	str	r3, [fp, #-8]

	sub	sp, sp, #4  //b = 20
	mov	r3, #30
	str	r3, [fp, #-12]

	bl	foo

	ldr	r3, [fp, #-12] //return b
	mov	r0, r3

	sub	sp, fp, #4
	pop	{fp, pc}
	.size	main, .-main
