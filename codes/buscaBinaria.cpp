#include "structs.h"

int busca_binaria_R(int esq, int dir, struct tViatura viaturas[], int x)
    {
        int meio;

        if (esq == dir - 1)
            return dir;
        else {
            meio = (esq + dir) / 2;
            if (viaturas[meio].codigo < x)
                return busca_binaria_R(meio, dir, viaturas, x);
            else
                return busca_binaria_R(esq, meio, viaturas, x);
    }
}
