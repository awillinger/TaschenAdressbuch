/*
  Name of file  : taschenrechner.c
  Author        : Andreas Willinger <awillinger@student.tgm.ac.at>
  Version       : 20131018.2
  Description   : Einfacher Taschenrechner basierend auf Funktions-Pointern
                  
*/
#include <stdio.h>
#include <stdlib.h>

#define VERSION 1.0

int addition(int, int);
int subtraktion(int, int);
int division(int, int);
int multiplikation(int,int);
void clear_buffer(void);

int (*fp[4])(int a, int b);

int main(int argc, char** argv)
{
	fp[0] = addition;
	fp[1] = subtraktion;
	fp[2] = division;
	fp[3] = multiplikation;

	char type;
	int x = 0, y = 0;

	printf("*** Willkommen zum FP-Rechner %.2f ***", VERSION);
	
	while(1)
	{
		printf("\n");
		printf("** (1) Bitte waehlen Sie eine Option aus:\n");
		printf("** [a] Addition\n");
		printf("** [s] Subtraktion\n");
		printf("** [d] Division\n");
		printf("** [m] Multiplikation\n");
		printf("** [b] Beenden\n\n");
		printf("* Ihre Eingabe: ");
		
		scanf("%c", &type);
		clear_buffer();

		if(type == 'b')
		{
			break;
		}
			
		printf("\n\n** (1) Bitte geben Sie die beiden Operanden ein:\n");
		printf("* 1. Operand: ");
		
		scanf("%d", &x);
		clear_buffer();

		printf("\n* 2. Operand: ");
		scanf("%d", &y);
		clear_buffer();
		
		switch(type)
		{
		case 'a':
			printf("Das Ergebnis der Addition ist: %d", (*fp[0])(x, y));
			break;
		case 's':
			printf("Das Ergebnis der Subtraktion ist: %d", (*fp[1])(x, y));
			break;
		case 'd':
			printf("Das Ergebnis der Division ist: %d", (*fp[2])(x, y));
			break;
		case 'm':
			printf("Das Ergebnis der Multiplikation ist: %d", (*fp[3])(x, y));
			break;
		default:
			printf("UNGUELTIGE EINGABE!");
			break;
		}
	}
	return EXIT_SUCCESS;
}

int addition(int a, int b)
{
	return a+b;
}

int subtraktion(int a, int b)
{
	return a-b;
}

int division(int a, int b)
{
	if(b == 0) return 0;
	return a/b;
}

int multiplikation(int a, int b)
{
	return a*b;
}

/**
 * Löscht den stdin-Puffer, um falsche Eingabedaten zu vermeiden
 */
void clear_buffer()
{
	char c;

	// alle zeichen aus dem Puffer lesen, dadurch wird er geleert
	while((c = getchar()) != EOF && c != '\n')
	{
		;
	}
}