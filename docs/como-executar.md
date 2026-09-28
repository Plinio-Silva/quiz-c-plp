# Como Executar o QUIZ

Este guia explica como compilar e executar o projeto no VS Code ou no Dev-C++.
O projeto usa recursos do Windows e deve ser compilado com GCC/MinGW para
Windows. O código-fonte da biblioteca `conio` (`conio.c` e `conio.h`) já está
incluído na pasta do projeto.

## Arquivos necessários

Extraia o ZIP e mantenha a estrutura completa da pasta `quiz-c-plp`. Para
compilar, são necessários estes arquivos:

- `src/main.c`
- `src/interface.c`
- `src/temporizador.c`
- `src/perguntas.c`
- `conio.c`
- Os headers `include/quiz.h` e `conio.h`

Não compile o executável `build/quiz.exe` como se fosse código-fonte. O
executável é gerado durante a compilação e não precisa ser incluído no envio.

## VS Code

1. Instale o VS Code e um GCC/MinGW para Windows. A task incluída no projeto
   espera encontrar o GCC do MSYS2 em `C:/msys64/ucrt64/bin/gcc`.
2. Selecione **Arquivo > Abrir Pasta...** e abra a pasta raiz `quiz-c-plp`,
   não apenas a pasta `src`.
3. Se a pasta `build` não existir, crie-a na raiz do projeto. No terminal
   PowerShell integrado, o comando é:

   ```powershell
   New-Item -ItemType Directory -Force build
   ```

4. Abra a Paleta de Comandos (`Ctrl+Shift+P`), escolha **Tasks: Run Task** e
   execute **Rodar Quiz**. Essa task compila os arquivos necessários e inicia
   o programa.

Se o GCC estiver instalado em outro local, ajuste o campo `command` da task
**Compilar Quiz** em `.vscode/tasks.json` para apontar para `gcc.exe`. Como
alternativa, se `gcc` estiver disponível no `PATH`, execute estes comandos no
terminal, a partir da pasta raiz do projeto:

```powershell
gcc -Wall -I. -Iinclude src/main.c src/interface.c src/temporizador.c src/perguntas.c conio.c -o quiz.exe
.\quiz.exe
```

## Dev-C++

1. Use uma versão do Dev-C++ para Windows que inclua um compilador GCC/MinGW.
2. Extraia o ZIP e crie um projeto do tipo **Console Application**, escolhendo
   a linguagem **C** (não C++). Salve o projeto na pasta raiz `quiz-c-plp`.
3. Adicione ao projeto os cinco arquivos-fonte: `src/main.c`,
   `src/interface.c`, `src/temporizador.c`, `src/perguntas.c` e `conio.c`.
   Adicione cada arquivo `.c` uma única vez. Os arquivos `.h` não são fontes a
   compilar.
4. Nas opções do projeto, em **Directories > Include Directories**, adicione a
   pasta raiz `quiz-c-plp`. Isso permite que os arquivos em `src` encontrem
   `conio.h`.
5. Use o comando **Compile & Run** do Dev-C++.

Não é necessário instalar `libconio.a` separadamente: este projeto compila o
arquivo local `conio.c`. Se aparecer um erro dizendo que `conio.h` não foi
encontrado, confira se a pasta raiz do projeto foi adicionada aos diretórios de
include. Se aparecerem erros de referências indefinidas, confira se todos os
cinco arquivos `.c` foram adicionados ao projeto.

## Usar o quiz

Na tela de boas-vindas, pressione **Enter**. Escolha o tema com **1** ou **2**
e responda cada pergunta com **A**, **B**, **C** ou **D** antes de o tempo
terminar.

## Preparação do envio

Compactar a pasta `quiz-c-plp` inteira, mantendo os diretórios `src`, `include`,
`docs` e o arquivo `conio.c` na estrutura original. Não é necessário enviar
`build/quiz.exe`; é possível compilar os fontes no Dev-C++ ou no VS Code.