# Projeto QUIZ em Linguagem C — Paradigma Imperativo

Este projeto é um trabalho da disciplina de Paradigmas de Linguagens de Programação (PLP), ministrada pelo professor **Sergio Roberto Costa Vieira**.  
O objetivo é desenvolver um **QUIZ interativo** em linguagem C, seguindo o paradigma imperativo e atendendo a todos os requisitos definidos no enunciado.

---

## 🎯 Objetivo do Projeto

Criar um quiz com dois temas diferentes, cada um contendo 10 perguntas de múltipla escolha (A, B, C, D), com temporizador, interface visual, animações e modularização completa do código.

---

## 📚 Requisitos Principais

- Dois temas de perguntas (conhecimentos gerais).
- Usuário deve escolher entre os temas.
- Cada tema contém 10 perguntas com quatro alternativas.
- Temporizador de **30 segundos** por pergunta.
- Interface com cores e animações:
  - Acerto → tela verde piscando 3 vezes.
  - Erro → tela vermelha piscando 3 vezes.
- Tela inicial com animação estilo *Loading*.
- Tela final com quantidade de acertos e erros.
- Uso obrigatório da biblioteca **conio.c**.
- Perguntas centralizadas na tela.
- Cada pergunta deve ser uma subrotina separada.
- Projeto com no máximo 5 arquivos no total (`.c` + `.h`), fora da biblioteca `conio.c`/`conio.h` exigida pelo professor.
- Linguagem C obrigatória (não aceitar `.cpp`).

---

## 🧱 Estrutura do Projeto

O projeto foi reestruturado para respeitar o limite de **5 arquivos no total** (`.c` + `.h`) definido pelo professor. A biblioteca `conio.c`/`conio.h`/`libconio.a`, exigida pelo próprio enunciado, fica fora dessa contagem, assim como `stdio.h`.

```quiz-c-plp/
│
├── src/                → arquivos .c (lógica do programa) — 4 arquivos
│   ├── main.c          → ponto de entrada, menu e tela final
│   ├── interface.c     → cores, centralização, loading e efeito piscar
│   ├── temporizador.c  → contagem regressiva de 30s por pergunta
│   └── perguntas.c     → perguntas e execução do Tema 1 e do Tema 2
│
├── include/            → arquivo .h (header único) — 1 arquivo
│   └── quiz.h          → structs, constantes e protótipos de todo o projeto
│
├── docs/               → documentação
│   ├── requisitos.md
│   ├── planejamento.md
│   ├── perguntas.md
│   └── anotacoes.md
│
├── assets/             → imagens, logos, mockups, etc.
│   └── (opcional)
│
├── build/              → executáveis gerados (não versionar)
│   └── quiz.exe
│
├── conio.c / conio.h / libconio.a  → biblioteca exigida pelo professor (fora da contagem de 5 arquivos)
│
├── .gitignore
├── README.md
└── Makefile

---

## 🛠️ Tecnologias Utilizadas

- Linguagem **C**
- Compilador **GCC**
- Biblioteca **conio.c**
- Editor **VS Code**
- Controle de versão **Git/GitHub**

---

## ▶️ Como Compilar

```bash
make
```

O Makefile compila `src/main.c`, `src/interface.c`, `src/temporizador.c` e
`src/perguntas.c` junto com `conio.c` (fornecido pelo professor, já incluído
na raiz do projeto), gerando `build/quiz.exe`.

---

## ▶️ Como Executar

```bash
./build/quiz.exe
```

## 👥 Autores
Plinio Tiago da Silva


## 📌 Status do Projeto
Em desenvolvimento 🚧