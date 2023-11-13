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

void encerrarChamada(int tipo, regularViatura *regulares, especialViatura *especiais, int indice, int prioridade, int &acao)
{
        if (tipo == 1)
        {
            regulares[indice].estado = 0;
            if (prioridade == 2)
            {
                regulares[indice].listaChamadas->chamada->estado = 3;
                regulares[indice].listaChamadas = regulares[indice].listaChamadas->prox;
            } else if (prioridade == 1)
            {
                regulares[indice].listaPrioritarias->chamada->estado = 3;
                regulares[indice].listaPrioritarias = regulares[indice].listaPrioritarias->prox;
            } else if (prioridade == 0){
                regulares[indice].listaReforco->chamada->estado = 3;
                regulares[indice].listaReforco = regulares[indice].listaReforco->prox;
            }
        } else {
            especiais[indice].estado = 0;
            if (prioridade == 1)
            {
                especiais[indice].listaChamadas->chamada->estado = 3;
                especiais[indice].listaChamadas = especiais[indice].listaChamadas->prox;
            } else if (prioridade == 0){
                especiais[indice].listaReforco->chamada->estado = 3;
                especiais[indice].listaReforco = especiais[indice].listaReforco->prox;
            } 
        }
        acao = 2; 
}

void pesquisarCPF(struct Pessoa *pessoas, int sizePessoas){

    long cpfIndividuo;

    printf("\e[1;1H\e[2J");
    printf(" SPM - Viatura: Pesquisar por CPF");
    printf("\n\n CPF: ");

    scanf("%ld", &cpfIndividuo);
    int indice;

    for(int i = 0; i < sizePessoas; i++){
        if (pessoas[i].cpf == cpfIndividuo){
            indice = i;
        }
    }

    printf("\n\n Nome: %s", pessoas[indice].nome);
    printf("\n CPF: %ld", pessoas[indice].cpf);
    printf("\n Idade: %d", pessoas[indice].idade);
    printf("\n Cidade: %s", pessoas[indice].cidade);
    
    printf("\n Inadimplencias: ");
    for (int i = 0; i < pessoas[indice].numInadimplencias; i++){
        if(i == pessoas[indice].numInadimplencias - 1){
          printf("%s", pessoas[indice].inadimplencias[i]);  
        } else {
        printf("%s, ", pessoas[indice].inadimplencias[i]);
        }
    }

    printf("\n Passagens: ");
    for (int i = 0; i < pessoas[indice].numPassagens; i++){
        if(i == pessoas[indice].numPassagens - 1){
          printf("%s", pessoas[indice].passagens[i]);  
        } else {
        printf("%s, ", pessoas[indice].passagens[i]);
        }
    }

}

void solicitarReforco(int tipo, regularViatura *regulares, especialViatura *especiais, int indice, int prioridade)
{

    int op;

    do{
    printf("\e[1;1H\e[2J");
    printf(" SPM - Viatura: Solicitar Reforço");
    printf("\n\n 1 - Confirmar Solicitação de Reforços");
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

void prisaoAndamento(int tipo, regularViatura *regulares, especialViatura *especiais, int indice, int &opcao, int &acao)
{

    int qnt;

        printf("\e[1;1H\e[2J");
        printf(" SPM - Viatura: Prisão em Andamento");

    if(regulares[indice].estado != 2)
    {
        printf("\n\n Quantidade de indíviduo(s) conduzido(s) para DP: ");
        scanf(" %d", &qnt);
        printf("\n CPF: ");

        long *individuos = (long *) calloc(qnt, sizeof(long));

        long cpf;
        for (int i = 0; i < qnt; i++){
            scanf("\n %ld", &cpf);
            individuos[i] = cpf;
        }
    }

    int op;

    printf("\n\n 1 - Confirmar retorno da DP");
    printf("\n 2 - Voltar para o Menu Principal");
    printf("\n Opção: ");

    scanf(" %d", &op);

    if (op == 1){
        if(tipo == 1){

                regulares[indice].estado = 0;
        } else {

                especiais[indice].estado = 0;
        }

        opcao = 4;     

    } else {
        if(tipo == 1){

                regulares[indice].estado = 2;
        } else {

                especiais[indice].estado = 2;
        }

        acao = 3;
        opcao = 5;

    }

}

void viaturaOcorrencia(regularViatura *regulares, especialViatura *especiais, int tipo, int indice, int prioridade, Pessoa *pessoas, int sizePessoa, int &acao)
{

    int op;

    do{

        printf("\e[1;1H\e[2J");
        printf(" SPM - Viatura: Ocorrências");

        printf("\n\n 1 - Pesquisar por CPF");
        printf("\n 2 - Solicitar Reforços");
        printf("\n 3 - Prisão em Andandamento");
        printf("\n 4 - Encerrar Ocorrência");

        printf("\n Opção: ");
        scanf(" %d", &op);

        if(op == 1) //Pesquisar por CPF.
        {
            pesquisarCPF(pessoas, sizePessoa);   
        }

        else if(op == 2) //Solicitar Reforços.
        {
            solicitarReforco(tipo, regulares, especiais, indice, prioridade);
        }

        else if(op == 3) //Prisão em andamento
        {
            prisaoAndamento(tipo, regulares, especiais, indice, op, acao);
        }

        } while (op != 4 && op != 5);

        if(op == 4)
        {
            encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
        }

}

void viaturaModoRonda()
{
    int op = 0;

    do {
        printf("\e[1;1H\e[2J");
        printf(" SPM - Viatura: Modo Ronda");

        printf("\n\n Viatura direciondada para rondas, no aguardo de chamadas policiais");
        
        printf("\n\n 1 - Voltar para o Menu principal.");
        printf("\n Opção: ");
        scanf(" %d", &op);
    } while (op != 1);

}

void viaturaEstadoNeutro(regularViatura *regulares, int sizeRegular, especialViatura *especiais, int sizeEspecial, listaChamada *&chamadas, int tipo, int viaturaCode,  Pessoa *pessoas, int sizePessoa)
{
    int op2, indice;

            if(tipo == 1){
                for(int i = 0; i < sizeRegular; i++)
                {
                    if (viaturaCode == regulares[i].viatura->codigo)
                    {
                        indice = i;
                        break;
                    }
                }

                if (regulares[indice].menuNeutro == 0)
                {
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Viatura: Estado Neutro");

                    printf("\n\n 1 - Apto para atender ocorrência");
                    printf("\n 2 - Cancelar Embarcação");
                    printf("\n Opção: ");
                    scanf(" %d", &op2);
                } else {
                    op2 = 1;
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
                
                if (especiais[indice].menuNeutro == 0)
                {
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Viatura: Estado Neutro");

                    printf("\n\n 1 - Apto para atender ocorrência");
                    printf("\n 2 - Cancelar Embarcação");
                    printf("\n Opção: ");
                    scanf(" %d", &op2);
                } else {
                    op2 = 1;
                }
            }


    if(op2 == 1){
        
        if (tipo == 1)
        {
            quicksortRegular(regulares, 0, sizeRegular);
        } else {
            quicksortEspecial(especiais, 0, sizeEspecial);
        }

        int distribuiu = distribui_chamada(chamadas, regulares, especiais);

        if (distribuiu < 0){
            
            if(tipo == 1){
                for(int i = 0; i < sizeRegular; i++)
                {
                    if (viaturaCode == regulares[i].viatura->codigo)
                    {
                        indice = i;
                        break;
                    }
                }
                regulares[indice].menuNeutro = 1;
                regulares[indice].estado = 0;
            } else {
                regulares[indice].menuNeutro = 1;
                for(int i = 0; i < sizeEspecial; i++)
                {
                    if (viaturaCode == especiais[i].viatura->codigo)
                    {
                        indice = i;
                        break;
                    }
                }
                especiais[indice].estado = 0;
            }
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
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Solicitação de Reforço");
                            
                    printf("\n\n Descricao: %s", viaturaLogada->listaReforco->chamada->descricao); 
                    printf("\n Localização: %s", viaturaLogada->listaReforco->chamada->loc);   
                   
                    printf("\n\n 1 - Confirmada Ação Policial\n 2 - Reforço Dispensado");
                    printf("\n Opção: ");

                    scanf(" %d", &acao);

                    int prioridade = 0;
                    viaturaLogada->chamada = prioridade;
                    while(acao != 2 && acao != 3)
                    {
                        viaturaLogada->estado = 1;
                        viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
                    }

                    if (acao == 2){
                        encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }                
                
                } else if (viaturaLogada->listaPrioritarias != NULL && viaturaLogada->listaReforco == NULL){
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Chamada Policial Prioritária");

                    printf("\n\n Descricao: %s", viaturaLogada->listaPrioritarias->chamada->descricao); 
                    printf("\n Localização: %s", viaturaLogada->listaPrioritarias->chamada->loc);   

                    printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                    printf("\n Opção: ");

                    scanf(" %d", &acao);

                    int prioridade = 1;
                    viaturaLogada->chamada = prioridade;
                    while(acao != 2 && acao != 3)
                    {
                        viaturaLogada->estado = 1;
                        viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
                    }

                    if (acao == 2){
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }else if (acao == 3){
                        encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }

                } else if (viaturaLogada->listaChamadas != NULL && viaturaLogada->listaPrioritarias == NULL && viaturaLogada->listaReforco == NULL){
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Chamada Policial");

                    printf("\n\n Descricao: %s", viaturaLogada->listaChamadas->chamada->descricao); 
                    printf("\n Localização: %s", viaturaLogada->listaChamadas->chamada->loc);   
 
                    printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                    printf("\n Opção: ");

                    scanf(" %d", &acao);

                    int prioridade = 2;
                    viaturaLogada->chamada = prioridade;
                    while(acao != 2 && acao != 3)
                    {
                        viaturaLogada->estado = 1;
                        viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
                    }

                    if (acao == 2){
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }else if (acao == 3){
                        encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }
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
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Solicitção de Reforço");

                    printf("\n\n Descricao: %s", viaturaLogada->listaReforco->chamada->descricao); 
                    printf("\n Localização: %s", viaturaLogada->listaReforco->chamada->loc);   

                    printf("\n\n 1 - Confirmada Ação Policial\n 2 - Reforço Dispensado");
                    printf("\n Opção: ");

                    scanf(" %d", &acao);

                    int prioridade = 0;
                    viaturaLogada->chamada = prioridade;
                    while(acao != 2 && acao != 3)
                    {
                        viaturaLogada->estado = 1;
                        viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
                    }

                    if (acao == 2){
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }else if (acao == 3){
                        encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    } 

                } else if (viaturaLogada->listaChamadas != NULL && viaturaLogada->listaReforco == NULL){
                    printf("\e[1;1H\e[2J");
                    printf(" SPM - Chamada Policial");

                    printf("\n\n Descricao: %s", viaturaLogada->listaChamadas->chamada->descricao); 
                    printf("\n Localização: %s", viaturaLogada->listaChamadas->chamada->loc);   

                    printf("\n\n 1 - Confirmada Ação Policial\n 2 - Ação Policial Dispensado");
                    printf("\n Opção: ");

                    scanf(" %d", &acao);

                    int prioridade = 1;
                    viaturaLogada->chamada = prioridade;
                    while(acao != 2 && acao != 3)
                    {
                        viaturaLogada->estado = 1;
                        viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
                    }
                    if (acao == 2){
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }else if (acao == 3){
                        encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
                        viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
                    }    
                }
            }
        }


    } else {
        if(tipo == 1)
        {
            sizeRegular = sizeRegular - 1;
            regulares = (regularViatura *) realloc(regulares, sizeRegular * sizeof(regularViatura));
        } else {
            sizeRegular = sizeEspecial - 1;
            especiais = (especialViatura *) realloc(especiais, sizeEspecial * sizeof(especialViatura));
        }
    }
}

void viaturaEmUso(regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial, listaChamada *&chamadas,  Pessoa *pessoas, int sizePessoa)
{

    int viaturaCode, tipo;
    int indice = 2208;
    /*Collecting user input:*/
    printf("\e[1;1H\e[2J");
    printf("\n SPM - Viatura: Em Uso");
    printf("\n\n Identificador da Viatura: ");

    scanf(" %d", &viaturaCode);

        for(int i = 0; i < sizeRegular; i++)
        {
                if (viaturaCode == regulares[i].viatura->codigo)
                {
                    indice = i;
                    tipo = 1;
                    break;
                }
        }

        if (indice == 2208){
            for(int i = 0; i < sizeEspecial; i++)
            {
                if (viaturaCode == especiais[i].viatura->codigo)
                {
                    indice = i;
                    tipo = 2;
                    break;
                }
            }  
        }

    if (tipo == 1){
        if (regulares[indice].listaReforco == NULL && regulares[indice].listaPrioritarias == NULL && regulares[indice].listaChamadas == NULL)
        {
            regulares[indice].estado = 0;
        } 
        
        if (regulares[indice].estado == 0){
            viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
        }

        if (regulares[indice].estado == 1){
            int prioridade;
            int acao = 1;
            regularViatura *viaturaLogada = &regulares[indice]; 

            if (viaturaLogada->chamada == 0){
                prioridade = 0;
            } else if (viaturaLogada->chamada == 1){
                prioridade = 1;
            } else if (viaturaLogada->chamada == 2){
                prioridade = 2;
            }
        

            while(acao != 2 && acao != 3)
            {
                viaturaLogada->estado = 1;
                viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
            }

        }

        if (regulares[indice].estado == 2){
            int op = 3;
            int acao = 2;
            int prioridade;
            regularViatura *viaturaLogada = &regulares[indice]; 

            if (viaturaLogada->chamada == 0){
                prioridade = 0;
            } else if (viaturaLogada->chamada == 1){
                prioridade = 1;
            } else if (viaturaLogada->chamada == 2){
                prioridade = 2;
            }

            do {
                prisaoAndamento(tipo, regulares, especiais, indice, op, acao);
            } while (op != 4 && op != 5);

            if(op == 4)
            {
                encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
            }
            
        }


    } else {
        if (especiais[indice].listaReforco == NULL && especiais[indice].listaChamadas == NULL)
        {
            especiais[indice].estado = 0;
        } 
        
        if (especiais[indice].estado == 0){
            viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, chamadas, tipo, viaturaCode, pessoas, sizePessoa);
        }

        if (regulares[indice].estado == 1){
            int prioridade;
            int acao = 1;
            especialViatura *viaturaLogada = &especiais[indice]; 

            if (viaturaLogada->chamada == 0){
                prioridade = 0;
            } else if (viaturaLogada->chamada == 1){
                prioridade = 1;
            } else if (viaturaLogada->chamada == 2){
                prioridade = 2;
            }
        

            while(acao != 2 && acao != 3)
            {
                viaturaLogada->estado = 1;
                viaturaOcorrencia(regulares, especiais, tipo, indice, prioridade, pessoas, sizePessoa, acao);
            }

        }

        if (especiais[indice].estado == 2){
            int op = 3;
            int acao = 2;
            int prioridade;
            regularViatura *viaturaLogada = &regulares[indice]; 

            if (viaturaLogada->chamada == 0){
                prioridade = 0;
            } else if (viaturaLogada->chamada == 1){
                prioridade = 1;
            }

            do {
                prisaoAndamento(tipo, regulares, especiais, indice, op, acao);
            } while (op != 4 && op != 5);

            if(op == 4)
            {
                encerrarChamada(tipo, regulares, especiais, indice, prioridade, acao);
            }
            
        }

    }
    
}
//alocar dinamicamente viaturas;

void viaturaLogin(Viatura *viaturas, int size, regularViatura *regulares, int &sizeRegular, especialViatura *especiais, int &sizeEspecial, listaChamada *listaChamadas, Pessoa *pessoas, int sizePessoa) 
{
    /*Starting variables:*/
    int tipo;
    int viaturaCode, quantidadePM, viaturaVetor;


    /*Collecting user input:*/
    printf("\e[1;1H\e[2J");
    printf(" SPM - Viatura: Login");
    
    printf("\n\n 1 - Polícia Regular");
    printf("\n 2 - Polícia Especializada"); 
    printf("\n Selecione o tipo de viatura: ");
    scanf(" %d", &tipo);
    
    while(tipo < 1 || tipo > 2) //error handling:
    {
        printf("\n\n Tipo inexistente");
        printf("\n Selecione o tipo de viatura: ");
        scanf(" %d", &tipo);
    }

    printf("\n Código da Viatura: ");
    scanf(" %d", &viaturaCode);


    /*Search for the vehicle index in the list of vehicles*/
    viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);

    //checks and error handling:
    while(viaturas[viaturaVetor].emUso == 1)
    {
        printf("\n\n Viatura selecionada em uso");
        printf("\n Código da Viatura: ");
        scanf(" %d", &viaturaCode);
        viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);
    }
    viaturas[viaturaVetor].emUso = 1;

    //checks and error handling:
    while((tipo == 1 && viaturas[viaturaVetor].tipo != 1) || (tipo == 2 && viaturas[viaturaVetor].tipo != 2))
    {
        printf("\n\n O código inserido não corresponde a uma viatura do tipo selecionado");   
        printf("\n Código da Viatura: ");
        scanf(" %d", &viaturaCode);
        viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);

        while(viaturas[viaturaVetor].emUso == 1)
        {
                printf("\n\n Viatura selecionada em uso");
                printf("\n Código da Viatura: ");
                scanf(" %d", &viaturaCode);
                viaturaVetor = buscaBinaria(viaturas, size, viaturaCode);
        }
        viaturas[viaturaVetor].emUso = 1;
    }

    printf("\n Quantidade de PMs: ");
    scanf("%d", &quantidadePM);

    //checks and error handling:
    while((tipo == 1 && quantidadePM < 2) || (quantidadePM > 4)
        || (tipo == 2 && quantidadePM != 4))
    {
        printf("\n\n Quantidade de PMs inválida! Autorização de embarque negada");
        printf("\n Quantidade de PMs: ");
        scanf(" %d", &quantidadePM);
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

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %s", regulares[0].policiais[i]);
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

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %s", regulares[sizeRegular - 1].policiais[i]);;
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

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %s", especiais[0].policiais[i]);
                }

                sizeEspecial++;

            } else {
                especiais = (especialViatura *) realloc(especiais, sizeEspecial * sizeof(especialViatura));

                especiais[sizeEspecial - 1].viatura = &viaturas[viaturaVetor];

                especiais[sizeEspecial - 1].listaChamadas = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[sizeEspecial - 1].listaChamadas = NULL;

                especiais[sizeEspecial - 1].listaReforco = (listaChamada *) malloc(sizeof(listaChamada));
                especiais[sizeEspecial - 1].listaReforco = NULL;

                printf("\n Identificação dos PMs: ");
                for (int i = 0; i < quantidadePM; i++)
                {
                    scanf(" %s", especiais[sizeEspecial - 1].policiais[i]);
                }
                sizeEspecial++;
            }
        }
    viaturaEstadoNeutro(regulares, sizeRegular, especiais, sizeEspecial, listaChamadas, tipo, viaturaCode, pessoas, sizePessoa);
}