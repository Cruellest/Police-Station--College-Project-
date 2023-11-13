#ifndef STRUCTS_H
#define STRUCTS_H
//This file is used as an structs header

//Struct of the officers cars
struct Viatura{
    int codigo;

    int tipo; /* 1 = Policial Regular
                 2 = Policia Especializada */

    int emUso = 0;

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


};

//Struct of the people
struct Pessoa{
    char nome[26];
    long cpf;
    char cidade[26];
    int idade;
    int numPassagens;
    char passagens[10][26];
    int numInadimplencias;
    char inadimplencias[10][26];

    
};

struct Chamada{

    int tipo;  /* 1 = Policia Regular
                 2 = Policia Especializada */

    int prioridade; /* 1 = Prioritária
                       2 = Não prioritária */

    char descricao[1000];

    char loc[1000];

    char policiais[4][26];

    bool reforco = false;

    bool acaoPolicial = false;

    int qntViaturas = 0;

    int estado = 0; /*0 = Não inicializada 
                1 = Inicializada
                2 =  Prisão em andamento
                3 = Encerrada */

    bool Boletim = false;

    int codigo;

    char BoletimTexto[3000];

    

};

struct listaChamada{
    struct Chamada *chamada;
    int qntChamada;
    int qntAtendida;
    struct listaChamada *prox;
};

struct regularViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    struct listaChamada *listaPrioritarias;

    struct listaChamada *listaChamadas;

    struct listaChamada *listaReforco;

    int qntChamadas = 0;

    int estado; /*0 = Em ronda (Livre)
                1 =  Atendendo chamada
                2 = Levando para a DP */;

    int menuNeutro = 0;

    int chamada = -1;

};

struct especialViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    struct listaChamada *listaChamadas;

    struct listaChamada *listaReforco;

    int qntChamadas = 0;

    int estado;  /*0 = Em ronda (Livre)
                1 =  Atendendo chamada
                2 = Levando para a DP */

    int menuNeutro = 0;

    int chamada = -1;

};

#endif