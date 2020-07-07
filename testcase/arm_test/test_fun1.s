	.arch armv7-a
	.file	"test_fun1.c"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
foo:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr
main:
	push	{fp, lr}
	add	fp, sp, #4
	bl	foo
	mov	r3, #0
	mov	r0, r3
	pop	{fp, pc}
