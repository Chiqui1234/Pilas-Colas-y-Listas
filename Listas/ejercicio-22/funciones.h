#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STD_SIZE 30+1


typedef struct 
{
    int legajo;
    char nombre[STD_SIZE];
} ST_ALUMNO;

typedef struct nodo
{
    ST_ALUMNO registro;
    struct nodo *ste;
} ST_NODO;

void error(const char *texto);
ST_NODO *crearNodo(ST_ALUMNO dato);
void insertarOrdenado(ST_NODO **cabecera, ST_ALUMNO dato);
void crearListaDePrueba(ST_NODO **cabecera, int cantRegistros);