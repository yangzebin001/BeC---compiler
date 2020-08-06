	.file	"../testcase/arm_test/many_global_var.sy"
	.text
	.data
	.comm	a0,4,4
	.comm	a1,4,4
	.comm	a2,4,4
	.comm	a3,4,4
	.comm	a4,4,4
	.comm	a5,4,4
	.comm	a6,4,4
	.comm	a7,4,4
	.comm	a8,4,4
	.comm	a9,4,4
	.comm	a10,4,4
	.comm	a11,4,4
	.comm	a12,4,4
	.comm	a13,4,4
	.comm	a14,4,4
	.comm	a15,4,4
	.comm	a16,4,4
	.comm	a17,4,4
	.comm	a18,4,4
	.comm	a19,4,4
	.comm	a20,4,4
	.comm	a21,4,4
	.comm	a22,4,4
	.comm	a23,4,4
	.comm	a24,4,4
	.comm	a25,4,4
	.comm	a26,4,4
	.comm	a27,4,4
	.comm	a28,4,4
	.comm	a29,4,4
	.comm	a30,4,4
	.comm	a31,4,4
	.comm	a32,4,4
	.comm	a33,4,4
	.comm	a34,4,4
	.comm	a35,4,4
	.comm	a36,4,4
	.comm	a37,4,4
	.comm	a38,4,4
	.comm	a39,4,4
	.text
	.align	2
	.global	testParam8
	.arch armv7-a
	.arm
	.ltorg
	.type	testParam8, %function
testParam8:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r6, [fp, #4]
    str        r6, [fp, #-24]
    sub        sp, sp, #4
    ldr        r6, [fp, #8]
    str        r6, [fp, #-28]
    sub        sp, sp, #4
    ldr        r6, [fp, #12]
    str        r6, [fp, #-32]
    sub        sp, sp, #4
    ldr        r6, [fp, #16]
    str        r6, [fp, #-36]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-40]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-40]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-44]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-44]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-48]
    ldr        r3, [fp, #-20]
    ldr        r7, [fp, #-48]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-52]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-52]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-56]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-56]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-60]
    ldr        r3, [fp, #-32]
    ldr        r7, [fp, #-60]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-64]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-64]
    add        r3, r7
    mov        r0, r3
    b          label_RETURN44
label_RETURN44:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	testParam8, .-testParam8
	.align	2
	.global	testParam16
	.arch armv7-a
	.arm
	.ltorg
	.type	testParam16, %function
testParam16:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r6, [fp, #4]
    str        r6, [fp, #-24]
    sub        sp, sp, #4
    ldr        r6, [fp, #8]
    str        r6, [fp, #-28]
    sub        sp, sp, #4
    ldr        r6, [fp, #12]
    str        r6, [fp, #-32]
    sub        sp, sp, #4
    ldr        r6, [fp, #16]
    str        r6, [fp, #-36]
    sub        sp, sp, #4
    ldr        r6, [fp, #20]
    str        r6, [fp, #-40]
    sub        sp, sp, #4
    ldr        r6, [fp, #24]
    str        r6, [fp, #-44]
    sub        sp, sp, #4
    ldr        r6, [fp, #28]
    str        r6, [fp, #-48]
    sub        sp, sp, #4
    ldr        r6, [fp, #32]
    str        r6, [fp, #-52]
    sub        sp, sp, #4
    ldr        r6, [fp, #36]
    str        r6, [fp, #-56]
    sub        sp, sp, #4
    ldr        r6, [fp, #40]
    str        r6, [fp, #-60]
    sub        sp, sp, #4
    ldr        r6, [fp, #44]
    str        r6, [fp, #-64]
    sub        sp, sp, #4
    ldr        r6, [fp, #48]
    str        r6, [fp, #-68]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-72]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-72]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-76]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-76]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-80]
    ldr        r3, [fp, #-20]
    ldr        r7, [fp, #-80]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-84]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-84]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-88]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-88]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-92]
    ldr        r3, [fp, #-32]
    ldr        r7, [fp, #-92]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-96]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-96]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-100]
    ldr        r3, [fp, #-40]
    ldr        r7, [fp, #-100]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-104]
    ldr        r3, [fp, #-44]
    ldr        r7, [fp, #-104]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-108]
    ldr        r3, [fp, #-48]
    ldr        r7, [fp, #-108]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-112]
    ldr        r3, [fp, #-52]
    ldr        r7, [fp, #-112]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-116]
    ldr        r3, [fp, #-56]
    ldr        r7, [fp, #-116]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-120]
    ldr        r3, [fp, #-60]
    ldr        r7, [fp, #-120]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-124]
    ldr        r3, [fp, #-64]
    ldr        r7, [fp, #-124]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-128]
    ldr        r3, [fp, #-68]
    ldr        r7, [fp, #-128]
    add        r3, r7
    mov        r0, r3
    b          label_RETURN45
label_RETURN45:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	testParam16, .-testParam16
	.align	2
	.global	testParam32
	.arch armv7-a
	.arm
	.ltorg
	.type	testParam32, %function
testParam32:
    push       {fp, lr}
    add        fp, sp, #4
    sub        sp, sp, #4
    str        r0, [fp, #-8]
    sub        sp, sp, #4
    str        r1, [fp, #-12]
    sub        sp, sp, #4
    str        r2, [fp, #-16]
    sub        sp, sp, #4
    str        r3, [fp, #-20]
    sub        sp, sp, #4
    ldr        r6, [fp, #4]
    str        r6, [fp, #-24]
    sub        sp, sp, #4
    ldr        r6, [fp, #8]
    str        r6, [fp, #-28]
    sub        sp, sp, #4
    ldr        r6, [fp, #12]
    str        r6, [fp, #-32]
    sub        sp, sp, #4
    ldr        r6, [fp, #16]
    str        r6, [fp, #-36]
    sub        sp, sp, #4
    ldr        r6, [fp, #20]
    str        r6, [fp, #-40]
    sub        sp, sp, #4
    ldr        r6, [fp, #24]
    str        r6, [fp, #-44]
    sub        sp, sp, #4
    ldr        r6, [fp, #28]
    str        r6, [fp, #-48]
    sub        sp, sp, #4
    ldr        r6, [fp, #32]
    str        r6, [fp, #-52]
    sub        sp, sp, #4
    ldr        r6, [fp, #36]
    str        r6, [fp, #-56]
    sub        sp, sp, #4
    ldr        r6, [fp, #40]
    str        r6, [fp, #-60]
    sub        sp, sp, #4
    ldr        r6, [fp, #44]
    str        r6, [fp, #-64]
    sub        sp, sp, #4
    ldr        r6, [fp, #48]
    str        r6, [fp, #-68]
    sub        sp, sp, #4
    ldr        r6, [fp, #52]
    str        r6, [fp, #-72]
    sub        sp, sp, #4
    ldr        r6, [fp, #56]
    str        r6, [fp, #-76]
    sub        sp, sp, #4
    ldr        r6, [fp, #60]
    str        r6, [fp, #-80]
    sub        sp, sp, #4
    ldr        r6, [fp, #64]
    str        r6, [fp, #-84]
    sub        sp, sp, #4
    ldr        r6, [fp, #68]
    str        r6, [fp, #-88]
    sub        sp, sp, #4
    ldr        r6, [fp, #72]
    str        r6, [fp, #-92]
    sub        sp, sp, #4
    ldr        r6, [fp, #76]
    str        r6, [fp, #-96]
    sub        sp, sp, #4
    ldr        r6, [fp, #80]
    str        r6, [fp, #-100]
    sub        sp, sp, #4
    ldr        r6, [fp, #84]
    str        r6, [fp, #-104]
    sub        sp, sp, #4
    ldr        r6, [fp, #88]
    str        r6, [fp, #-108]
    sub        sp, sp, #4
    ldr        r6, [fp, #92]
    str        r6, [fp, #-112]
    sub        sp, sp, #4
    ldr        r6, [fp, #96]
    str        r6, [fp, #-116]
    sub        sp, sp, #4
    ldr        r6, [fp, #100]
    str        r6, [fp, #-120]
    sub        sp, sp, #4
    ldr        r6, [fp, #104]
    str        r6, [fp, #-124]
    sub        sp, sp, #4
    ldr        r6, [fp, #108]
    str        r6, [fp, #-128]
    sub        sp, sp, #4
    ldr        r6, [fp, #112]
    str        r6, [fp, #-132]
    ldr        r3, [fp, #-8]
    sub        sp, sp, #4
    str        r3, [fp, #-136]
    ldr        r3, [fp, #-12]
    ldr        r7, [fp, #-136]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-140]
    ldr        r3, [fp, #-16]
    ldr        r7, [fp, #-140]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-144]
    ldr        r3, [fp, #-20]
    ldr        r7, [fp, #-144]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-148]
    ldr        r3, [fp, #-24]
    ldr        r7, [fp, #-148]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-152]
    ldr        r3, [fp, #-28]
    ldr        r7, [fp, #-152]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-156]
    ldr        r3, [fp, #-32]
    ldr        r7, [fp, #-156]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-160]
    ldr        r3, [fp, #-36]
    ldr        r7, [fp, #-160]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-164]
    ldr        r3, [fp, #-40]
    ldr        r7, [fp, #-164]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-168]
    ldr        r3, [fp, #-44]
    ldr        r7, [fp, #-168]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-172]
    ldr        r3, [fp, #-48]
    ldr        r7, [fp, #-172]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-176]
    ldr        r3, [fp, #-52]
    ldr        r7, [fp, #-176]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-180]
    ldr        r3, [fp, #-56]
    ldr        r7, [fp, #-180]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-184]
    ldr        r3, [fp, #-60]
    ldr        r7, [fp, #-184]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-188]
    ldr        r3, [fp, #-64]
    ldr        r7, [fp, #-188]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-192]
    ldr        r3, [fp, #-68]
    ldr        r7, [fp, #-192]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-196]
    ldr        r3, [fp, #-72]
    ldr        r7, [fp, #-196]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-200]
    ldr        r3, [fp, #-76]
    ldr        r7, [fp, #-200]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-204]
    ldr        r3, [fp, #-80]
    ldr        r7, [fp, #-204]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-208]
    ldr        r3, [fp, #-84]
    ldr        r7, [fp, #-208]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-212]
    ldr        r3, [fp, #-88]
    ldr        r7, [fp, #-212]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-216]
    ldr        r3, [fp, #-92]
    ldr        r7, [fp, #-216]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-220]
    ldr        r3, [fp, #-96]
    ldr        r7, [fp, #-220]
    sub        r3, r7, r3
    sub        sp, sp, #4
    str        r3, [fp, #-224]
    ldr        r3, [fp, #-100]
    ldr        r7, [fp, #-224]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-228]
    ldr        r3, [fp, #-104]
    ldr        r7, [fp, #-228]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-232]
    ldr        r3, [fp, #-108]
    ldr        r7, [fp, #-232]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-236]
    ldr        r3, [fp, #-112]
    ldr        r7, [fp, #-236]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-240]
    ldr        r3, [fp, #-116]
    ldr        r7, [fp, #-240]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-244]
    ldr        r3, [fp, #-120]
    ldr        r7, [fp, #-244]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-248]
    ldr        r3, [fp, #-124]
    ldr        r7, [fp, #-248]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-252]
    ldr        r3, [fp, #-128]
    ldr        r7, [fp, #-252]
    add        r3, r7
    sub        sp, sp, #4
    str        r3, [fp, #-256]
    ldr        r3, [fp, #-132]
    ldr        r7, [fp, #-256]
    add        r3, r7
    mov        r0, r3
    b          label_RETURN46
label_RETURN46:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	testParam32, .-testParam32
	.align	2
	.global	main
	.arch armv7-a
	.arm
	.ltorg
	.type	main, %function
main:
    push       {fp, lr}
    add        fp, sp, #4
    ldr        r3, =0
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r3, =1
    mov        r8, r3
    ldr        r2, .L4
    str        r8, [r2]
    ldr        r3, =2
    mov        r8, r3
    ldr        r2, .L5
    str        r8, [r2]
    ldr        r3, =3
    mov        r8, r3
    ldr        r2, .L6
    str        r8, [r2]
    ldr        r3, =4
    mov        r8, r3
    ldr        r2, .L7
    str        r8, [r2]
    ldr        r3, =5
    mov        r8, r3
    ldr        r2, .L8
    str        r8, [r2]
    ldr        r3, =6
    mov        r8, r3
    ldr        r2, .L9
    str        r8, [r2]
    ldr        r3, =7
    mov        r8, r3
    ldr        r2, .L10
    str        r8, [r2]
    ldr        r3, =8
    mov        r8, r3
    ldr        r2, .L11
    str        r8, [r2]
    ldr        r3, =9
    mov        r8, r3
    ldr        r2, .L12
    str        r8, [r2]
    ldr        r3, =0
    mov        r8, r3
    ldr        r2, .L13
    str        r8, [r2]
    ldr        r3, =1
    mov        r8, r3
    ldr        r2, .L14
    str        r8, [r2]
    ldr        r3, =2
    mov        r8, r3
    ldr        r2, .L15
    str        r8, [r2]
    ldr        r3, =3
    mov        r8, r3
    ldr        r2, .L16
    str        r8, [r2]
    ldr        r3, =4
    mov        r8, r3
    ldr        r2, .L17
    str        r8, [r2]
    ldr        r3, =5
    mov        r8, r3
    ldr        r2, .L18
    str        r8, [r2]
    ldr        r3, =6
    mov        r8, r3
    ldr        r2, .L19
    str        r8, [r2]
    ldr        r3, =7
    mov        r8, r3
    ldr        r2, .L20
    str        r8, [r2]
    ldr        r3, =8
    mov        r8, r3
    ldr        r2, .L21
    str        r8, [r2]
    ldr        r3, =9
    mov        r8, r3
    ldr        r2, .L22
    str        r8, [r2]
    ldr        r3, =0
    mov        r8, r3
    ldr        r2, .L23
    str        r8, [r2]
    ldr        r3, =1
    mov        r8, r3
    ldr        r2, .L24
    str        r8, [r2]
    ldr        r3, =2
    mov        r8, r3
    ldr        r2, .L25
    str        r8, [r2]
    ldr        r3, =3
    mov        r8, r3
    ldr        r2, .L26
    str        r8, [r2]
    ldr        r3, =4
    mov        r8, r3
    ldr        r2, .L27
    str        r8, [r2]
    ldr        r3, =5
    mov        r8, r3
    ldr        r2, .L28
    str        r8, [r2]
    ldr        r3, =6
    mov        r8, r3
    ldr        r2, .L29
    str        r8, [r2]
    ldr        r3, =7
    mov        r8, r3
    ldr        r2, .L30
    str        r8, [r2]
    ldr        r3, =8
    mov        r8, r3
    ldr        r2, .L31
    str        r8, [r2]
    ldr        r3, =9
    mov        r8, r3
    ldr        r2, .L32
    str        r8, [r2]
    ldr        r3, =0
    mov        r8, r3
    ldr        r2, .L33
    str        r8, [r2]
    ldr        r3, =1
    mov        r8, r3
    ldr        r2, .L34
    str        r8, [r2]
    ldr        r3, =4
    mov        r8, r3
    ldr        r2, .L35
    str        r8, [r2]
    ldr        r3, =5
    mov        r8, r3
    ldr        r2, .L36
    str        r8, [r2]
    ldr        r3, =6
    mov        r8, r3
    ldr        r2, .L37
    str        r8, [r2]
    ldr        r3, =7
    mov        r8, r3
    ldr        r2, .L38
    str        r8, [r2]
    ldr        r3, =8
    mov        r8, r3
    ldr        r2, .L39
    str        r8, [r2]
    ldr        r3, =9
    mov        r8, r3
    ldr        r2, .L40
    str        r8, [r2]
    ldr        r3, =0
    mov        r8, r3
    ldr        r2, .L41
    str        r8, [r2]
    ldr        r3, =1
    mov        r8, r3
    ldr        r2, .L42
    str        r8, [r2]
    sub        sp, sp, #16
    ldr        r2, .L7
    ldr        r3, [r2]
    str        r3, [sp, #0]
    ldr        r2, .L8
    ldr        r3, [r2]
    str        r3, [sp, #4]
    ldr        r2, .L9
    ldr        r3, [r2]
    str        r3, [sp, #8]
    ldr        r2, .L10
    ldr        r3, [r2]
    str        r3, [sp, #12]
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    ldr        r2, .L4
    ldr        r3, [r2]
    mov        r1, r3
    ldr        r2, .L5
    ldr        r3, [r2]
    mov        r7, r3
    ldr        r2, .L6
    ldr        r3, [r2]
    mov        r3, r3
    mov        r2, r7
    bl         testParam8
    mov        r3, r0
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    sub        sp, sp, #48
    ldr        r2, .L39
    ldr        r3, [r2]
    str        r3, [sp, #0]
    ldr        r2, .L40
    ldr        r3, [r2]
    str        r3, [sp, #4]
    ldr        r2, .L41
    ldr        r3, [r2]
    str        r3, [sp, #8]
    ldr        r2, .L42
    ldr        r3, [r2]
    str        r3, [sp, #12]
    ldr        r2, .L11
    ldr        r3, [r2]
    str        r3, [sp, #16]
    ldr        r2, .L12
    ldr        r3, [r2]
    str        r3, [sp, #20]
    ldr        r2, .L13
    ldr        r3, [r2]
    str        r3, [sp, #24]
    ldr        r2, .L14
    ldr        r3, [r2]
    str        r3, [sp, #28]
    ldr        r2, .L15
    ldr        r3, [r2]
    str        r3, [sp, #32]
    ldr        r2, .L16
    ldr        r3, [r2]
    str        r3, [sp, #36]
    ldr        r2, .L17
    ldr        r3, [r2]
    str        r3, [sp, #40]
    ldr        r2, .L18
    ldr        r3, [r2]
    str        r3, [sp, #44]
    ldr        r2, .L35
    ldr        r3, [r2]
    mov        r0, r3
    ldr        r2, .L36
    ldr        r3, [r2]
    mov        r1, r3
    ldr        r2, .L37
    ldr        r3, [r2]
    mov        r7, r3
    ldr        r2, .L38
    ldr        r3, [r2]
    mov        r3, r3
    mov        r2, r7
    bl         testParam16
    mov        r3, r0
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    sub        sp, sp, #112
    ldr        r2, .L7
    ldr        r3, [r2]
    str        r3, [sp, #0]
    ldr        r2, .L8
    ldr        r3, [r2]
    str        r3, [sp, #4]
    ldr        r2, .L9
    ldr        r3, [r2]
    str        r3, [sp, #8]
    ldr        r2, .L10
    ldr        r3, [r2]
    str        r3, [sp, #12]
    ldr        r2, .L11
    ldr        r3, [r2]
    str        r3, [sp, #16]
    ldr        r2, .L12
    ldr        r3, [r2]
    str        r3, [sp, #20]
    ldr        r2, .L13
    ldr        r3, [r2]
    str        r3, [sp, #24]
    ldr        r2, .L14
    ldr        r3, [r2]
    str        r3, [sp, #28]
    ldr        r2, .L15
    ldr        r3, [r2]
    str        r3, [sp, #32]
    ldr        r2, .L16
    ldr        r3, [r2]
    str        r3, [sp, #36]
    ldr        r2, .L17
    ldr        r3, [r2]
    str        r3, [sp, #40]
    ldr        r2, .L18
    ldr        r3, [r2]
    str        r3, [sp, #44]
    ldr        r2, .L19
    ldr        r3, [r2]
    str        r3, [sp, #48]
    ldr        r2, .L20
    ldr        r3, [r2]
    str        r3, [sp, #52]
    ldr        r2, .L21
    ldr        r3, [r2]
    str        r3, [sp, #56]
    ldr        r2, .L22
    ldr        r3, [r2]
    str        r3, [sp, #60]
    ldr        r2, .L23
    ldr        r3, [r2]
    str        r3, [sp, #64]
    ldr        r2, .L24
    ldr        r3, [r2]
    str        r3, [sp, #68]
    ldr        r2, .L25
    ldr        r3, [r2]
    str        r3, [sp, #72]
    ldr        r2, .L26
    ldr        r3, [r2]
    str        r3, [sp, #76]
    ldr        r2, .L27
    ldr        r3, [r2]
    str        r3, [sp, #80]
    ldr        r2, .L28
    ldr        r3, [r2]
    str        r3, [sp, #84]
    ldr        r2, .L29
    ldr        r3, [r2]
    str        r3, [sp, #88]
    ldr        r2, .L30
    ldr        r3, [r2]
    str        r3, [sp, #92]
    ldr        r2, .L31
    ldr        r3, [r2]
    str        r3, [sp, #96]
    ldr        r2, .L32
    ldr        r3, [r2]
    str        r3, [sp, #100]
    ldr        r2, .L33
    ldr        r3, [r2]
    str        r3, [sp, #104]
    ldr        r2, .L34
    ldr        r3, [r2]
    str        r3, [sp, #108]
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    ldr        r2, .L4
    ldr        r3, [r2]
    mov        r1, r3
    ldr        r2, .L5
    ldr        r3, [r2]
    mov        r7, r3
    ldr        r2, .L6
    ldr        r3, [r2]
    mov        r3, r3
    mov        r2, r7
    bl         testParam32
    mov        r3, r0
    mov        r8, r3
    ldr        r2, .L3
    str        r8, [r2]
    ldr        r2, .L3
    ldr        r3, [r2]
    mov        r0, r3
    bl         putint
    mov        r3, r0
    ldr        r3, =0
    mov        r0, r3
    b          label_RETURN47
label_RETURN47:
    sub        sp, fp, #4
    pop        {fp, pc}
	.size	main, .-main
	.text
.L3:
	.word	a0
.L4:
	.word	a1
.L13:
	.word	a10
.L14:
	.word	a11
.L15:
	.word	a12
.L16:
	.word	a13
.L17:
	.word	a14
.L18:
	.word	a15
.L19:
	.word	a16
.L20:
	.word	a17
.L21:
	.word	a18
.L22:
	.word	a19
.L5:
	.word	a2
.L23:
	.word	a20
.L24:
	.word	a21
.L25:
	.word	a22
.L26:
	.word	a23
.L27:
	.word	a24
.L28:
	.word	a25
.L29:
	.word	a26
.L30:
	.word	a27
.L31:
	.word	a28
.L32:
	.word	a29
.L6:
	.word	a3
.L33:
	.word	a30
.L34:
	.word	a31
.L35:
	.word	a32
.L36:
	.word	a33
.L37:
	.word	a34
.L38:
	.word	a35
.L39:
	.word	a36
.L40:
	.word	a37
.L41:
	.word	a38
.L42:
	.word	a39
.L7:
	.word	a4
.L8:
	.word	a5
.L9:
	.word	a6
.L10:
	.word	a7
.L11:
	.word	a8
.L12:
	.word	a9
