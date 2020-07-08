	.file	"../testcase/arm_test/test_fun2.sy"
	.text
	.align	2
	.global	foo
	.arch armv7-a
	.arm
	.type	foo, %function
foo:
    push       {fp, lr}
    add        fp, sp, #4
    bl         coo
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	foo, .-foo
	.align	2
	.global	coo
	.arch armv7-a
	.arm
	.type	coo, %function
coo:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	coo, .-coo
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    bl         foo
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
