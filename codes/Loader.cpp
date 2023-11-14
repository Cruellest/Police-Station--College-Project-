//This file is used to store the loader for all the structs that
//need to be loaded from a file
#ifndef STRUCTS_H
#include "structs.h"
#endif
#ifndef QUICKSORTVIATURA_H
#include "quicksortViatura.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function used to know the amount of viatures data the file stores
int amountofViaturas(){
   
    FILE *viaturas;
    int size = 1;
    char line;

    viaturas = fopen("viaturas.txt","r");
    if(viaturas == NULL){
        return -1;
    }

    //returns the amount of lines that the file have
    do {
        line = fgetc(viaturas);
        if(line == '\n'){
            size++;
        }
    }
    while (line != EOF);
    //Amount of viatures (assuming that the user wrote it down correctly)

    //closing the file and returning the amount of viaturas
    fclose(viaturas);
    return size/2;

}

//Function used to load the app data from a txt file
int loadViaturas(Viatura *local){

    FILE *viaturas;
    int i = 0;



    viaturas = fopen("viaturas.txt","r");
    if(viaturas == NULL){
        return 1;//return that the function have failed
    }

    while(feof(viaturas) == 0){

        fscanf(viaturas, "%d", &local[i].codigo);
        char holder[16];
        fscanf(viaturas, "%s", holder);
        if(strcmp(holder, "especializada") == 0){
            local[i].tipo = 2;
        }

        else if(strcmp(holder,"regular") == 0){
            local[i].tipo = 1;
        }
        i++;
    }
    //closing the file
    fclose(viaturas);
    quicksortViatura(local,0,amountofViaturas());
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

//returns the ammount of police officers Data that the file contains
int ammountofPoliceOfficers(){
    FILE *policiais;
    int size = 1;
    char line;

    policiais = fopen("policiais.txt","r");
    if(policiais == NULL){          //if the file opening fails it should return -1
        return -1;
    }

    //returns the amount of lines that the file have
    do {
        line = fgetc(policiais);
        if(line == '\n'){
            size++;
        }
    }
    while (line != EOF);

    //Amount of viatures (assuming that the user wrote it down correctly)
    //and closing the file
    fclose(policiais);
    return size/7;

}

//Function used to load the data of the police officers found in "policiais.txt"
int loadPoliceOfficers(Policial *local){
    FILE *policiais;

    policiais = fopen("policiais.txt","r");
    if(policiais == NULL){
        return -1;
    }

    //Loading the police officers data in each field of the struct
    int i = 0;
    while(feof(policiais) == 0){

        fscanf(policiais,"%[^\n]\n",local[i].nome);
        fscanf(policiais,"%ld\n",&local[i].cpf);
        fscanf(policiais,"%[^\n]\n",local[i].guerra);
        fscanf(policiais,"%[^\n]\n",local[i].cidade);
        fscanf(policiais,"%d\n",&local[i].idade);
        fscanf(policiais,"%[^\n]\n",local[i].cargo);
        //loading and decrypting the password (I know that from a security point of view thats terrible butttttt it makes easier to debug)
        char holder[26];
        fscanf(policiais,"%[^\n]\n",holder);
        decript(holder,local[i].senha);
       
        i++;
    }
    
    //Closing the file
    fclose(policiais);
    return 0;
}

//returns the ammount of people data that the file "Pessoas.txt" contains
int amountofPeople(){
    FILE *pessoas;
    int size = 1,sizetemp = 1,timeskip = 0;
    char line;


    pessoas = fopen("pessoas.txt","r");
    if(pessoas == NULL){    //if opening the file fails returns -1
        return -1;
    }
    
    do{
        line = fgetc(pessoas);
        if(line == '\n'){
            size++;
            sizetemp++;
        }
        //compensating the dynamic size variance
        if(sizetemp == 5){
            fscanf(pessoas,"%d",&timeskip);
           
            for(int i = -1; i<timeskip;){
                line = fgetc(pessoas);
                if(line == '\n'||line == EOF){
                    i++;
                }
            } 
         fscanf(pessoas,"%d",&timeskip);
          for(int i = -1; i<timeskip;){
                line = fgetc(pessoas);
            if(line == '\n'||line == EOF){
                i++;
            }
        sizetemp = 1;
        }
        
    }
    }
    while(line != EOF);

    //closing the file and returning the amount of people
    fclose(pessoas);
    return size/4;
}

//loading people file data into a struct
int loadPeople(Pessoa *local){
    FILE *pessoas;

    //file opening
    pessoas = fopen("pessoas.txt","r");
    if(pessoas == NULL){    //if it fails returns -1
        return -1;
    }

    // loading the data into the correspondent fields of the struct
    int i = 0;
    while(feof(pessoas) == 0){

       fscanf(pessoas,"%[^\n]\n",local[i].nome);
       fscanf(pessoas,"%ld\n",&local[i].cpf);
       fscanf(pessoas,"%[^\n]\n",local[i].cidade);
       fscanf(pessoas,"%d\n",&local[i].idade);
       fscanf(pessoas,"%d\n",&local[i].numPassagens);

       //Loading the dynamically sized variables
       for (int j = 0; j < local[i].numPassagens; j++)
       {
        fscanf(pessoas,"%[^\n]\n",local[i].passagens[j]);
       }
       fscanf(pessoas,"%d\n",&local[i].numInadimplencias);
       for(int j = 0; j < local[i].numInadimplencias; j++)
       {
        fscanf(pessoas,"%[^\n]\n",local[i].inadimplencias[j]);
       }
       
        i++;
    }
    fclose(pessoas);
    return 0;
}