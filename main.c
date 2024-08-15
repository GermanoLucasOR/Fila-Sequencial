#include <stdio.h>
#include <unistd.h>
#include "fila.h"

void imprimirFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Fila: ");
    int i = f->frente;
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % TAMANHO_MAX;
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializarFila(&f);

    printf("Enfileirar 10: %s\n", enfileirar(&f, 10) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 20: %s\n", enfileirar(&f, 20) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 30: %s\n", enfileirar(&f, 30) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 40: %s\n", enfileirar(&f, 40) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 50: %s\n", enfileirar(&f, 50) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 60: %s\n", enfileirar(&f, 60) ? "Sucesso" : "Falha");
    sleep(1);
    printf("\n");

    imprimirFila(&f);
    sleep(1);
    printf("Fila cheia? %s\n", estaCheia(&f) ? "Sim" : "Não");
    sleep(1);

    int valor;
    if (consultarFrente(&f, &valor)) {
        printf("Elemento na frente é %d\n", valor);
    } else {
        printf("Fila está vazia\n");
    }
    printf("\n");
    sleep(1);

    printf("Desenfileirando elementos...\n");
    sleep(1);
    while (!estaVazia(&f)) {
        if (desenfileirar(&f, &valor)) {
            imprimirFila(&f);
            sleep(1);
        }
    }

    printf("\n");
    printf("Enfileirar 70: %s\n", enfileirar(&f, 70) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 80: %s\n", enfileirar(&f, 80) ? "Sucesso" : "Falha");
    sleep(1);
    printf("Enfileirar 90: %s\n", enfileirar(&f, 90) ? "Sucesso" : "Falha");
    sleep(1);

    imprimirFila(&f);
    sleep(1);
    printf("Fila cheia? %s\n", estaCheia(&f) ? "Sim" : "Não");
    sleep(1);

    return 0;
}
