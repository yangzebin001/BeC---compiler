	.file	"../testcase/test2.sy"
	.text
	.data
	.global c
	.align	2
	.type	c, %object
	.size	c, 4
c:
	.word	3
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    mov        r3, #1
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	c
