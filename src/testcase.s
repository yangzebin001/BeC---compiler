	.file	"../testcase/arm_test/test_manyparam.sy"
	.text
	.align	2
	.global	func1
	.arch armv7-a
	.arm
	.type	func1, %function
func1:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r6, [fp, #4]
    str        r6, [fp, #-24]
    ldr        r6, [fp, #8]
    str        r6, [fp, #-28]
    ldr        r3, =1
    mov        r8, r3
    str        r8, [fp, #-8]
    ldr        r3, =2
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, =3
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, =4
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, =5
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, =22
    mov        r8, r3
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-28]
    str        r8, [r1, r9]
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	func1, .-func1
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #16
    sub        r2, fp, #20
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    ldr        r3, =10
    str        r3, [r2, #0]
    ldr        r3, =11
    str        r3, [r2, #4]
    ldr        r3, =12
    str        r3, [r2, #8]
    ldr        r3, =13
    str        r3, [r2, #12]
    sub        sp, sp, #4
    ldr        r3, =3
    str        r3, [fp, #-24]
    sub        sp, sp, #4
    ldr        r3, =4
    str        r3, [fp, #-28]
    sub        sp, sp, #4
    ldr        r3, =5
    str        r3, [fp, #-32]
    sub        sp, sp, #4
    ldr        r3, =6
    str        r3, [fp, #-36]
    sub        sp, sp, #4
    ldr        r3, =7
    str        r3, [fp, #-40]
    sub        sp, sp, #8
    ldr        r3, [fp, #-36]
    str        r3, [sp, #0]
    sub        r3, fp, #20
    str        r3, [sp, #4]
    ldr        r3, [fp, #-24]
    mov        r0, r3
    ldr        r3, [fp, #-40]
    mov        r1, r3
    ldr        r3, [fp, #-28]
    mov        r2, r3
    ldr        r3, [fp, #-32]
    mov        r3, r3
    bl         func1
    mov        r3, r0
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #20
    ldr        r3, [r1, r9]
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
