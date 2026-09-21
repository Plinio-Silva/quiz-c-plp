/*
 * quiz.h - Header unico do projeto (structs, constantes e prototipos).
 * Unificado para respeitar o limite de 5 arquivos definido pelo professor.
 */
#ifndef QUIZ_H
#define QUIZ_H

/* ---------- Perguntas ---------- */
#define TOTAL_PERGUNTAS 10
#define TOTAL_ALTERNATIVAS 4
#define TAM_ENUNCIADO 200
#define TAM_ALTERNATIVA 150

/* Representa uma pergunta com 4 alternativas e a letra da resposta correta (A, B, C ou D) */
typedef struct {
    char enunciado[TAM_ENUNCIADO];
    char alternativas[TOTAL_ALTERNATIVAS][TAM_ALTERNATIVA];
    char respostaCorreta;
} Pergunta;

/* Executa as 10 perguntas do tema indicado, acumulando os resultados em *acertos e *erros */
void executarTema1(int *acertos, int *erros);
void executarTema2(int *acertos, int *erros);

/* ---------- Interface (cores, centralizacao, animacoes) ---------- */
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

void limparTela(void);
void definirCor(int corTexto, int corFundo);
int obterLarguraConsole(void);
void centralizarTexto(const char *texto, int linha);
void exibirTelaLoading(void);
void exibirTelaInicial(void);
void piscarTela(int corFundo, const char *mensagem, int vezes);

/* ---------- Temporizador ---------- */
#define TEMPO_LIMITE_SEGUNDOS 30

/* Aguarda o usuario pressionar A, B, C ou D dentro do tempo informado.
 * Retorna 1 se respondeu a tempo (preenchendo *resposta) ou 0 se o tempo esgotou. */
int aguardarResposta(int segundos, char *resposta);

#endif /* QUIZ_H */
