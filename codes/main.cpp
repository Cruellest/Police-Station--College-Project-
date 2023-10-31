#include <stdio.h>
#include "PM.cpp"

int main(){

    /*
    op = opção;
    */
    int op = NULL;
    
    

    //This piece of code dynamicaly alocates all the files arrays and load the data from the files
    Viatura *viaturas = (Viatura*) calloc(amountofViaturas(),sizeof(Viatura));
    loadViaturas(viaturas);
    Policial *policiais = (Policial*) calloc(ammountofPoliceOfficers(),sizeof(Policial));
    loadPoliceOfficers(policiais);
    
    int size = amountofViaturas();

    int sizeEspecial = 1;
    especialViatura *especiais =(especialViatura *) calloc(sizeEspecial,sizeof(especialViatura));
    
    int sizeRegular = 1;
    regularViatura *regulares = (regularViatura *) calloc(sizeRegular,sizeof(regularViatura));

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
            viaturaLogin(viaturas, amountofViaturas(), regulares, sizeRegular, especiais, sizeEspecial);
            for(int i = 0; i < sizeRegular; i++) {
                printf("%d", regulares[i].viatura->codigo);
            }
            for(int i = 0; i < sizeRegular; i++) {
                printf("%d", especiais[i].viatura->codigo);
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
            int opdeb = 0;
            
            printf("\n1 - Decrypt Password\n2 - Print Police Struct Array POS\n3 - Print Viatura Struct Array POS\n4 - Print Ammount of Officers\n5 - Print Ammount of Viaturas\n");
            scanf(" %d",&opdeb);
            
            if(opdeb == 1){
                char senha[25], var[25];

                scanf("%s",senha);

                decript(senha,var);

                printf("\n%s\n",var);
            }

            else if(opdeb == 2){
                int POS = 0;

                printf("\nArray POS\n");
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

            else if(opdeb == 3){
                int POS = 0;

                printf("\nArray POS\n");
                scanf(" %d", &POS);

                printf("\nCodigo: %d\n",viaturas[POS].codigo);
                printf("Tipo: %d\n",viaturas[POS].tipo);
                getchar();
                getchar();
            }

            else if(opdeb == 4){
                printf("%d\n",ammountofPoliceOfficers());
                getchar();
                getchar();
            }

            else if(opdeb == 5){
                printf("%d\n",amountofViaturas());
                getchar();
                getchar();
            }

        }

    }while(0 != op);

    free(policiais);
    free(viaturas);
    return 0;
}