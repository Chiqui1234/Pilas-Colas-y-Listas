#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE = 0, TRUE} BOOL; // Para no importar stdbool.h al divino botón

typedef struct NODO
{
    int data; // Por ej: ¿cuántas reputación tiene el libro?
    struct NODO *partner; // Acá guardo el puntero al libro anterior
} ST_NODO; // La cabecera apunta a UN nodo
