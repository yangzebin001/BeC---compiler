	.file	"../testcase/functional_test/36_domain_test.sy"
	.text
	.data
	.comm	a,8,4
	.text
	.align	2
	.global	func
	.arch armv7-a
	.arm
	.type	func, %function
func:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    mov        r3, #1
    mov        r8, r3
    mov        r3, #0
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L3
    str        r8, [r1, r9]
    mov        r3, #3
    sub        sp, sp, #4
    str        r3, [fp, #-12]
    mov        r3, #0
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L3
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-12]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
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
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #12
    sub        r2, fp, #20
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    mov        r3, #1
    rsb        r3, r3, #0
    mov        r8, r3
    mov        r3, #0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #20
    str        r8, [r1, r9]
    mov        r3, #4
    mov        r8, r3
    mov        r3, #1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #20
    str        r8, [r1, r9]
    mov        r3, #8
    mov        r8, r3
    mov        r3, #2
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #20
    str        r8, [r1, r9]
    sub        r3, fp, #20
    mov        r0, r3
    bl         func
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-8]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    mov        r3, #1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #20
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-24]
    add        r3, r7
    mov        r0, r3
    b          label_RETURN6
label_RETURN6:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
