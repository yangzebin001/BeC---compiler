	.file	"../testcase/functional_test/15_array_test3.sy"
	.text
	.data
	.global a
	.align	2
	.type	a, %object
	.size	a, 100
a:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
	.text
.L3:
	.word	a
	.text
	.align	2
	.global	func
	.arch armv7-a
	.arm
	.ltorg
	.type	func, %function
func:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, =0
    str        r3, [fp, #-12]
    sub        sp, sp, #4
    ldr        r3, =0
    str        r3, [fp, #-16]
    sub        sp, sp, #4
    ldr        r3, =0
    str        r3, [fp, #-20]
label_WHILESTART6:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =5
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bge        label_WHILEEND7
label_WHILESTART8:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, =5
    ldr        r7, [fp, #-28]
    cmp        r7, r3
    bge        label_WHILEEND9
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, [fp, #-12]
    mov        r9, r3
    ldr        r3, [fp, #-16]
    mov        r7, #5
    mul        r9, r7
    add        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-32]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =1
    ldr        r7, [fp, #-36]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    b          label_WHILESTART8
label_WHILEEND9:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =1
    ldr        r7, [fp, #-40]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-12]
    b          label_WHILESTART6
label_WHILEEND7:
    ldr        r3, [fp, #-20]
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	func, .-func
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r2, .L3
    mov        r3, r2
    mov        r0, r3
    bl         func
    mov        r3, r0
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =9
    mov        r0, r3
    b          label_RETURN10
label_RETURN10:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
