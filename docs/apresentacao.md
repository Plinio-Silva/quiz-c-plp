# Documentação de Apresentação — QUIZ em Linguagem C

**Data:** 21/09/2026
**Autor:** Plinio Tiago da Silva
**Disciplina:** Paradigmas de Linguagens de Programação (PLP)
**Professor:** Sergio Roberto Costa Vieira

> Este documento explica o **funcionamento do programa já pronto e testado**,
> relacionando cada parte do código com as diretrizes exigidas pelo professor
> (ver [requisitos.md](requisitos.md)) e justificando as decisões de
> implementação. Ele serve de material de apoio para a apresentação oficial e
> para validação prévia com o professor.

---

## 1. Visão Geral do Funcionamento

O fluxo do programa, do início ao fim, é:

1. `main()` chama `exibirTelaLoading()` — tela de apresentação com barra de
   progresso animada (requisito: *"tela inicial com animação estilo Loading"*).
2. `exibirTelaInicial()` mostra o menu com os dois temas disponíveis.
3. `lerOpcaoTema()` lê a escolha do usuário (1 ou 2) via `getch()` (conio).
4. De acordo com a escolha, `executarTema1()` ou `executarTema2()` roda as
   10 perguntas daquele tema, uma a uma.
5. Para cada pergunta: a tela é exibida centralizada, o temporizador de 30s é
   iniciado (`aguardarResposta`), a resposta é validada, e a tela pisca em
   verde (acerto) ou vermelho (erro).
6. Ao final das 10 perguntas, `exibirTelaFinal()` mostra a quantidade de
   acertos e erros.

---

## 2. Estrutura de Arquivos e Justificativa

| Arquivo | Responsabilidade |
|---|---|
| `src/main.c` | Ponto de entrada (`main`), menu de escolha e tela final de resultado |
| `src/interface.c` | Cores, centralização de texto, tela de loading e efeito de piscar |
| `src/temporizador.c` | Controle da contagem regressiva de 30 segundos por pergunta |
| `src/perguntas.c` | As 10 perguntas de cada tema (20 no total) e a execução de cada tema |
| `include/quiz.h` | Header único: structs, constantes e protótipos de todo o projeto |
| `conio.c` / `conio.h` / `libconio.a` | Biblioteca de console exigida pelo enunciado (`getch`, `kbhit`, `gotoxy`) |

**Justificativa da reestruturação:** o professor definiu um limite de
**5 arquivos no total** (`.c` + `.h`). Originalmente o projeto tinha 5 `.c`
(`main`, `interface`, `temporizador`, `tema1`, `tema2`) + 5 `.h`, ultrapassando
o limite. A solução foi unificar `tema1.c`/`tema2.c` em `perguntas.c` (os dois
temas têm a mesma estrutura de execução, então unificá-los não prejudica a
modularização) e unificar todos os headers em um único `quiz.h`. O resultado
são exatamente **4 arquivos `.c` + 1 arquivo `.h` = 5 arquivos**, ficando
`conio.c`/`conio.h` de fora da contagem por serem a biblioteca externa
obrigatória (equivalente a não contar `stdio.h`).

---

## 3. Como cada requisito foi atendido

| Requisito do professor | Implementação | Onde no código |
|---|---|---|
| Dois temas de conhecimentos gerais | Tema 1 (história, geografia, ciências) e Tema 2 (tecnologia, filmes, esportes) | `perguntasTema1[]` / `perguntasTema2[]` em `perguntas.c` |
| Usuário escolhe o tema | Menu com opções 1/2 lido via `getch()` | `lerOpcaoTema()` em `main.c` |
| 10 perguntas por tema, 4 alternativas (A-D) | `TOTAL_PERGUNTAS = 10`, `Pergunta.alternativas[4]` | `quiz.h`, `perguntaTemaX_01..10()` |
| Temporizador de 30s por pergunta | `TEMPO_LIMITE_SEGUNDOS = 30`, contagem regressiva exibida na tela | `aguardarResposta()` em `temporizador.c` |
| Sem resposta a tempo = errada | Se `aguardarResposta` retorna 0, soma em `*erros` | `executarTema1/2()` em `perguntas.c` |
| Cabeçalho de identificação do aluno | Comentário no topo de cada `.c` | Todos os arquivos `src/*.c` |
| Sem `.cpp` | Todo o código em `.c` | — |
| Indentação e comentários semânticos | Código indentado, comentários explicando o "porquê" de cada função | Todos os arquivos |
| Modularização com funções/procedimentos | Funções com retorno (`int aguardarResposta`) e procedimentos (`void limparTela`) | `interface.c`, `temporizador.c` |
| Subrotinas com e sem parâmetros | `perguntaTema1_01(void)` sem parâmetros / `exibirPerguntaTema1(Pergunta, int)` com parâmetros | `perguntas.c` |
| Tela inicial com apresentação + loading | Barra de progresso animada com `Sleep()` | `exibirTelaLoading()` em `interface.c` |
| Temporizador visível na tela | `"Tempo restante: %2d s"` atualizado a cada segundo | `temporizador.c` |
| Fundo e texto com cores diferentes | `definirCor(texto, fundo)` via `SetConsoleTextAttribute` | `interface.c` |
| Tela pisca verde/vermelho, mínimo 3x | `piscarTela()` alterna cor 3 vezes + exibição final | `interface.c` |
| Tela final com acertos/erros | `exibirTelaFinal(acertos, erros)` | `main.c` |
| Uso da biblioteca `conio.c` | `getch`, `kbhit`, `gotoxy` usados em todo o projeto | `main.c`, `temporizador.c`, `interface.c` |
| Perguntas/respostas centralizadas | `centralizarTexto()` calcula a coluna central com base na largura do console | `interface.c` |
| Cada pergunta é uma subrotina separada | `perguntaTema1_01()` até `perguntaTema1_10()`, idem Tema 2 | `perguntas.c` |
| Máximo 5 arquivos no total | Ver seção 2 acima | `src/`, `include/` |
| Ordem aleatória (opcional/diferencial) | **Não implementado** — não é obrigatório, apenas diferencial | — |

---

## 4. Testes Realizados

- Compilação limpa com `gcc -Wall`, sem erros nem *warnings*.
- Execução completa do fluxo: loading → menu → Tema 1 → tela final.
- Execução completa do fluxo: loading → menu → Tema 2 → tela final.
- Teste de acerto (tela verde piscando) e erro (tela vermelha piscando).
- Teste de tempo esgotado (30s sem resposta = erro registrado).
- Teste de centralização de texto em diferentes larguras de terminal.

---

## 5. Pontos em Aberto para Validação com o Professor

- Confirmar se `conio.c`/`conio.h` realmente não contam no limite de 5 arquivos
  (interpretação adotada neste projeto).
- Confirmar se o cabeçalho com um único nome de aluno está correto para
  trabalho individual (ou se é necessário indicar dupla).
- Perguntar se a ordem aleatória das perguntas (diferencial opcional) é
  desejável antes da apresentação final.
