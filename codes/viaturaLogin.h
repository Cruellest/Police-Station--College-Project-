#include "viaturaLogin.cpp"

int separaRegular(int p, int sizeVetor, regularViatura *vetor);

void quicksortRegular(regularViatura *vetor, int p, int sizeVetor);

int separaEspecial(int p, int sizeVetor, especialViatura *vetor);

void quicksortEspecial(especialViatura *vetor, int p, int sizeVetor);

void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial, listaChamada *listaChamadas) ;

