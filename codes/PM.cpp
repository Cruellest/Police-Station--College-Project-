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
    int op = -1;

    while(op != 0){
    printf("\e[1;1H\e[2J");
    printf("SPM - Menu PM\n");
    printf("1 - Visualizar ocorrencias sem boletim\n2 - Escrever boletim de ocorrencia\n0 - Voltar ao menu\nOpção: ");
    scanf(" %d",&op);

    switch (op)
    {
    case 1:

        if(localchamadas == NULL)
        {
            printf("Não existem ocorrencias\n");
            getchar();
            getchar();
            break;
        }
        else{
            printf("\e[1;1H\e[2J");
            for(listaChamada *i = localchamadas; i != NULL; i = i->prox){
            if(i->chamada.estado == 3 && i->chamada.Boletim == false){
                printf("Ocorrencias sem Boletins\n\n");
                for (int j = 0; j < 4; j++)
                {
                    if (strcmp(local[officer].guerra,i->chamada.policiais[j])==0)
                    {
                        printf("Codigo: %d\n",i->chamada.codigo);
                        printf("Descrição: %s\n",i->chamada.descricao);
                        printf("Localização: %s\n\n",i->chamada.loc);

                        printf("Boletim: %s\n",i->chamada.Boletim ? "Existente" : "Inexistente");
                    }
                    
                }
                printf("\nPressione enter");
                getchar();
                getchar();
            }    
            }
        break;
        }

    case 2:



        if(localchamadas == NULL)
        {
            printf("Não existem ocorrencias\n");
            getchar();
            getchar();
            break;
        }

        else{
            int codigo;
            printf("Por favor digite o Codigo\n");
            scanf(" %d",&codigo);

            for (listaChamada *i = localchamadas; i != NULL;i = i->prox)
            {
                if((i->chamada.codigo == codigo) &&  (i->chamada.Boletim == false)){

                    printf("Digite o texto do Boletim: \n");
                    scanf(" %[^\n]",i->chamada.BoletimTexto);
                    i->chamada.Boletim = true;

                }
            }
            
        } 
    
    default:
        break;
    }
    }
    printf("\e[1;1H\e[2J");
    return 0;
}