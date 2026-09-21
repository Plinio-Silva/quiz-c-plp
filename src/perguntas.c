/*
 * perguntas.c
 * Aluno: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Tema 1: Conhecimentos Gerais (historia, geografia e ciencias).
 * Tema 2: Conhecimentos Gerais (tecnologia, filmes e esportes).
 * Cada pergunta e montada por uma subrotina propria (funcao sem parametros).
 */
#include <stdio.h>
#include <string.h>
#include "../include/quiz.h"

typedef Pergunta (*FuncaoPergunta)(void);

/* ======================= TEMA 1 ======================= */

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

static FuncaoPergunta perguntasTema1[TOTAL_PERGUNTAS] = {
    perguntaTema1_01, perguntaTema1_02, perguntaTema1_03, perguntaTema1_04,
    perguntaTema1_05, perguntaTema1_06, perguntaTema1_07, perguntaTema1_08,
    perguntaTema1_09, perguntaTema1_10
};

/* Exibe a pergunta e suas alternativas centralizadas na tela (procedimento com parametros) */
static void exibirPerguntaTema1(Pergunta pergunta, int numero) {
    (void)numero;
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

        exibirPerguntaTema1(pergunta, i + 1);
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

/* ======================= TEMA 2 ======================= */

static Pergunta perguntaTema2_01(void) {
    Pergunta p;
    strcpy(p.enunciado, "1) Qual linguagem de programacao foi usada neste quiz?");
    strcpy(p.alternativas[0], "A) Python");
    strcpy(p.alternativas[1], "B) C");
    strcpy(p.alternativas[2], "C) Java");
    strcpy(p.alternativas[3], "D) PHP");
    p.respostaCorreta = 'B';
    return p;
}

static Pergunta perguntaTema2_02(void) {
    Pergunta p;
    strcpy(p.enunciado, "2) Quem interpreta o personagem Iron Man nos filmes da Marvel?");
    strcpy(p.alternativas[0], "A) Chris Evans");
    strcpy(p.alternativas[1], "B) Chris Hemsworth");
    strcpy(p.alternativas[2], "C) Robert Downey Jr.");
    strcpy(p.alternativas[3], "D) Mark Ruffalo");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema2_03(void) {
    Pergunta p;
    strcpy(p.enunciado, "3) Quantos jogadores titulares tem um time de futebol em campo?");
    strcpy(p.alternativas[0], "A) 9");
    strcpy(p.alternativas[1], "B) 10");
    strcpy(p.alternativas[2], "C) 11");
    strcpy(p.alternativas[3], "D) 12");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema2_04(void) {
    Pergunta p;
    strcpy(p.enunciado, "4) Qual empresa criou o sistema operacional Windows?");
    strcpy(p.alternativas[0], "A) Apple");
    strcpy(p.alternativas[1], "B) Microsoft");
    strcpy(p.alternativas[2], "C) Google");
    strcpy(p.alternativas[3], "D) IBM");
    p.respostaCorreta = 'B';
    return p;
}

static Pergunta perguntaTema2_05(void) {
    Pergunta p;
    strcpy(p.enunciado, "5) Qual e o pais que mais venceu Copas do Mundo de futebol?");
    strcpy(p.alternativas[0], "A) Argentina");
    strcpy(p.alternativas[1], "B) Alemanha");
    strcpy(p.alternativas[2], "C) Italia");
    strcpy(p.alternativas[3], "D) Brasil");
    p.respostaCorreta = 'D';
    return p;
}

static Pergunta perguntaTema2_06(void) {
    Pergunta p;
    strcpy(p.enunciado, "6) O que significa a sigla CPU?");
    strcpy(p.alternativas[0], "A) Central Process Unit");
    strcpy(p.alternativas[1], "B) Central Processing Unit");
    strcpy(p.alternativas[2], "C) Computer Personal Unit");
    strcpy(p.alternativas[3], "D) Central Programming Unity");
    p.respostaCorreta = 'B';
    return p;
}

static Pergunta perguntaTema2_07(void) {
    Pergunta p;
    strcpy(p.enunciado, "7) Qual filme ganhou o Oscar de Melhor Filme em 2020?");
    strcpy(p.alternativas[0], "A) Parasita");
    strcpy(p.alternativas[1], "B) Coringa");
    strcpy(p.alternativas[2], "C) 1917");
    strcpy(p.alternativas[3], "D) Ford vs Ferrari");
    p.respostaCorreta = 'A';
    return p;
}

static Pergunta perguntaTema2_08(void) {
    Pergunta p;
    strcpy(p.enunciado, "8) Qual e a rede social criada por Mark Zuckerberg?");
    strcpy(p.alternativas[0], "A) Twitter");
    strcpy(p.alternativas[1], "B) Instagram");
    strcpy(p.alternativas[2], "C) Facebook");
    strcpy(p.alternativas[3], "D) LinkedIn");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema2_09(void) {
    Pergunta p;
    strcpy(p.enunciado, "9) Qual esporte e conhecido como 'rei dos esportes' no Brasil?");
    strcpy(p.alternativas[0], "A) Volei");
    strcpy(p.alternativas[1], "B) Basquete");
    strcpy(p.alternativas[2], "C) Futebol");
    strcpy(p.alternativas[3], "D) Tenis");
    p.respostaCorreta = 'C';
    return p;
}

static Pergunta perguntaTema2_10(void) {
    Pergunta p;
    strcpy(p.enunciado, "10) Qual e a extensao padrao de arquivos-fonte em C?");
    strcpy(p.alternativas[0], "A) .cpp");
    strcpy(p.alternativas[1], "B) .py");
    strcpy(p.alternativas[2], "C) .c");
    strcpy(p.alternativas[3], "D) .java");
    p.respostaCorreta = 'C';
    return p;
}

static FuncaoPergunta perguntasTema2[TOTAL_PERGUNTAS] = {
    perguntaTema2_01, perguntaTema2_02, perguntaTema2_03, perguntaTema2_04,
    perguntaTema2_05, perguntaTema2_06, perguntaTema2_07, perguntaTema2_08,
    perguntaTema2_09, perguntaTema2_10
};

/* Exibe a pergunta e suas alternativas centralizadas na tela (procedimento com parametros) */
static void exibirPerguntaTema2(Pergunta pergunta, int numero) {
    (void)numero;
    limparTela();
    definirCor(COR_AMARELO, COR_PRETO);
    centralizarTexto("TEMA 2 - CONHECIMENTOS GERAIS", 2);
    definirCor(COR_BRANCO, COR_PRETO);
    centralizarTexto(pergunta.enunciado, 5);
    centralizarTexto(pergunta.alternativas[0], 7);
    centralizarTexto(pergunta.alternativas[1], 8);
    centralizarTexto(pergunta.alternativas[2], 9);
    centralizarTexto(pergunta.alternativas[3], 10);
}

/* Executa as 10 perguntas do Tema 2 e acumula os resultados */
void executarTema2(int *acertos, int *erros) {
    int i;

    for (i = 0; i < TOTAL_PERGUNTAS; i++) {
        Pergunta pergunta = perguntasTema2[i]();
        char resposta;
        int respondeuATempo;

        exibirPerguntaTema2(pergunta, i + 1);
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
