/*
 * tema1.c
 * Aluno: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Tema 1: Conhecimentos Gerais (historia, geografia e ciencias).
 * Cada pergunta e montada por uma subrotina propria (funcao sem parametros).
 */
#include <stdio.h>
#include <string.h>
#include "../include/tema1.h"
#include "../include/perguntas.h"
#include "../include/interface.h"
#include "../include/temporizador.h"

static Pergunta perguntaTema1_01(void) {
    Pergunta p;
    strcpy(p.enunciado, "1) Qual e o maior planeta do Sistema Solar?");
    strcpy(p.alternativas[0], "A) Terra");
    strcpy(p.alternativas[1], "B) Marte");
    strcpy(p.alternativas[2], "C) Jupiter");
    strcpy(p.alternativas[3], "D) Saturno");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema1_02(void) {
    Pergunta p;
    strcpy(p.enunciado, "2) Em que ano ocorreu a Proclamacao da Republica no Brasil?");
    strcpy(p.alternativas[0], "A) 1822");
    strcpy(p.alternativas[1], "B) 1889");
    strcpy(p.alternativas[2], "C) 1900");
    strcpy(p.alternativas[3], "D) 1945");
    p.respostaCorreta = 'B';
    return p;
}

static Pergunta perguntaTema1_03(void) {
    Pergunta p;
    strcpy(p.enunciado, "3) Qual e o maior oceano do mundo?");
    strcpy(p.alternativas[0], "A) Atlantico");
    strcpy(p.alternativas[1], "B) Indico");
    strcpy(p.alternativas[2], "C) Artico");
    strcpy(p.alternativas[3], "D) Pacifico");
    p.respostaCorreta = 'D';
    return p;
}

static Pergunta perguntaTema1_04(void) {
    Pergunta p;
    strcpy(p.enunciado, "4) Quem pintou a Mona Lisa?");
    strcpy(p.alternativas[0], "A) Leonardo da Vinci");
    strcpy(p.alternativas[1], "B) Pablo Picasso");
    strcpy(p.alternativas[2], "C) Vincent van Gogh");
    strcpy(p.alternativas[3], "D) Michelangelo");
    p.respostaCorreta = 'A';
    return p;
}

static Pergunta perguntaTema1_05(void) {
    Pergunta p;
    strcpy(p.enunciado, "5) Qual e o menor pais do mundo em area territorial?");
    strcpy(p.alternativas[0], "A) Monaco");
    strcpy(p.alternativas[1], "B) Vaticano");
    strcpy(p.alternativas[2], "C) San Marino");
    strcpy(p.alternativas[3], "D) Liechtenstein");
    p.respostaCorreta = 'B';
    return p;
}

static Pergunta perguntaTema1_06(void) {
    Pergunta p;
    strcpy(p.enunciado, "6) Qual e o orgao do corpo humano responsavel por bombear sangue?");
    strcpy(p.alternativas[0], "A) Pulmao");
    strcpy(p.alternativas[1], "B) Figado");
    strcpy(p.alternativas[2], "C) Coracao");
    strcpy(p.alternativas[3], "D) Rim");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema1_07(void) {
    Pergunta p;
    strcpy(p.enunciado, "7) Qual e o maior deserto quente do mundo?");
    strcpy(p.alternativas[0], "A) Deserto do Saara");
    strcpy(p.alternativas[1], "B) Deserto de Gobi");
    strcpy(p.alternativas[2], "C) Deserto do Atacama");
    strcpy(p.alternativas[3], "D) Deserto da Australia");
    p.respostaCorreta = 'A';
    return p;
}

static Pergunta perguntaTema1_08(void) {
    Pergunta p;
    strcpy(p.enunciado, "8) Quantos ossos tem o corpo humano adulto, aproximadamente?");
    strcpy(p.alternativas[0], "A) 106");
    strcpy(p.alternativas[1], "B) 156");
    strcpy(p.alternativas[2], "C) 206");
    strcpy(p.alternativas[3], "D) 256");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema1_09(void) {
    Pergunta p;
    strcpy(p.enunciado, "9) Qual e a capital da Australia?");
    strcpy(p.alternativas[0], "A) Sydney");
    strcpy(p.alternativas[1], "B) Melbourne");
    strcpy(p.alternativas[2], "C) Camberra");
    strcpy(p.alternativas[3], "D) Perth");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema1_10(void) {
    Pergunta p;
    strcpy(p.enunciado, "10) Qual e o elemento quimico de simbolo O?");
    strcpy(p.alternativas[0], "A) Ouro");
    strcpy(p.alternativas[1], "B) Oxigenio");
    strcpy(p.alternativas[2], "C) Osmio");
    strcpy(p.alternativas[3], "D) Oganessonio");
    p.respostaCorreta = 'B';
    return p;
}

typedef Pergunta (*FuncaoPergunta)(void);

static FuncaoPergunta perguntasTema1[TOTAL_PERGUNTAS] = {
    perguntaTema1_01, perguntaTema1_02, perguntaTema1_03, perguntaTema1_04,
    perguntaTema1_05, perguntaTema1_06, perguntaTema1_07, perguntaTema1_08,
    perguntaTema1_09, perguntaTema1_10
};

/* Exibe a pergunta e suas alternativas centralizadas na tela (procedimento com parametros) */
static void exibirPergunta(Pergunta pergunta, int numero) {
    limparTela();
    definirCor(COR_AMARELO, COR_PRETO);
    centralizarTexto("TEMA 1 - CONHECIMENTOS GERAIS", 2);
    definirCor(COR_BRANCO, COR_PRETO);
    centralizarTexto(pergunta.enunciado, 5);
    centralizarTexto(pergunta.alternativas[0], 7);
    centralizarTexto(pergunta.alternativas[1], 8);
    centralizarTexto(pergunta.alternativas[2], 9);
    centralizarTexto(pergunta.alternativas[3], 10);
}

/* Executa as 10 perguntas do Tema 1 e acumula os resultados */
void executarTema1(int *acertos, int *erros) {
    int i;

    for (i = 0; i < TOTAL_PERGUNTAS; i++) {
        Pergunta pergunta = perguntasTema1[i]();
        char resposta;
        int respondeuATempo;

        exibirPergunta(pergunta, i + 1);
        respondeuATempo = aguardarResposta(TEMPO_LIMITE_SEGUNDOS, &resposta);

        if (respondeuATempo && resposta == pergunta.respostaCorreta) {
            (*acertos)++;
            piscarTela(COR_VERDE, "CORRETO!", 3);
        } else {
            (*erros)++;
            piscarTela(COR_VERMELHO, "INCORRETO!", 3);
        }
    }
}
