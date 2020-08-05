	.file	"../testcase/functional_test/62_long_code.sy"
	.text
	.data
	.comm	n,4,4
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
	.global	insertsort
	.arch armv7-a
	.arm
	.ltorg
	.type	insertsort, %function
insertsort:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    ldr        r3, =1
    mov        r8, r3
    str        r8, [fp, #-12]
label_WHILESTART15:
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-16]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-16]
    cmp        r7, r3
    bge        label_WHILEEND17
label_WHILETRUE16:
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-20]
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, =1
    ldr        r7, [fp, #-28]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-24]
label_WHILESTART18:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    rsb        r3, r3, #0
    ldr        r7, [fp, #-32]
    cmp        r7, r3
    ble        label_WHILEEND20
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-36]
    cmp        r7, r3
    bge        label_WHILEEND20
label_WHILETRUE19:
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =1
    ldr        r7, [fp, #-40]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, =1
    ldr        r7, [fp, #-44]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-24]
    b          label_WHILESTART18
label_WHILEEND20:
    ldr        r3, [fp, #-20]
    mov        r8, r3
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-48]
    ldr        r3, =1
    ldr        r7, [fp, #-48]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, =1
    ldr        r7, [fp, #-52]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-12]
    b          label_WHILESTART15
label_WHILEEND17:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN14
label_RETURN14:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	insertsort, .-insertsort
	.align	2
	.global	QuickSort
	.arch armv7-a
	.arm
	.ltorg
	.type	QuickSort, %function
QuickSort:
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
    bge        label_IFEND22
label_IFTRUE23:
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    mov        r8, r3
    str        r8, [fp, #-24]
    sub        sp, sp, #4
    ldr        r3, [fp, #-16]
    mov        r8, r3
    str        r8, [fp, #-28]
    sub        sp, sp, #4
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-32]
label_WHILESTART24:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-36]
    cmp        r7, r3
    bge        label_WHILEEND26
label_WHILETRUE25:
label_WHILESTART27:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-40]
    cmp        r7, r3
    bge        label_WHILEEND29
    ldr        r3, [fp, #-28]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, [fp, #-32]
    sub        sp, sp, #4
    str        r3, [fp, #-48]
    ldr        r3, =1
    ldr        r7, [fp, #-48]
    sub        r3, r7, r3
    ldr        r7, [fp, #-44]
    cmp        r7, r3
    ble        label_WHILEEND29
label_WHILETRUE28:
    ldr        r3, [fp, #-28]
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, =1
    ldr        r7, [fp, #-52]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-28]
    b          label_WHILESTART27
label_WHILEEND29:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-56]
    cmp        r7, r3
    bge        label_IFEND30
label_IFTRUE31:
    ldr        r3, [fp, #-28]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, =1
    ldr        r7, [fp, #-60]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-24]
label_IFEND30:
label_WHILESTART32:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-64]
    cmp        r7, r3
    bge        label_WHILEEND34
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-68]
    ldr        r3, [fp, #-32]
    ldr        r7, [fp, #-68]
    cmp        r7, r3
    bge        label_WHILEEND34
label_WHILETRUE33:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-72]
    ldr        r3, =1
    ldr        r7, [fp, #-72]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-24]
    b          label_WHILESTART32
label_WHILEEND34:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-76]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-76]
    cmp        r7, r3
    bge        label_IFEND35
label_IFTRUE36:
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-28]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-28]
    sub        sp, sp, #4
    str        r3, [fp, #-80]
    ldr        r3, =1
    ldr        r7, [fp, #-80]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-28]
label_IFEND35:
    b          label_WHILESTART24
label_WHILEEND26:
    ldr        r3, [fp, #-32]
    mov        r8, r3
    ldr        r3, [fp, #-24]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    sub        sp, sp, #4
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-88]
    ldr        r3, =1
    ldr        r7, [fp, #-88]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-84]
    ldr        r3, [fp, #-8]
    mov        r0, r3
    ldr        r3, [fp, #-12]
    mov        r1, r3
    ldr        r3, [fp, #-84]
    mov        r2, r3
    bl         QuickSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-84]
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-92]
    ldr        r3, =1
    ldr        r7, [fp, #-92]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-84]
    ldr        r3, [fp, #-8]
    mov        r0, r3
    ldr        r3, [fp, #-84]
    mov        r1, r3
    ldr        r3, [fp, #-16]
    mov        r2, r3
    bl         QuickSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-84]
label_IFEND22:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN21
label_RETURN21:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	QuickSort, .-QuickSort
	.align	2
	.global	getMid
	.arch armv7-a
	.arm
	.ltorg
	.type	getMid, %function
getMid:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-16]
    ldr        r3, =2
    ldr        r7, [fp, #-16]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idivmod
    mov        r3, r1
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r3, =0
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bne        label_IFFALSE38
label_IFTRUE39:
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =2
    ldr        r7, [fp, #-24]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    ldr        r7, [fp, #-32]
    sub        r3, r7, r3
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-28]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =2
    ldr        r7, [fp, #-36]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r0, r3
    b          label_RETURN37
    b          label_IFEND40
label_IFFALSE38:
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =2
    ldr        r7, [fp, #-40]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-12]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r0, r3
    b          label_RETURN37
label_IFEND40:
label_RETURN37:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	getMid, .-getMid
	.align	2
	.global	getMost
	.arch armv7-a
	.arm
	.ltorg
	.type	getMost, %function
getMost:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    ldr        r6, =4008
    sub        r0, fp, r6
    mov        r1, #0
    ldr        r2, =4000
    bl         memset
    sub        sp, sp, #4000
    ldr        r6, =4008
    sub        r2, fp, r6
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-4012]
label_WHILESTART42:
    ldr        r3, [fp, #-4012]
    sub        sp, sp, #4
    str        r3, [fp, #-4016]
    ldr        r3, =1000
    ldr        r7, [fp, #-4016]
    cmp        r7, r3
    bge        label_WHILEEND44
label_WHILETRUE43:
    ldr        r3, =0
    mov        r8, r3
    ldr        r3, [fp, #-4012]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =4008
    sub        r1, fp, r6
    str        r8, [r1, r9]
    ldr        r3, [fp, #-4012]
    sub        sp, sp, #4
    str        r3, [fp, #-4020]
    ldr        r3, =1
    ldr        r7, [fp, #-4020]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-4012]
    b          label_WHILESTART42
label_WHILEEND44:
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-4012]
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-4024]
label_WHILESTART45:
    ldr        r3, [fp, #-4012]
    sub        sp, sp, #4
    str        r3, [fp, #-4032]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-4032]
    cmp        r7, r3
    bge        label_WHILEEND47
label_WHILETRUE46:
    sub        sp, sp, #4
    ldr        r3, [fp, #-4012]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-4036]
    ldr        r3, [fp, #-4036]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =4008
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-4040]
    ldr        r3, =1
    ldr        r7, [fp, #-4040]
    add        r3, r7
    mov        r8, r3
    ldr        r3, [fp, #-4036]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =4008
    sub        r1, fp, r6
    str        r8, [r1, r9]
    ldr        r3, [fp, #-4036]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =4008
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-4044]
    ldr        r3, [fp, #-4024]
    ldr        r7, [fp, #-4044]
    cmp        r7, r3
    ble        label_IFEND48
label_IFTRUE49:
    ldr        r3, [fp, #-4036]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =4008
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-4024]
    ldr        r3, [fp, #-4036]
    mov        r8, r3
    str        r8, [fp, #-4028]
label_IFEND48:
    ldr        r3, [fp, #-4012]
    sub        sp, sp, #4
    str        r3, [fp, #-4048]
    ldr        r3, =1
    ldr        r7, [fp, #-4048]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-4012]
    b          label_WHILESTART45
label_WHILEEND47:
    ldr        r3, [fp, #-4028]
    mov        r0, r3
    b          label_RETURN41
label_RETURN41:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	getMost, .-getMost
	.align	2
	.global	revert
	.arch armv7-a
	.arm
	.ltorg
	.type	revert, %function
revert:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-20]
label_WHILESTART51:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, [fp, #-20]
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bge        label_WHILEEND53
label_WHILETRUE52:
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-12]
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-12]
    mov        r8, r3
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, =1
    ldr        r7, [fp, #-28]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =1
    ldr        r7, [fp, #-32]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-20]
    b          label_WHILESTART51
label_WHILEEND53:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN50
label_RETURN50:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	revert, .-revert
	.align	2
	.global	arrCopy
	.arch armv7-a
	.arm
	.ltorg
	.type	arrCopy, %function
arrCopy:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
label_WHILESTART55:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-20]
    cmp        r7, r3
    bge        label_WHILEEND57
label_WHILETRUE56:
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    ldr        r3, [fp, #-16]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-12]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r3, =1
    ldr        r7, [fp, #-24]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    b          label_WHILESTART55
label_WHILEEND57:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN54
label_RETURN54:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	arrCopy, .-arrCopy
	.align	2
	.global	calSum
	.arch armv7-a
	.arm
	.ltorg
	.type	calSum, %function
calSum:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-20]
label_WHILESTART59:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-24]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-24]
    cmp        r7, r3
    bge        label_WHILEEND61
label_WHILETRUE60:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-28]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-32]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idivmod
    mov        r3, r1
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =1
    ldr        r7, [fp, #-40]
    sub        r3, r7, r3
    ldr        r7, [fp, #-36]
    cmp        r7, r3
    beq        label_IFFALSE62
label_IFTRUE63:
    ldr        r3, =0
    mov        r8, r3
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    b          label_IFEND64
label_IFFALSE62:
    ldr        r3, [fp, #-16]
    mov        r8, r3
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
label_IFEND64:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, =1
    ldr        r7, [fp, #-44]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    b          label_WHILESTART59
label_WHILEEND61:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN58
label_RETURN58:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	calSum, .-calSum
	.align	2
	.global	avgPooling
	.arch armv7-a
	.arm
	.ltorg
	.type	avgPooling, %function
avgPooling:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
    sub        sp, sp, #4
label_WHILESTART66:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-28]
    cmp        r7, r3
    bge        label_WHILEEND68
label_WHILETRUE67:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =1
    ldr        r7, [fp, #-36]
    sub        r3, r7, r3
    ldr        r7, [fp, #-32]
    cmp        r7, r3
    bge        label_IFFALSE69
label_IFTRUE70:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-40]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-16]
    b          label_IFEND71
label_IFFALSE69:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, [fp, #-12]
    sub        sp, sp, #4
    str        r3, [fp, #-48]
    ldr        r3, =1
    ldr        r7, [fp, #-48]
    sub        r3, r7, r3
    ldr        r7, [fp, #-44]
    cmp        r7, r3
    bne        label_IFFALSE72
label_IFTRUE73:
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-52]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r8, r3
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    b          label_IFEND74
label_IFFALSE72:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    ldr        r7, [fp, #-56]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-60]
    sub        r3, r7, r3
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-64]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-68]
    ldr        r3, =1
    ldr        r7, [fp, #-68]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-72]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-72]
    mov        r1, r3
    mov        r0, r7
    bl         __aeabi_idiv
    mov        r3, r0
    mov        r8, r3
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-76]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-76]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-80]
    ldr        r3, =1
    ldr        r7, [fp, #-80]
    add        r3, r7
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
label_IFEND74:
label_IFEND71:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-84]
    ldr        r3, =1
    ldr        r7, [fp, #-84]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    b          label_WHILESTART66
label_WHILEEND68:
    ldr        r2, .L3
    ldr        r3, [r2]
    sub        sp, sp, #4
    str        r3, [fp, #-88]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-88]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-92]
    ldr        r3, =1
    ldr        r7, [fp, #-92]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
label_WHILESTART75:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-96]
    ldr        r2, .L3
    ldr        r3, [r2]
    ldr        r7, [fp, #-96]
    cmp        r7, r3
    bge        label_WHILEEND77
label_WHILETRUE76:
    ldr        r3, =0
    mov        r8, r3
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    str        r8, [r1, r9]
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-100]
    ldr        r3, =1
    ldr        r7, [fp, #-100]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    b          label_WHILESTART75
label_WHILEEND77:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN65
label_RETURN65:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	avgPooling, .-avgPooling
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r3, =32
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r6, =132
    sub        r0, fp, r6
    mov        r1, #0
    ldr        r2, =128
    bl         memset
    sub        sp, sp, #128
    sub        r2, fp, #132
    ldr        r6, =260
    sub        r0, fp, r6
    mov        r1, #0
    ldr        r2, =128
    bl         memset
    sub        sp, sp, #128
    ldr        r6, =260
    sub        r2, fp, r6
    ldr        r3, =7
    mov        r8, r3
    ldr        r3, =0
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =23
    mov        r8, r3
    ldr        r3, =1
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =89
    mov        r8, r3
    ldr        r3, =2
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =26
    mov        r8, r3
    ldr        r3, =3
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =282
    mov        r8, r3
    ldr        r3, =4
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =254
    mov        r8, r3
    ldr        r3, =5
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =27
    mov        r8, r3
    ldr        r3, =6
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =5
    mov        r8, r3
    ldr        r3, =7
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =83
    mov        r8, r3
    ldr        r3, =8
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =273
    mov        r8, r3
    ldr        r3, =9
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =574
    mov        r8, r3
    ldr        r3, =10
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =905
    mov        r8, r3
    ldr        r3, =11
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =354
    mov        r8, r3
    ldr        r3, =12
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =657
    mov        r8, r3
    ldr        r3, =13
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =935
    mov        r8, r3
    ldr        r3, =14
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =264
    mov        r8, r3
    ldr        r3, =15
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =639
    mov        r8, r3
    ldr        r3, =16
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =459
    mov        r8, r3
    ldr        r3, =17
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =29
    mov        r8, r3
    ldr        r3, =18
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =68
    mov        r8, r3
    ldr        r3, =19
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =929
    mov        r8, r3
    ldr        r3, =20
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =756
    mov        r8, r3
    ldr        r3, =21
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =452
    mov        r8, r3
    ldr        r3, =22
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =279
    mov        r8, r3
    ldr        r3, =23
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =58
    mov        r8, r3
    ldr        r3, =24
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =87
    mov        r8, r3
    ldr        r3, =25
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =96
    mov        r8, r3
    ldr        r3, =26
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =36
    mov        r8, r3
    ldr        r3, =27
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =39
    mov        r8, r3
    ldr        r3, =28
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =28
    mov        r8, r3
    ldr        r3, =29
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =1
    mov        r8, r3
    ldr        r3, =30
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    ldr        r3, =290
    mov        r8, r3
    ldr        r3, =31
    mov        r9, r3
    lsl        r9, r9, #2
    sub        r1, fp, #132
    str        r8, [r1, r9]
    sub        sp, sp, #4
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         revert
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART79:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-272]
    ldr        r3, =32
    ldr        r7, [fp, #-272]
    cmp        r7, r3
    bge        label_WHILEEND81
label_WHILETRUE80:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-276]
    ldr        r3, =1
    ldr        r7, [fp, #-276]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART79
label_WHILEEND81:
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         bubblesort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART82:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-280]
    ldr        r3, =32
    ldr        r7, [fp, #-280]
    cmp        r7, r3
    bge        label_WHILEEND84
label_WHILETRUE83:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-284]
    ldr        r3, =1
    ldr        r7, [fp, #-284]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART82
label_WHILEEND84:
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         getMid
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         getMost
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         bubblesort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART85:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-288]
    ldr        r3, =32
    ldr        r7, [fp, #-288]
    cmp        r7, r3
    bge        label_WHILEEND87
label_WHILETRUE86:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-292]
    ldr        r3, =1
    ldr        r7, [fp, #-292]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART85
label_WHILEEND87:
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    bl         insertsort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART88:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-296]
    ldr        r3, =32
    ldr        r7, [fp, #-296]
    cmp        r7, r3
    bge        label_WHILEEND90
label_WHILETRUE89:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-300]
    ldr        r3, =1
    ldr        r7, [fp, #-300]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART88
label_WHILEEND90:
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
    ldr        r3, =31
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    ldr        r3, [fp, #-268]
    mov        r1, r3
    ldr        r3, [fp, #-264]
    mov        r2, r3
    bl         QuickSort
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
label_WHILESTART91:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-304]
    ldr        r3, =32
    ldr        r7, [fp, #-304]
    cmp        r7, r3
    bge        label_WHILEEND93
label_WHILETRUE92:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-308]
    ldr        r3, =1
    ldr        r7, [fp, #-308]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART91
label_WHILEEND93:
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    ldr        r3, =4
    mov        r1, r3
    bl         calSum
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART94:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-312]
    ldr        r3, =32
    ldr        r7, [fp, #-312]
    cmp        r7, r3
    bge        label_WHILEEND96
label_WHILETRUE95:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-316]
    ldr        r3, =1
    ldr        r7, [fp, #-316]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART94
label_WHILEEND96:
    sub        r3, fp, #132
    mov        r0, r3
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r1, r3
    bl         arrCopy
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r6, =260
    sub        r3, fp, r6
    mov        r0, r3
    ldr        r3, =3
    mov        r1, r3
    bl         avgPooling
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-268]
label_WHILESTART97:
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-320]
    ldr        r3, =32
    ldr        r7, [fp, #-320]
    cmp        r7, r3
    bge        label_WHILEEND99
label_WHILETRUE98:
    ldr        r3, [fp, #-268]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =260
    sub        r1, fp, r6
    ldr        r3, [r1, r9]
    mov        r8, r3
    str        r8, [fp, #-264]
    ldr        r3, [fp, #-264]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, [fp, #-268]
    sub        sp, sp, #4
    str        r3, [fp, #-324]
    ldr        r3, =1
    ldr        r7, [fp, #-324]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-268]
    b          label_WHILESTART97
label_WHILEEND99:
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN78
label_RETURN78:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
	.text
.L3a:
	.align	2
.L3:
	.word	n
