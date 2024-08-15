#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define TAMANHO_MAX 5

typedef struct {
    int dados[TAMANHO_MAX];
    int frente;
    int final;
    int tamanho;
} Fila;

void inicializarFila(Fila *f);
bool estaCheia(Fila *f);
bool estaVazia(Fila *f);
bool enfileirar(Fila *f, int valor);
bool desenfileirar(Fila *f, int *valor);
bool consultarFrente(Fila *f, int *valor);

#endif
