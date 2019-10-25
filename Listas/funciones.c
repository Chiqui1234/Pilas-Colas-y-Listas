#include "funciones.h"

// STR_NODO *insertNotDuplicate(STR_NODO **lista, STR_DATOS dato)
// {

// }

STR_NODO *crearNodo(int dato)
{
    STR_NODO *nodo=(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->dato = dato;
    nodo->ste = NULL;

    return nodo;
}
STR_NODO *insertFront(STR_NODO **list, int dato)
{
    STR_NODO *nodo = crearNodo(dato);
    nodo->ste = *list;
    *list = nodo;

    return nodo;
}

STR_NODO *insertEnd(STR_NODO **list, int dato)
{
    STR_NODO *nodo = crearNodo(dato);
    STR_NODO *aux = *list;

    while(aux && aux->ste != NULL)
    { aux = aux->ste; }
    
    if(aux == NULL)
    { *list = nodo; }
    else
    { aux->ste = nodo; }
    
    return nodo;
}

STR_NODO *insertOrder(STR_NODO **list, int dato)
{
    STR_NODO *nodo = crearNodo(dato);
    STR_NODO *aux = *list;
    STR_NODO *nodoAnt = NULL;

    while(aux && dato > aux->dato)
    {
        nodoAnt = aux;
        aux = aux->ste;
    }
    if(nodoAnt == NULL)
    { *list = nodo; }
    else
    { nodoAnt->ste = nodo; }

    nodo->ste = aux;

    return nodo;   
}

STR_NODO *search(STR_NODO *list, int dato)
{
    STR_NODO *aux = list;

    while(aux && dato != list->dato)
    {
        aux = aux->ste;
    }

    return aux;
}

STR_NODO *insertNotDuplicate(STR_NODO **list, int dato)
{
    STR_NODO *nodo = search(*list, dato);
    if(nodo == NULL)
    {
        nodo = insertOrder(*list, dato);
    }

    return nodo;
}
int deleteFirst(STR_NODO **list)
{
    STR_NODO *aux = *list;
    list = aux->ste;
    int valor  = aux->dato;
    free(aux);
    
    return valor;
}
void sortList(STR_NODO **list)
{
    STR_NODO *aux = NULL;
    while(list != NULL)
    {
        int dato = deleteFirst(list);
        insertOrder(&aux, dato);
    }
    *list = aux;
}