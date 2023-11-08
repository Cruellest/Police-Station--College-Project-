#ifndef STRUCTS_H
#include "structs.h"
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "buscaBinaria.h"
#ifndef COPOM_H
#include "COPOM.h"
#include "quicksortViatura.h"
#endif

void viaturaEstadoNeutro(regularViatura *regulares, int sizeRegular, especialViatura *especiais, int sizeEspecial, listaChamada *&chamadas, int tipo, int viaturaCode)
{
    int op2;

    printf("\n SPM - Viatura Estado Neutro");

    printf("\n\n 1 - Apto para atender ocorrência");
    printf("\n 2 - Cancelar Embarcação\n");
    scanf(" %d", &op2);

    if(op2 == 1){
        /*tirar*/printf("\n%d na celula %d", regulares[sizeRegular - 2].viatura->codigo, sizeRegular - 2);
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

void viaturaModoRonda()
{
    int op = 0;

    do {
        printf("\n Viatura direciondada para rondas, no aguardo de chamadas policiais.");
        printf("\n 1 - Voltar para o Menu principal.");
        scanf("%d", &op);
    } while (op != 1);

}

void viaturaChamada(regularViatura *regulares, int sizeRegular, especialViatura *especiais, int sizeEspecial, listaChamada *&chamadas, int tipo, int viaturaCode)
{

    int indice, acao;

    switch(tipo)
    {
        case 1:
            for(int i = 0; i < sizeRegular; i++)
            {
                if (viaturaCode == regulares[i].viatura->codigo)
                {
                    indice = i;
                    break;
                }
            }

            regularViatura *viaturaLogada = &regulares[indice];

            if(viaturaLogada->listaPrioritarias != NULL){
                printf("\n Descricao: %c", viaturaLogada->listaPrioritarias->chamada.descricao); 
                printf("\n Localização: %c", viaturaLogada->listaPrioritarias->chamada.loc);   

                printf("\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensada");

                scanf("%d", &acao);

                if(acao == 1){
                    viaturaOcorrencia();
                } else {
                    viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode);
                }
            }

            break

        
        case 2:



    }




}

void viaturaOcorrencia(){}
void solicitarReforcoRegular(){}
void prisaoRegular(){}
void encerrarOcorrenciaRegular(){}

void viaturaChamadaEspecial(regularViatura especiais){}
void encerrarOcorrenciaEspecial(){}
void prisaoEspecial(){}
void solicitarReforcoEspecial(){}

void pesquisarCPF(){}