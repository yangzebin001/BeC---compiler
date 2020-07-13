	.file	"../testcase/functional_test/32_while_if_test3.sy"
	.text
	.align	2
	.global	deepWhileBr
	.arch armv7-a
	.arm
	.type	deepWhileBr, %function
deepWhileBr:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
