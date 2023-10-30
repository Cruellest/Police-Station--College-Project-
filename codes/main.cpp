#include <stdio.h>
#include "viaturaLogin.cpp"

int main(int argc, const char** argv){

    /*
    op = opção;
    */
    int op;

    //This piece of code dynamicaly alocates all the files arrays and load the data from the files
    Viatura *viatura = (Viatura*) calloc(amountofViaturas(),sizeof(Viatura));
    loadViaturas(viatura);
    Policial *policiais = (Policial*) calloc(ammountofPoliceOfficers(),sizeof(Policial));
    loadPoliceOfficers(policiais);
    

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
            viaturaLogin(viatura, 10);
           
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