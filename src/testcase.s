	.file	"../testcase/arm_test/testcase.sy"
	.text
	.data
	.global arr
	.align	2
	.type	arr, %object
	.size	arr, 24
arr:
	.word	1
	.word	2
	.word	3
	.word	5
	.space	8
	.text
.L3:
	.word	arr
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
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
