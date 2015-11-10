// Lösung zu Termin2
// Aufgabe 4
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

#include "../h/pmc.h"
#include "../h/pio.h"
#include "../h/aic.h"

void taste_irq_handler (void) __attribute__ ((interrupt));

void taste_irq_handler (void)
{
	StructAIC* aicbase = AIC_BASE;
	StructPIO* piobaseb = PIOB_BASE;

	if(!(piobaseb->PIO_PDSR & KEY1))
		piobaseb->PIO_CODR = 0x100;
	if(!(piobaseb->PIO_PDSR & KEY2))
		piobaseb->PIO_SODR = 0x100;
	
	aicbase->AIC_EOICR = piobaseb-> PIO_ISR;//wert in das end of register schreiben

}

int main(void)
{
	StructPIO * piobaseb = PIOB_BASE;
	StructPMC * pmcbase = PMC_BASE;
	StructAIC * aicbase = AIC_BASE;
	
	pmcbase->PMC_PCER = 0x4000;
	piobaseb->PIO_PER = 0x318;
	piobaseb->PIO_OER = 0x300;
	piobaseb->PIO_ODR = 0x018;
	
	aicbase->AIC_IDCR = 1 << 14;  //dissable interrupts
	aicbase->AIC_ICCR = 1 << 14;  //delete interrupts
	aicbase->AIC_SVR[PIOB_ID] = (unsigned int) taste_irq_handler;
	aicbase->AIC_SMR[PIOB_ID] = 0x7;   //Priorität
	aicbase->AIC_IECR = 1 << 14; //interrupts für PIOB aktivieren
	piobaseb->PIO_IER = 0x18; //interrupt für Taster Aktivieren
	
	while(1){
	int i;
	piobaseb->PIO_CODR=0x200;
	for(i=0;i<250000;i++){}
	piobaseb->PIO_SODR=0x200;
	for(i=0;i<250000;i++){}	
	
	return 0;
}
