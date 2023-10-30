#include "viaturaLogin.cpp"

int LoginPm(Policial *local){

    char usuario[26], senha[26];

    printf("\e[1;1H\e[2J");

    printf("Usuario:");
    scanf(" %s", usuario);

    printf("Senha:");
    scanf(" %s", senha);

    for(int i = 0; i < ammountofPoliceOfficers(); i++)
    {
        if(local[i].guerra == usuario){
            if (local[i].senha == senha){
                printf("Login Correto");
                return 0;
            }

            else{
                printf("Senha Incorreta");
                return 1;
            }
        }
    }
    
    printf("Login Inexistente");
    return 1;

}