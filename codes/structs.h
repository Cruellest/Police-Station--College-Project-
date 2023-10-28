#define maxPM 4

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

struct PM{
    char nome[26];

    int cpf;

    char guerra[16];

    char cidade[26];

    int idade;

    char cargo[26];

    char senha[17];

};

