#include "fila.h"

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->final = -1;
    f->tamanho = 0;
}

bool estaCheia(Fila *f) {
    return f->tamanho == TAMANHO_MAX;
}

bool estaVazia(Fila *f) {
    return f->tamanho == 0;
}

bool enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        return false;
    }
    f->final = (f->final + 1) % TAMANHO_MAX;
    f->dados[f->final] = valor;
    f->tamanho++;
    return true;
}

bool desenfileirar(Fila *f, int *valor) {
    if (estaVazia(f)) {
        return false;
    }
    *valor = f->dados[f->frente];
    f->frente = (f->frente + 1) % TAMANHO_MAX;
    f->tamanho--;
    return true;
}

bool consultarFrente(Fila *f, int *valor) {
    if (estaVazia(f)) {
        return false;
    }
    *valor = f->dados[f->frente];
    return true;
}
