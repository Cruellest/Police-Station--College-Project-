#include <stdio.h>
#include "viaturaLogin.cpp"

int main(){

    /*
    op = opção;
    */
    int op;

    //This piece of code dynamicaly alocates all the files arrays and load the data from the files
    tViatura *viatura = (tViatura*) calloc(amountofViaturas(),sizeof(tViatura));
    loadViaturas(viatura);
    Policiais *policiais = (Policiais*) calloc(ammountofPoliceOfficers(),sizeof(Policiais));
    loadPoliceOfficers(policiais);

    //Meu amor comenta aqui por favor te amo S2 <3
    tViaturaLogin *i, *f;
    i = NULL;   
    f = NULL;
    
    //(WIP) UI for menu
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
            //loads functions from Viatura Login
            viaturaLogin(viatura, i, f);
            //PFV EXPLICA ISSO TBM LINDA TE AMO
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

    free(policiais);
    free(viatura);
    return 0;
}