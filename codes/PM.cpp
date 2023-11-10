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

int menuPM (Policial *local,int officer,listaChamada *localchamadas){
    int op;
    printf("Menu PM (WIP)\n");
    printf("1 - Visualizar ocorrencias sem boletim\n2 - Escrever boletim de ocorrencia\nOpção: ");
    scanf(" %d",&op);

    switch (op)
    {
    case 1:

        if(localchamadas == NULL)
        {
            printf("Não existem ocorrencias\n");
            break;
        }
        else{
            for(listaChamada* i = localchamadas; i == NULL; i = i->prox){
            if(i->chamada.estado == 3 && i->chamada.Boletim == false){
                for (int j = 0; j < 4; j++)
                {
                    if (strcmp(local[officer].guerra,i->chamada.policiais[j])==0)
                    {
                        printf("%s\n",i->chamada.descricao);
                        printf("%s\n\n",i->chamada.loc);
                    }
                    
                }
                
            }    
            }
        break;
        }

        
        
    
    default:
        break;
    }
    return 0;
}