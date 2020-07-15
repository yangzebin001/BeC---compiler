	.file	"../testcase/functional_test/42_index_func_ret.sy"
	.text
	.align	2
	.global	_getMaxOfAll
	.arch armv7-a
	.arm
	.type	_getMaxOfAll, %function
_getMaxOfAll:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    ldr        r3, =999999
    rsb        r3, r3, #0
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r3, =1
    ldr        r7, [fp, #-20]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-12]
label_WHILESTART5:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =1
    rsb        r3, r3, #0
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    ble        label_WHILEEND6
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-28]
    cmp        r7, r3
    ble        label_IFEND7
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-16]
label_IFEND7:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    ldr        r7, [fp, #-32]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-12]
    b          label_WHILESTART5
label_WHILEEND6:
    ldr        r3, [fp, #-16]
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	_getMaxOfAll, .-_getMaxOfAll
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #12
    sub        r2, fp, #16
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    ldr        r3, =2
    rsb        r3, r3, #0
    mov        r8, r3
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #16
    str        r8, [r1, r9]
    ldr        r3, =2
    mov        r8, r3
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #16
    str        r8, [r1, r9]
    ldr        r3, =7
    rsb        r3, r3, #0
    mov        r8, r3
    ldr        r3, =2
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #16
    str        r8, [r1, r9]
    sub        sp, sp, #4
    sub        r3, fp, #16
    mov        r0, r3
    ldr        r3, =3
    mov        r1, r3
    bl         _getMaxOfAll
    mov        r3, r0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #16
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, [fp, #-20]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN8
label_RETURN8:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
