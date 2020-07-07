	.arch armv7-a
	.file	"test_fun2.c"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.type	foo, %function
foo:
	push	{fp, lr}
	add	fp, sp, #4
	bl	coo
	mov	r0, r3
	sub	sp, fp, #4
	pop	{fp, pc}
coo:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	mov	r0, r3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr
main:
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #20
	str	r3, [fp, #-8]
	bl	foo
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	pop	{fp, pc}
