morse old.c
DETALHES
ATIVIDADE
Hoje
12:55

Você fez o upload de 1 item
C
morse old.c
Nenhuma atividade registrada antes de 11 de dezembro de 2017
Minimizada 

#include <stdio.h>
#include <stdlib.h>
#include "morse2.h"
#include <locale.h>
#include <string.h>

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
        char codaux[MAX];
        a = (Morse*) malloc(sizeof(Morse));
        printf("\n Alocando ponteiros");
        a->letra = chave;
        a->esq = NULL;
        a->dir = NULL;
        strcpy(a->cod,codaux);
        // a->cod = codaux;
    }
    else if (chave < (a->letra))
        a->esq = InsereABP(a->esq,chave, codaux);
    else
        a->dir = InsereABP(a->dir,chave, codaux);
    return a;
}

void ler_morse (Morse *a)
{
    char ch; 							//buffer para caractere lido no arquivo
    FILE *arq;
    arq = fopen("TabelaMorse.txt", "r");//abre o arquivo

    if (arq == NULL) 					//se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo\n");
        return 0;
    }
    else
    {
        while(!feof(arq))
        {
            ch= fgetc(arq);
            printf("%c ",ch);
            // fseek(arq,1* sizeof(char),SEEK_CUR); //incrementa ponteiro do arquivo para ignorar o TAB
            int cont = 0;
            char codaux[MAX];
            while(((ch = fgetc(arq)) != '\n') &&  !feof(arq ))	//enquanto nao terminar a linha, guardar como o codigo morse
            {
                codaux[cont] = ch;
                printf("%c ",codaux[cont]);
                cont++;
            }
            codaux[cont]='\n';
            //fseek(arq,1* sizeof(char),SEEK_CUR);
            InsereABP(a,ch,codaux);
        }
            fclose(arq);
    }
    //ImprimePreFix(a);
}

void copia_arquivo(Morse *a, int *comp)
{
    char ch;							     //buffer para caractere lido no arquivo
    FILE *arq_in, *arq_out;
    arq_in = fopen("godfather.txt", "r");    //abre o arquivo a ser convertido
    arq_out = fopen("saida.txt", "w");       //cria arquivo de saida

    if (arq_in == NULL) 					    //se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo\n");
        return;
    }
    else
    {
        while((ch = fgetc(arq_in)) != EOF)
        {
            Morse* novo=InicializaABP();
            remove_acento(ch);
            toupper(ch);                       //minúsculo para maiúsculo
            if( novo=consulta(a,ch,comp) == NULL)
            {
                if(ch == 32)
                {
                    fputs('/', arq_out);
                }
                else
                    printf("Caractere nao reconhecido\n");
            }
            fputs(novo->cod, arq_out);
        }
    }
    fclose(arq_in);
    fclose(arq_out);
}

Morse* consulta(Morse *a, int chave, int *comp)
{
    while (a!=NULL)
    {
        if (a->letra == chave )
        {
            *comp++;
            return a; //achou então retorna o ponteiro para o nodo
        }
        else if (a->letra > chave)
        {
            *comp++;
            a = a->esq;
            consulta(a,chave,comp);
        }
        else
            a = a->dir;
            consulta(a,chave,comp);
    }
    return NULL; //se não achou
}

char    remove_acento( char c)
{
    if( (192 <= c <= 197) || (224 <= c <= 229) )    return 'A';
    if( (200 <= c <= 203) || (232 <= c <= 235) )    return 'E';
    if( (204 <= c <= 207) || (236 <= c <= 239) )    return 'I';
    if( (210 <= c <= 214) || (242 <= c <= 246) )    return 'O';
    if( (217 <= c <= 220) || (249 <= c <= 252) )    return 'U';
}

void ImprimePreFix(Morse *a)
{
    if (a!= NULL)
    {
        printf("%c\n",a->letra);
        ImprimePreFix(a->esq);
        ImprimePreFix(a->dir);
    }
}
