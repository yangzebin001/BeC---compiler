	.file	"../testcase/arm_test/test_var1.sy"
	.text
	.data
	.global b
	.align	2
	.type	b, %object
	.size	b, 12
b:
	.word	10
	.word	11
	.word	12
	.text
	.data
	.global e
	.align	2
	.type	e, %object
	.size	e, 8
e:
	.word	44
	.word	45
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #8
    sub        r2, fp, #12
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    ldr        r3, =55
    str        r3, [r2, #0]
    ldr        r3, =56
    str        r3, [r2, #4]
    sub        sp, sp, #4
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L3
    ldr        r3, [r1, r9]
    str        r3, [fp, #-16]
    sub        sp, sp, #4
    ldr        r3, =10
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L4
    ldr        r3, [r1, r9]
    str        r3, [fp, #-24]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #12
    ldr        r3, [r1, r9]
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-28]
    mov        r0, r3
    b          label_RETURN6
label_RETURN6:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	b
.L4:
	.word	e
