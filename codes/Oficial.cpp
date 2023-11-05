#include "PM.cpp"

int officerLogin(Policial *local){
    
    int Policial = LoginPm(local);

    if (Policial == -1){
        return -1;

    }

    else{
        if((strcmp(local[Policial].cargo,"Oficial") == 0) || (strcmp(local[Policial].cargo,"Comandante Geral") == 0)){
            
            int op = -1;

            printf("Menu Oficial (WIP)\n");
            printf("1 - Excluir Boletim de Ocorrencia\n2 - Gerar Relatorio Oficial\nOpções: ");
            scanf(" %d",&op);

            switch (op)
            {
            case 1: 
                printf("Just a Place Holder\n");
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