// Lösung zur Aufgabe Termin4
// Aufgabe 1
//****************************
// Zeiger auf Peripherie
// Messen der Periodendauer einer angelegten Frequenz
// 
// von: Manfred Pester
// vom: 06. August 2003

#include "../h/pio.h"
#include "../h/tc.h"
#include "../h/pmc.h"

// für die Initialisierung des Zähler TC4

#define TC4_INIT  TC_CLKS_MCK2 | TC_LDBSTOP | TC_CAPT | TC_LDRA_RISING_EDGE | TC_LDRB_RISING_EDGE


int main(void)
{
	volatile int	captureRA1;
	volatile int	captureRB1;
	volatile int	capturediff1;
	volatile float Periodendauer1;
	
	StructPMC* pmcbase = PMC_BASE;
	StructPIO* piobaseA = PIOA_BASE;
	StructTC* tcbase4 = TCB4_BASE;
	StructTC* tcbase5 = TCB5_BASE;
	
	pmcbase->PMC_PCER = 0x06f80;	// Clock PIOA, PIOB, Timer5, Timer4, Timer1 einschalten
	
// Periodendauer der Waagensignale messen
// Signal aud TIOA4 ca. 16kHz entspricht ca. einer Periodendauer von 62,5us
// durch den Teiler von 32 ergeben sich ca. 2ms
// Zähler mit positiver Flanke starten 

	piobaseA->PIO_PDR	=	0x090;		
	tcbase4->TC_CCR		=	TC_CLKDIS;
	tcbase4->TC_CMR		=	TC4_INIT;
	tcbase4->TC_CCR		=	TC_CLKEN;
	tcbase4->TC_CCR		=	TC_SWTRG;
	
	while(!(piobaseB->PIO_PDSR & KEY3))
	{
		tcbase4->TC_CCR	=	TC_SWTRG;
		while (!( tcbase4->TC_SR & 0x40));		// Capture Register B wurde geladen Messung abgeschlossen
			captureRA1	= tcbase4->TC_RA;				// 	
			captureRB1	= tcbase4->TC_RB;
			capturediff1	=	abs(captureRB1) - abs(captureRA1);
			Periodendauer1 = abs(capturediff1) / 12.5;	// Zeit in us
	}
	
	return 0;
}
