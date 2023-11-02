#include "structs.h"

int buscaBinaria(struct Viatura *viaturas, int size, int chave) {
    int inicio = 0;
    int fim = size - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se a chave está no meio
        if (viaturas[meio].codigo == chave) {
            return meio;
        }

        // Se a chave estiver à esquerda do meio
        if (viaturas[meio].codigo > chave) {
            fim = meio - 1;
        } else {
            // Se a chave estiver à direita do meio
            inicio = meio + 1;
        }
    }

    // Se não encontrar a chave
    return -1;
}

int buscaBinariaRegular(struct regularViatura *regulares, int size, int chave) {
    int inicio = 0;
    int fim = size - 1;


    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if(meio < 1)
        {
            return -1;
        } else {

            // Verifica se a chave está no meio
            if (regulares[meio].viatura->codigo == chave) {
                return meio;
            }

            // Se a chave estiver à esquerda do meio
            if (regulares[meio].viatura->codigo > chave) {
                fim = meio - 1;
            } else {
                // Se a chave estiver à direita do meio
                inicio = meio + 1;
            }
        }
    }

    // Se não encontrar a chave
    return -1;
}

int buscaBinariaEspecial(struct especialViatura *especiais, int size, int chave) {
    int inicio = 0;
    int fim = size - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if(meio < 1)
        {
            return -1;
        } else {

            // Verifica se a chave está no meio
            if (especiais[meio].viatura->codigo == chave) {
                return meio;
            }

            // Se a chave estiver à esquerda do meio
            if (especiais[meio].viatura->codigo > chave) {
                fim = meio - 1;
            } else {
                // Se a chave estiver à direita do meio
                inicio = meio + 1;
            }
        }
    }

    // Se não encontrar a chave
    return -1;
}