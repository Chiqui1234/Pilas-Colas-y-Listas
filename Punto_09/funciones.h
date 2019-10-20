#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODO
{
    int numero;
    struct NODO *ste;
}STR_NODO;

void push(STR_NODO **pila, int numero);
STR_NODO *crearNodo(int dato);
int pop(STR_NODO **pila);
