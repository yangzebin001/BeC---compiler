	.file	"../testcase/arm_test/testcase.sy"
	.text
	.data
	.global arr
	.align	2
	.type	arr, %object
	.size	arr, 400
arr:
	.space	400
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
    ldr        r3, =4
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
	.text
.L3:
	.word	arr
