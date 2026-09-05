/*
 * perguntas.h - Estrutura de dados compartilhada para as perguntas do quiz.
 */
#ifndef PERGUNTAS_H
#define PERGUNTAS_H

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

#endif /* PERGUNTAS_H */
