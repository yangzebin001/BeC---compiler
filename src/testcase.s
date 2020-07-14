	.file	"../testcase/functional_test/60_while_fibonacci.sy"
	.text
	.data
	.comm	n,4,4
	.text
	.align	2
	.global	fib
	.arch armv7-a
	.arm
	.type	fib, %function
fib:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    mov        r3, #0
    mov        r8, r3
    str        r8, [fp, #-12]
    mov        r3, #1
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    mov        r3, #0
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bne        label_IFEND6
    mov        r3, #0
    mov        r0, r3
    b          label_RETURN5
label_IFEND6:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    mov        r3, #1
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bne        label_IFEND7
    mov        r3, #1
    mov        r0, r3
    b          label_RETURN5
label_IFEND7:
label_WHILESTART8:
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    mov        r3, #1
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    ble        label_WHILEEND9
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-28]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, [fp, #-16]
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-20]
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    mov        r3, #1
    ldr        r7, [fp, #-28]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-8]
    b          label_WHILESTART8
label_WHILEEND9:
    ldr        r3, [fp, #-20]
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	fib, .-fib
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
    sub        sp, sp, #4
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    bl         fib
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-8]
    ldr        r3, [fp, #-8]
    mov        r0, r3
    b          label_RETURN10
label_RETURN10:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	n
