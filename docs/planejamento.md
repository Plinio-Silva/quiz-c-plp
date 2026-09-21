# Planejamento do Projeto — QUIZ em C

Este documento descreve o planejamento geral do desenvolvimento do projeto, incluindo etapas, prioridades e organização.

---

## 🗂️ Estrutura de Desenvolvimento

### 1) Organização Inicial
- Criar estrutura de diretórios
- Criar README.md
- Criar repositório no GitHub
- Criar quadro no Notion/Trello

### 2) Documentação
- Preencher requisitos (feito)
- Criar lista de perguntas
- Criar roadmap técnico
- Criar anotações gerais

### 3) Implementação Técnica
- Criar tela inicial + loading
- Criar sistema de cores e centralização
- Implementar temporizador (30s)
- Criar lógica de escolha de tema
- Implementar perguntas do Tema 1
- Implementar perguntas do Tema 2
- Criar feedback visual (verde/vermelho piscando)
- Criar tela final de resultados

### 4) Modularização
- Estrutura final (5 arquivos no total, exigência do professor):
  - src/main.c        → ponto de entrada, menu e tela final
  - src/interface.c   → cores, centralização, loading e efeito piscar
  - src/temporizador.c → contagem regressiva de 30s por pergunta
  - src/perguntas.c   → perguntas e execução do Tema 1 e do Tema 2 (unificados)
  - include/quiz.h    → header único com structs, constantes e protótipos
- conio.c / conio.h ficam fora da contagem (biblioteca exigida pelo enunciado).

### 5) Testes
- Testar temporizador
- Testar animações
- Testar fluxo completo
- Testar acertos/erros
- Testar centralização de texto

### 6) Finalização
- Revisar código
- Revisar documentação
- Preparar apresentação para o professor

---

## 📅 Cronograma Sugerido

| Etapa | Período |
|------|---------|
| Organização e documentação | 1–2 dias |
| Interface inicial + loading | 1 dia |
| Temporizador | 1 dia |
| Tema 1 | 2 dias |
| Tema 2 | 2 dias |
| Feedback visual | 1 dia |
| Tela final | 1 dia |
| Testes e ajustes | 2 dias |

---

## 📌 Status Atual

- Estrutura criada e reestruturada para 5 arquivos (.c + .h)
- README criado e atualizado
- Documentação atualizada (anotações com problemas/soluções registrados)
- Implementação concluída: loading, temporizador, dois temas, feedback visual e tela final funcionando
- Build validado via task própria do VS Code ("Compilar Quiz" / "Rodar Quiz") e via Makefile