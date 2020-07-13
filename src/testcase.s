	.file	"../testcase/functional_test/25_if_test4.sy"
	.text
	.align	2
	.global	if_ifElse_
	.arch armv7-a
	.arm
	.type	if_ifElse_, %function
if_ifElse_:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    mov        r3, #5
    mov        r8, r3
    str        r8, [fp, #-8]
    sub        sp, sp, #4
    mov        r3, #10
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-16]
    mov        r3, #5
    ldr        r7, [fp, #-16]
    cmp        r7, r3
    bne        label_IFEND5
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    mov        r3, #10
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bne        label_IFFALSE6
label_IFTRUE6:
    mov        r3, #25
    mov        r8, r3
    str        r8, [fp, #-8]
    b          label_IFEND8
label_IFFALSE6:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    mov        r3, #15
    ldr        r7, [fp, #-24]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-8]
label_IFEND8:
label_IFEND5:
    ldr        r3, [fp, #-8]
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	if_ifElse_, .-if_ifElse_
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    bl         if_ifElse_
    mov        r3, r0
    mov        r0, r3
    b          label_RETURN9
label_RETURN9:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
