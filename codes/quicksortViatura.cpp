#ifndef STRUCTS_H
#include "structs.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int separaRegular(int p, int sizeVetor, regularViatura *&vetor)
{
    int x, i, j;

    regularViatura aux;

    x = vetor[p].qntChamadas;
    i = p - 1;
    j = sizeVetor + 1;

    while(1)
    {
        do 
        {
            j--;

        } while (vetor[j].qntChamadas > x);
        do 
        {
            i++;
        } while (vetor[i].qntChamadas < x);

        if(i < j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        } else {
            return j;
        }

    } 


}

void quicksortRegular(regularViatura *&vetor, int p, int sizeVetor)
{

    int q;

    if(p < sizeVetor)
    {
        q = separaRegular(p, sizeVetor, vetor);
        quicksortRegular(vetor, p, q);
        quicksortRegular(vetor, q + 1, sizeVetor);
    }

}

int separaEspecial(int p, int sizeVetor, especialViatura *&vetor)
{
    int x, i, j;
    especialViatura aux;

    x = vetor[p].qntChamadas;
    i = p - 1;
    j = sizeVetor + 1;

    while(1)
    {
        do 
        {
            j--;

        } while (vetor[j].qntChamadas > x);
        do 
        {
            i++;
        } while (vetor[i].qntChamadas < x);

        if(i < j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        } else {
            return j;
        }

    } 


}

void quicksortEspecial(especialViatura *&vetor, int p, int sizeVetor)
{

    int q;

    if(p < sizeVetor)
    {
        q = separaEspecial(p, sizeVetor, vetor);
        quicksortEspecial(vetor, p, q);
        quicksortEspecial(vetor, q + 1, sizeVetor);
    }

}


int separaViatura(int p, int sizeVetor, Viatura *&vetor)
{
    int x, i, j;
    Viatura aux;

    x = vetor[p].codigo;
    i = p - 1;
    j = sizeVetor + 1;

    while(1)
    {
        do 
        {
            j--;

        } while (vetor[j].codigo > x);
        do 
        {
            i++;
        } while (vetor[i].codigo < x);

        if(i < j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        } else {
            return j;
        }

    } 


}

void quicksortViatura(Viatura *&vetor, int p, int sizeVetor)
{

    int q;

    if(p < sizeVetor)
    {
        q = separaViatura(p, sizeVetor, vetor);
        quicksortViatura(vetor, p, q);
        quicksortViatura(vetor, q + 1, sizeVetor);
    }

}

int separaPolicia(int p, int sizeVetor, Policial *&vetor){

    int x,i,j;
    Policial aux;

    x = vetor[p].nome[0];
    i = p - 1;
    j = sizeVetor + 1;

while(1){
    do{
        j--;
    }while(vetor[j].nome[0] > x);
    
    do{
        i++;
    }while (vetor[i].nome[0] < x);
    
    if(i<j){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
    else{
        return j;
    }
}
}

void quicksortPoliciais(Policial *&vetor,int p,int sizeVetor){
    int q;

    if(p<sizeVetor){
        q = separaPolicia(p,sizeVetor,vetor);
        quicksortPoliciais(vetor, p, q);
        quicksortPoliciais(vetor,q+1 , sizeVetor);

    }
}