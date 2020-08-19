	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"test_globalvar2.c"
	.text

	.global	a
	.data
	.align	2
	.type	a, %object
	.size	a, 4
a:
	.word	22

	.comm	b,4,4
	
	.global	c
	.align	2
	.type	c, %object
	.size	c, 4
c:
	.word	44
	.text
	.align	2
	.global	main
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L3
	mov	r2, #33
	str	r2, [r3]
	ldr	r3, .L5
	mov	r2, #55
	str	r2, [r3]
	ldr	r3, .L5
	ldr	r3, [r3]
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	main, .-main
.L4:
	.align	2
.L5:
	.word	b
.L3:
	.word	c
