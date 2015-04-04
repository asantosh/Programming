	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"list.c"
	.comm	cptr,4,4
	.comm	head,4,4
	.comm	ptr,4,4
	.comm	sptr,4,4
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-8]
	mov	r0, #8
	bl	malloc
	mov	r3, r0
	mov	r2, r3
	ldr	r3, .L5
	str	r2, [r3, #0]
	ldr	r3, .L5
	ldr	r2, [r3, #0]
	ldr	r3, .L5+4
	str	r2, [r3, #0]
	ldr	r3, .L5
	ldr	r2, [r3, #0]
	ldr	r3, .L5+8
	str	r2, [r3, #0]
	mov	r3, #1
	str	r3, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, .L5+8
	ldr	r3, [r3, #0]
	mov	r0, r3
	ldr	r1, [fp, #-8]
	bl	insert
	mov	r2, r0
	ldr	r3, .L5+8
	str	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #4
	ble	.L3
	ldr	r3, .L5
	ldr	r3, [r3, #0]
	mov	r0, r3
	bl	printlist
	ldr	r3, .L5
	ldr	r3, [r3, #0]
	mov	r0, r3
	mov	r1, #3
	bl	delete
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L6:
	.align	2
.L5:
	.word	sptr
	.word	head
	.word	cptr
	.size	main, .-main
	.align	2
	.global	insert
	.type	insert, %function
insert:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #12
	str	r0, [fp, #-16]
	str	r1, [fp, #-20]
	ldr	r3, .L9
	ldr	r2, [fp, #-16]
	str	r2, [r3, #0]
	ldr	r3, .L9
	ldr	r3, [r3, #0]
	ldr	r2, [fp, #-20]
	str	r2, [r3, #0]
	ldr	r3, .L9
	ldr	r4, [r3, #0]
	mov	r0, #8
	bl	malloc
	mov	r3, r0
	str	r3, [r4, #4]
	ldr	r3, .L9
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L9
	str	r2, [r3, #0]
	ldr	r3, .L9
	ldr	r3, [r3, #0]
	mov	r0, r3
	sub	sp, fp, #8
	ldmfd	sp!, {r4, fp, lr}
	bx	lr
.L10:
	.align	2
.L9:
	.word	cptr
	.size	insert, .-insert
	.align	2
	.global	delete
	.type	delete, %function
delete:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	ldr	r3, .L18
	ldr	r2, [fp, #-8]
	str	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	bne	.L17
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L18+4
	str	r2, [r3, #0]
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #4]
	ldr	r3, .L18
	str	r2, [r3, #0]
	b	.L16
.L15:
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	bne	.L14
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	sub	r2, r3, #8
	ldr	r3, .L18
	str	r2, [r3, #0]
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	ldr	r2, .L18
	ldr	r2, [r2, #0]
	ldr	r2, [r2, #4]
	ldr	r2, [r2, #4]
	str	r2, [r3, #4]
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	mov	r0, r3
	bl	free
	b	.L14
.L17:
	mov	r0, r0	@ nop
.L14:
	ldr	r3, .L18
	ldr	r3, [r3, #0]
	cmp	r3, #0
	bne	.L15
.L16:
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L19:
	.align	2
.L18:
	.word	cptr
	.word	sptr
	.size	delete, .-delete
	.section	.rodata
	.align	2
.LC0:
	.ascii	"\012 data = %d \011 nptr = %d \012\000"
	.text
	.align	2
	.global	printlist
	.type	printlist, %function
printlist:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	b	.L21
.L22:
	ldr	r1, .L24
	ldr	r3, [fp, #-8]
	ldr	r2, [r3, #0]
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	mov	r0, r1
	mov	r1, r2
	mov	r2, r3
	bl	printf
	ldr	r3, [fp, #-8]
	ldr	r3, [r3, #4]
	str	r3, [fp, #-8]
.L21:
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L22
	sub	sp, fp, #4
	ldmfd	sp!, {fp, lr}
	bx	lr
.L25:
	.align	2
.L24:
	.word	.LC0
	.size	printlist, .-printlist
	.ident	"GCC: (ctng-1.6.1) 4.4.3"
	.section	.note.GNU-stack,"",%progbits
