#include "structs.h"

int buscaViatura(int esq, int dir, struct Viatura viaturas[], int x)
    {
        int meio;

        if (esq == dir - 1)
            return dir;
        else {
            meio = (esq + dir) / 2;
            if (viaturas[meio].codigo < x)
                return buscaViatura(meio, dir, viaturas, x);
            else
                return buscaViatura(esq, meio, viaturas, x);
    }
}
