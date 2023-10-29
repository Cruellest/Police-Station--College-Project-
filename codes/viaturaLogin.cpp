#include <stdio.h>
#include  "Loader.cpp"

void logar(struct tViatura *viatura, int quantidadePM, struct tViaturaLogin *&I, struct tViaturaLogin *&F){
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

void viaturaLogin(struct tViatura viaturas[], struct tViaturaLogin *&I, struct tViaturaLogin *&F) 
{
    int op;
    int viaturacode, quantidadePM;

    printf("\n Policia Regular - 1");
    printf("\n Policia Especializada - 2");
    
    printf("\n Selecione o tipo da aviatura: ");
    scanf(" %d", &op);

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturacode);
    
    //validar se é do tipo correto e se já não está sendo utilizada.

    printf("\n Quantidade de PMs: ");
    scanf(" %d", &quantidadePM);

    for(;(op == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (op == 2 && quantidadePM != 4);){

        printf("\n Quantidade de PMs invalida! Autorização de embarque negada.");
        printf("\n Quantidade de PMs: ");
        scanf(" %d", &quantidadePM);
    }

    int viaturaID = busca_binaria_R(0, 10, viaturas, viaturacode);

    logar(&viaturas[viaturaID], quantidadePM, I, F);

}