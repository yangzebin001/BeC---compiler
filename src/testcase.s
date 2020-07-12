	.file	"../testcase/functional_test/02_arr_defn4.sy"
	.text
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #32
    sub        r2, fp, #32
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    str        r3, [r2, #16]
    str        r3, [r2, #20]
    str        r3, [r2, #24]
    str        r3, [r2, #28]
    mov        r3, #1
    str        r3, [r2, #0]
    mov        r3, #2
    str        r3, [r2, #4]
    mov        r3, #3
    str        r3, [r2, #8]
    mov        r3, #4
    str        r3, [r2, #12]
    mov        r3, #5
    str        r3, [r2, #16]
    mov        r3, #6
    str        r3, [r2, #20]
    mov        r3, #7
    str        r3, [r2, #24]
    mov        r3, #8
    str        r3, [r2, #28]
    sub        sp, sp, #32
    sub        r2, fp, #64
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    str        r3, [r2, #16]
    str        r3, [r2, #20]
    str        r3, [r2, #24]
    str        r3, [r2, #28]
    mov        r3, #0
    mov        r9, r3
    lsl        r9, r9, #2
    mov        r3, #0
    mov        r7, #2
    lsl        r7, r7, #2
    mul        r6, r7
    add        r9, r6
    sub        r1, fp, #32
    ldr        r3, [r1, r9]
    str        r3, [r2, #0]
    mov        r3, #1
    mov        r9, r3
    lsl        r9, r9, #2
    mov        r3, #0
    mov        r7, #2
    lsl        r7, r7, #2
    mul        r6, r7
    add        r9, r6
    sub        r1, fp, #32
    ldr        r3, [r1, r9]
    str        r3, [r2, #4]
    mov        r3, #3
    str        r3, [r2, #8]
    mov        r3, #4
    str        r3, [r2, #12]
    mov        r3, #5
    str        r3, [r2, #16]
    mov        r3, #6
    str        r3, [r2, #20]
    mov        r3, #7
    str        r3, [r2, #24]
    mov        r3, #8
    str        r3, [r2, #28]
    mov        r3, #1
    mov        r9, r3
    lsl        r9, r9, #2
    mov        r3, #0
    mov        r7, #2
    lsl        r7, r7, #2
    mul        r6, r7
    add        r9, r6
    sub        r1, fp, #64
    ldr        r3, [r1, r9]
    mov        r0, r3
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
