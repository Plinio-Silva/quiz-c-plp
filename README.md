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
- Modularização em até 5 arquivos `.c`.
- Linguagem C obrigatória (não aceitar `.cpp`).

---

## 🧱 Estrutura do Projeto

O projeto está organizado em múltiplos arquivos para garantir modularidade e clareza no código. Abaixo está a estrutura sugerida:

```quiz-c-plp/
│
├── src/                → arquivos .c (lógica do programa)
│   ├── main.c
│   ├── interface.c
│   ├── temporizador.c
│   ├── tema1.c
│   ├── tema2.c
│   └── perguntas/      → opcional, se quiser separar ainda mais
│       ├── p1_tema1.c
│       ├── p2_tema1.c
│       ├── p1_tema2.c
│       └── ...
│
├── include/            → arquivos .h (headers)
│   ├── interface.h
│   ├── temporizador.h
│   ├── tema1.h
│   ├── tema2.h
│   └── perguntas.h
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
├── .gitignore
├── README.md
└── Makefile            → opcional, mas profissional

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

O Makefile utiliza os arquivos `conio.c`, `conio.h` e `libconio.a` fornecidos
pelo professor na pasta `D:/Projetos/conio`.

---

## ▶️ Como Executar

```bash
./build/quiz.exe
```

## 👥 Autores
Plinio Tiago da Silva


## 📌 Status do Projeto
Em desenvolvimento 🚧