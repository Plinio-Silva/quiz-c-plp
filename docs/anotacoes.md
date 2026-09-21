# Anotações Gerais do Projeto

Espaço para registrar ideias, decisões, testes, problemas encontrados e soluções.

---

## 💡 Ideias

- Criar animação de loading com barras ou pontos.
- Usar cores da biblioteca conio para destacar perguntas.
- Criar função para centralizar texto automaticamente.
- Criar função para piscar tela com cor específica.

---

## 🧪 Testes

- Testar temporizador com diferentes velocidades.
- Testar centralização em diferentes tamanhos de terminal.
- Testar fluxo de acerto/erro.

---

## 🛠️ Problemas Encontrados

- **Quiz não rodava:** o build genérico do VS Code ("Compilar C") compila apenas o arquivo atualmente aberto no editor (`${file}`). Ao tentar compilar com `main.c`, `tema1.c` ou até `README.md` abertos isoladamente, o `gcc` falhava com erros de `undefined reference` (funções como `limparTela`, `definirCor`, `centralizarTexto` ficavam sem o restante dos arquivos do projeto) ou tentava compilar um arquivo que nem era `.c`.
- `mingw32-make` não estava disponível no PATH do terminal, então `make`/`make run` também falhavam.
- O professor informou que o projeto deve ter **no máximo 5 arquivos no total**, contando `.c` e `.h`. A estrutura original tinha 5 `.c` (`main.c`, `interface.c`, `temporizador.c`, `tema1.c`, `tema2.c`) + 5 `.h` (`interface.h`, `perguntas.h`, `temporizador.h`, `tema1.h`, `tema2.h`), ultrapassando o limite.

---

## ✔️ Soluções

- **21/09/2026 — Correção de build:** criada task própria do VS Code ([.vscode/tasks.json](../.vscode/tasks.json)) com "Compilar Quiz" e "Rodar Quiz", que sempre compilam todos os arquivos do projeto (`src/*.c` + `conio.c`) e geram `build/quiz.exe`, em vez de depender da task genérica que compila só o arquivo aberto.
- **21/09/2026 — Reestruturação para 5 arquivos:** unificados todos os headers (`interface.h`, `perguntas.h`, `temporizador.h`, `tema1.h`, `tema2.h`) em um único [include/quiz.h](../include/quiz.h), e unificados `tema1.c` + `tema2.c` em um único [src/perguntas.c](../src/perguntas.c). Estrutura final: `main.c`, `interface.c`, `temporizador.c`, `perguntas.c` + `quiz.h` = 5 arquivos, ficando `conio.c`/`conio.h` fora da contagem por serem a biblioteca externa exigida pelo enunciado. Makefile, tasks.json e README.md atualizados para refletir a nova estrutura. Recompilado e validado sem erros/warnings após a mudança.

---

## 📌 Observações

- Manter código limpo e modular.
- Atualizar documentação conforme o projeto evolui.
- Comunicar progresso e impedimentos regularmente.