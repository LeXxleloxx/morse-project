#include <stdio.h>
#include <stdlib.h>
#include "morse.h"
#include <locale.h>

/**Precisamos:
-	passar todo o arquivo para ABP
-	tratar caracteres com acento. ex: 'É' passar para 'E'
-	deixar todos caracteres minúsculos (função lower) 

ps: reusar funções prontas das aulas anteriores
**/

Morse* InicializaABP(void)
{
 return NULL;
}

Morse* InsereABP(Morse *a, int chave, char codaux)
{
    if (a == NULL)
    {
        a = (Morse*) malloc(sizeof(Morse));
        a->info = chave;
        a->esq = NULL;
        a->dir = NULL;
		a->cod = 
    }
    else if (chave < (a->info))
        a->esq = InsereArvore(a->esq,chave);
    else
        a->dir = InsereArvore(a->dir,chave);
    return a;
}

void ler_morse (Morse a)
{
    char ch; 							//buffer para caractere lido no arquivo
    FILE *arq;
    arq = fopen("TabelaMorse.txt", "r");//abre o arquivo

    if (arq == NULL) 					//se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo\n");
        return;
    }
    else{
        while((ch = fgetc(arq)) != EOF)
		{
			arq++;					//incrementa ponteiro do arquivo para ignorar o TAB
			int cont = 0;
			char codaux[MAX];
			while((ch = fgetc(arq)) != '\n')	//enquanto nao terminar a linha, guardar como o codigo morse
			{ 
                  codaux[cont] = fgetc(arq);
                  cont = cont + 1;
            }
			InsereABP(a,ch,codaux);
            }
        }
    }
    fclose(arq);
}


Morse* consulta(Morse *a, int chave){
 while (a!=NULL){
 if (a->info == chave ){
 comp++;
 return a; //achou então retorna o ponteiro para o nodo
 }
 else if (a->info > chave){
 comp++;
 a = a->esq;
 }
 else
 a = a->dir;
 }
 return NULL; //se não achou
} 