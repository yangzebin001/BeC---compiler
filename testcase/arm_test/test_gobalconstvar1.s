	.arch armv7-a
	.text
	.global	a
	.section	.rodata
	.align	2
	.type	a, %object
	.size	a, 4
a:
	.word	22
	.text
	.align	2
	.global	main
	.arch armv7-a
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	mov	r3, #22
	str	r3, [fp, #-8]
	mov	r3, #1
	mov	r0, r3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr
	.size	main, .-main
