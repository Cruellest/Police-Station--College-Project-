#include <stdio.h>
#include  "Loader.cpp"
#define MAX 50

void viaturaLogin(struct tViatura *viatura, int n) 
{
    int op;
    int viaturacode,quantidadePM;
    char nome[8][26];

    printf("\n Policia Regular - 1");
    printf("\n Policia Especializada - 2");
    
    printf("\n Selecione o tipo da aviatura: ");
    scanf(" %d", &op);

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturacode);
    
    printf("\n Quantidade de PMs: ");
    scanf(" %d", &quantidadePM);

    for(;(op == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (op == 2 && quantidadePM != 4);){

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf(" %d",&quantidadePM);
    }

    printf("\nIdentificação dos PMs: ");

    for (int i = 0; i < quantidadePM; i++)
    {
    scanf(" %[^\n]",nome[i]);
    }

}