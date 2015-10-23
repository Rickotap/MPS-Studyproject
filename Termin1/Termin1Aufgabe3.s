	.file	"Termin1Aufgabe3.c"
	.comm	a,4,4
	.comm	b,4,4
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
	mov	r3, #68
	str	r3, [fp, #-8]
	mov	r3, #153
	str	r3, [fp, #-4]
	ldr	r3, .L3
	ldr	r2, [fp, #-8]
	str	r2, [r3, #0]
	ldr	r3, .L3+4
	ldr	r2, [fp, #-4]
	str	r2, [r3, #0]
	mov	r3, #0
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
.L4:
	.align	2
.L3:
	.word	a
	.word	b
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.1"
