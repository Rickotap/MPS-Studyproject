// Lösung zu Termin3
// Aufgabe 1
// von:
// vom: 
// 

#include "../h/pmc.h"
#include "../h/tc.h"
#include "../h/pio.h"
#include "../h/aic.h"

void taste_irq_handler (void) __attribute__ ((interrupt));
 
// Interruptserviceroutine der Taster SW1 und SW2
void taste_irq_handler (void)
{
  StructPIO* piobaseA = PIOA_BASE;		// Basisadresse des PIOA 
  StructPIO* piobaseB = PIOB_BASE;		// Basisadresse des PIOB
  StructAIC* aicbase = AIC_BASE;		// Basisadresse des AdvancedInterruptControler
	
// ab hier entsprechend der Aufgabestellung ergänzen
// *************************************************

	if(!(piobaseB->PIO_PDSR & KEY2))
		piobaseA->PIO_PDR = (1<<PIOTIOA3);	//Aktivieren des Ausgang durch Peripherie Enable (!clock)		
	if(!(piobaseB->PIO_PDSR & KEY1))
		piobaseA->PIO_PER  = (1<<PIOTIOA3);	// Deaktivieren des Ausgang durch Peripherie Enable (!clock)
  	
	aicbase->AIC_EOICR = piobaseB->PIO_ISR;	// End of Interrupt Command Register wird durch das Interrupt Status Register beschrieben
}



// Timer3 initialisieren
void Timer3_init( void )
{
  StructTC* timerbase3  = TCB3_BASE;		// Basisadressse des TC
  StructPIO* piobaseA   = PIOA_BASE;		// Basisadresse des PIOB

	timerbase3->TC_CCR = TC_CLKDIS;		// Disable Clock
 
  // Initialize the mode of the timer 3
  timerbase3->TC_CMR =
    TC_ACPC_CLEAR_OUTPUT  |    // RC clear TIOA
    TC_ACPA_SET_OUTPUT    |    // RA set TIOA
    TC_WAVE               |    //Waveform mode aktivieren
    TC_CPCTRG             |    //CompareTrigger
    TC_CLKS_MCK1024;           //Select des Timers

  // Initialize the counter:
  timerbase3->TC_RA = 244; // ((25.000.000/1024)/100
  timerbase3->TC_RC = 488; //((25.000.000/1024)*2)/100

  // Start the timer :
  timerbase3->TC_CCR = TC_CLKEN ;	// Aktiviere die clock
  timerbase3->TC_CCR = TC_SWTRG ;	// auf Software Trigger stellen
  piobaseA->PIO_PER  = (1<<PIOTIOA3) ;	// clock für PIOTIOA3 aktivieren
  piobaseA->PIO_OER  = (1<<PIOTIOA3) ;	// Als Output setzen
  piobaseA->PIO_CODR = (1<<PIOTIOA3) ;	// Setze ausgang auf 0
}



int main(void)
{

	StructPMC* pmcbase	= PMC_BASE;	// Basisadresse PMC
	StructPIO* piobaseA   	= PIOA_BASE;	// Basisadresse PIOA
	StructPIO* piobaseB   	= PIOB_BASE;	// Basisadresse PIOB
	StructAIC* aicbase	= AIC_BASE;	// Basisadresse AIC

	pmcbase->PMC_PCER	= 0x6200;	//PIOA, PIOB, TIMER3 einschalten  
	
// ab hier entsprechend der Aufgabestellung ergÃ¤nzen
//**************************************************
	
	piobaseB->PIO_PER = 0x18;		// SW1 und SW2 aktivieren
	piobaseB->PIO_ODR = 0x18;		// SW1 und SW2 als Input definieren
	
	
	aicbase->AIC_IDCR = 0x4000; 		//deaktivieren interrupts for PIOB
	aicbase->AIC_ICCR = 0x4000;		// Löschen der Interrupts
	aicbase->AIC_SVR[PIOB_ID] = (unsigned int)taste_irq_handler;
	aicbase->AIC_SMR[PIOB_ID] = 0x7; 
	aicbase->AIC_IECR = 0x4000;		//Aktiviere Interrupts an PIOB
	piobaseB->PIO_IER = KEY1 | KEY2; 	//enable Interrupts inerhalb der PIOB	
		
	Timer3_init();
 
			
	while(1);
	
	return 0;
}

