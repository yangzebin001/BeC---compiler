	.file	"../testcase/functional_test/59_sort_test7.sy"
	.text
	.data
	.comm	n,4,4
	.text
	.align	2
	.global	Merge
	.arch armv7-a
	.arm
	.type	Merge, %function
Merge:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-28]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    ldr        r7, [fp, #-32]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-24]
    sub        sp, sp, #4
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-40]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-36]
    sub        sp, sp, #40
    sub        r2, fp, #80
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
    sub        sp, sp, #40
    sub        r2, fp, #120
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
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-124]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-128]
label_WHILESTART6:
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-132]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-132]
    cmp        r7, r3
    bge        label_WHILEEND7
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-136]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-136]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-124]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #80
    str        r8, [r1, r9]
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-140]
    ldr        r3, =1
    ldr        r7, [fp, #-140]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-124]
    b          label_WHILESTART6
label_WHILEEND7:
label_WHILESTART8:
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-144]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-144]
    cmp        r7, r3
    bge        label_WHILEEND9
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-148]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-148]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-152]
    ldr        r3, =1
    ldr        r7, [fp, #-152]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-128]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #120
    str        r8, [r1, r9]
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-156]
    ldr        r3, =1
    ldr        r7, [fp, #-156]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-128]
    b          label_WHILESTART8
label_WHILEEND9:
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-124]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-128]
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    mov        r8, r3
    str        r8, [fp, #-160]
label_WHILESTART10:
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-164]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-164]
    cmp        r7, r3
    beq        label_WHILEEND11
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-168]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-168]
    cmp        r7, r3
    beq        label_WHILEEND11
    ldr        r3, [fp, #-124]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #80
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-172]
    ldr        r3, [fp, #-128]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #120
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-176]
    ldr        r3, =1
    ldr        r7, [fp, #-176]
    add        r3, r7
    ldr        r7, [fp, #-172]
    cmp        r7, r3
    bge        label_IFFALSE12
label_IFTRUE13:
    ldr        r3, [fp, #-124]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #80
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-160]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-160]
    sub        sp, sp, #4
    str        r3, [fp, #-180]
    ldr        r3, =1
    ldr        r7, [fp, #-180]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-160]
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-184]
    ldr        r3, =1
    ldr        r7, [fp, #-184]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-124]
    b          label_IFEND14
label_IFFALSE12:
    ldr        r3, [fp, #-128]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #120
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-160]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-160]
    sub        sp, sp, #4
    str        r3, [fp, #-188]
    ldr        r3, =1
    ldr        r7, [fp, #-188]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-160]
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-192]
    ldr        r3, =1
    ldr        r7, [fp, #-192]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-128]
label_IFEND14:
    b          label_WHILESTART10
label_WHILEEND11:
label_WHILESTART15:
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-196]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-196]
    cmp        r7, r3
    bge        label_WHILEEND16
    ldr        r3, [fp, #-124]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #80
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-160]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-160]
    sub        sp, sp, #4
    str        r3, [fp, #-200]
    ldr        r3, =1
    ldr        r7, [fp, #-200]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-160]
    ldr        r3, [fp, #-124]
    sub        sp, sp, #4
    str        r3, [fp, #-204]
    ldr        r3, =1
    ldr        r7, [fp, #-204]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-124]
    b          label_WHILESTART15
label_WHILEEND16:
label_WHILESTART17:
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-208]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-208]
    cmp        r7, r3
    bge        label_WHILEEND18
    ldr        r3, [fp, #-128]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #120
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-160]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-160]
    sub        sp, sp, #4
    str        r3, [fp, #-212]
    ldr        r3, =1
    ldr        r7, [fp, #-212]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-160]
    ldr        r3, [fp, #-128]
    sub        sp, sp, #4
    str        r3, [fp, #-216]
    ldr        r3, =1
    ldr        r7, [fp, #-216]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-128]
    b          label_WHILESTART17
label_WHILEEND18:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN5
label_RETURN5:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	Merge, .-Merge
	.align	2
	.global	MergeSort
	.arch armv7-a
	.arm
	.type	MergeSort, %function
MergeSort:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bge        label_IFEND20
label_IFTRUE21:
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-28]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =2
    ldr        r7, [fp, #-32]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-24]
    sub        sp, sp, #4
    ldr        r3, [fp, #-8]
    mov        r0, r3
    ldr        r3, [fp, #-12]
    mov        r1, r3
    ldr        r3, [fp, #-24]
    mov        r2, r3
    bl         MergeSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-36]
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =1
    ldr        r7, [fp, #-40]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-36]
    ldr        r3, [fp, #-8]
    mov        r0, r3
    ldr        r3, [fp, #-36]
    mov        r1, r3
    ldr        r3, [fp, #-16]
    mov        r2, r3
    bl         MergeSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-36]
    ldr        r3, [fp, #-8]
    mov        r0, r3
    ldr        r3, [fp, #-12]
    mov        r1, r3
    ldr        r3, [fp, #-24]
    mov        r2, r3
    ldr        r3, [fp, #-16]
    mov        r3, r3
    bl         Merge
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-36]
label_IFEND20:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN19
label_RETURN19:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	MergeSort, .-MergeSort
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
    sub        sp, sp, #4
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, =1
    ldr        r7, [fp, #-56]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-52]
    sub        r3, fp, #44
    mov        r0, r3
    ldr        r3, [fp, #-48]
    mov        r1, r3
    ldr        r3, [fp, #-52]
    mov        r2, r3
    bl         MergeSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-48]
label_WHILESTART23:
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-60]
    cmp        r7, r3
    bge        label_WHILEEND24
    ldr        r3, [fp, #-48]
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #44
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-52]
    ldr        r3, [fp, #-52]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =10
    mov        r8, r3
    str        r8, [fp, #-52]
    ldr        r3, [fp, #-52]
    mov        r0, r3
    bl         putch
    mov        r3, r0
    ldr        r3, [fp, #-48]
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, =1
    ldr        r7, [fp, #-64]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-48]
    b          label_WHILESTART23
label_WHILEEND24:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN22
label_RETURN22:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
.L3:
	.word	n
