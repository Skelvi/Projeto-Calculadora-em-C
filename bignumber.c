#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

int menorPotencia(int n){
    int x = 1;
    while (x<n){
        x = x << 1;
    }
    return x;
}

void checagemSinaisSoma(Bignumber *n1,Bignumber *n2){
    if(n1->sinal == '+' && n2->sinal == '+'){
        somao(n1,n2);
    }
    else if(n1->sinal == '+' && n2->sinal == '-'){
        subtracao(n1,n2);
    }
    else if(n1->sinal == '-' && n2->sinal == '+'){
        subtracao(n1,n2);
    }
    else if(n1->sinal == '-' && n2->sinal == '-'){
        somao(n1,n2);
    }
}

void checagemSinaisSub(Bignumber *n1,Bignumber *n2){
    if(n1->sinal == '+' && n2->sinal == '+'){
        n2->sinal = '-';
        subtracao(n1,n2);
    }
    else if(n1->sinal == '+' && n2->sinal == '-'){
        n2->sinal = '+';
        somao(n1,n2);
    }
    else if(n1->sinal == '-' && n2->sinal == '+'){
        n2->sinal = '-';
        somao(n1,n2);
    }
    else if(n1->sinal == '-' && n2->sinal == '-'){
        n2->sinal = '+';
        subtracao(n1,n2);
    }
}

void checagemSinaisMulti(Bignumber *n1, Bignumber *n2){
    int i;
    if(n1->sinal == '+' && n2->sinal == '+'){
        n1->sinal ='+';
        if(n1->digitos[0] == 1 && n1->tamanho == 1){
            for(i = (n2->tamanho-1); i >= 0;i--){
                printf("%d", n2->digitos[i]);
            }
        }
        else if(n2->digitos[0] == 1 && n2->tamanho == 1){
            for(i = (n1->tamanho-1); i >= 0;i--){
                printf("%d", n1->digitos[i]);
            }
        }
        else if((n1->digitos[0] == 0 && n1->tamanho == 1) || (n2->digitos[0] == 0 && n2->tamanho == 1)){
            printf("0");
        }
        else{
            multiplicacao(n1,n2);
        }
    }
    else if(n1->sinal == '+' && n2->sinal == '-'){
        n1->sinal ='-';
        if(n1->digitos[0] == 1 && n1->tamanho == 1){
            printf("-");
            for(i = (n2->tamanho-1); i >= 0;i--){
                printf("%d", n2->digitos[i]);
            }
        }
        else if(n2->digitos[0] == 1 && n2->tamanho == 1){
            printf("-");
            for(i = (n1->tamanho-1); i >= 0;i--){
                printf("%d", n1->digitos[i]);
            }
        }
        else if((n1->digitos[0] == 0 && n1->tamanho == 1) || (n2->digitos[0] == 0 && n2->tamanho == 1)){
            printf("0");
        }
        else{
            multiplicacao(n1,n2);
        }
    }
    else if(n1->sinal == '-' && n2->sinal == '+'){
        n1->sinal ='-';
        if(n1->digitos[0] == 1 && n1->tamanho == 1){
            printf("-");
            for(i = (n2->tamanho-1); i >= 0;i--){
                printf("%d", n2->digitos[i]);
            }
        }
        else if(n2->digitos[0] == 1 && n2->tamanho == 1){
            printf("-");
            for(i = (n1->tamanho-1); i >= 0;i--){
                printf("%d", n1->digitos[i]);
            }
        }
        else if((n1->digitos[0] == 0 && n1->tamanho == 1) || (n2->digitos[0] == 0 && n2->tamanho == 1)){
            printf("0");
        }
        else{
            multiplicacao(n1,n2);
        }
    }
    else if(n1->sinal == '-' && n2->sinal == '-'){
        n1->sinal ='+';
        if(n1->digitos[0] == 1 && n1->tamanho == 1){
            for(i = (n2->tamanho-1); i >= 0;i--){
                printf("%d", n2->digitos[i]);
            }
        }
        else if(n2->digitos[0] == 1 && n2->tamanho == 1){
            for(i = (n1->tamanho-1); i >= 0;i--){
                printf("%d", n1->digitos[i]);
            }
        }
        else if((n1->digitos[0] == 0 && n1->tamanho == 1) || (n2->digitos[0] == 0 && n2->tamanho == 1)){
            printf("0");
        }
        else{
            multiplicacao(n1,n2);
        }
    }
}

void tirar_zeros(Bignumber *n){
    int i, contador;
    contador = 0;
    for(i = (n->tamanho-1); n->digitos[i] == 0; i--){
        contador++;
    }
    contador = n->tamanho-contador;
    if(contador == 0){
        n->digitos = realloc(n->digitos, 1 * sizeof(int));
        if(n->digitos == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        n->tamanho = 1;
    }
    else{
        n->digitos = realloc(n->digitos, contador * sizeof(int));
        if(n->digitos == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        n->tamanho = contador;
    }
}

void criar_numerao(char *x, Bignumber *n){
    int i;
    if((x[0])=='-'){
        n->tamanho = strlen(x)-1;
        n->sinal = '-';
        n->digitos = malloc(n->tamanho*sizeof(int));
        if(n->digitos == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        for(i=1; i<=n->tamanho;i++){
            n->digitos[((n->tamanho)-i)]=x[i]-'0';
        }
    }
    else{
        n->tamanho = strlen(x);
        n->sinal = '+';
        n->digitos = malloc(n->tamanho*sizeof(int));
        if(n->digitos == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        for(i=0; i<n->tamanho;i++){
            n->digitos[((n->tamanho)-i)-1]=x[i]-'0';
        }
    }
}

void somao(Bignumber *n1,Bignumber *n2){
    int i, extra, sominha;
    tirar_zeros(n1);
    tirar_zeros(n2);
    extra = 0;
    if(n1->tamanho > n2->tamanho){
        n2->digitos=realloc(n2->digitos, n1->tamanho*sizeof(int));
        if(n2->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n2->tamanho; i < n1->tamanho; i++){
            n2->digitos[i] = 0;
        }
        for(i=0; i<n1->tamanho;i++){
            sominha = n1->digitos[i]+n2->digitos[i]+extra;
            if(sominha > 9){
                n1->digitos[i] = sominha % 10;
                extra = 1;
                if(i+1 == n1->tamanho){
                    n1->tamanho++;
                    n1->digitos=realloc(n1->digitos, n1->tamanho*sizeof(int));
                    n2->digitos=realloc(n2->digitos, n1->tamanho*sizeof(int));
                    n1->digitos[i+1] = 0;
                    n2->digitos[i+1] = 0;
                }
            }
            else{
                n1->digitos[i]= sominha;
                extra = 0;
            }
        }
        if(n1->sinal == '-'){
            printf("%c",n1->sinal);
        }
        for(i= (n1->tamanho-1); i >= 0;i--){
            printf("%d", n1->digitos[i]);
        }
        return;
    }
    if(n1->tamanho < n2->tamanho){
        n1->digitos=realloc(n1->digitos, n2->tamanho*sizeof(int));
        if(n1->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n1->tamanho; i < n2->tamanho; i++){
            n1->digitos[i] = 0;
        }
        n1->tamanho = n2->tamanho;
        for(i=0; i<n2->tamanho;i++){
            sominha = n2->digitos[i]+n1->digitos[i]+extra;
            if(sominha > 9){
                n1->digitos[i] = sominha % 10;
                extra = 1;
                if(i+1 == n2->tamanho){
                    n1->tamanho++;
                    n2->tamanho++;
                    n1->digitos=realloc(n1->digitos, n1->tamanho*sizeof(int));
                    n2->digitos=realloc(n2->digitos, n1->tamanho*sizeof(int));
                    n1->digitos[i+1] = 0;
                    n2->digitos[i+1] = 0;
                }
            }
            else{
                n1->digitos[i]= sominha;
                extra = 0;
            }
        }
        if(n2->sinal == '-'){
            printf("%c",n2->sinal);
        }
        for(i= (n1->tamanho-1); i >= 0;i--){
            printf("%d", n1->digitos[i]);
        }
        return;
    }
    if(n1->tamanho == n2->tamanho){
        for(i=0; i<n1->tamanho;i++){
            sominha = n1->digitos[i]+n2->digitos[i]+extra;
            if(sominha > 9){
                if((i+1)==n1->tamanho){
                    n1->tamanho++;
                    n1->digitos=realloc(n1->digitos, n1->tamanho*sizeof(int));
                    if(n1->digitos==NULL){
                        printf("Memoria insuficiente");
		                exit(1);
                    }  
                    n1->digitos[i] = sominha % 10;
                    n1->digitos[i+1] = 1;
                    break;
                }
                else{
                    n1->digitos[i] = sominha % 10;
                    extra = 1;
                }
            }
            else{
                n1->digitos[i]= sominha;
                extra = 0;
            }
        }
        if(n1->sinal == '-'){
            printf("%c",n1->sinal);
        }
        for(i= (n1->tamanho-1); i >= 0;i--){
            printf("%d", n1->digitos[i]);
        }
        return;
    }  
}

void subtracao(Bignumber *n1, Bignumber *n2){
    int i, sub, extra;
    tirar_zeros(n1);
    tirar_zeros(n2);
    extra = 0;
    if(n1->tamanho > n2->tamanho){
        n2->digitos=realloc(n2->digitos, n1->tamanho*sizeof(int));
        if(n2->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n2->tamanho; i < n1->tamanho; i++){
            n2->digitos[i] = 0;
        }
        for(i = 0; i < n1->tamanho; i++){
            sub = n1->digitos[i] - n2->digitos[i] - extra;
            if(sub<0){
                sub += 10;
                n1->digitos[i] = sub;
                extra = 1;
            }
            else{
                extra = 0;
                n1->digitos[i] = sub;   
            }
        }
        if(n1->digitos[n1->tamanho-1]==0){
            tirar_zeros(n1);
        }
        if(n1->sinal == '-'){
            printf("%c",n1->sinal);
        }
        for(i= (n1->tamanho-1); i >= 0;i--){
            printf("%d", n1->digitos[i]);
        }
        return;
    }
    if(n1->tamanho < n2->tamanho){
        n1->digitos=realloc(n1->digitos, n2->tamanho*sizeof(int));
        if(n1->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n1->tamanho; i < n2->tamanho; i++){
            n1->digitos[i] = 0;
        }
        n1->tamanho = n2->tamanho;
        for(i=0; i<n2->tamanho;i++){
            sub = n2->digitos[i] - n1->digitos[i] - extra;
            if(sub < 0){
                sub+= 10;
                n1->digitos[i] = sub;
                extra = 1;
            }
            else{
                n1->digitos[i]= sub;
                extra = 0;
            }
        }
        if(n1->digitos[n1->tamanho-1]==0){
            tirar_zeros(n1);
        }
        if(n2->sinal == '-'){
            printf("%c",n2->sinal);
        }
        for(i= (n1->tamanho-1); i >= 0;i--){
            printf("%d", n1->digitos[i]);
        }
        return;
    }
    if(n1->tamanho == n2->tamanho){
        for(i=1; i <= n1->tamanho; i++){
            if((n1->digitos[n1->tamanho-i])<(n2->digitos[n2->tamanho-i])){
                for(i=0; i<n1->tamanho;i++){
                    sub = n2->digitos[i] - n1->digitos[i] - extra;
                    if(sub < 0){
                        sub+= 10;
                        n1->digitos[i] = sub;
                        extra = 1;
                    }
                    else{
                        n1->digitos[i]= sub;
                        extra = 0;
                    }
                }
                if(n1->digitos[n1->tamanho-1]==0){
                    tirar_zeros(n1);
                }
                if(n2->sinal == '-'){
                    printf("%c",n2->sinal);
                }
                for(i= (n1->tamanho-1); i >= 0;i--){
                    printf("%d", n1->digitos[i]);
                }
                return;
            }
            if((n1->digitos[n1->tamanho-i])>(n2->digitos[n2->tamanho-i])){
                for(i=0; i<n1->tamanho;i++){
                    sub = n1->digitos[i] - n2->digitos[i] - extra;
                    if(sub < 0){
                        sub+= 10;
                        n1->digitos[i] = sub;
                        extra = 1;
                    }
                    else{
                        n1->digitos[i]= sub;
                        extra = 0;
                    }
                }
                if(n1->sinal == '-'){
                    printf("%c",n1->sinal);
                }
                if(n1->digitos[n1->tamanho-1]==0){
                    tirar_zeros(n1);
                }
                for(i= (n1->tamanho-1); i >= 0;i--){
                    printf("%d", n1->digitos[i]);
                }
                return;
            }
        }
        printf("0");
    }
}

void multiplicacao(Bignumber *n1, Bignumber *n2){
    int i, maximo;
    tirar_zeros(n1);
    tirar_zeros(n2);
    if(n1->tamanho > n2->tamanho){
        maximo = menorPotencia(n1->tamanho);
        n2->digitos=realloc(n2->digitos, maximo*sizeof(int));
        if(n2->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n2->tamanho; i < maximo; i++){
            n2->digitos[i] = 0;
        }
        n1->digitos=realloc(n1->digitos, maximo*sizeof(int));
        if(n1->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n1->tamanho; i < maximo; i++){
            n1->digitos[i] = 0;
        }
        int *resultados = calloc((6*maximo),sizeof(int));
        if(resultados == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        karatsuba(n1->digitos,n2->digitos,resultados,maximo);
        int a = maximo*2;
        resto(resultados, a);
        for(i = a-1;i>0;i--){
            if(resultados[i] != 0){
                break;
            }
        }
        if(i == 0 && resultados[0] == 0){
            printf("0");
        }
        else{
            if(n1->sinal == '-'){
                printf("%c",n1->sinal);
            }
            for(;i>=0;i--){
                printf("%d",resultados[i]);
            }
        }
        free(resultados);
    }
    else if(n1->tamanho < n2->tamanho){
        maximo = menorPotencia(n2->tamanho);
        n1->digitos=realloc(n1->digitos, maximo*sizeof(int));
        if(n1->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n1->tamanho; i < maximo; i++){
            n1->digitos[i] = 0;
        }
        n2->digitos=realloc(n2->digitos, maximo*sizeof(int));
        if(n2->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n2->tamanho; i < maximo; i++){
            n2->digitos[i] = 0;
        }
        n1->tamanho = n2->tamanho;
        int *resultados = calloc((6*maximo),sizeof(int));
        if(resultados == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        karatsuba(n1->digitos,n2->digitos,resultados,maximo);
        int a = maximo*2;
        resto(resultados, a);
        for(i = a-1;i>0;i--){
            if(resultados[i] != 0){
                break;
            }
        }
        if(i == 0 && resultados[0] == 0){
            printf("0");
        }
        else{
            if(n1->sinal == '-'){
                printf("%c",n1->sinal);
            }
            for(;i>=0;i--){
                printf("%d",resultados[i]);
            }
        }
        free(resultados);
    }
    else{
        maximo = menorPotencia(n2->tamanho);
        n1->digitos=realloc(n1->digitos, maximo*sizeof(int));
        if(n1->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n1->tamanho; i < maximo; i++){
            n1->digitos[i] = 0;
        }
        n2->digitos=realloc(n2->digitos, maximo*sizeof(int));
        if(n2->digitos==NULL){
            printf("Memoria insuficiente");
		    exit(1);
        }
        for(i = n2->tamanho; i < maximo; i++){
            n2->digitos[i] = 0;
        }
        int *resultados = calloc((6*maximo), sizeof(int));
        if(resultados == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        karatsuba(n1->digitos,n2->digitos,resultados,maximo);
        int a = maximo*2;
        resto(resultados, a);
        for(i = a-1;i>0;i--){
            if(resultados[i] != 0){
                break;
            }
        }
        if(i == 0 && resultados[0] == 0){
            printf("0");
        }
        else{
            if(n1->sinal == '-'){
                printf("%c",n1->sinal);
            }
            for(;i>=0;i--){
                printf("%d",resultados[i]);
            }
        }
        free(resultados);
    }
}

void karatsuba(int *n1, int *n2, int *resultados,int tamanho){
    int i;
    int m = tamanho/2;
    int *p = &n1[0];
    int *q = &n1[m];
    int *r = &n2[0];
    int *s = &n2[m];
    int *somaA = &resultados[tamanho*5];
    int *somaB = &resultados[tamanho*5 + m];
    int *x1 = &resultados[tamanho*0];
    int *x2 = &resultados[tamanho*1];
    int *x3 = &resultados[tamanho*2];
    if(tamanho <= 4){
        multiplicacaoLonga(n1,n2,resultados,tamanho);
        return;
    }
    for(i = 0; i < m; i++){
        somaA[i] = p[i]+q[i];
        somaB[i] = r[i]+s[i];
    }
    karatsuba(p,r,x1,m);
    karatsuba(q,s,x2,m);
    karatsuba(somaA,somaB,x3,m);
    for(i = 0; i< tamanho; i++){
        x3[i]=x3[i]-x1[i]-x2[i];
    }
    for(i = 0; i< tamanho; i++){
        resultados[i+m] += x3[i];
    }
}

void multiplicacaoLonga(int *n1, int *n2, int *resultados, int tamanho){
    int i, j;
    for(i=0; i< 2*tamanho; i++){
        resultados[i]=0;
    }
    for(i=0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            resultados[i+j] += n1[i] * n2[j];
        }
    }
}

void resto(int *resultado,int tamanho){
    int  i, resto;
    resto = 0;
    for(i=0; i < tamanho;i++){
        resultado[i] += resto;
        if(resultado[i]<0){
            resto = -(-(resultado[i]+1)/10+1);
        }
        else{
            resto = resultado[i]/10;
        }
        resultado[i] -= resto *10;
    }
}