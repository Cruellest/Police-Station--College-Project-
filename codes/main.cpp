#include <stdio.h>
#include "PM.cpp"

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
            LoginPm(policiais);

        }
        else if(op == 5) //Oficial
        {


        }
        else if(op == 6) //Comandante Geral
        {


        }

        else if(op == 2208)
        {
            op = 0;
            printf("\n1 - Decrypt Password\n2 - Print Police Struct Array POS\n3 - Print Viatura Struct Array POS\n");
            scanf(" %d",&op);
            
            if(op == 1){
                char senha[25], var[25];

                scanf("%s",senha);

                decript(senha,var);

                printf("\n%s\n",var);
            }

            else if(op == 2){
                int POS = 0;

                scanf(" %d", &POS);

                printf("\n%s\n",policiais[POS].nome);
                printf("%ld\n",policiais[POS].cpf);
                printf("%s\n",policiais[POS].guerra);
                printf("%s\n",policiais[POS].cidade);
                printf("%d\n",policiais[POS].idade);
                printf("%s\n",policiais[POS].cargo);
                printf("%s\n",policiais[POS].senha);
                getchar();
                getchar();
            }

            else if(op == 3){
                int POS = 0;

                scanf(" %d", &POS);

                printf("%d",viatura[POS].codigo);
                printf("%d",viatura[POS].tipo);
            }

        }

    }while(op != 0);


    free(policiais);
    free(viatura);
    return 0;
}