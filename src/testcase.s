	.file	"../testcase/functional_test/00_main.sy"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
foo:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, fp, #4
    pop        {fp, pc}

main:
    push       {fp, lr}
    add        fp, sp, #4
    bl         foo
    mov        r0, #0
    sub        sp, fp, #4
    pop        {fp, pc}

