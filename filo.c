/*
Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros nodos ​​de ​​la ​​pila ​​y ​​deje ​​el​​ valor​ ​I ​​como​ ​primero.
​​(Definir​​ parámetros ​​y ​​codificar).
Ayuda de Lu: sí la cabecera apunta al ultimo nodo que seria N, y para modificar el primero y segundo nodo, tenes que utilizar una pila aux, para cambiar el orden de los nodos y poder borrar la primera y segunda posición, una vez que lo hiciste como bien decis se debe ingresar el valor I, y luego volves a pasar los nodos a la pila original para que te quede I en la primer posición, esto es lo que pide el ejercicio
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
    //printf("%p, %p\n", (*cabecera)->partner, *cabecera);
    return cabecera==NULL;
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

/**
 * @param ST_NODO **cabecera recibe la dirección de la cabecera
 * @param int reputacionI recibe el valor a poner en el nuevo nodo
 */
void resolverParcial(ST_NODO **cabecera, int reputacionI)
{
    int n = 0;
    ST_NODO *cabeceraAux = *cabecera;
    while( !empty(&cabeceraAux) ) // Mientras no encuentre el primer nodo (que apunta a NULL, osea está "vacío") el while() corre
    {
        cabeceraAux = *cabecera;
        n++;
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
        //printf("Estado de la cabecera: %s\n", empty(&cabecera) == 1?"La cabecera apunta a NULL":"La cabecera apunta al nodo anterior");
    }
    // Fin del Lote de prueba

    resolverParcial(&cabecera, reputacionI); // Recorre toda la pila y almacena los primeros 3 nodos. Los primeros dos los elimino y creo un nodo nuevo con reputacionI. El tercer nodo es porque tengo que editar a dónde apunta (ahora apunta al nuevo nodo con el valor de reputaciónI)
}