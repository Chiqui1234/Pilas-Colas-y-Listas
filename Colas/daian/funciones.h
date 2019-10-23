#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct info{
    int dato;
   // char nombre[20];
}STR_INFO;

typedef struct nodo{
    STR_INFO info;
    struct nodo *ste;
 } STR_NODO;

typedef struct {
    STR_NODO *fte;
    STR_NODO *fin;
    int cant;
}STR_COLA;


STR_INFO cargaDatos(int i);
STR_NODO *crearNodo(STR_INFO dato);
void crearCola(STR_COLA *cola);
void addCola (STR_COLA *cola, STR_INFO dato);
STR_INFO removeCola(STR_COLA *cola);