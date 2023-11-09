#ifndef QUICKSORTVIATURA_H
#define QUICKSORTVIATURA_H
#include "quicksortViatura.cpp"

int separaRegular(int p, int sizeVetor, regularViatura *vetor);

void quicksortRegular(regularViatura *vetor, int p, int sizeVetor);

int separaEspecial(int p, int sizeVetor, especialViatura *vetor);

void quicksortEspecial(especialViatura *vetor, int p, int sizeVetor);

#endif // !QUICKSORTVIATURA_H