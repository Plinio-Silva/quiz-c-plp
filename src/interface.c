/*
 * interface.c
 * Alunos: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Implementa a interface visual do quiz: cores, centralizacao de texto,
 * tela de loading e efeito de piscar (feedback de acerto/erro).
 */
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../include/interface.h"

/* Move o cursor do console para a coluna/linha informadas */
void gotoxy(int coluna, int linha) {
    COORD posicao = { (SHORT)coluna, (SHORT)linha };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posicao);
}

void limparTela(void) {
    system("cls");
}

/* Define a cor do texto e do fundo (substitui textcolor/textbackground do Turbo C) */
void definirCor(int corTexto, int corFundo) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, (WORD)(corFundo * 16 + corTexto));
}

int obterLarguraConsole(void) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.srWindow.Right - info.srWindow.Left + 1;
}

/* Imprime o texto centralizado horizontalmente na linha informada */
void centralizarTexto(const char *texto, int linha) {
    int largura = obterLarguraConsole();
    int coluna = (largura - (int)strlen(texto)) / 2;
    if (coluna < 0) {
        coluna = 0;
    }
    gotoxy(coluna, linha);
    printf("%s", texto);
}

/* Tela inicial de apresentacao com animacao estilo loading */
void exibirTelaLoading(void) {
    int i, j;
    int largura = obterLarguraConsole();
    int colunaBarra = (largura - 30) / 2;

    limparTela();
    definirCor(COR_BRANCO_INTENSO, COR_PRETO);
    centralizarTexto("QUIZ - PARADIGMAS DE LINGUAGENS DE PROGRAMACAO", 8);
    definirCor(COR_AMARELO, COR_PRETO);

    for (i = 0; i <= 20; i++) {
        gotoxy(colunaBarra, 12);
        printf("Carregando [");
        for (j = 0; j < 20; j++) {
            putchar(j < i ? '#' : ' ');
        }
        printf("] %3d%%", i * 5);
        Sleep(80);
    }

    limparTela();
}

/* Tela inicial com o menu de escolha de tema */
void exibirTelaInicial(void) {
    limparTela();
    definirCor(COR_AMARELO, COR_PRETO);
    centralizarTexto("=== BEM-VINDO AO QUIZ ===", 5);
    definirCor(COR_BRANCO, COR_PRETO);
    centralizarTexto("Escolha um tema para comecar:", 7);
    centralizarTexto("1 - Tema 1 (Historia, Geografia e Ciencias)", 9);
    centralizarTexto("2 - Tema 2 (Tecnologia, Filmes e Esportes)", 10);
}

/* Faz a tela inteira piscar na cor informada, exibindo uma mensagem de feedback */
void piscarTela(int corFundo, const char *mensagem, int vezes) {
    int i;
    for (i = 0; i < vezes; i++) {
        definirCor(COR_PRETO, corFundo);
        system("cls");
        centralizarTexto(mensagem, 12);
        Sleep(300);
        definirCor(COR_BRANCO, COR_PRETO);
        system("cls");
        Sleep(150);
    }
    definirCor(COR_PRETO, corFundo);
    system("cls");
    centralizarTexto(mensagem, 12);
    Sleep(500);
    definirCor(COR_BRANCO, COR_PRETO);
    system("cls");
}
