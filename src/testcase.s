	.file	"../testcase/functional_test/49_decl_in_defn.sy"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    mov        r3, #12
    mov        r8, r3
    str        r8, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, [fp, #-8]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    mov        r3, #0
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
