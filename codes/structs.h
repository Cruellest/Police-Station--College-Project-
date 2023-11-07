#ifndef STRUCTS_H
#define STRUCTS_H
//This file is used as an structs header

//Struct of the officers cars
struct Viatura{
    int codigo;

    int tipo; /* 1 = Policial Regular
                 2 = Policia Especializada */

};

//Struct of the officers
struct Policial{
    char nome[26];

    long cpf;

    char guerra[26];

    char cidade[26];

    int idade;

    char cargo[26];

    char senha[26];

    bool logado = 0;

};

struct Chamada{

    int tipo;  /* 1 = Policia Regular
                 2 = Policia Especializada */

    int prioridade; /* 1 = Prioritária
                       2 = Não prioritária */

    char descricao[1000];

    char loc[1000];

    bool reforco = false;

    bool acaoPolicial = false;

    int qntViaturas = 0;

};

struct listaChamada{
    struct Chamada chamada;
    struct listaChamada *prox;
};

struct regularViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    struct listaChamada *listaPrioritarias;

    struct listaChamada *listaChamadas;

    struct listaChamada *listaReforco;

    int qntChamadas = 0;

};

struct especialViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    struct listaChamada *listaChamadas;

    struct listaChamada *listaReforco;

    int qntChamadas = 0;

};

#endif