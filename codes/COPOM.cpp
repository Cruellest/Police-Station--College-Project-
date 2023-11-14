#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCTS_H
#include "structs.h"
#endif

#ifndef QUICKSORTVIATURA_H
#include "quicksortViatura.h"
#endif


int distribui_chamada(struct listaChamada *&chamadas, regularViatura *&regulares, especialViatura *&especiais)
{
    struct listaChamada *copia, *novo, *auxiliar;

    copia = chamadas;

    if (copia == NULL){
        return - 1;
    } else {
            while(copia != NULL)
            {
                if(copia->chamada.qntViaturas > 0)
                {
                    novo = (listaChamada *) malloc(sizeof(listaChamada));
                    novo->prox = NULL;
                    novo->chamada = copia->chamada;

                    if(copia->chamada.tipo == 1)
                    {
                        for (int i = 0; i < 4; i++){
                            strcpy(novo->chamada.policiais[i], regulares[0].policiais[i]);
                        }

                        if(copia->chamada.prioridade == 1)
                        {
                            if(regulares[0].listaPrioritarias == NULL)
                            {
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
                        for (int i = 0; i < 4; i++)
                        {
                            strcpy(novo->chamada.policiais[i], especiais[0].policiais[i]);
                        }
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
                    copia->chamada.qntViaturas = copia->chamada.qntViaturas - 1;
                }
                copia = copia->prox;
            }
        } 
        
        return 1;
}

int verif_reforco(struct listaChamada *&listaChamadas, struct Chamada *&codChamada)
{
    struct listaChamada *copia;

    copia = listaChamadas;

    if(copia != NULL){
        if(copia->prox == NULL){
            if (copia->chamada.reforco == true) 
                {
                    copia->chamada.reforco = false;
                    codChamada = &copia->chamada;
                    return 1;
                }else {
                    copia = copia->prox;
                }
        } else {
            while(copia->prox != NULL)
            {
                if (copia->chamada.reforco == true) 
                {
                    copia->chamada.reforco = false;
                    codChamada = &copia->chamada;
                    copia = copia->prox;
                    return 1;
                } else {
                    copia = copia->prox;
                }
            } 
        } return -1;
    } return -1;
}

void inserir_reforco_regular(struct Chamada *codChamada, struct regularViatura *&regulares){
    listaChamada *novo, *auxiliar;

    novo = (listaChamada * ) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = *codChamada;

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

void inserir_reforco_especial(struct Chamada *codChamada, struct especialViatura *&especiais){
    listaChamada *novo, *auxiliar;

    novo = (listaChamada * ) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = *codChamada;

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

void cadastrarChamada(struct listaChamada *&listaChamadas, struct regularViatura *&regulares, struct especialViatura *&especiais, int &contChamadas)
{  
    int op1;
    listaChamada *copia;

    Chamada novaChamada;

    Chamada *codChamada;

    printf("\e[1;1H\e[2J");
    printf(" SPM - COPOM");

    int temReforco = verif_reforco(listaChamadas, codChamada);

    while (temReforco > 0){
        printf("\n\n Solicitação de Reforço Recebida");
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
    printf("\e[1;1H\e[2J");
    printf(" SPM - COPOM");

    printf("\n\n Cadastrar Nova Chamada");
    
    printf("\n\n 1 - Polícia Regular");
    printf("\n 2 - Polícia Especializada");
    
    int tipo;
    printf("\n Selecione o tipo de polícia: ");
    scanf("%d", &tipo);

    novaChamada.tipo = tipo;

    if(novaChamada.tipo == 1)
    {
        printf("\n 1 - Chamada Prioritária");
        printf("\n 2 - Chamada Não Prioritária");
    
        int prioridade;
        printf("\n Selecione a prioridade da chamada: ");
        scanf("%d", &prioridade);

        novaChamada.prioridade = prioridade;
    }

    int qnt;
    printf("\n Viaturas Necessárias: ");
    scanf("%d", &qnt);
    novaChamada.qntViaturas = qnt;

    printf("\n Descrição: ");
    scanf(" %[^\n]", novaChamada.descricao);

    printf("\n Localização: ");
    scanf(" %[^\n]", novaChamada.loc);

    novaChamada.codigo = contChamadas;
    contChamadas++;

    listaChamada *novo = (listaChamada *) malloc(sizeof(listaChamada));
    novo->prox = NULL;
    novo->chamada = novaChamada;

    if (listaChamadas == NULL)
    {
        listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
        listaChamadas = novo;
    } else {
        copia = listaChamadas;
        while(copia->prox != NULL)
        {
            copia = copia->prox;
        }
        copia->prox = novo;
    }
}
/*celula *novo, *p;
novo = (celula*) malloc(sizeof(celula));
novo->prox = NULL;

novo->chave = x;
if(lst == NULL) lista esta vazia
lst = novo;
else{
p = lst;
while(p->prox != NULL)
p = p->prox;
p->prox = novo;
}*/