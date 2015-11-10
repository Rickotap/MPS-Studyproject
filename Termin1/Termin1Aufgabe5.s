	.file	"Termin1Aufgabe5.c"
	.text
	.align	2
	.global	addition
	.type	addition, %function
addition:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r3, [r1, #0]
	add	r3, r2, r3
	ldr	r0, [r0, #0]
	add	r0, r3, r0
	bx	lr
	.size	addition, .-addition
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	sub	sp, sp, #8
	mov	r3, #256
	add	r3, r3, #1
	orr	r3, r3, r3, asl #16
	str	r3, [sp, #4]
	mov	r3, #512
	add	r3, r3, #2
	orr	r3, r3, r3, asl #16
	str	r3, [sp, #0]
	mov	r2, #768
	add	r2, r2, #3
	orr	r2, r2, r2, asl #16
	ldr	r3, .L5
	str	r2, [r3, #0]
	add	r0, sp, #4
	mov	r1, sp
	bl	addition
	ldr	r3, .L5+4
	str	r0, [r3, #0]
	mov	r0, #0
	add	sp, sp, #8
	ldmfd	sp!, {pc}
.L6:
	.align	2
.L5:
	.word	c
	.word	d
	.size	main, .-main
	.comm	c,4,4
	.comm	d,4,4
	.ident	"GCC: (GNU) 4.4.1"
