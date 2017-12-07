#include <stdio.h>
#include <stdlib.h>
#include "morse.h"
#include <locale.h>

main()
{
	int	comp=0;	//numero de comparações
	Morse *a;	//ABP
	Morse *b;	//AVL
	a=InicializaABP();
	b=InicializaABP();
	
	lermorse(a);
}