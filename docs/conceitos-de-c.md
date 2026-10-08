# Conceitos de C aplicados ao projeto Quiz

Este guia explica conceitos de programação em C usando exemplos do quiz. Os caminhos indicam onde encontrar cada trecho no projeto.

## Onde as funções ficam

O projeto separa as funções em três partes:

| Parte | Onde encontrar | Exemplo |
| --- | --- | --- |
| Protótipos, que anunciam a função | [include/quiz.h](../include/quiz.h) | `void executarTema1(int *acertos, int *erros);` |
| Implementações, que contêm as instruções | Arquivos dentro de [src](../src) | `executarTema1` está em `perguntas.c` |
| Chamadas, que executam a função | Outras funções do programa | `main` chama `executarTema1` ou `executarTema2` |

O protótipo permite que um arquivo conheça uma função implementada em outro. Por exemplo, `main.c` inclui `quiz.h` para poder chamar as funções de interface, temporizador e perguntas.

## Função, parâmetros e retorno

Uma função reúne instruções para realizar uma tarefa. Parâmetros são os dados recebidos; o tipo antes do nome indica o tipo de valor que ela retorna.

Em [src/main.c](../src/main.c), `lerOpcaoTema` não recebe parâmetros e retorna um `int`:

```c
static int lerOpcaoTema(void) {
    int opcao;
    char tecla;

    do {
        tecla = getch();
        opcao = tecla - '0';
    } while (opcao != 1 && opcao != 2);

    return opcao;
}
```

`int` informa que a função devolve um inteiro. `return opcao` encerra a função e entrega esse valor a quem a chamou. O `do...while` repete a leitura enquanto a opção não for 1 nem 2. A expressão `tecla - '0'` converte o caractere numérico, como `'1'`, no inteiro correspondente, como `1`.

Uma função também pode receber parâmetros. `exibirTelaFinal(int acertos, int erros)`, no mesmo arquivo, recebe dois inteiros para montar e mostrar o placar.

## O que significa `void`

`void` aparece em dois lugares com significados diferentes:

- Antes do nome, indica que a função não devolve um valor. Exemplo: `void limparTela(void)` em `quiz.h`.
- Dentro dos parênteses, indica que a função não recebe parâmetros. Exemplo: `int main(void)` ou `static int lerOpcaoTema(void)`.

Assim, `static void exibirTelaFinal(int acertos, int erros)` recebe dois valores, mas não retorna um resultado. Já `Pergunta perguntaTema1_01(void)` não recebe argumentos e retorna uma estrutura do tipo `Pergunta`.

## Passagem por valor

C passa os argumentos por valor: cada parâmetro recebe uma cópia do argumento. Alterar um parâmetro comum não altera, por si só, a variável usada na chamada.

Em `main.c`, o placar é exibido assim:

```c
exibirTelaFinal(acertos, erros);
```

Os valores de `acertos` e `erros` são copiados para os parâmetros de mesmo nome em `exibirTelaFinal`. A função pode usá-los para exibição, mas não altera as variáveis do `main`.

## Ponteiros e passagem de endereço

Um ponteiro guarda um endereço de memória. O operador `&` obtém o endereço de uma variável; o operador `*`, quando aplicado a um ponteiro, acessa o valor guardado naquele endereço.

Em `main.c`, o quiz inicia cada tema passando os endereços do placar:

```c
executarTema1(&acertos, &erros);
```

A função está declarada em `quiz.h` e implementada em [src/perguntas.c](../src/perguntas.c):

```c
void executarTema1(int *acertos, int *erros) {
    /* ... */
    (*acertos)++;
}
```

`int *acertos` declara um ponteiro para inteiro. O endereço recebido é copiado para o parâmetro, mas ele continua apontando para a variável original do `main`. `(*acertos)++` acessa essa variável e incrementa seu valor. Os parênteses deixam explícito que o incremento é feito no valor apontado.

Tecnicamente, C continua passando o argumento por valor, inclusive quando ele é um ponteiro. O que permite alterar o placar original é passar uma cópia do endereço e acessar o dado por esse endereço; isso costuma ser chamado de passagem por endereço.

## Ponteiro usado para devolver um resultado

Em [src/temporizador.c](../src/temporizador.c), a função recebe o tempo e um endereço onde gravará a tecla escolhida:

```c
int aguardarResposta(int segundos, char *resposta) {
    /* ... */
    *resposta = tecla;
    return 1;
}
```

`segundos` é recebido por valor: a contagem usa uma cópia local. `char *resposta` é um ponteiro para caractere; a função grava nele a resposta, que pode ser lida pelo chamador. O retorno `1` indica que houve resposta válida. Quando o tempo termina, a função grava `\0` em `*resposta` e retorna `0`.

A chamada em `perguntas.c` usa `&resposta` para fornecer esse endereço:

```c
respondeuATempo = aguardarResposta(TEMPO_LIMITE_SEGUNDOS, &resposta);
```

O retorno informa se houve resposta no prazo; a variável `resposta` recebe a letra escolhida. São dois meios diferentes de comunicar um resultado: o valor de retorno e a escrita através de um ponteiro.

## Funções que retornam uma estrutura

Cada função de pergunta monta e devolve uma estrutura `Pergunta`. O tipo da estrutura está definido em `quiz.h`:

```c
static Pergunta perguntaTema1_01(void) {
    Pergunta p;
    strcpy(p.enunciado, "1) Qual e o maior planeta do Sistema Solar?");
    strcpy(p.alternativas[0], "A) Terra");
    /* ... */
    p.respostaCorreta = 'C';
    return p;
}
```

`p` agrupa o enunciado, as alternativas e a resposta correta. `return p` devolve essa estrutura por valor. Em `executarTema1`, o retorno é armazenado em uma variável local:

```c
Pergunta pergunta = perguntasTema1[i]();
```

## Vetor de ponteiros para funções

Em `perguntas.c`, o tipo `FuncaoPergunta` representa um ponteiro para uma função que não recebe argumentos e retorna `Pergunta`:

```c
typedef Pergunta (*FuncaoPergunta)(void);

static FuncaoPergunta perguntasTema1[TOTAL_PERGUNTAS] = {
    perguntaTema1_01, perguntaTema1_02 /* ... */
};
```

O vetor guarda as funções de cada pergunta. A expressão `perguntasTema1[i]()` seleciona a função da posição `i` e a executa. Assim, o laço do tema pode percorrer as perguntas sem escrever uma chamada diferente para cada uma.

## Condições e laços no fluxo do quiz

Em `perguntas.c`, a condição combina duas verificações:

```c
if (respondeuATempo && resposta == pergunta.respostaCorreta) {
    (*acertos)++;
} else {
    (*erros)++;
}
```

`&&` significa “e”: as duas condições precisam ser verdadeiras para contar um acerto. Caso contrário, o bloco `else` conta um erro. O `for` ao redor dessa lógica repete o processo para as dez perguntas.

Em `temporizador.c`, o `while` externo continua enquanto ainda há tempo, e o `while` interno verifica o teclado durante cada segundo. `return` encerra imediatamente `aguardarResposta` quando uma opção válida é pressionada.

## Funções auxiliares com `static`

Em uma função definida fora de qualquer outra função, `static` restringe seu uso ao próprio arquivo `.c`. Por exemplo, `static int lerOpcaoTema(void)` só é chamada em `main.c`; ela não é uma função pública do projeto. Já funções como `executarTema1`, declaradas em `quiz.h`, podem ser chamadas por outros arquivos.
