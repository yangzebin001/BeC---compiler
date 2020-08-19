	.file	"../testcase/functional_test/65_word_count.sy"
	.text
	.align	2
	.global	wc
	.arch armv7-a
	.arm
	.ltorg
	.type	wc, %function
wc:
    push       {fp, lr}
    add        fp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-20]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-24]
label_WHILESTART5:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-28]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-28]
    cmp        r7, r3
    bge        label_WHILEEND7
label_WHILETRUE6:
    ldr        r3, [fp, #-20]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r1, [fp, #-8]
    ldr        r3, [r1, r9]
    sub        sp, sp, #4
    str        r3, [fp, #-32]
    ldr        r3, =32
    ldr        r7, [fp, #-32]
    cmp        r7, r3
    beq        label_IFFALSE8
label_IFTRUE9:
    ldr        r3, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-36]
    ldr        r3, =0
    ldr        r7, [fp, #-36]
    cmp        r7, r3
    bne        label_IFEND11
label_IFTRUE12:
    ldr        r3, [fp, #-24]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, =1
    ldr        r7, [fp, #-40]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-24]
    ldr        r3, =1
    mov        r8, r3
    str        r8, [fp, #-16]
label_IFEND11:
    b          label_IFEND10
label_IFFALSE8:
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-16]
label_IFEND10:
    ldr        r3, [fp, #-20]
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, =1
    ldr        r7, [fp, #-44]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-20]
    b          label_WHILESTART5
label_WHILEEND7:
    ldr        r3, [fp, #-24]
    mov        r0, r3
    b          label_RETURN4
label_RETURN4:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	wc, .-wc
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r6, =2004
    sub        r0, fp, r6
    mov        r1, #0
    ldr        r2, =2000
    bl         memset
    sub        sp, sp, #2000
    ldr        r6, =2004
    sub        r2, fp, r6
    sub        sp, sp, #4
    sub        sp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-2012]
    ldr        r3, =0
    mov        r8, r3
    str        r8, [fp, #-2008]
label_WHILESTART14:
    ldr        r3, [fp, #-2008]
    sub        sp, sp, #4
    str        r3, [fp, #-2016]
    ldr        r3, =10
    ldr        r7, [fp, #-2016]
    cmp        r7, r3
    beq        label_WHILEEND16
label_WHILETRUE15:
    bl         getch
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-2008]
    ldr        r3, [fp, #-2008]
    mov        r8, r3
    ldr        r3, [fp, #-2012]
    mov        r9, r3
    lsl        r9, r9, #2
    ldr        r6, =2004
    sub        r1, fp, r6
    str        r8, [r1, r9]
    ldr        r3, [fp, #-2012]
    sub        sp, sp, #4
    str        r3, [fp, #-2020]
    ldr        r3, =1
    ldr        r7, [fp, #-2020]
    add        r3, r7
    mov        r8, r3
    str        r8, [fp, #-2012]
    b          label_WHILESTART14
label_WHILEEND16:
    ldr        r6, =2004
    sub        r3, fp, r6
    mov        r0, r3
    ldr        r3, [fp, #-2012]
    mov        r1, r3
    mov        r2, r7
    bl         wc
    mov        r3, r0
    mov        r8, r3
    str        r8, [fp, #-2008]
    ldr        r3, [fp, #-2008]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN13
label_RETURN13:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
	.text
