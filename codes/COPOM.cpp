#include <stdio.h>
#include  "viaturaLogin.cpp"

void distribui_chamada(struct listaChamada *listaChamadas, regularViatura *regulares, especialViatura *especiais)
{
    struct listaChamada *copia, *novo, *auxiliar;

    copia = listaChamadas;

    while(copia->prox != NULL)
    {
        if(copia->chamada->qntViaturas > 0)
        {
            novo = (listaChamada *) malloc(sizeof(listaChamada));
            novo->prox = NULL;
            novo->chamada = copia->chamada;

            if(copia->chamada->tipo == 1)
            {
                if(copia->chamada->prioridade == 1)
                {
                    if(regulares[0].listaPrioritarias == NULL){
                        regulares[0].listaPrioritarias = novo;
                    } else {
                        auxiliar = regulares[0].listaPrioritarias;
                        while(auxiliar->prox != NULL){
                            auxiliar = auxiliar->prox;
                        }
                        auxiliar->prox = novo; 
                    }
                } else {
                    if(regulares[0].listaChamadas == NULL){
                        regulares[0].listaChamadas = novo;
                    } else {
                        auxiliar = regulares[0].listaChamadas;
                        while(auxiliar->prox != NULL){
                            auxiliar = auxiliar->prox;
                        }
                        auxiliar->prox = novo; 
                    }
                }
            } else {
                if(especiais[0].listaChamadas == NULL){
                    especiais[0].listaChamadas = novo;
                } else {
                    auxiliar = especiais[0].listaChamadas;
                    while(auxiliar->prox != NULL){
                        auxiliar = auxiliar->prox;
                    }
                    auxiliar->prox = novo; 
                }
            }
        }
        copia->chamada->qntViaturas = copia->chamada->qntViaturas - 1;
        copia = copia->prox;
    } 
}


void verif_reforco(struct listaChamada *listaChamada, bool &reforcoLocal, struct Chamada *codChamada)
{
    struct listaChamada *copia;

    copia = listaChamada;

    while(copia->prox != NULL){
        if (listaChamada->chamada->reforco == true) 
        {
            reforcoLocal = true;
            listaChamada->chamada->reforco = false;
            codChamada = listaChamada->chamada;
            copia = copia->prox;
        } else {
            copia = copia->prox;
        }

    }
}

void inserir_reforco_regular(struct Chamada *codChamada, struct regularViatura *regulares){
    listaChamada *novo, *auxiliar;

    novo = (listaChamada * ) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = codChamada;

    if (regulares[0].listaReforco == NULL){
        regulares[0].listaReforco = novo;
    } else {
        auxiliar = regulares[0].listaReforco;
        while(auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo; 
    }
}

void inserir_reforco_especial(struct Chamada *codChamada, struct especialViatura *especiais){
    listaChamada *novo, *auxiliar;

    novo = (listaChamada * ) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = codChamada;

    if (especiais[0].listaReforco == NULL){
        especiais[0].listaReforco = novo;
    } else {
        auxiliar = especiais[0].listaReforco;
        while(auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo; 
    }
}




void cadastrarChamada(struct listaChamada *listaChamada, struct regularViatura *regulares, struct especialViatura *especiais)
{  
    int op1;
    bool reforco; 
    struct Chamada *codChamada, *auxiliar;
    verif_reforco(listaChamada, reforco, codChamada);

    while (reforco == true){
        printf("\n SOLICITAÇÃO DE REFORÇO!");
        printf("\n 1 - Atender");
        printf("\n 2 - Negar");
        scanf("%d", &op1);

        if (op1 == 1){
            if(codChamada->tipo == 1)
            {
                inserir_reforco_regular(codChamada, regulares);
                  
            } else {
                inserir_reforco_especial(codChamada, especiais);
            }
        }
        verif_reforco(listaChamada, reforco, codChamada);
    }


}