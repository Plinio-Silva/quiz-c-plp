/*
 * tema2.c
 * Alunos: Plinio Tiago da Silva / (adicionar nome do colega, se houver)
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Tema 2: Conhecimentos Gerais (tecnologia, filmes e esportes).
 * Cada pergunta e montada por uma subrotina propria (funcao sem parametros).
 */
#include <stdio.h>
#include <string.h>
#include "../include/tema2.h"
#include "../include/perguntas.h"
#include "../include/interface.h"
#include "../include/temporizador.h"

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

typedef Pergunta (*FuncaoPergunta)(void);

static FuncaoPergunta perguntasTema2[TOTAL_PERGUNTAS] = {
    perguntaTema2_01, perguntaTema2_02, perguntaTema2_03, perguntaTema2_04,
    perguntaTema2_05, perguntaTema2_06, perguntaTema2_07, perguntaTema2_08,
    perguntaTema2_09, perguntaTema2_10
};

/* Exibe a pergunta e suas alternativas centralizadas na tela (procedimento com parametros) */
static void exibirPergunta(Pergunta pergunta, int numero) {
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
