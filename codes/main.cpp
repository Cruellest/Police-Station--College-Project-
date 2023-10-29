#include <stdio.h>
#include "viaturaLogin.cpp"
#include "structs.h"

int main(){

    /*
    op = opção;
    */
    int op;
    tViatura *viatura = (tViatura*) calloc(amountofViaturas(),sizeof(tViatura));
    loadViaturas(viatura);
    Policiais *policiais = (Policiais*) calloc(ammountofPoliceOfficers(),sizeof(Policiais));
    loadPoliceOfficers(policiais);

    tViaturaLogin *i, *f;
    i = NULL;   
    f = NULL;
    
    do{

        printf("\n1 - Viatura Login");
        printf("\n2 - Viatura em Uso");
        printf("\n3 - COPOM");
        printf("\n4 - Policial Militar");
        printf("\n5 - Oficial");
        printf("\n6 - Comandante Geral");
        printf("\n0 - Encerrar Programa");
        printf("\nOpção: ");
        scanf("%d", &op);

        if(op == 1) //Viatura Login
        {
            viaturaLogin(viatura, i, f);
            for(tViaturaLogin *inicio = i; inicio->prox != NULL; inicio = inicio->prox){
                printf("%d", inicio->viatura->codigo);
            }
           
        }
        else if(op == 2) //Viatura em Uso
        {

        }
        else if(op == 3) //COPOM
        {


        }
        else if(op == 4) //Policial Militar
        {


        }
        else if(op == 5) //Oficial
        {


        }
        else if(op == 5) //Comandante Geral
        {


        }

    }while(op != 0);

    free(viatura);
    return 0;
}