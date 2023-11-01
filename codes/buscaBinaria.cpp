#include "structs.h"

int buscaViatura(struct Viatura viaturas[], int size, int x)
{
    for (int i = 0; i < size; i++){
        if (x == viaturas[i].codigo){
            return i;
        }
    }    
}
