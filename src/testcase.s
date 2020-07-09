	.file	"../testcase/arm_test/test_gobalvar2.sy"
	.text
	.global a
	.data
	.align	2
	.type	a, %object
	.size	a, 4
a:
	.word	a
	.comm	b,4,4
	.global c
	.data
	.align	2
	.type	c, %object
	.size	c, 4
c:
	.word	a
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
