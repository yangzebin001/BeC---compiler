	.file	"../testcase/functional_test/58_sort_test6.sy"
	.text
	.data
	.comm	n,4,4
	.text
	.align	2
	.global	counting_sort
	.arch armv7-a
	.arm
	.type	counting_sort, %function
counting_sort:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #40
    sub        r2, fp, #56
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    str        r3, [r2, #16]
    str        r3, [r2, #20]
    str        r3, [r2, #24]
    str        r3, [r2, #28]
    str        r3, [r2, #32]
    str        r3, [r2, #36]
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-68]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-60]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-64]
label_WHILESTART6:
    ldr        r3, [fp, #-68]
    sub        sp, sp, #4
    str        r3, [fp, #-72]
    ldr        r3, =10
    ldr        r7, [fp, #-72]
    cmp        r7, r3
    bge        label_WHILEEND7
    ldr        r3, =0
    mov        r8, r3
    ldr        r3, [fp, #-68]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    str        r8, [r1, r9]
    ldr        r3, [fp, #-68]
    sub        sp, sp, #4
    str        r3, [fp, #-76]
    ldr        r3, =1
    ldr        r7, [fp, #-76]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-68]
    b          label_WHILESTART6
label_WHILEEND7:
label_WHILESTART8:
    ldr        r3, [fp, #-60]
    sub        sp, sp, #4
    str        r3, [fp, #-80]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-80]
    cmp        r7, r3
    bge        label_WHILEEND9
    ldr        r3, [fp, #-60]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-84]
    ldr        r3, =1
    ldr        r7, [fp, #-84]
    add        r3, r7
    mov        r8, r3
    ldr        r3, [fp, #-60]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    str        r8, [r1, r9]
    ldr        r3, [fp, #-60]
    sub        sp, sp, #4
    str        r3, [fp, #-88]
    ldr        r3, =1
    ldr        r7, [fp, #-88]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-60]
    b          label_WHILESTART8
label_WHILEEND9:
    ldr        r3, =1
    mov        r8, r3
    str        r8, [fp, #-68]
label_WHILESTART10:
    ldr        r3, [fp, #-68]
    sub        sp, sp, #4
    str        r3, [fp, #-92]
    ldr        r3, =10
    ldr        r7, [fp, #-92]
    cmp        r7, r3
    bge        label_WHILEEND11
    ldr        r3, [fp, #-68]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-96]
    ldr        r3, [fp, #-68]
    sub        sp, sp, #4
    str        r3, [fp, #-100]
    ldr        r3, =1
    ldr        r7, [fp, #-100]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-96]
    add        r3, r7
    mov        r8, r3
    ldr        r3, [fp, #-68]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    str        r8, [r1, r9]
    ldr        r3, [fp, #-68]
    sub        sp, sp, #4
    str        r3, [fp, #-104]
    ldr        r3, =1
    ldr        r7, [fp, #-104]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-68]
    b          label_WHILESTART10
label_WHILEEND11:
    ldr        r3, [fp, #-16]
    mov        r8, r3
    str        r8, [fp, #-64]
label_WHILESTART12:
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-108]
    ldr        r3, =0
    ldr        r7, [fp, #-108]
    cmp        r7, r3
    ble        label_WHILEEND13
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-112]
    ldr        r3, =1
    ldr        r7, [fp, #-112]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-116]
    ldr        r3, =1
    ldr        r7, [fp, #-116]
    sub        r3, r7, r3
    mov        r8, r3
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-120]
    ldr        r3, =1
    ldr        r7, [fp, #-120]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    str        r8, [r1, r9]
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-124]
    ldr        r3, =1
    ldr        r7, [fp, #-124]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-128]
    ldr        r3, =1
    ldr        r7, [fp, #-128]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #56
    ldr        r3, [r1, r9]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-12]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-64]
    sub        sp, sp, #4
    str        r3, [fp, #-132]
    ldr        r3, =1
    ldr        r7, [fp, #-132]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-64]
    b          label_WHILESTART12
label_WHILEEND13:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	counting_sort, .-counting_sort
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r3, =10
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    sub        sp, sp, #40
    sub        r2, fp, #44
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    str        r3, [r2, #16]
    str        r3, [r2, #20]
    str        r3, [r2, #24]
    str        r3, [r2, #28]
    str        r3, [r2, #32]
    str        r3, [r2, #36]
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
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-48]
    sub        sp, sp, #40
    sub        r2, fp, #88
    mov        r3, #0
    str        r3, [r2, #0]
    str        r3, [r2, #4]
    str        r3, [r2, #8]
    str        r3, [r2, #12]
    str        r3, [r2, #16]
    str        r3, [r2, #20]
    str        r3, [r2, #24]
    str        r3, [r2, #28]
    str        r3, [r2, #32]
    str        r3, [r2, #36]
    sub        r3, fp, #44
    mov        r0, r3
    sub        r3, fp, #88
    mov        r1, r3
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r2, r3
    bl         counting_sort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-48]
label_WHILESTART15:
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-92]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-92]
    cmp        r7, r3
    bge        label_WHILEEND16
    sub        sp, sp, #4
    ldr        r3, [fp, #-48]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #88
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-96]
    ldr        r3, [fp, #-96]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =10
    mov        r8, r3
    str        r8, [fp, #-96]
    ldr        r3, [fp, #-96]
    mov        r0, r3
    bl         putch
    mov        r3, r0
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-100]
    ldr        r3, =1
    ldr        r7, [fp, #-100]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-48]
    b          label_WHILESTART15
label_WHILEEND16:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN14
label_RETURN14:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	n
