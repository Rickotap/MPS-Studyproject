	.file	"Termin1Aufgabe6.c"
	.comm	c,4,4
	.text
	.align	2
	.global	Addition
	.type	Addition, %function
Addition:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #8
	str	r0, [fp, #-4]
	str	r1, [fp, #-8]
	ldr	r2, [fp, #-4]
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	Addition, .-Addition
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	mov	r3, #34
	str	r3, [fp, #-12]
	mov	r3, #68
	str	r3, [fp, #-8]
	ldr	r0, [fp, #-12]
	ldr	r1, [fp, #-8]
	bl	Addition
	mov	r2, r0
	ldr	r3, .L5
	str	r2, [r3, #0]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	ldmfd	sp!, {fp, pc}
.L6:
	.align	2
.L5:
	.word	c
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
