	.file	"../testcase/functional_test/08_arr_assign.sy"
	.text
	.data
	.comm	a,40,4
	.text
.L3:
	.word	a
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
    ldr        r3, =1
    mov        r8, r3
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L3
    str        r8, [r1, r9]
    ldr        r3, =2
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, .L3
    ldr        r3, [r1, r9]
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
