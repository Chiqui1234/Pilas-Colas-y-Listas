#include <stdio.h>
#include <stdlib.h>
#define CANT_NODOS 5

typedef struct node
{
    int data;
    struct node *ste;
} ST_NODE;

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

int main()
{
    int data[CANT_NODOS];
    ST_NODE *head = NULL;

    for(int i = 0;i < CANT_NODOS;i++) // Creo los datos para los nodos de prueba
        data[i] = rand() % 100;

    for(int i = 0;i < CANT_NODOS;i++) // Creo los nodos
        push(&head, data[i]);

    for(int i = 0;i < 2;i++) // Saco el primer y segundo nodo
        pop(&head);

    push(&head, 2); // Creo un nodo nuevo para poner primero :)
    
    return 0;
}