	.file	"../testcase/functional_test/53_sort_test1.sy"
	.text
	.data
	.comm	n,4,4
	.text
.L3:
	.word	n
	.text
	.align	2
	.global	bubblesort
	.arch armv7-a
	.arm
	.ltorg
	.type	bubblesort, %function
bubblesort:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-12]
label_WHILESTART6:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =1
    ldr        r7, [fp, #-24]
    sub        r3, r7, r3
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bge        label_WHILEEND8
label_WHILETRUE7:
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
label_WHILESTART9:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-32]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =1
    ldr        r7, [fp, #-36]
    sub        r3, r7, r3
    ldr        r7, [fp, #-28]
    cmp        r7, r3
    bge        label_WHILEEND11
label_WHILETRUE10:
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, =1
    ldr        r7, [fp, #-44]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-40]
    cmp        r7, r3
    ble        label_IFEND12
label_IFTRUE13:
    sub        sp, sp, #4
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, =1
    ldr        r7, [fp, #-52]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-48]
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, =1
    ldr        r7, [fp, #-56]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-48]
    mov        r8, r3
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
label_IFEND12:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, =1
    ldr        r7, [fp, #-60]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    b          label_WHILESTART9
label_WHILEEND11:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, =1
    ldr        r7, [fp, #-64]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-12]
    b          label_WHILESTART6
label_WHILEEND8:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	bubblesort, .-bubblesort
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r3, =10
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r6, =44
    sub        r0, fp, r6
    mov        r1, #0
    ldr        r2, =40
    bl         memset
    sub        sp, sp, #40
    sub        r2, fp, #44
    ldr        r3, =4
    mov        r8, r3
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =3
    mov        r8, r3
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =9
    mov        r8, r3
    ldr        r3, =2
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =2
    mov        r8, r3
    ldr        r3, =3
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =0
    mov        r8, r3
    ldr        r3, =4
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =1
    mov        r8, r3
    ldr        r3, =5
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =6
    mov        r8, r3
    ldr        r3, =6
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =5
    mov        r8, r3
    ldr        r3, =7
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =7
    mov        r8, r3
    ldr        r3, =8
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    ldr        r3, =8
    mov        r8, r3
    ldr        r3, =9
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    str        r8, [r1, r9]
    sub        sp, sp, #4
    sub        r3, fp, #44
    mov        r0, r3
    bl         bubblesort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-48]
label_WHILESTART15:
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-52]
    cmp        r7, r3
    bge        label_WHILEEND17
label_WHILETRUE16:
    sub        sp, sp, #4
    ldr        r3, [fp, #-48]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-56]
    ldr        r3, [fp, #-56]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =10
    mov        r8, r3
    str        r8, [fp, #-56]
    ldr        r3, [fp, #-56]
    mov        r0, r3
    bl         putch
    mov        r3, r0
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, =1
    ldr        r7, [fp, #-60]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-48]
    b          label_WHILESTART15
label_WHILEEND17:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN14
label_RETURN14:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
