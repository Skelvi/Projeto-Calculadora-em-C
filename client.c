#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

int main(){
    char *x, *y, c, operacao;
    c = ' ';
    int i, MAX;
    while(c != EOF){
        MAX = 500;
        c = EOF;
        i=0;
        x = malloc(MAX * sizeof(char));
        if(x == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        y = malloc(MAX * sizeof(char));
        if(y == NULL){
            printf("Memoria insuficiente");
            exit(1);
        }
        Bignumber n1,n2;
        while (c != '\n'){
            c = getc(stdin);
            if (c == EOF){
                break;
            }
            i++;
            if(i == MAX){
                MAX += 500;
                x = realloc(x, MAX * sizeof(char));
                if(x == NULL){
                    printf("Memoria insuficiente");
                    exit(1);
                }
            }
            x[i-1]=c;
        }
        if (c == EOF){
                break;
        }
        x[strcspn(x,"\n")] = 0;
        x[i]='\0';
        criar_numerao(x, &n1);
        MAX = 500;
        i = 0;
        c = EOF;
        while (c != '\n'){
            c = getc(stdin);
            i++;
            if(i == MAX){
                MAX += 500;
                y = realloc(y, MAX * sizeof(char));
                if(x == NULL){
                    printf("Memoria insuficiente");
                    exit(1);
                }
            }
            y[i-1]=c;
        }
        y[strcspn(y,"\n")] = 0;
        y[i]='\0';
        criar_numerao(y, &n2);
        scanf("%c",&operacao);
        getchar();
        if(operacao == '+'){
            checagemSinaisSoma(&n1,&n2);
        }
        else if(operacao == '-'){
            checagemSinaisSub(&n1,&n2);
        }
        else if(operacao == '*'){
            checagemSinaisMulti(&n1,&n2);
        }
        else{
            exit(1);
        }
        free(n1.digitos);
        free(n2.digitos);
        free(x);
        free(y);
        printf("\n");
    }
    free(x);
    free(y);
    return 0;
}