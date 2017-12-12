#include <stdio.h>
#include <stdlib.h>
#include "morse2.h"
#include <locale.h>

main()
{
    int	comp=0;	//numero de comparações
    Morse *a;	//ABP
//	Morse *b;	//AVL
    a=InicializaABP();

    setlocale(LC_ALL, "Portuguese");
    printf("Lendo tabela morse...\n");

    ler_morse(a);

  //  printf("\nCodificando...\n");

  //  copia_arquivo(a, &comp);

   // printf("Numero de comparacoes: %i",comp);
    return 0;
}
