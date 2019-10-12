#include "general.h"
// FILO

int main()
{
    ST_NODO *cabecera = NULL; // apunta a a la primer estructura. En el siguiente paso, se crea una estructura nueva ST_NODO, que apunta al mismo lugar que la cabecera. La cabecera apuntará a la nueva estructura
    int valor = 2;
    push(&cabecera, &valor); // paso la dirección del puntero cabecera
    valor = 5;
    push(&cabecera, &valor);
    printf("Valor: %d\n", pop(&cabecera)); // libero 5
    printf("Valor: %d\n", pop(&cabecera)); // libero 2
}