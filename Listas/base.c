#include <stdio.h>
#include <stdlib.h>
#define NEW LISTA 20

typedef struct nodo
{
    int dato;
    struct nodo *ste;
} ST_NODO;

ST_NODO *crearNodo(int dato)
{
    ST_NODO *new = (ST_NODO*) malloc(sizeof(ST_NODO));
    new->ste = NULL;
    new->dato = dato;
    return new;
}

ST_NODO *insertFront(ST_NODO **lista, int dato)
{
    // ST_NODO *new = (ST_NODO*) malloc(sizeof(ST_NODO));
    ST_NODO *new = crearNodo(dato);
    new->dato = dato;
    new->ste = *lista;
    *lista = new;
    return new;
}

ST_NODO *insertEnd(ST_NODO **lista, int dato)
{
    ST_NODO *new = crearNodo(dato);
    ST_NODO *aux = *lista;
    // new->dato = dato;
    while( aux != NULL && aux->ste != NULL )
        aux = aux->ste;

    if( aux == NULL)
        *lista = new;
    else
        aux->ste = new;
}

void order(ST_NODO **lista, int dato, int query)
{
    
}

int main()
{
    ST_NODO *lista = NULL;
}