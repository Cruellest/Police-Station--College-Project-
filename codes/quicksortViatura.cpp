#ifndef STRUCTS_H
#include "structs.h"
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int separaRegular(int p, int sizeVetor, regularViatura *vetor)
{
    int x, i, j, aux;

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
        } while (vetor[i].qntChamadas > x);

        if(i < j)
        {
            aux = vetor[i].qntChamadas;
            vetor[i].qntChamadas = vetor[j].qntChamadas;
            vetor[j].qntChamadas = aux;
        } else {
            return j;
        }

    } 


}

void quicksortRegular(regularViatura *vetor, int p, int sizeVetor)
{

    int q;

    if(p < sizeVetor)
    {
        q = separaRegular(p, sizeVetor, vetor);
        quicksortRegular(vetor, p, q);
        quicksortRegular(vetor, q + 1, sizeVetor);
    }

}

int separaEspecial(int p, int sizeVetor, especialViatura *vetor)
{
    int x, i, j, aux;

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
        } while (vetor[i].qntChamadas > x);

        if(i < j)
        {
            aux = vetor[i].qntChamadas;
            vetor[i].qntChamadas = vetor[j].qntChamadas;
            vetor[j].qntChamadas = aux;
        } else {
            return j;
        }

    } 


}

void quicksortEspecial(especialViatura *vetor, int p, int sizeVetor)
{

    int q;

    if(p < sizeVetor)
    {
        q = separaEspecial(p, sizeVetor, vetor);
        quicksortEspecial(vetor, p, q);
        quicksortEspecial(vetor, q + 1, sizeVetor);
    }

}