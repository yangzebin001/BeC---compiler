	.file	"../testcase/arm_test/test_arraydef2.sy"
	.text
	.data
	.global arr
	.align	2
	.type	arr, %object
	.size	arr, 16
arr:
	.global arr2
	.align	2
	.type	arr2, %object
	.size	arr2, 64
arr2:
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    mov        r3, #4
    str        r3, [r2]
    mov        r3, #3
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	arr
.L4:
	.word	arr2
