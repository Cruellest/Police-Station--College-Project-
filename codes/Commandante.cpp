#include <stdio.h>
#ifndef STRUCTS_H
#include "structs.h"
#endif
#ifndef PM_H
#include "PM.h"
#endif

int CommanderLogin(Policial *local,listaChamada *localchamadas){
    
    int Policial = LoginPm(local);

    if (Policial == -1){
        return -1;

    }

    else{
        if((strcmp(local[Policial].cargo,"Comandante Geral") == 0)){
            
            int op = -1;

            printf("Menu Comandante Geral (WIP)\n");
            printf("1 - Gerar Oficio de Ocorrencias\nOpções: ");
            scanf(" %d",&op);

            switch (op)
            {
            case 1: 

                FILE *oficio;

                oficio = fopen("oficio_ocorrencias.txt", "w");

                if(oficio == NULL){
                    printf("Criação do Oficio Falhou\n");
                    return -1;
                }

                else{
                    fputs("Ocorrencias - \n",oficio);

                    for(listaChamada *i = localchamadas; i != NULL; i = i->prox){
                        fprintf(oficio,"Tipo Policia: %d\n",i->chamada->tipo);
                        fprintf(oficio,"Descrição %s - Localização %s\n",i->chamada->descricao,i->chamada->loc);
                        fprintf(oficio,"Policiais:");
                        for (int j = 0; j < 4; j++)
                        {
                            fprintf(oficio," %s",i->chamada->policiais[j]);
                        }

                        fprintf(oficio,"\n");
                        

                    }
                }

                printf("Oficio Gerado\n");

                fclose(oficio);
                getchar();
                getchar();
                break;
            
            default:
                break;
            }
        }

        else{
        printf("Você não possui Permissão para acessar essa opção\n");
        getchar();
        printf("\e[1;1H\e[2J");
        }
    }
    
    return 0;
}