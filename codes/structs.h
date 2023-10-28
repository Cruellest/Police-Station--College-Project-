//This file is used as an structs header


#define maxPM 4

//Struct of the officers cars
struct tViatura
{
    int codigo;

    int tipo; /* 1 = Policial Regular
                 2 = Policia Especializada */

    int estado; /* 0 = Neutro
                   1 = Livre
                   2 = Modo Ronda */

    int quantidadePM;

    char listaPM[maxPM];

};

//Struct of the officers
struct Policiais{
    char nome[26];

    int cpf;

    char guerra[16];

    char cidade[26];

    int idade;

    char cargo[26];

    char senha[17];

};

