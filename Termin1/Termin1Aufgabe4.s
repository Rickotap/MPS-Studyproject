	.file	"Termin1Aufgabe4.c"
	.text
	.align	2
	.global	addition
	.type	addition, %function
addition:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	add	r0, r1, r0
	add	r0, r0, r2
	bx	lr
	.size	addition, .-addition
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	str	lr, [sp, #-4]!
	mov	r2, #768
	add	r2, r2, #3
	orr	r2, r2, r2, asl #16
	ldr	r3, .L5
	str	r2, [r3, #0]
	mov	r0, #256
	add	r0, r0, #1
	orr	r0, r0, r0, asl #16
	mov	r1, #512
	add	r1, r1, #2
	orr	r1, r1, r1, asl #16
	bl	addition
	ldr	r3, .L5+4
	str	r0, [r3, #0]
	mov	r0, #0
	ldr	pc, [sp], #4
.L6:
	.align	2
.L5:
	.word	c
	.word	d
	.size	main, .-main
	.comm	c,4,4
	.comm	d,4,4
	.ident	"GCC: (GNU) 4.4.1"
