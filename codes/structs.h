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

};

struct prioritariaChamada{
    int id;

    int tipo;  /* 1 = Policial Regular
                 2 = Policia Especializada */

    struct Viatura *viaturas[26];

    char descricao[1000];

    char loc[1000];

    bool reforco = false;

    bool acaoPolicial = false;

    struct prioritariaChamada *prox;

};

struct Chamada{
    int id;

    int tipo;  /* 1 = Policial Regular
                 2 = Policia Especializada */

    struct Viatura *viaturas[26];

    char descricao[1000];

    char loc[1000];

    bool reforco = false;

    bool acaoPolicial = false;

    struct Chamada *prox;

};

struct regularViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    int chamadas;

};

struct especialViatura{

    struct Viatura *viatura;
    
    char policiais[4][26];

    int chamadas;

};

