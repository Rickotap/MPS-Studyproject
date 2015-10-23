	.file	"Termin1Aufgabe1.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #8
	mov	r3, #13056
	add	r3, r3, #51
	str	r3, [fp, #-8]
	mov	r3, #26112
	add	r3, r3, #102
	str	r3, [fp, #-4]
	mov	r3, #0
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
