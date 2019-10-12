#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WEB_LENGHT 50+1
typedef struct NODO
{
    int dato;
    struct NODO *sig; // apunta a la estructura siguiente (en el caso de FILO, sería la anterior jeje)
} ST_NODO;

typedef struct HISTORIAL
{
    char www[WEB_LENGHT];
    struct HISTORIAL *sig; // apunta a la estructura siguiente (en el caso de FILO, sería la anterior jeje)
} ST_HISTORIAL;

typedef enum 
{
    FALSE = 0,
    TRUE
} BOOL;

BOOL empty(ST_NODO **cabecera);
BOOL push(ST_NODO **cabecera, int *valor);
int pop(ST_NODO **cabecera);
BOOL emptyChar(ST_HISTORIAL **cabecera);
BOOL pushChar(ST_HISTORIAL **cabecera, char *valor);
char *popChar(ST_HISTORIAL **cabecera);