/*
Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros nodos ​​de ​​la ​​pila ​​y ​​deje ​​el​​ valor​ ​I ​​como​ ​primero.
​​(Definir​​ parámetros ​​y ​​codificar).
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE = 0, TRUE} BOOL; // Para no importar stdbool.h al divino botón

typedef struct NODO
{
    int data; // Por ej: ¿cuántas reputación tiene el libro?
    struct NODO *partner; // Acá guardo el puntero al libro anterior
} ST_NODO; // La cabecera apunta a UN nodo

/**
 * @param ST_NODO *cabecera recibe la dirección de memoria de la cabecera
 * @return TRUE si struct NODO *partner está vacío.
 */
BOOL empty(ST_NODO **cabecera)
{
    printf("%p, %p\n", (*cabecera)->partner, *cabecera);
    return (*cabecera)->partner == NULL?TRUE:FALSE;
}

BOOL push(ST_NODO **cabecera, int valor)
{
    if( valor == '.' ) // Mi corte de control
        return FALSE;

    ST_NODO *nodo = (ST_NODO*) malloc(sizeof(ST_NODO)); // Creo el nodo
    nodo->data = valor; // Guardo el dato en el nodo
    nodo->partner = *cabecera; // Guardo la dirección del nodo anterior
    *cabecera = nodo;
    return TRUE;
}

void resolverParcial(ST_NODO **cabecera, int reputacionI)
{
    struct ST_NODO *cabeceraAuxiliar = *cabecera; // Esta cabecera me va a permitir moverme por los nodos
    while( !empty(cabecera) ) // Mientras no encuentre el primer nodo (que apunta a NULL, osea está "vacío") el while() corre
    {
        cabeceraAuxiliar = (*cabecera)->partner; // La idea es que acá me guardo el nodo anterior
    }
}

int main()
{
    ST_NODO *cabecera = NULL; // La cabecera, en una primera instancia, no apunta a nada
    int reputacionI = 40; // Valor que dará el usuario. EDIT: lo pongo yo para testear más rápido

    // Lote de prueba: creo 5 nodos para luego hacer lo pedido por el ejercicio
    int reputacionDelLibro[5] = {50, 69, 75, 85, 80};
    for(int i = 0;i < 5;i++)
    {
        push(&cabecera, reputacionDelLibro[i]); // Creo un nodo por iteración 
        printf("Estado de la cabecera: %s\n", empty(&cabecera) == 1?"La cabecera apunta a NULL":"La cabecera apunta al nodo anterior");
    }
    // Fin del Lote de prueba

    resolverParcial(&cabecera, reputacionI); // Recorre toda la pila y almacena los primeros 3 nodos. Los primeros dos los elimino y creo un nodo nuevo con reputacionI. El tercer nodo es porque tengo que editar a dónde apunta (ahora apunta al nuevo nodo con el valor de reputaciónI)
}