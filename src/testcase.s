	.file	"../testcase/functional_test/28_while_test2.sy"
	.text
	.align	2
	.global	FourWhile
	.arch armv7-a
	.arm
	.type	FourWhile, %function
FourWhile:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    mov        r3, #5
    mov        r8, r3
    str        r8, [fp, #-8]
    sub        sp, sp, #4
    sub        sp, sp, #4
    mov        r3, #6
    mov        r8, r3
    str        r8, [fp, #-12]
    mov        r3, #7
    mov        r8, r3
    str        r8, [fp, #-16]
    sub        sp, sp, #4
    mov        r3, #10
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-20]
    ldr        r7, [fp, #-28]
    add        r3, r7
    ldr        r7, [fp, #-24]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-32]
    add        r3, r7
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	FourWhile, .-FourWhile
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    bl         FourWhile
    mov        r3, r0
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
