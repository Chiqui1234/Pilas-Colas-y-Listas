#include "funciones.h"

/**
 * Dado un archivo de registros de alumnos ARCHA sin ningún orden, donde cada registro contiene:
 * a) Apellido y Nombre del alumno (34 caracteres) 
 * b) Número de legajo (6 dígitos) c) División asignada (1 a 100).
 * Se debe desarrollar el algoritmo y codificación del programa que genere un archivo ARCHL igual al anterior pero ordenado por número de legajo.
 * Nota: Memoria estática 64 KB; dinámica suficiente si ningún​ ​nodo​ ​ocupa​ ​más​ ​de​ ​12​ ​bytes. 
 */
// ftell se divide por la posición del registro, porque ftell() devuelve un long int

void error(const char *text)
{
    printf("%s\n", text);
    exit(EXIT_FAILURE);
}

FILE *open(const char *nombre, const char *modo)
{
    FILE *nuevoArchivo = NULL;
    if( (nuevoArchivo = fopen(nombre, modo)) == NULL )
        error("Imposible abrir el archivo.");

    return nuevoArchivo; 
}

ST_NODO *crearNodo(ST_BIN dato, int pos)
{
    ST_NODO *nuevoNodo = (ST_NODO*) malloc(sizeof(ST_NODO));
    // chequear el espacio en memoria
    nuevoNodo->legajo = dato.legajo;
    nuevoNodo->pup = pos;
    nuevoNodo->ste = NULL;
    return nuevoNodo;
}

ST_NODO *insertarOrdenado(ST_NODO **cabecera, ST_BIN dato, int pos)
{
    ST_NODO *nuevoNodo = crearNodo(dato, pos);
    ST_NODO *aux = *cabecera;
    ST_NODO *anterior = NULL;
    while( aux && dato.legajo > aux->legajo )
    {
        anterior = aux;
        aux = aux->ste;
    }
    if( anterior != NULL ) // Si hay anterior, quiere decir que había un legajo menor en el espacio anterior
        anterior->ste = nuevoNodo; // Así que ese anterior tiene que apuntar a siguiente, que tiene un valor mayor
    else 
        *cabecera = nuevoNodo;

    // nuevoNodo->pup = pos;
    nuevoNodo->ste = aux; // enlazo el nodo nuevo con el resto de la lista (debería tener valores mayores a nuevoNodo->legajo)
    return nuevoNodo;
}

void crearPup(ST_BIN lectura, ST_NODO *ultimoNodoAgregado)
{
    FILE *archivoPup = open(OUTPUT_BIN, "a+b");
    fseek(archivoPup, sizeof(ST_BIN)*lectura.legajo, SEEK_SET); // Me posiciono en el espacio correspondiente al legajo
    fwrite(&lectura, sizeof(ST_BIN), 1, archivoPup); // Escribo la wea cuántica
    fclose(archivoPup);
}

int main()
{
    // Leo secuencialmente el archivo
    // Hago un algoritmo que acomode la lista según van entrando los legajos nuevos
    ST_BIN lectura;
    ST_NODO *cabecera = NULL;
    ST_NODO *ultimoNodoAgregado = NULL;
    int pos = 0;
    crearBinarioDeEntrada();
    mostrarBinarioDeEntrada();
    FILE *entrada = open(INPUT_BIN, "r+b");
    fread(&lectura, sizeof(ST_BIN), 1, entrada);
    while( !feof(entrada) )
    {
        ultimoNodoAgregado = insertarOrdenado(&cabecera, lectura, pos); // Insertará en la cabecera el legajo de forma ordenada
        // crearPup(lectura, ultimoNodoAgregado, pos); // Ubicará en el archivo el registro del alumno completo
        fread(&lectura, sizeof(ST_BIN), 1, entrada);
        pos++;
    }
    fclose(entrada);
    //mostrarSalida(&cabecera);
    mostrarLista(&cabecera);
}