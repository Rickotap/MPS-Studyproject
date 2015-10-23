	.file	"Termin1Aufgabe2.c"
	.comm	a,4,4
	.comm	b,4,4
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r2, .L3
	mov	r3, #1632
	add	r3, r3, #6
	str	r3, [r2, #0]
	ldr	r2, .L3+4
	mov	r3, #2448
	add	r3, r3, #9
	str	r3, [r2, #0]
	mov	r3, #0
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L4:
	.align	2
.L3:
	.word	b
	.word	a
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
