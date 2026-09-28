/*
 * main.c
 * Aluno: Plinio Tiago da Silva
 * Disciplina: Paradigmas de Linguagens de Programacao (PLP)
 * Professor: Sergio Roberto Costa Vieira
 *
 * Ponto de entrada do QUIZ: exibe a apresentacao inicial, o menu de escolha
 * de tema, executa o tema selecionado e mostra a tela final de resultados.
 */
#include <stdio.h>
#include <conio.h>
#include "../include/quiz.h"

/* Exibe a tela final com a quantidade de acertos e erros do usuario */
static void exibirTelaFinal(int acertos, int erros) {
    char linhaAcertos[50];
    char linhaErros[50];

    /* Formata os numeros em textos que podem ser centralizados na tela. */
    sprintf(linhaAcertos, "Acertos: %d", acertos);
    sprintf(linhaErros, "Erros: %d", erros);

    limparTela();
    definirCor(COR_AMARELO, COR_PRETO);
    centralizarTexto("=== RESULTADO FINAL ===", 6);

    definirCor(COR_VERDE, COR_PRETO);
    centralizarTexto(linhaAcertos, 9);
    definirCor(COR_VERMELHO, COR_PRETO);
    centralizarTexto(linhaErros, 10);

    definirCor(COR_BRANCO, COR_PRETO);
    centralizarTexto("Pressione qualquer tecla para sair...", 14);
    getch();
}

/* Le a escolha do usuario (1 ou 2) no menu inicial */
static int lerOpcaoTema(void) {
    int opcao;
    char tecla;

    do {
        /* Converte o caractere digitado em seu valor numerico (por exemplo, '1' em 1). */
        tecla = getch();
        opcao = tecla - '0';
        /* Repete a leitura ate receber uma das duas opcoes validas. */
    } while (opcao != 1 && opcao != 2);

    return opcao;
}

int main(void) {
    int acertos = 0;
    int erros = 0;
    int opcao;

    exibirTelaLoading();
    exibirTelaBoasVindas();
    exibirTelaInicial();
    opcao = lerOpcaoTema();

    /* Cada tema atualiza o placar original por meio dos enderecos das variaveis. */
    if (opcao == 1) {
        executarTema1(&acertos, &erros);
    } else {
        executarTema2(&acertos, &erros);
    }

    exibirTelaFinal(acertos, erros);
    return 0;
}
