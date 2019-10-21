/**
 * Crear un procedimiento que ordene una pila por valor y la retorne.
 */
#include <stdio.h>
#include <stdlib.h>
#define CANT_NODOS 10

typedef struct node
{
    int data;
    struct node *ste;
} ST_NODE;

typedef enum { FALSE=0, TRUE} BOOL;

void push(ST_NODE **head, int data)
{
    ST_NODE *newNode = (ST_NODE*) malloc(sizeof(ST_NODE)); // NUEVO NODO
    newNode->data = data;   // Asigno "data" al valor que almacena el nodo
    newNode->ste = *head;   // El nodo apunta al nodo anterior
    *head = newNode;        // La cabecera apunta al NUEVO NODO
}

int pop(ST_NODE **head)
{
    int dataToBackup = (*head)->data;   // Guardo el valor del nodo a eliminar
    ST_NODE *aux = *head;   // Creo un puntero al nodo a eliminar (esa dirección la guarda *head)
    *head = aux->ste;       // Ahora *head apunta al nodo anterior al nodo que vamos a eliminar
    free(aux);  // Terminamos de eliminar el nodo pasado por parámetro de la función
    return dataToBackup;    // Devolvemos el dato
}

BOOL is_empty(ST_NODE *head)
{
    return head==NULL; // Devuelve TRUE(1) si head es nulo
}

ST_NODE * order(ST_NODE **head)
{
    ST_NODE *aux1, *aux2 = NULL; // Cabecera/Pila auxiliar
    int a1, a2;
    a1 = pop(head);
    a2 = pop(head);
    while( !is_empty(*head) ) // Mientras la pila tenga algún nodo
    {
        
    }
    //return aux;
}

int main()
{
    int data[CANT_NODOS];
    ST_NODE *head = NULL;

    for(int i = 0;i < CANT_NODOS;i++) // Creo los datos para los nodos de prueba
        data[i] = rand() % 100;

    for(int i = 0;i < CANT_NODOS;i++) // Creo los nodos de prueba (lote de prueba)
        push(&head, data[i]);
    
    // head = 
    
    order(&head); // Ordeno la pila
}