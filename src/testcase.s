	.file	"../testcase/functional_test/09_if.sy"
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
    mov        r3, #2
    mov        r8, r3
    ldr        r2, .L4
    str        r8, [r2]
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-4]
    ldr        r2, .L4
    ldr        r3, [r2]
    ldr        r2, [fp, #-4]
    cmp        r2, r3
    beq        IFEND4
    mov        r3, #1
    mov        r0, r3
    b          RETURN
IFEND4:
    mov        r3, #0
    mov        r0, r3
    b          RETURN
RETURN:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
.L4:
	.word	b
