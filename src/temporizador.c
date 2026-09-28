/*
 * temporizador.c
 * Aluno: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Controla o temporizador de 30 segundos de cada pergunta, usando conio.h
 * para leitura de teclado sem bloquear a contagem (kbhit/getch).
 */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "../include/quiz.h"

/* Aguarda o usuario pressionar A, B, C ou D dentro do tempo limite informado */
int aguardarResposta(int segundos, char *resposta) {
    /* Uma variavel local permite descontar o tempo sem alterar a constante recebida. */
    int tempoRestante = segundos;

    while (tempoRestante > 0) {
        /* Marca o inicio deste segundo para medir um intervalo de aproximadamente 1000 ms. */
        DWORD marcaSegundo = GetTickCount();

        definirCor(COR_CIANO, COR_PRETO);
        /* A biblioteca conio usa coordenadas de tela iniciadas em 1. */
        gotoxy(3, 20);
        printf("Tempo restante: %2d s   ", tempoRestante);
        definirCor(COR_BRANCO, COR_PRETO);

        while (GetTickCount() - marcaSegundo < 1000) {
            /* kbhit verifica o teclado sem bloquear o restante da contagem. */
            if (kbhit()) {
                /* Padroniza a entrada para aceitar tanto letras minusculas quanto maiusculas. */
                char tecla = (char)toupper(getch());
                if (tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D') {
                    /* A resposta e gravada no endereco recebido e 1 sinaliza sucesso. */
                    *resposta = tecla;
                    return 1;
                }
            }
            /* Libera brevemente o processador antes de verificar o teclado de novo. */
            Sleep(20);
        }
        /* O segundo terminou sem resposta valida; reduz o tempo restante. */
        tempoRestante--;
    }

    /* O caractere nulo indica que nenhuma alternativa foi escolhida dentro do prazo. */
    *resposta = '\0';
    return 0;
}
