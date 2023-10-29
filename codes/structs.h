//This file is used as an structs header

//Struct of the officers cars
struct tViatura{
    int codigo;

    int tipo; /* 1 = Policial Regular
                 2 = Policia Especializada */

};

//Struct of the officers
struct Policiais{
    char nome[26];

    long cpf;

    char guerra[26];

    char cidade[26];

    int idade;

    char cargo[26];

    char senha[26];

};

struct tChamada{
    int id;

    int tipo;  /* 1 = Policial Regular
                 2 = Policia Especializada */

    int prioridade;

    struct tViatura *viaturas[26];

    char descricao[1000];

    char loc[1000];

    bool reforco = false;

    bool acaoPolicial = false;

    struct tChamada *prox;

};

struct tViaturaLogin{

    struct tViatura *viatura;
    
    char policiais[4];

    struct tViaturaLogin *prox;

};