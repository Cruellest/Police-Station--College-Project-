#include <stdio.h>
#include  "viaturaLogin.cpp"

//fazer alg de ordenação das viaturas .

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



void cadastrarChamada(struct listaChamada *listaChamadas, struct regularViatura *regulares, struct especialViatura *especiais)
{  
    int op1;
    Chamada *novaChamada;
    listaChamada *copia = listaChamadas;

    bool reforco; 
    struct Chamada *codChamada, *auxiliar;
    printf("\n SPM - COPOM");

    verif_reforco(listaChamadas, reforco, codChamada);

    while (reforco == true){
        printf("\n\n SOLICITAÇÃO DE REFORÇO!");
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
        verif_reforco(listaChamadas, reforco, codChamada);
    }

    printf("\n\n Cadastrar nova chamada:");
    printf("\n 1 - Polícia Regular");
    printf("\n 2 - Polícia Especializada");
    
    printf("\n\n Selecione o tipo de polícia: ");
    scanf("%d", novaChamada->tipo);

    if(novaChamada->tipo == 1)
    {
        printf("\n 1 - Chamada Prioritária");
        printf("\n 2 - Chamada Não Prioritária");
    
        printf("\n\n Selecione a prioridade da chamada: ");
        scanf("%d", novaChamada->tipo);
    }

    printf("\n 1 - Viaturas Necessárias");
    scanf("%d", &novaChamada->qntViaturas);

    printf("/n Descrição: ");
    scanf(" %[^\n]", novaChamada->descricao);

    printf("/n Localização: ");
    scanf(" %[^\n]", novaChamada->loc);

    listaChamada *nova = (listaChamada *) malloc(sizeof(listaChamada));
            nova->prox = NULL;
            nova->chamada = novaChamada;
    

    if (listaChamadas == NULL)
    {
        listaChamadas = nova;
    } else {
        while(copia != NULL)
        {
        copia = copia->prox;
        }
        copia->prox = nova;
    }

}