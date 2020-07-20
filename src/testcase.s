	.file	"../testcase/arm_test/testcase.sy"
	.text
	.data
	.global a
	.align	2
	.type	a, %object
	.size	a, 32
a:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.word	6
	.word	7
	.word	8
	.global cc
	.align	2
	.type	cc, %object
	.size	cc, 40000
cc:
	.word	0
	.word	1
	.word	2
	.word	3
	.space	39984
	.text
.L3:
	.word	a
.L4:
	.word	cc
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
    ldr        r3, =9999
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L4
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-12]
    ldr        r3, =2
    ldr        r7, [fp, #-12]
    add        r3, r7
    str        r3, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, =2
    str        r3, [fp, #-16]
    ldr        r3, [fp, #-16]
    mov        r0, r3
    b          label_RETURN6
label_RETURN6:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
