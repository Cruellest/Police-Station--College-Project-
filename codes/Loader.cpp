#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


char linha[256];
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

void decript(char *senha, char *var){
    int m = 0;
    for (int i = 0; senha[i] != '\0'; i++)
    {
        if((senha[i]> 64 && senha[i] < 91)||(senha[i]> 96 && senha[i] < 123)){
            senha[i] = senha[i] - 3;
    }
    m++;
    }
    for (int i = 0,k = m-1; i < m; i++,k--)
    {
        var[i] = senha[k];
}
    var[m] = '\0';
}

int loadPM();