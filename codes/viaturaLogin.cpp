#include <stdio.h>
#include <string.h>
#include  "Loader.cpp"

void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial) 
{
    /*Starting variables:*/
    int op1, op2;
    int viaturaCode, quantidadePM, viaturaVetor, verifRegular, verifEspecial;


    /*Collecting user input:*/
    printf("\n SPM - Viatura Login");
    printf("\n\n 1 - Policia Regular");
    printf("\n 2 - Policia Especializada");
    
    printf("\n\n Selecione o tipo de viatura: ");
    scanf(" %d", &op1);
    
    while(op1 < 1 || op1 > 2) //error handling:
    {
        printf("\n Tipo inexistente.");
        printf("\n Selecione o tipo de viatura: ");
        scanf(" %d", &op1);
    }

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturaCode);


    /*Search for the vehicle index in the list of vehicles*/
    viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);

    //checks and error handling:
    for(;(op1 == 1 && viaturas[viaturaVetor].tipo != 1) || (op1 == 2 && viaturas[viaturaVetor].tipo != 2);)
    {
        printf("\nO código inserido não corresponde a uma viatura do tipo selecionado.");   
        printf("\n Código da Viatura: ");
        scanf(" %d", &viaturaCode);
        viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);
    }

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

    printf("\n Quantidade de PMs: ");
    scanf(" %d", &quantidadePM);

    //checks and error handling:
    for(;(op1 == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (op1 == 2 && quantidadePM != 4);)
    {

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf(" %d", &quantidadePM);
    }


    /*Saving data into their corresponding vectors:*/
    if (op1 == 1)
    {
            if (sizeRegular == 1)
            {
                regulares[0].viatura = &viaturas[viaturaVetor];

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", regulares[0].policiais[i]);
                }

                sizeRegular++;

            } else {
                regulares = (regularViatura *) realloc(regulares, sizeRegular * sizeof(regularViatura));

                regulares[sizeRegular - 1].viatura = &viaturas[viaturaVetor];

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

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", especiais[0].policiais[i]);
                }

                sizeEspecial++;

            } else {
                especiais = (especialViatura *) realloc(especiais, sizeEspecial * sizeof(especialViatura));

                especiais[sizeEspecial - 1].viatura = &viaturas[viaturaVetor];

                printf("\n Identificação dos PMs:");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %[^\n]", especiais[sizeEspecial - 1].policiais[i]);
                }
                sizeEspecial++;
            }
        }

    printf("\n SPM - Viatura Estado Neutro");

    printf("\n\n 1 - Apto para atender ocorrência");
    printf("\n 2 - Cancelar Embarcação\n");
    scanf(" %d", &op2);

    //if(op2 == 1){implementar após criar função COPOM};

    /*Removing discarded data:*/
    if(op2 == 2)
    {
        if(op1 == 1)
        {
            regulares = (regularViatura *) realloc(regulares, sizeRegular - 1 * sizeof(regularViatura));
        } else {
            especiais = (especialViatura *) realloc(especiais, sizeEspecial - 1 * sizeof(especialViatura));

        }
    }

}