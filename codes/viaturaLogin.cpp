#ifndef STRUCTS_H
#include "structs.h"
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscaBinaria.h"
#ifndef COPOM_H
#include "COPOM.h"
#include "viaturaFuncionalidade.h"
#include "quicksortViatura.h"
#endif


void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial, listaChamada *listaChamadas) 
{
    /*Starting variables:*/
    int tipo;
    int viaturaCode, quantidadePM, viaturaVetor, verifRegular, verifEspecial;


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
/*
    if (op1 == 1 && sizeRegular != 1)
    {
        verifRegular = buscaBinariaRegular(regulares, sizeRegular, viaturaCode);
        while(verifRegular != -1){
            printf("\nViatura selecionada em uso.");   
            printf("\n Código da Viatura: ");
            scanf(" %d", &viaturaCode);
            verifRegular = buscaBinariaRegular(regulares, sizeRegular, viaturaCode); 
        }
    } else if (op1 == 2 && sizeEspecial != 1) 
    {
        verifEspecial = buscaBinariaEspecial(especiais, sizeEspecial, viaturaCode);
        while(verifEspecial != -1){
            printf("\nViatura selecionada em uso.");   
            printf("\n Código da Viatura: ");
            scanf(" %d", &viaturaCode);
            verifEspecial = buscaBinariaEspecial(especiais, sizeRegular, viaturaCode); 
        }
    }
*/
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