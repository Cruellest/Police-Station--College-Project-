//This file is used to store the loader for all the structs that
//need to be loaded from a file

#include <stdio.h>
#include <stdlib.h> //This includes need to be optimized
#include <string.h>
#include "structs.h"

//Function used to load the app data from a txt file
int loadViaturas(tViatura *local){

    FILE *viaturas;

    viaturas = fopen("viaturas.txt","r");
    if(viaturas == NULL){
        fclose(viaturas);
        return -1;
    }


    int i = 0;
    while(feof(viaturas) == 0){

        fscanf(viaturas,"%d",&local[i].codigo);
        char holder[16];
        fscanf(viaturas,"%s",holder);
        if(strcmp(holder,"especializada") == 0){
            local[i].tipo = 2;
        }

        else if(strcmp(holder,"regular") == 0){
            local[i].tipo = 1;
        }
        i++;
    }
    
    fclose(viaturas);
    return 0;
}

//Function used to decrypt the passwords that will be used in the next function
//and can be found in the "policiais.txt"
void decript(char *senha, char *var){
    int m = 0;
    for (int i = 0; senha[i] != '\0'; i++)
    {
        if((senha[i]> 64 && senha[i] < 91)||(senha[i]> 96 && senha[i] < 123)){
            if (senha[i]<=67||senha[i]<=99) {
                senha[i] = senha[i] +23;
            }

            else{
            senha[i] = senha[i] - 3;
            }
    }
    m++;
    }
    for (int i = 0,k = m-1; i < m; i++,k--)
    {
        var[i] = senha[k];
}
    var[m] = '\0';
}

//Function used to load the data of the police officers found in "policiais.txt"
int loadPM(Policiais *local){
    FILE *policiais;

    policiais = fopen("policiais.txt","r");
    if(policiais == NULL){
        fclose(policiais);
        return -1;
    }

    int i = 0;
    while(feof(policiais) == 0){

        fscanf(policiais,"%s",local[i].nome);
        fscanf(policiais,"%d",&local[i].cpf);
        fscanf(policiais,"%s",local[i].guerra);
        fscanf(policiais,"%s",local[i].cidade);
        fscanf(policiais,"%d",&local[i].idade);
        char holder[26];
        fscanf(policiais,"%s",holder);
        decript(holder,local[i].senha);
       
        i++;
    }
    
    fclose(policiais);
    return 0;
};