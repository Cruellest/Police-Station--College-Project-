#include "viaturaLogin.cpp"

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

