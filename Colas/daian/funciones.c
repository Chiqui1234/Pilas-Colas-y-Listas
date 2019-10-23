#include "funciones.h"


void crearPila(STR_NODO **pila)
{
   *pila = NULL;
}
void crearCola(STR_COLA *cola)
{
    cola->fte = NULL;
    cola->fin = NULL;
    cola->cant = 0;
}

STR_INFO cargaDatos (int i)
{
    STR_INFO dato;
    //char nombre[20];

           dato.dato= i;
//           printf("Ingrese el Nombre: ");
//           gets(nombre);
//           strcpy(dato.nombre, nombre);

       return dato;
}

void addCola (STR_COLA *cola, STR_INFO dato)
{
    STR_NODO *nodo = crearNodo(dato);
    if(cola->fte == NULL)
    {
        cola->fte = nodo;
    }
    else
    {
        cola->fin->ste = nodo;
    }
    
    cola->fin = nodo;
    cola->cant++;
}

STR_INFO removeCola(STR_COLA *cola)
{
    STR_NODO *aux = cola->fte;

    cola->fte = aux->ste;
    
    if(cola->fte == NULL)
    {
        cola->fin = NULL;
        
    }
    
    STR_INFO dato = aux->info;
    free(aux);
    cola->cant--;
    return dato;
}

STR_NODO *crearNodo(STR_INFO dato)
{
    STR_NODO *nodo=(STR_NODO*)malloc(sizeof(STR_NODO));
    nodo->info.dato= dato.dato;
    nodo->ste = NULL;

    return nodo;
}