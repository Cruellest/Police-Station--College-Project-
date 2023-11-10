#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCTS_H
#include "structs.h"
#endif


int distribui_chamada(struct listaChamada *&chamadas, regularViatura *regulares, especialViatura *especiais)
{
    printf("Entrou em distribui.");
    struct listaChamada *copia, *novo, *auxiliar;

    copia = chamadas;

    if (copia == NULL){
        return - 1;
    } else if (copia != NULL || copia->qntAtendida < copia->qntChamada)
    {
        if(copia->prox == NULL){
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
                            regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                        } else {
                            auxiliar = regulares[0].listaPrioritarias;
                            regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                            while(auxiliar->prox != NULL)
                            {    
                                auxiliar = auxiliar->prox;
                            }
                                auxiliar->prox = novo; 
                            }
                    } else {
                        if(regulares[0].listaChamadas == NULL)
                        {
                            regulares[0].listaChamadas = novo;
                            regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                        } else {
                            auxiliar = regulares[0].listaChamadas;
                            regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                            while(auxiliar->prox != NULL)
                            {
                                auxiliar = auxiliar->prox;
                            }
                            auxiliar->prox = novo; 
                        }
                    }
                } else {
                    if(especiais[0].listaChamadas == NULL)
                    {
                        especiais[0].listaChamadas = novo;
                        especiais[0].qntChamadas = regulares[0].qntChamadas + 1;
                    } else {
                        auxiliar = especiais[0].listaChamadas;
                        especiais[0].qntChamadas = regulares[0].qntChamadas + 1;
                        while(auxiliar->prox != NULL)
                        {
                            auxiliar = auxiliar->prox;
                        }
                        auxiliar->prox = novo; 
                    }
                }
                copia->chamada->qntViaturas = copia->chamada->qntViaturas - 1;
                copia->qntAtendida++;
            }
            copia = copia->prox;
        } else {
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
                                regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                            } else {
                                auxiliar = regulares[0].listaPrioritarias;
                                regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                                while(auxiliar->prox != NULL)
                                {
                                    auxiliar = auxiliar->prox;
                                }
                                auxiliar->prox = novo; 
                            }
                        } else {
                            if(regulares[0].listaChamadas == NULL)
                            {
                                regulares[0].listaChamadas = novo;
                                regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                            } else {
                                auxiliar = regulares[0].listaChamadas;
                                regulares[0].qntChamadas = regulares[0].qntChamadas + 1;
                                while(auxiliar->prox != NULL)
                                {
                                    auxiliar = auxiliar->prox;
                                }
                                auxiliar->prox = novo; 
                            }
                        }
                    } else {
                        if(especiais[0].listaChamadas == NULL)
                        {
                            especiais[0].listaChamadas = novo;
                            especiais[0].qntChamadas = regulares[0].qntChamadas + 1;
                        } else {
                            auxiliar = especiais[0].listaChamadas;
                            especiais[0].qntChamadas = regulares[0].qntChamadas + 1;
                            while(auxiliar->prox != NULL)
                            {
                                auxiliar = auxiliar->prox;
                            }
                            auxiliar->prox = novo; 
                        }
                    }
                    copia->chamada->qntViaturas = copia->chamada->qntViaturas - 1;
                    copia->qntAtendida++;
                }
                copia = copia->prox;
            }
        } 
        
        return 1;
    } return -1;
}


int verif_reforco(struct listaChamada *&listaChamadas, struct Chamada *&codChamada)
{
    struct listaChamada *copia;

    copia = listaChamadas;

    if(copia != NULL){
        if(copia->prox == NULL){
            if (copia->chamada->reforco == true) 
                {
                    copia->chamada->reforco = false;
                    codChamada = copia->chamada;
                    return 1;
                }else {
                    copia = copia->prox;
                }
        } else {
            while(copia->prox != NULL)
            {
                if (copia->chamada->reforco == true) 
                {
                    copia->chamada->reforco = false;
                    codChamada = copia->chamada;
                    copia = copia->prox;
                    return 1;
                } else {
                    copia = copia->prox;
                }
            } 
        } return -1;
    } return -1;
}

void inserir_reforco_regular(struct Chamada *codChamada, struct regularViatura *regulares){
    listaChamada *novo, *auxiliar;

    novo = (listaChamada * ) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = codChamada;

    if (regulares[0].listaReforco == NULL)
    {
        regulares[0].listaReforco = novo;
    } else {
        auxiliar = regulares[0].listaReforco;
        while(auxiliar->prox != NULL)
        {
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

    if (especiais[0].listaReforco == NULL)
    {
        especiais[0].listaReforco = novo;
    } else {
        auxiliar = especiais[0].listaReforco;
        while(auxiliar->prox != NULL)
        {
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo; 
    }
}

//passar nome policial

void cadastrarChamada(struct listaChamada *&listaChamadas, struct regularViatura *regulares, struct especialViatura *especiais)
{  
    int op1;
    listaChamada *copia = listaChamadas;

    Chamada *novaChamada;

    Chamada *codChamada = (Chamada *) malloc(sizeof(Chamada));
    codChamada = NULL;

    printf("\n SPM - COPOM");

    int temReforco = verif_reforco(listaChamadas, codChamada);

    if (temReforco > 0){
        printf("\nTem reforço.");
    }

    while (temReforco > 0){
        printf("\n\n SOLICITAÇÃO DE REFORÇO!");
        printf("\n 1 - Atender");
        printf("\n 2 - Negar");
        printf("\n Opção: ");

        scanf(" %d", &op1);

        if (op1 == 1){
            if(codChamada->tipo == 1)
            {
                inserir_reforco_regular(codChamada, regulares);
                  
            } else {
                inserir_reforco_especial(codChamada, especiais);
            }
        }
        temReforco = verif_reforco(listaChamadas, codChamada);
    }

    printf("\n\n Cadastrar nova chamada:");
    printf("\n 1 - Polícia Regular");
    printf("\n 2 - Polícia Especializada");
    
    int tipo;
    printf("\n\n Selecione o tipo de polícia: ");
    scanf("%d", &tipo);

    novaChamada->tipo = tipo;


    if(novaChamada->tipo == 1)
    {
        printf("\n 1 - Chamada Prioritária");
        printf("\n 2 - Chamada Não Prioritária");
    
        int prioridade;
        printf("\n\n Selecione a prioridade da chamada: ");
        scanf("%d", &prioridade);

        novaChamada->prioridade = prioridade;
    }

    int qnt;
    printf("\n 1 - Viaturas Necessárias: ");
    scanf("%d", &qnt);
    novaChamada->qntViaturas = qnt;

    printf("\n Descrição: ");
    scanf(" %[^\n]", novaChamada->descricao);

    printf("\n Localização: ");
    scanf(" %[^\n]", novaChamada->loc);

    if (listaChamadas == NULL)
    {
        printf("Entrou em Lista == Null\n");
        listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
        listaChamadas->chamada = novaChamada;
        listaChamadas->qntChamada = 1;
        listaChamadas->qntAtendida = 0;
        listaChamadas->prox = NULL;
    } else {
        while(copia->prox != NULL)
        {
            copia = copia->prox;
        }
        copia = (listaChamada *) malloc(sizeof(listaChamada));
        copia->chamada = novaChamada;
        copia->qntChamada++;
        listaChamadas->qntAtendida = 0;
        copia->prox = NULL;
    }

}