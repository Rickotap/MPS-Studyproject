// Lösung zu Termin2
// Aufgabe 1
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

#include "../h/pmc.h"
#include "../h/pio.h"

StructPIO * piobaseb = PIOB_BASE;
StructPMC * pmcbase = PMC_BASE;
// Beispiel des Anlegens und der Nutzung einer Zeigervariablen
//#define PIOB_PER	((volatile unsigned int*) 0xFFFF0000)
//#define PIOB_OER 	((volatile unsigned int*) 0xFFFF0010)
//#define PIOB_SODR 	((volatile unsigned int*) 0xFFFF0030)
//#define PIOB_CODR 	((volatile unsigned int*) 0xFFFF0034)
//#define PMC_PCER	((volatile unsigned int*) 0xFFFF4010)

int main(void)
{
	piobaseb->PIO_PER = 0x118;	// aktiviere Register LED's und Taster an PortB
	piobaseb->PIO_OER = 0x100;	// LED1
	piobaseb->PIO_ODR = 0x018;

	pmcbase->PMC_PCER	=0x4000;	//Clock
			
	while(1){
	if(!(piobaseb->PIO_PDSR & 0x008))	//taster 1 schaltet die LED an
	    piobaseb->PIO_CODR	=0x100;
	
	if(!(piobaseb->PIO_PDSR & 0x010))	//taster 2 schaltet die LED aus

	piobaseb->PIO_SODR	=0x100;
	}


	return 0;
}
