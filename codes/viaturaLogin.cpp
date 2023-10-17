#include <stdio.h>
#define maxPM 4
#define MAX 50

struct tViatura
{
    int codigo;

    int tipo; /* 1 = Policial Regular
                 2 = Policia Especializada */

    int estado; /* 0 = Neutro
                   1 = Livre
                   2 = Modo Ronda */

    int quantidadePM;

    char listaPM[maxPM];
};


void viaturaLogin(struct tViatura viatura[], int n) 
{
    int op;

    printf("\n Poilicia Regular - 1");
    printf("\n Poilicia Especializada - 2");
    
    printf("\n Selecione o tipo da aviatura: ");
    scanf("%d", &op);

    printf("\n Código da Viatura: ");
    scanf("%d", &viatura[n].codigo);
    
    printf("\n Quantidade de PMs: ");
    scanf("%d", &viatura[n].quantidadePM);

    if ((op == 1 && viatura[n].quantidadePM < 2 || viatura[n].quantidadePM > 4)
        || (op == 2 && viatura[n].quantidadePM != 4)) 
    {
        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs:");
        scanf("%d", &viatura[n].quantidadePM);
    }

}