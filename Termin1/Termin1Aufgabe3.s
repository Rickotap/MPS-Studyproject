	.file	"Termin1Aufgabe3.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	mov	r2, #68
	ldr	r3, .L3
	str	r2, [r3, #0]
	mov	r2, #153
	ldr	r3, .L3+4
	str	r2, [r3, #0]
	mov	r0, #0
	bx	lr
.L4:
	.align	2
.L3:
	.word	a
	.word	b
	.size	main, .-main
	.comm	a,4,4
	.comm	b,4,4
	.ident	"GCC: (GNU) 4.4.1"
