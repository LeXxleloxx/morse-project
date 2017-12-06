#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE* arq;
    char c;
    arq=fopen("TabelaMorse.txt","r");
    if (arq == NULL)
        printf("Erro na leitura do arquivo\n");

        c=fgetc(arq);
    printf(" %c\n",c);
        c=fgetc(arq);
    printf("%c\n",c);
        c=fgetc(arq);
    printf("%c\n",c);
}
