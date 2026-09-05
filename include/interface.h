/*
 * interface.h - Funcoes de apresentacao visual do quiz (cores, centralizacao, animacoes).
 * Substitui as funcoes classicas do Turbo C (gotoxy, textcolor, clrscr), que nao existem
 * no conio.h do MinGW/UCRT64, usando a API do Windows por baixo dos panos.
 */
#ifndef INTERFACE_H
#define INTERFACE_H

/* Cores compativeis com SetConsoleTextAttribute (0-15) */
#define COR_PRETO           0
#define COR_AZUL            1
#define COR_VERDE           2
#define COR_CIANO           3
#define COR_VERMELHO        4
#define COR_MAGENTA         5
#define COR_AMARELO         6
#define COR_BRANCO          7
#define COR_CINZA           8
#define COR_BRANCO_INTENSO  15

void gotoxy(int coluna, int linha);
void limparTela(void);
void definirCor(int corTexto, int corFundo);
int obterLarguraConsole(void);
void centralizarTexto(const char *texto, int linha);
void exibirTelaLoading(void);
void exibirTelaInicial(void);
void piscarTela(int corFundo, const char *mensagem, int vezes);

#endif /* INTERFACE_H */
