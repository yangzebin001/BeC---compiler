	.file	"../testcase/arm_test/test_whileandor.sy"
	.text
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
    ldr        r3, =0
    str        r3, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, =0
    str        r3, [fp, #-12]
    sub        sp, sp, #4
    ldr        r3, =0
    str        r3, [fp, #-16]
label_WHILESTART5:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r3, =10
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bgt        label_WHILEEND7
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =5
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bgt        label_WHILEEND7
label_WHILETRUE6:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-8]
    ldr        r7, [fp, #-28]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    ldr        r7, [fp, #-32]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =1
    ldr        r7, [fp, #-36]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-8]
    b          label_WHILESTART5
label_WHILEEND7:
    ldr        r3, [fp, #-16]
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
