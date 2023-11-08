#ifndef viaturaFuncionalidade.H
#define viaturaFuncionalidade.H

void viaturaEstadoNeutro(regularViatura regulares[], int sizeRegular, especialViatura especiais[], int sizeEspecial, listaChamada chamadas[], int tipo, int viaturaCode);

void viaturaModoRonda();

void viaturaChamadaRegular(regularViatura regulares);

void solicitarReforcoRegular();
void prisaoRegular();
void encerrarOcorrenciaRegular();

void viaturaChamadaEspecial(regularViatura especiais);
void encerrarOcorrenciaEspecial();
void prisaoEspecial();
void solicitarReforcoEspecial();

void pesquisarCPF();

#endif

