/*
 * temporizador.h - Controle do tempo limite de 30s para responder cada pergunta.
 */
#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

#define TEMPO_LIMITE_SEGUNDOS 30

/* Aguarda o usuario pressionar A, B, C ou D dentro do tempo informado.
 * Retorna 1 se respondeu a tempo (preenchendo *resposta) ou 0 se o tempo esgotou. */
int aguardarResposta(int segundos, char *resposta);

#endif /* TEMPORIZADOR_H */
