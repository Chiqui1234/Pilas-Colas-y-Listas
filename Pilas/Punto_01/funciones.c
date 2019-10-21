#include "funciones.h"

STR_NODO *crearNodo(int dato)
{
    STR_NODO *nodo=(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->numero = dato;
    nodo->ste = NULL;

    return nodo;
}

void push(STR_NODO **pila, int dato)
{
    STR_NODO *nodo = crearNodo(dato);
    nodo->ste = *pila;
    *pila = nodo;
}

void pop(STR_NODO **pila)
{
    STR_NODO *aux = *pila;
    *pila = aux->ste;
    free(aux);
}