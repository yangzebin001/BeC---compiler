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
	.file	"test_manyparam.c"
	.text
	.align	2
	.global	func1
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	func1, %function
func1:
	@ args = 8, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	mov	r3, #1
	str	r3, [fp, #-8]
	mov	r3, #2
	str	r3, [fp, #-16]
	mov	r3, #3
	str	r3, [fp, #-20]
	mov	r3, #4
	str	r3, [fp, #4]
	mov	r3, #5
	str	r3, [fp, #8]
	ldr	r3, [fp, #-12]
	add	r3, r3, #4
	mov	r2, #22
	str	r2, [r3]
	mov	r3, #0
	mov	r0, r3
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	func1, .-func1
	.section	.rodata
	.align	2
.LC0:
	.word	10
	.word	11
	.word	12
	.word	13
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #48
	ldr	r3, .L5
	sub	ip, fp, #40
	ldm	r3, {r0, r1, r2, r3}
	stm	ip, {r0, r1, r2, r3}
	mov	r3, #3
	str	r3, [fp, #-8]
	mov	r3, #4
	str	r3, [fp, #-12]
	mov	r3, #5
	str	r3, [fp, #-16]
	mov	r3, #6
	str	r3, [fp, #-20]
	mov	r3, #7
	str	r3, [fp, #-24]
	sub	r1, fp, #40
	ldr	r3, [fp, #-24]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-20]
	str	r3, [sp]
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-12]
	ldr	r0, [fp, #-8]
	bl	func1
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L6:
	.align	2
.L5:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
