#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_ALUMNOS 10
#define INPUT_BIN "entrada.bin"
#define OUTPUT_BIN "salida.bin"

/**
 * Char: 1 byte
 * Puntero: 4 bytes
 * Entero: 4 bytes
 * Coma flotante: 8 bytes
 * Bool (enum): 4 bytes
 * Bool: 1 byte
 *** Si usamos "short" la cantidad de bytes es la mitad.
 *** Si usamos "long" la cantidad de bytes es el doble.
 */

/**
 *  Estructura para leer el archivo ARCHA. Memoria estática
 *  41 bytes
 */
typedef struct 
{
    int legajo; // 4 bytes, puede ir de 0 a 999.999
    char nombre[34+1]; // 35 bytes
    short int divisionAsignada; // 2 bytes
} ST_BIN;

/**
 * Estructura para el nodo
 */
typedef struct nodo
{
    int pup; // 4 bytes
    int legajo; // 4 bytes
    struct nodo *ste; // 4 bytes
} ST_NODO;

void error(const char *text);
FILE *open(const char *nombre, const char *modo);
ST_NODO *crearNodo(ST_BIN dato, int pos);
ST_NODO *insertarOrdenado(ST_NODO **cabecera, ST_BIN dato, int pos);
void crearPup(ST_BIN lectura, ST_NODO *ultimoNodoAgregado);
void crearBinarioDeEntrada();
void mostrarBinarioDeEntrada();
void mostrarSalida(ST_NODO **cabecera);
void mostrarLista(ST_NODO **cabecera);