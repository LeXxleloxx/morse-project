#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE* arq;
    int i=0;
    char c;
    arq=fopen("TabelaMorse.txt","r");
    if (arq == NULL)
        printf("Erro na leitura do arquivo\n");

    //fseek(arq,6* sizeof(char),SEEK_SET);


for(i=0;i<10;i++){
        c=getc(arq);
    printf("%i - %c \n",i,c);
}

}
//    fseek(arq,1* sizeof(char),SEEK_CUR);
