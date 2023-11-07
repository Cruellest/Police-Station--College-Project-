#ifndef STRUCTS_H
#include "structs.h"
#endif
#include <stdio.h>
#include <string.h>
#ifndef LOADER_H
#include "Loader.h"
#endif

int LoginPm(Policial *local){

    char usuario[26], senha[26];

    printf("\e[1;1H\e[2J");

    printf("Usuario: ");
    scanf(" %s", usuario);

    printf("Senha: ");
    scanf(" %s", senha);

    for(int i = 0; i < ammountofPoliceOfficers(); i++)
    {
        if(strcmp(local[i].guerra,usuario) == 0){
            if (strcmp(local[i].senha,senha) == 0){
                printf("Login Correto\n");
                getchar();
                getchar();
                printf("\e[1;1H\e[2J");
                local[i].logado = 1;
                return i;
            }

            else{
                printf("Senha Incorreta\n");
                getchar();
                getchar();
                printf("\e[1;1H\e[2J");
                return -1;
            }
        }
        
    }
    printf("Login Inexistente\n");
    getchar();
    getchar();
    printf("\e[1;1H\e[2J");
    return -1;
    }

int menuPM (Policial *local){
    int op;
    printf("Menu PM (WIP)\n");
    printf("1 - Visualizar ocorrencias sem boletim\n2 - Escrever boletim de ocorrencia\nOpção: ");
    scanf(" %d",&op);

    switch (op)
    {
    case 1:
        for (int i = 0; i < ammountofPoliceOfficers(); i++)
        {
            printf("Just a place holder \n");
        }
        
    
        
    
    default:
        break;
    }
    return 0;
}