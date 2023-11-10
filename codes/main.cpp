#include <stdio.h>
#include<stdlib.h>
#ifndef PM_H
#include "PM.h"
#endif
#ifndef LOADER_H
#include "Loader.h"
#endif
#include "viaturaLogin.cpp"
#ifndef COPOM_H
#include "COPOM.h"
#endif
#include "Oficial.h"
#include "Commandante.h"

int main(){

    /*
    op = opção;
    */
    int op;
    
    

    //This piece of code dynamicaly alocates all the files arrays and load the data from the files
    Viatura *viaturas = (Viatura*) calloc(amountofViaturas(),sizeof(Viatura));
    loadViaturas(viaturas);
    Policial *policiais = (Policial*) calloc(ammountofPoliceOfficers(),sizeof(Policial));
    loadPoliceOfficers(policiais);
    Pessoa *pessoas = (Pessoa*) calloc(amountofpeople(),sizeof(Pessoa));
    loadPeople(pessoas);


    int sizeEspecial = 1;
    especialViatura *especiais = (especialViatura *) calloc(sizeEspecial,sizeof(especialViatura));
    
    int sizeRegular = 1;
    regularViatura *regulares = (regularViatura *) calloc(sizeRegular,sizeof(regularViatura));

    listaChamada *chamadas;
    chamadas = NULL;

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
            viaturaLogin(viaturas, amountofViaturas(), regulares, sizeRegular, especiais, sizeEspecial, chamadas);
        }
        else if(op == 2) //Viatura em Uso
        {

        }

        else if(op == 3) //COPOM
        {
            cadastrarChamada(chamadas, regulares, especiais);
        }
        else if(op == 4) //Policial Militar
        {   
            int LogTry = LoginPm(policiais);
            if(LogTry != -1){
                menuPM(policiais);
            }

        }
        else if(op == 5) //Oficial
        {
            officerLogin(policiais);

        }
        else if(op == 6) //Comandante Geral
        {
            CommanderLogin(policiais);

        }

        else if(op == 2208)
        {
            int opdeb = 0;
            
            printf("\n1 - Decrypt Password\n2 - Print Police Struct Array POS\n3 - Print Viatura Struct Array POS\n4 - Print Ammount of Officers\n5 - Print Ammount of Viaturas\n6 - Print regularViatura Struct Array\n7 - Print especialViatura Array\n8 - Print chamadas Array\n9 - Print Amount of People\n10 - Print pessoas array\n");
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
                printf("%d\n",policiais[POS].logado);
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

            else if(opdeb == 6){
                int POS = 0;

                printf("\nArray POS\n");
                scanf(" %d", &POS);

                printf("\nCodigo: %d\n",regulares[POS].viatura->codigo);
                printf("Quantidade de chamadas: %d\n", regulares[POS].qntChamadas);

                listaChamada *copia;

                copia = regulares[POS].listaChamadas;

                if (copia != NULL)
                {
                    while(copia->prox != NULL)
                    {
                        printf("%s", copia->chamada.descricao);
                        copia = copia->prox;
                    }
                    printf("%s", copia->chamada.descricao);

                    getchar();
                    getchar();
                } else {
                    printf("\nSem chamadas.");
                }
            } else if (opdeb == 8){
                listaChamada *copia = chamadas;


                if (copia != NULL)
                {
                    while(copia->prox != NULL)
                    {
                        printf("%s", copia->chamada.descricao);
                        copia = copia->prox;
                    }
                    printf("%s", copia->chamada.descricao);
                } else {
                    printf("Sem chamadas.");
                }
            }

        
        else if (opdeb == 9){
                printf("%d\n",amountofpeople());
            }

         else if (opdeb == 10){
            int POS = 0;

                printf("\nArray POS\n");
                scanf(" %d", &POS);

                printf("\n%s\n",pessoas[POS].nome);
                printf("%ld\n",pessoas[POS].cpf);
                printf("%s\n",pessoas[POS].cidade);
                printf("%d\n",pessoas[POS].idade);
                printf("%d\n",pessoas[POS].numPassagens);
                for (int i = 0; i < pessoas[POS].numPassagens; i++)
                {
                printf("%s\n",pessoas[POS].passagens[i]);
                }
                printf("%d\n",pessoas[POS].numInadimplencias);
                for (int i = 0; i < pessoas[POS].numInadimplencias; i++)
                {
                printf("%s\n",pessoas[POS].inadimplencias[i]);
                }
                getchar();
                getchar();
            }


        }
    

    }while(0 != op);

    free(pessoas);
    free(policiais);
    free(viaturas);
    return 0;
}
