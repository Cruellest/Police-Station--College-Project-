#include <stdio.h>
#include  "Loader.cpp"
#define MAX 50

void viaturaLogin(struct tViatura viatura[], int n) 
{
    int op;

    printf("\n Policia Regular - 1");
    printf("\n Policia Especializada - 2");
    
    printf("\n Selecione o tipo da aviatura: ");
    scanf("%d", &op);

    printf("\n Código da Viatura: ");
    scanf("%d", &viatura[n].codigo);
    
    printf("\n Quantidade de PMs: ");
    scanf("%d", &viatura[n].quantidadePM);

    for(;(op == 1 && viatura[n].quantidadePM < 2) || (viatura[n].quantidadePM > 4)
        || (op == 2 && viatura[n].quantidadePM != 4);){

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf("%d", &viatura[n].quantidadePM);
    }

}