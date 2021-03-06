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

Morse* InsereABP(Morse *a, char chave, char codaux[MAX])
{
    if (a == NULL)
    {
        a = (Morse*) malloc(sizeof(Morse));
        a->letra = chave;
        a->esq = NULL;
        a->dir = NULL;
        strcpy(a->cod,codaux);
    }
    else if (chave < (a->letra))
        a->esq = InsereABP(a->esq,chave, codaux);
    else
        a->dir = InsereABP(a->dir,chave, codaux);
    return a;
}

Morse* ler_morse (Morse *a)
{
    char ch;							//buffer para caractere lido no arquivo
    FILE *arq;
    arq = fopen("TabelaMorse.txt", "r");//abre o arquivo

    if (arq == NULL) 					//se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo tabela\n");
    }
    else
    {
        while( (ch=fgetc(arq))!= EOF )
        {
            fseek(arq,1* sizeof(char),SEEK_CUR); //incrementa ponteiro do arquivo para ignorar o TAB
            int cont = 0;
            char codaux[MAX];
            while(( (codaux[cont] = fgetc(arq)) != '\n') &&  codaux[cont]!= EOF )	//enquanto nao terminar a linha, guardar como o codigo morse
            {
                cont++;
            }
            codaux[cont]='\0';
            printf("%c|%s \n",ch,codaux);
            a=InsereABP(a,ch,codaux);
        }
        fclose(arq);
    }
    return a;
}

void copia_arquivo(Morse *a, int *comp)
{
    char ch;							     //buffer para caractere lido no arquivo
    FILE *arq_in, *arq_out;
    arq_in = fopen("godfather.txt", "r");    //abre o arquivo a ser convertido
    arq_out = fopen("saida.txt", "w");       //cria arquivo de saida

    printf(" primeira letra %c ",a->letra);    //testando se arvore a tem conteudo
    if (arq_in == NULL) 					    //se não conseguiu abrir
    {
        printf("Problemas na leitura do arquivo de entrada\n");
        return;
    }
    else
    {
        while( (ch = fgetc(arq_in)) != EOF)
        {
            Morse* novo;
            novo=InicializaABP();
            ch=remove_acento(ch);
            ch=toupper(ch);                       //minúsculo para maiúsculo
            novo=consulta(a,ch,comp);
            if(novo == NULL)
            {
                if(ch == 32)
                fputs("/", arq_out);
            }
            else{
                fputs(novo->cod, arq_out);
                fputs(" ", arq_out);
        }
        }
    }
    fclose(arq_in);
    fclose(arq_out);
}

Morse* consulta(Morse *a, char chave, int *comp)
{
    while (a!=NULL)
    {
        if (a->letra == chave )
        {
            comp++;
            return a; //achou então retorna o ponteiro para o nodo
        }
        else if (a->letra > chave)
        {
            comp++;
    return consulta(a->esq,chave,comp);
        }
        else
    return consulta(a->dir,chave,comp);
    }
    return NULL; //se não achou
}

char    remove_acento( char c)
{
    if( (192 <= c && c <= 197) || (224 <= c && c <= 229) )    return 'A';
    if( (200 <= c && c <= 203) || (232 <= c && c <= 235) )    return 'E';
    if( (204 <= c && c <= 207) || (236 <= c && c <= 239) )    return 'I';
    if( (210 <= c && c <= 214) || (242 <= c && c <= 246) )    return 'O';
    if( (217 <= c && c <= 220) || (249 <= c && c <= 252) )    return 'U';
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
