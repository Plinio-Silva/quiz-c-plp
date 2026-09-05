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
#include "../include/temporizador.h"
#include "../include/interface.h"

/* Aguarda o usuario pressionar A, B, C ou D dentro do tempo limite informado */
int aguardarResposta(int segundos, char *resposta) {
    int tempoRestante = segundos;

    while (tempoRestante > 0) {
        DWORD marcaSegundo = GetTickCount();

        definirCor(COR_CIANO, COR_PRETO);
        /* A biblioteca conio usa coordenadas de tela iniciadas em 1. */
        gotoxy(3, 20);
        printf("Tempo restante: %2d s   ", tempoRestante);
        definirCor(COR_BRANCO, COR_PRETO);

        while (GetTickCount() - marcaSegundo < 1000) {
            if (kbhit()) {
                char tecla = (char)toupper(getch());
                if (tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D') {
                    *resposta = tecla;
                    return 1;
                }
            }
            Sleep(20);
        }
        tempoRestante--;
    }

    *resposta = '\0';
    return 0;
}
