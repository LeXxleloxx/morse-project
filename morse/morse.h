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


Morse* InicializaABP(void);
Morse* InsereABP(Morse *a, int chave);
void ler_morse (Morse a);
Morse* consulta(Morse *a, int chave);