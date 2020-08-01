	.file	"../testcase/arm_test/testcase.sy"
	.text
	.data
	.global arr
	.align	2
	.type	arr, %object
	.size	arr, 24
arr:
	.word	7
	.word	2
	.word	3
	.word	5
	.space	8
	.global c
	.align	2
	.type	c, %object
	.size	c, 4
c:
	.word	291
	.global d
	.align	2
	.type	d, %object
	.size	d, 4
d:
	.word	291
	.global e
	.align	2
	.type	e, %object
	.size	e, 4
e:
	.word	83
	.global f
	.align	2
	.type	f, %object
	.size	f, 4
f:
	.word	2147483647
	.text
.L3:
	.word	arr
.L4:
	.word	c
.L5:
	.word	d
.L6:
	.word	e
.L7:
	.word	f
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
    ldr        r3, =1
    str        r3, [fp, #-8]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-12]
    ldr        r3, =1
    ldr        r7, [fp, #-12]
    cmp        r7, r3
    bne        label_IFEND10
label_IFTRUE11:
    ldr        r3, =20
    mov        r0, r3
    b          label_RETURN9
label_IFEND10:
    ldr        r2, .L7
    ldr        r3, [r2]
    mov        r0, r3
    b          label_RETURN9
label_RETURN9:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
