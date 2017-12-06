struct TNodoA{
    int numero;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

#define MAX 10

struct AlfabetoMorse{
    char letra;
    struct AlfabetoMorse *ant;
    struct AlfabetoMorse *pos;
    char *cod[];
};
typedef struct AlfabetoMorse Morse;

void ler_morse ();
pNodoA* consulta(pNodoA *a, int chave);
