// Lösung zu Termin2
// Aufgabe 1
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

int main(void)
{
// Beispiel des Anlegens und der Nutzung einer Zeigervariablen
#define PIOB_PER	((volatile unsigned int *) 0xFFFF0000)
	*PIOB_PER = 0x100;	// aktiviere Register LED's und Taster an PortB


	return 0;
}
