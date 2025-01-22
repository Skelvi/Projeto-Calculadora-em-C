#ifndef bignumber
#define bignumber

typedef struct 
{
    int tamanho;
    char sinal;
    int *digitos;
} Bignumber;

void tirar_zeros(Bignumber*);
void somao(Bignumber*, Bignumber*);
void criar_numerao(char*, Bignumber*);
void subtracao(Bignumber*, Bignumber*);
void multiplicacao(Bignumber*, Bignumber*);
void karatsuba(int*, int*, int*, int);
void multiplicacaoLonga(int*, int*, int*, int);
void resto(int*, int);
void checagemSinaisSoma(Bignumber*, Bignumber*);
void checagemSinaisSub(Bignumber*, Bignumber*);
void checagemSinaisMulti(Bignumber*, Bignumber*);
int menorPotencia(int);

#endif