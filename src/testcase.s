	.file	"../testcase/functional_test/05_add.sy"
	.text
	.data
	.comm	a,4,4
	.comm	b,4,4
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    mov        r3, #10
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    mov        r3, #20
    mov        r8, r3
    ldr        r2, .L4
    str        r8, [r2]
    sub        sp, sp, #4
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-8]
    ldr        r2, .L4
    ldr        r3, [r2]
    ldr        r7, [fp, #-8]
    add        r3, r7
    rsb        r3, r3, #0
    mov        r8, r3
    str        r8, [fp, #-4]
    ldr        r3, [fp, #-4]
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
.L4:
	.word	b
