	.file	"../testcase/functional_test/08_arr_assign.sy"
	.text
	.data
	.comm	a,40,4
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    mov        r3, #0
    mov        r8, r3
    lsl        r8, r8, #2
    mov        r3, #33
    ldr        r1, .L3
    str        r3, [r1, r8]
    mov        r3, #0
    mov        r8, r3
    lsl        r8, r8, #2
    ldr        r1, .L3
    ldr        r3, [r1, r8]
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	a
