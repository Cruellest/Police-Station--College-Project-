#include <stdio.h>
#include <string.h>
#include  "Loader.cpp"
/*

            viaturaLogin(viaturas, size, regulares, sizeRegular, especiais, sizeEspecial);
            for(int i = 0; i < sizeRegular; i++) {
                printf("%d", regulares[i].viatura->codigo);
            }
            for(int i = 0; i < sizeRegular; i++) {
                printf("%d", especiais[i].viatura->codigo);
            }

void logar(struct Viatura *viatura, int quantidadePM, struct tViaturaLogin *&I, struct tViaturaLogin *&F){
    struct tViaturaLogin *nova;
    char nomes[26+1];

    nova = (struct tViaturaLogin *) malloc(sizeof (struct tViaturaLogin));
    nova->viatura = viatura;
    
    printf("\nIdentificação dos PMs: ");

    for (int i = 0; i < quantidadePM; i++)
    {
        scanf(" %[^\n]", nomes);
        nova->policiais[i] = nomes[i];
    }

    nova->prox = NULL;

    if (I == NULL)
        I = F = nova;
    else
    {
    F->prox = nova;
    F = nova;
    }


}
*/

void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial) 
{
    int op1, op2;
    int viaturacode, quantidadePM, aux;

    printf("\n SPM - Viatura Login");

    printf("\n\n 1 - Policia Regular");
    printf("\n 2 - Policia Especializada");
    
    printf("\n\n Selecione o tipo de viatura: ");
    scanf(" %d", &op1);

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturacode);
    //validar se é do tipo correto e se já não está sendo utilizada.

    printf("\n Quantidade de PMs: ");
    scanf(" %d", &quantidadePM);

    for(;(op1 == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (op1 == 2 && quantidadePM != 4);){

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf(" %d", &quantidadePM);
    }

        aux = buscaViatura(0, size, viaturas, viaturacode);

        if (op1 == 1)
        {
            if (sizeRegular == 1)
            {
                regulares[0].viatura = &viaturas[aux];

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i == quantidadePM; i++)
                {
                    printf(" %[^\n]", regulares[i].policiais[i]);

    
                }

                sizeRegular++;

            } else {
                regulares = (regularViatura *) realloc(regulares, 1 * sizeof(regularViatura));

                regulares[sizeRegular - 1].viatura = &viaturas[aux];

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i == quantidadePM; i++)
                {
                    scanf(" %[^\n]", regulares[sizeRegular - 1].policiais[i]);;
                }

                sizeRegular++;
            }
        } else {
            if (sizeEspecial == 1)
            {
                especiais[0].viatura = &viaturas[aux];

                printf("\n Identificação dos PMs:");
                for (int i = 0; i == quantidadePM; i++)
                {
                    scanf("%[^\n]", especiais[0].policiais[i]);
                }

                sizeEspecial++;

            } else {
                especiais = (especialViatura *) realloc(especiais, 1 * sizeof(especialViatura));

                especiais[sizeEspecial - 1].viatura = &viaturas[aux];

                printf("\n Identificação dos PMs:");
                for (int i = 0; i == quantidadePM; i++)
                {
                    scanf("%[^\n]", especiais[sizeEspecial - 1].policiais[i]);
                }

                sizeEspecial++;
            }
        }

    printf("\n SPM - Viatura Estado Neutro");

    printf("\n\n 1 - Apto para atender ocorrência");
    printf("\n 2 - Cancelar Embarcação\n");
    scanf(" %d", &op2);

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