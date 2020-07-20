	.file	"../testcase/arm_test/testcase.sy"
	.text
	.data
	.global a
	.align	2
	.type	a, %object
	.size	a, 4
a:
	.word	0
	.global b
	.align	2
	.type	b, %object
	.size	b, 4
b:
	.word	4660
	.global c
	.align	2
	.type	c, %object
	.size	c, 4
c:
	.word	83
	.text
.L3:
	.word	a
.L4:
	.word	b
.L5:
	.word	c
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0x14
    str        r3, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, =0123
    str        r3, [fp, #-12]
    ldr        r3, [fp, #-12]
    mov        r0, r3
    b          label_RETURN7
label_RETURN7:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
