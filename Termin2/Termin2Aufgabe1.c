// Lösung zu Termin2
// Aufgabe 1
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

// Beispiel des Anlegens und der Nutzung einer Zeigervariablen
#define PIOB_PER	((volatile unsigned int*) 0xFFFF0000)
#define PIOB_OER 	((volatile unsigned int*) 0xFFFF0010)
#define PIOB_SODR 	((volatile unsigned int*) 0xFFFF0030)
#define PIOB_CODR 	((volatile unsigned int*) 0xFFFF0034)
#define PMC_PCER	((volatile unsigned int*) 0xFFFF4010)

int main(void)
{
	*PIOB_PER = 0x100;	// aktiviere Register LED's und Taster an PortB
	*PIOB_OER = 0x100;
	

	*PMC_PCER	=0x4000;	//Clock
	*PIOB_PER	=0x100;		// LED1
	
	*PIOB_CODR	=0x100;
	*PIOB_SODR	=0x100;
	*PIOB_CODR	=0x100;
	*PIOB_SODR	=0x100;
	*PIOB_CODR	=0x100;
	*PIOB_SODR	=0x100;
	*PIOB_CODR	=0x100;
	*PIOB_SODR	=0x100;		


	return 0;
}
