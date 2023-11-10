#ifndef STRUCTS_H
#include "structs.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscaBinaria.h"

#ifndef COPOM_H
#include "COPOM.h"
#endif

#ifndef QUICKSORTVIATURA_H
#include "quicksortViatura.h"
#endif

//void pesquisaCPF(){};

void solicitarReforco(int tipo, regularViatura *regulares, especialViatura *especiais, int indice, int prioridade)
{

    int op;

    do{
    printf("\n 1 - Confirmar Solicitação de Reforços");
    printf("\n 2 - Cancelar");
    printf("\n Opção: ");

    scanf(" %d", &op);

    if (op == 1){
        if (tipo == 1)
        {
            if (prioridade == 2)
            {
                regulares[indice].listaChamadas->chamada->reforco = true;
            } else if (prioridade == 1)
            {
                regulares[indice].listaPrioritarias->chamada->reforco = true;
            } else if (prioridade == 0){
                regulares[indice].listaReforco->chamada->reforco = true;
            }
        } else {
            if (prioridade == 1)
            {
                especiais[indice].listaChamadas->chamada->reforco = true;
            } else if (prioridade == 0){
                especiais[indice].listaReforco->chamada->reforco = true;
            } 
        }
    }
    op = 2;

    } while(op != 2);

}

void viaturaOcorrencia(regularViatura *regulares, int sizeRegular, especialViatura *especiais, int sizeEspecial, listaChamada *&chamadas, int tipo, int viaturaCode, int prioridade){

    int op;

    do{

        printf("\n1 - Pesquisar por CPF");
        printf("\n2 - Solicitar Reforços");
        printf("\n3 - Prisão em Andandamento");
        printf("\n4 - Encerrar Ocorrência");

        printf("\nOpção: ");
        scanf(" %d", &op);

        if(op == 1) //Pesquisar por CPF.
        {
            //loads functions from Viatura Login
            
        }
        else if(op == 2) //Solicitar Reforços.
        {
            solicitarReforco(tipo, regulares, especiais, viaturaCode, prioridade);
        }

        else if(op == 3) //Prisão em andamento
        {
            
        }

        } while (op != 4);

}

void viaturaModoRonda()
{
    int op = 0;

    do {
        printf("\n Viatura direciondada para rondas, no aguardo de chamadas policiais.");
        printf("\n 1 - Voltar para o Menu principal.");
        printf("\n Opção: ");
        scanf(" %d", &op);
    } while (op != 1);

}

void viaturaEstadoNeutro(regularViatura *regulares, int sizeRegular, especialViatura *especiais, int sizeEspecial, listaChamada *&chamadas, int tipo, int viaturaCode)
{
    int op2;

    printf("\n SPM - Viatura Estado Neutro");

    printf("\n\n 1 - Apto para atender ocorrência");
    printf("\n 2 - Cancelar Embarcação\n");
    printf("\n Opção: ");
    scanf(" %d", &op2);

    if(op2 == 1){
 
        if (tipo == 1)
        {
            quicksortRegular(regulares, 0, sizeRegular);
        } else {
            quicksortEspecial(especiais, 0, sizeEspecial);
        }

        printf("\n%d na celula %d", regulares[sizeRegular - 2].viatura->codigo, sizeRegular - 2);

        int distribuiu = distribui_chamada(chamadas, regulares, especiais);

        if (distribuiu < 0){
            viaturaModoRonda();
        } else {
            int indice, acao;

            if(tipo == 1)
            {
                        for(int i = 0; i < sizeRegular; i++)
                        {
                            if (viaturaCode == regulares[i].viatura->codigo)
                            {
                                indice = i;
                                break;
                            }
                        }

                        regularViatura *viaturaLogada = &regulares[indice];

                        if (viaturaLogada->listaReforco != NULL) {
                            printf("\n Solicitação de Reforço Recebida.");
                            
                            printf("\n Descricao: %s", viaturaLogada->listaReforco->chamada->descricao); 
                            printf("\n Localização: %s", viaturaLogada->listaReforco->chamada->loc);   

                            printf("\n\n 1 - Confirmada Ação Policial\n 2 - Reforço Dispensado");
                            printf("\n Opção: ");

                            scanf(" %d", &acao);

                            if(acao == 1){
                                int prioridade = 0;
                                viaturaOcorrencia(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, indice, prioridade);
                            } else {
                                viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                            }
                        } else if (viaturaLogada->listaPrioritarias != NULL && viaturaLogada->listaReforco == NULL){
                            printf("\n Descricao: %s", viaturaLogada->listaPrioritarias->chamada->descricao); 
                            printf("\n Localização: %s", viaturaLogada->listaPrioritarias->chamada->loc);   

                            printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                            printf("\n Opção: ");

                            scanf(" %d", &acao);

                            if(acao == 1){
                                int prioridade = 1;
                                viaturaOcorrencia(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, indice, prioridade);
                            } else {
                                viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                            }

                        } else if (viaturaLogada->listaPrioritarias == NULL && viaturaLogada->listaReforco == NULL && viaturaLogada->listaChamadas != NULL){
                            printf("\n Descricao: %s", viaturaLogada->listaChamadas->chamada->descricao); 
                            printf("\n Localização: %s", viaturaLogada->listaChamadas->chamada->loc);   
 
                            printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                            printf("\n Opção: ");

                            scanf(" %d", &acao);

                            if(acao == 1){
                                int prioridade = 2;
                                viaturaOcorrencia(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, indice, prioridade);
                            } else {
                                viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                            }

                    
            } else {

                        for(int i = 0; i < sizeEspecial; i++)
                        {
                            if (viaturaCode == especiais[i].viatura->codigo)
                            {
                                indice = i;
                                break;
                            }
                        }

                        especialViatura *viaturaLogada = &especiais[indice];


                        if (viaturaLogada->listaReforco != NULL) {
                            printf("\n Solicitação de Reforço Recebida.");
                            
                            printf("\n Descricao: %s", viaturaLogada->listaReforco->chamada->descricao); 
                            printf("\n Localização: %s", viaturaLogada->listaReforco->chamada->loc);   

                            printf("\n\n 1 - Confirmada Ação Policial\n 2 - Reforço Dispensado");
                            printf("\n Opção: ");

                            scanf(" %d", &acao);

                            if(acao == 1){
                                int prioridade = 0;
                                viaturaOcorrencia(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, indice, prioridade);
                            } else {
                                viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                            }
                        } else if (viaturaLogada->listaChamadas != NULL && viaturaLogada->listaReforco == NULL){
                            printf("\n Descricao: %s", viaturaLogada->listaChamadas->chamada->descricao); 
                            printf("\n Localização: %s", viaturaLogada->listaChamadas->chamada->loc);   

                            printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                            printf("\n Opção: ");

                            scanf(" %d", &acao);

                            if(acao == 1){
                                int prioridade = 1;
                                viaturaOcorrencia(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, indice, prioridade);
                            } else {
                                viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                            }

                        }
            }

        }

    } else {
        if(tipo == 1)
        {
            regulares = (regularViatura *) realloc(regulares, sizeRegular - 1 * sizeof(regularViatura));
        } else {
            especiais = (especialViatura *) realloc(especiais, sizeEspecial - 1 * sizeof(especialViatura));

        }
    }

}


void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial, listaChamada *listaChamadas) 
{
    /*Starting variables:*/
    int tipo;
    int viaturaCode, quantidadePM, viaturaVetor;


    /*Collecting user input:*/
    printf("\n SPM - Viatura Login");
    printf("\n\n 1 - Polícia Regular");
    printf("\n 2 - Polícia Especializada");
    
    printf("\n\n Selecione o tipo de viatura: ");
    scanf(" %d", &tipo);
    
    while(tipo < 1 || tipo > 2) //error handling:
    {
        printf("\n Tipo inexistente.");
        printf("\n Selecione o tipo de viatura: ");
        scanf(" %d", &tipo);
    }

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturaCode);


    /*Search for the vehicle index in the list of vehicles*/
    viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);

    //checks and error handling:
    for(;(tipo == 1 && viaturas[viaturaVetor].tipo != 1) || (tipo == 2 && viaturas[viaturaVetor].tipo != 2);)
    {
        printf("\nO código inserido não corresponde a uma viatura do tipo selecionado.");   
        printf("\n Código da Viatura: ");
        scanf(" %d", &viaturaCode);
        viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);
    }

    printf("\n Quantidade de PMs: ");
    scanf("%d", &quantidadePM);

    //checks and error handling:
    for(;(tipo == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (tipo == 2 && quantidadePM != 4);)
    {

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf("%d", &quantidadePM);
    }


    /*Saving data into their corresponding vectors:*/
    if (tipo == 1)
    {
            if (sizeRegular == 1)
            {
                regulares[0].viatura = &viaturas[viaturaVetor];

                regulares[0].listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[0].listaChamadas = NULL;

                regulares[0].listaPrioritarias = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[0].listaPrioritarias = NULL;

                regulares[0].listaReforco = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[0].listaReforco = NULL;

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", regulares[0].policiais[i]);
                }

                sizeRegular++;

            } else {
                regulares = (regularViatura *) realloc(regulares, sizeRegular * sizeof(regularViatura));

                regulares[sizeRegular - 1].viatura = &viaturas[viaturaVetor];

                regulares[sizeRegular - 1].listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[sizeRegular - 1].listaChamadas = NULL;

                regulares[sizeRegular - 1].listaPrioritarias = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[sizeRegular - 1].listaPrioritarias = NULL;

                regulares[sizeRegular - 1].listaReforco = (listaChamada *) malloc(sizeof(listaChamada));
                regulares[sizeRegular - 1].listaReforco = NULL;

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", regulares[sizeRegular - 1].policiais[i]);;
                }
                sizeRegular++;
            }
    } else {
            if (sizeEspecial == 1)
            {
                especiais[0].viatura = &viaturas[viaturaVetor];

                especiais[0].listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[0].listaChamadas = NULL;

                especiais[0].listaReforco = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[0].listaReforco = NULL;

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", especiais[0].policiais[i]);
                }

                sizeEspecial++;

            } else {
                especiais = (especialViatura *) realloc(especiais, sizeEspecial * sizeof(especialViatura));

                especiais[sizeEspecial - 1].viatura = &viaturas[viaturaVetor];

                especiais[sizeEspecial - 1].listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[sizeEspecial - 1].listaChamadas = NULL;

                especiais[sizeEspecial - 1].listaReforco = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[sizeEspecial - 1].listaReforco = NULL;

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", especiais[sizeEspecial - 1].policiais[i]);
                }
                sizeEspecial++;
            }
        }
    viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, listaChamadas, tipo, viaturaCode);
}