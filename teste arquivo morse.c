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


#include <stdio.h>
#include <stdlib.h>
#include "morse.h"
#include <locale.h>

void ler_morse ()
{
    char ch; //ponteiro que vai percorrendo o arquivo
    Morse *tabela; //estrutura da tabela morse
	setlocale(LC_ALL, "Portuguese");

    FILE *arq;
    arq = fopen("TabelaMorse.txt", "r"); //abre o arquivo

    if (arq == NULL) //se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo\n");
        return;
    }
    else{
        while((ch = fgetc(arq)) != EOF){
            if (ch == 'A'){
                Morse *novo;
                novo->ant = NULL;
                novo->pos = NULL;
                novo->letra = 'a';

                char aux = 'a';
                char *codaux[MAX];
                int cont = 0;

                while((ch = fgetc(arq)) == ' '){ //enquanto for espacos, prosseguir
                    ch = fgetc(arq);
                }
                while((ch = fgetc(arq)) != '\n'){ //enquanto nao terminar a linha, guardar como o codigo morse
                    codaux[cont] = fgetc(arq);
                    cont = cont + 1;
                }

                novo->cod = codaux;

                tabela = novo; //acrescenta na estrutura

            }
        }
    }

    fclose(arq);
}

Percorre_arq


if(MorseTree == NULL){
MorseTree->letra = fgetc(arq);
MorseTree->esq = NULL;
MorseTree->dir = NULL;
arq++;
MorseTree->codigo = fgetc(arq);




A	,,,,,