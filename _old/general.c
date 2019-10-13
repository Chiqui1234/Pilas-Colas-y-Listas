#include "general.h"

BOOL empty(ST_NODO **cabecera)
{
    return (*cabecera)->sig != NULL?TRUE:FALSE;
}

BOOL emptyChar(ST_HISTORIAL **cabecera)
{
    return (*cabecera)->sig != NULL?TRUE:FALSE;
}

BOOL push(ST_NODO **cabecera, int *valor)
{
    if( *valor == '.' )
        return FALSE;

    ST_NODO *nodo = (ST_NODO*) malloc(sizeof(ST_NODO));
    nodo->dato = *valor;
    nodo->sig = *cabecera;
    *cabecera = nodo;
    return TRUE;
}

int pop(ST_NODO **cabecera)
{
    if(empty(cabecera))
        return -1;

    int valor = (*cabecera)->dato;
    ST_NODO *aux = *cabecera;
    *cabecera = aux->sig;
    free(aux);
    return valor;
}

BOOL pushChar(ST_HISTORIAL **cabecera, char *valor)
{
    if( *valor == '.' )
        return FALSE;

    ST_HISTORIAL *nodo = (ST_HISTORIAL*) malloc(sizeof(ST_HISTORIAL));
    strncpy(nodo->www, valor, WEB_LENGHT); // el nuevo nodo obtiene el valor por parámetro
    nodo->sig = *cabecera; // este miembro del nuevo nodo apunta al nodo anterior
    *cabecera = nodo; // el puntero cabecera obtiene la información del nodo actual, es decir, a dónde debe apuntar ahora (la cabecera apunta al último nodo siempre)
    return TRUE;
}

char *popChar(ST_HISTORIAL **cabecera)
{
    if(!emptyChar(cabecera))
        return '.';

    char valor = (*cabecera)->www;
    ST_HISTORIAL *aux = *cabecera;
    *cabecera = aux->sig; // le paso la estructura referenciada
    free(aux);
    return valor;
}