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
    ST_NODE *newNode = (ST_NODE*) malloc(sizeof(ST_NODE));
    newNode->data = data; // Asigno "data" al valor que almacena el nodo
    newNode->ste = *head; // Que hacen los asteriscos en el caso de *head->ste?
    *head = newNode;
}

int pop(ST_NODE **head)
{
    int dataToBackup = (*head)->data;
    ST_NODE *aux = *head;
    *head = aux->ste; // Que hacen los asteriscos en el caso de *head->ste?

    free(aux);
    return dataToBackup;
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