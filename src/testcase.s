	.file	"../testcase/functional_test/38_if_complex_expr.sy"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =5
    mov        r8, r3
    str        r8, [fp, #-8]
    ldr        r3, =5
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, =1
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, =2
    rsb        r3, r3, #0
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, =2
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, =1
    ldr        r7, [fp, #-28]
    mul        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =2
    ldr        r7, [fp, #-32]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =0
    ldr        r7, [fp, #-36]
    cmp        r7, r3
    bge        label_ORFALSE7
    blt        label_IFTRUE6
    b          label_IFTRUE6
label_ORFALSE7:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-40]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, =0
    ldr        r7, [fp, #-44]
    cmp        r7, r3
    beq        label_IFEND5
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-48]
    ldr        r3, =3
    ldr        r7, [fp, #-48]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, =2
    ldr        r7, [fp, #-52]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idivmod
    mov        r3, r1
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, =0
    ldr        r7, [fp, #-56]
    cmp        r7, r3
    beq        label_IFEND5
label_IFTRUE6:
    ldr        r3, [fp, #-24]
    mov        r0, r3
    bl         putint
    mov        r3, r0
label_IFEND5:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, =2
    ldr        r7, [fp, #-60]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idivmod
    mov        r3, r1
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, =67
    ldr        r7, [fp, #-64]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-68]
    ldr        r3, =0
    ldr        r7, [fp, #-68]
    cmp        r7, r3
    bge        label_ORFALSE11
    blt        label_IFTRUE10
    b          label_IFTRUE10
label_ORFALSE11:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-72]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-72]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-76]
    ldr        r3, =0
    ldr        r7, [fp, #-76]
    cmp        r7, r3
    beq        label_IFEND9
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-80]
    ldr        r3, =2
    ldr        r7, [fp, #-80]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-84]
    ldr        r3, =2
    ldr        r7, [fp, #-84]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idivmod
    mov        r3, r1
    sub        sp, sp, #4
    str        r3, [fp, #-88]
    ldr        r3, =0
    ldr        r7, [fp, #-88]
    cmp        r7, r3
    beq        label_IFEND9
label_IFTRUE10:
    ldr        r3, =4
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, [fp, #-24]
    mov        r0, r3
    bl         putint
    mov        r3, r0
label_IFEND9:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
