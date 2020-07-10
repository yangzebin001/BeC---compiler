	.file	"../testcase/functional_test/06_var_defn_func.sy"
	.text
	.align	2
	.global	defn
	.arch armv7-a
	.arm
	.type	defn, %function
defn:
    push       {fp, lr}
    add        fp, sp, #4
    mov        r3, #4
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	defn, .-defn
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    bl         defn
    mov        r3, r0
    str        r3, [fp, #-4]
    ldr        r3, [fp, #-4]
    mov        r0, r3
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
