	.file	"../testcase/functional_test/10_if_else.sy"
	.text
	.data
	.comm	a,4,4
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
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-4]
    mov        r3, #0
    ldr        r7, [fp, #-4]
    cmp        r7, r3
    ble        label_IFFALSE6
    mov        r3, #1
    mov        r0, r3
    b          label_RETURN5
    b          label_IFEND7
label_IFFALSE6:
    mov        r3, #0
    mov        r0, r3
    b          label_RETURN5
label_IFEND7:
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
