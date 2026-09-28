/*
 * interface.c
 * Aluno: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Implementa a interface visual do quiz: cores, centralizacao de texto,
 * tela de loading e efeito de piscar (feedback de acerto/erro).
 */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "../include/quiz.h"

/* Limpa a tela para que cada etapa do quiz tenha uma apresentacao propria. */
void limparTela(void) {
    system("cls");
}

/* Define a cor do texto e do fundo (substitui textcolor/textbackground do Turbo C) */
void definirCor(int corTexto, int corFundo) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    /* O Windows espera o texto e o fundo combinados em um unico valor. */
    SetConsoleTextAttribute(console, (WORD)(corFundo * 16 + corTexto));
}

int obterLarguraConsole(void) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    /* A janela pode ocupar apenas parte do buffer do console. */
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.srWindow.Right - info.srWindow.Left + 1;
}

static void desenharBordaTela(void) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    int largura, altura, coluna, linha;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    largura = info.srWindow.Right - info.srWindow.Left + 1;
    altura = info.srWindow.Bottom - info.srWindow.Top + 1;
    /* Evita desenhar uma borda que nao caberia em uma janela muito pequena. */
    if (largura < 5 || altura < 5) {
        return;
    }

    definirCor(COR_CIANO, COR_PRETO);
    gotoxy(2, 2);
    putchar('+');
    /* Desenha as linhas superior e inferior entre os cantos da moldura. */
    for (coluna = 3; coluna < largura - 1; coluna++) putchar('-');
    putchar('+');

    /* Percorre as linhas internas para ligar as bordas superior e inferior. */
    for (linha = 3; linha < altura - 1; linha++) {
        gotoxy(2, linha);
        putchar('|');
        gotoxy(largura - 1, linha);
        putchar('|');
    }

    gotoxy(2, altura - 1);
    putchar('+');
    for (coluna = 3; coluna < largura - 1; coluna++) putchar('-');
    putchar('+');
}

/* Imprime o texto centralizado horizontalmente na linha informada */
void centralizarTexto(const char *texto, int linha) {
    int largura = obterLarguraConsole();
    /* A diferenca entre a largura da tela e a do texto define as margens. */
    int coluna = (largura - (int)strlen(texto)) / 2;
    if (coluna < 0) {
        coluna = 0;
    }
    /* A conio usa coordenadas iniciadas em 1, por isso somamos 1 a coluna. */
    gotoxy(coluna + 1, linha + 1);
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

    /* Cada passo preenche mais um caractere e avanca a porcentagem em 5%. */
    for (i = 0; i <= 20; i++) {
        gotoxy(colunaBarra + 1, 13);
        printf("Carregando [");
        /* '#': parte concluida; espaco: parte que ainda falta carregar. */
        for (j = 0; j < 20; j++) {
            putchar(j < i ? '#' : ' ');
        }
        printf("] %3d%%", i * 5);
        Sleep(80);
    }

    limparTela();
}

/* Tela de entrada com botao simulado; Enter inicia a escolha de tema. */
void exibirTelaBoasVindas(void) {
    limparTela();
    desenharBordaTela();
    definirCor(COR_AMARELO, COR_PRETO);
    centralizarTexto("QUIZ - PARADIGMAS DE LINGUAGENS DE PROGRAMACAO", 7);
    definirCor(COR_BRANCO_INTENSO, COR_PRETO);
    centralizarTexto("Prepare-se para testar seus conhecimentos", 10);
    definirCor(COR_VERDE, COR_PRETO);
    centralizarTexto("[ INICIAR QUIZ ]", 13);
    definirCor(COR_BRANCO, COR_PRETO);
    centralizarTexto("Pressione ENTER para continuar", 15);
    /* getch aguarda uma tecla sem precisar pressionar Enter. */
    getch();
}

/* Tela inicial com o menu de escolha de tema */
void exibirTelaInicial(void) {
    limparTela();
    desenharBordaTela();
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
    /* Alterna entre a mensagem colorida e a tela limpa para criar o efeito. */
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
