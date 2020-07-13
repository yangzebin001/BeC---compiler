	.file	"../testcase/functional_test/13_and.sy"
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
    bl         getint
    mov        r3, r0
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    bl         getint
    mov        r3, r0
    mov        r8, r3
    ldr        r2, .L4
    str        r8, [r2]
    ldr        r2, .L3
    ldr        r3, [r2]
    cmp        r3, #0
    beq        label_IFEND7
    beq        label_IFEND7
    111        r7, r3
    ldr        r2, .L4
    ldr        r3, [r2]
    cmp        r3, #0
    beq        label_IFEND7
    222        r7, r3
    mov        r3, #1
    mov        r0, r3
    b          label_RETURN6
label_IFEND7:
    mov        r3, #0
    mov        r0, r3
    b          label_RETURN6
label_RETURN6:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
.L4:
	.word	b
