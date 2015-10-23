// Lösung zur Aufgabe Termin4
// Aufgabe 4
//****************************
// Zeiger auf Peripherie
// Messen der aufgelegten Masse
// 
// von: Manfred Pester
// vom: 06. August 2003

#include "../h/pio.h"
#include "../h/tc.h"
#include "../h/pmc.h"


void PIO_Init(void)
{

}

void Timer_Init(void)
{

}

int main(void)
{

	volatile int Masse;
	
	PIO_Init();	
	Timer_Init();
	
	while(!(piobaseA->PIO_ODSR & KEY3))
	{
		Masse = MessungderMasse();
	}
	
	return 0;
}
