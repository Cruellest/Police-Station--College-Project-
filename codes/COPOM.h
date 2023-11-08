
#ifndef COPOM_H
#define COPOM_H

#include "COPOM.cpp"

int distribui_chamada(struct listaChamada *listaChamadas, regularViatura *regulares, especialViatura *especiais);

void verif_reforco(struct listaChamada *listaChamadas, bool &reforcoLocal, struct Chamada *codChamada);

void inserir_reforco_regular(struct Chamada *codChamada, struct regularViatura *regulares);

void inserir_reforco_especial(struct Chamada *codChamada, struct especialViatura *especiais);

void cadastrarChamada(struct listaChamada *&listaChamadas, struct regularViatura *regulares, struct especialViatura *especiais);
#endif