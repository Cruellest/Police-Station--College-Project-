#ifndef STRUCTS_H
#include "structs.h"
#endif

#ifndef PM_H
#include "PM.h"
#endif

#include <stdio.h>

int officerLogin(Policial *local,listaChamada *localchamadas){
    
    int Policial = LoginPm(local);

    if (Policial == -1){
        return -1;

    }

    else{
        if((strcmp(local[Policial].cargo,"Oficial") == 0) || (strcmp(local[Policial].cargo,"Comandante Geral") == 0)){
            
            int op = -1;

            while (op != 0)
            {
                printf("SPM - Menu Oficial\n");
                printf("1 - Excluir Boletim de Ocorrencia\n2 - Gerar Relatorio Oficial\n0 - Voltar ao menu\nOpções: ");
                scanf(" %d",&op);

                switch (op)
                {
                case 1: 

                    int codigo;
                    if(localchamadas == NULL)
                    {
                        printf("Não existem ocorrencias\n");
                        getchar();
                        getchar();
                        break;
                    }
                    else{
                        for(listaChamada *i = localchamadas; i != NULL; i = i->prox){
                        if(i->chamada.estado == 3 && i->chamada.Boletim == true){
                            printf("\e[1;1H\e[2J");
                            printf(" Ocorrencias com Boletins\n");

                                    printf("Codigo: %d\n",i->chamada.codigo);
                                    printf("Descrição: %s\n",i->chamada.descricao);
                                    printf("Localização: %s\n\n",i->chamada.loc);

                                    printf("Boletim: %s\n",i->chamada.Boletim ? "Existente" : "Inexistente");
                                    printf("Texto do Boletim: %s",i->chamada.BoletimTexto);

                        }    
                        }
                                

                            printf("\nDigite o codigo do Boletim que voce deseja excluir: ");
                            scanf(" %d",&codigo);

                            for(listaChamada *i = localchamadas; i != NULL; i = i->prox){
                            if(i->chamada.codigo == codigo && i->chamada.Boletim == true){
                                i->chamada.Boletim = false;
                                strcpy(i->chamada.BoletimTexto,""); 
                            }}

                            printf("Boletim Excluido com sucesso\n");
                            
                            getchar();
                            getchar();
                            printf("\e[1;1H\e[2J");
                    break;
                    }                

                    case 2:

                    FILE *relatorio;

                    relatorio = fopen("relatorio_oficial.txt","w");

                    fprintf(relatorio,"Policiais\n");                    


                    break;

                
                default:
                    break;
                }
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