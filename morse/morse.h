#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct TNodoA{
    int numero;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;


struct AlfabetoMorse{
    char letra;
    struct AlfabetoMorse *esq;
    struct AlfabetoMorse *dir;
    char cod[MAX];
};
typedef struct AlfabetoMorse Morse;


Morse* InicializaABP(void);
Morse* InsereABP(Morse *a, int chave, char codaux);
void ler_morse (Morse* a);
Morse* consulta(Morse *a, int chave,int *comp);
void copia_arquivo(Morse *a, int *comp);
char remove_acento( char c);
void ImprimePreFix(Morse *a);
