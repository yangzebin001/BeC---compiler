	.file	"../testcase/functional_test/00_main.sy"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    str        fp, [sp, #-4]!
    add        fp, sp, #0
    ldr        fp, [sp], #4
    bx         lr

