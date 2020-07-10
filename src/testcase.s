	.file	"../testcase/arm_test/test_arraydef2.sy"
	.text
	.data
	.global arr
	.align	2
	.type	arr, %object
	.size	arr, 16
arr:
	.word	1
	.word	2
	.word	3
	.comm	arr0,20,4
	.global arr2
	.align	2
	.type	arr2, %object
	.size	arr2, 64
arr2:
	.word	22
	.word	33
	.word	44
	.word	1
	.word	2
	.global arr3
	.align	2
	.type	arr3, %object
	.size	arr3, 24
arr3:
	.word	1
	.word	2
	.word	3
	.word	4
	.word	5
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
    mov        r3, #3
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	arr
.L4:
	.word	arr0
.L5:
	.word	arr2
.L6:
	.word	arr3
