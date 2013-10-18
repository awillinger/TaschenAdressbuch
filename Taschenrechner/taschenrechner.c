/*
  Name of file  : taschenrechner.c
  Author        : Andreas Willinger <awillinger@student.tgm.ac.at>
  Version       : 20131018.1
  Description   : Einfacher Taschenrechner basierend auf Funktions-Pointern
                  
*/
#include <stdio.h>
#include <stdlib.h>

int addition(int, int);
int subtraktion(int, int);
int division(int, int);
int multiplikation(int,int);

int (*fp[4])(int a, int b);

int main(int argc, char** argv)
{
	fp[0] = addition;
	fp[1] = subtraktion;
	fp[2] = division;
	fp[3] = multiplikation;


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