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
 * Dado un archivo de registros de alumnos ARCHA sin ningún orden, donde cada registro contiene:
 * a) Apellido y Nombre del alumno (34 caracteres) 
 * b) Número de legajo (6 dígitos) c) División asignada (1 a 100).
 * Se debe desarrollar el algoritmo y codificación del programa que genere un archivo ARCHL igual al anterior pero ordenado por número de legajo.
 * Nota: Memoria estática 64 KB; dinámica suficiente si ningún​ ​nodo​ ​ocupa​ ​más​ ​de​ ​12​ ​bytes. 
 */
// ftell se divide por la posición del registro, porque ftell() devuelve un long int

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
    int legajo; // 4 bytes
    int pos;
    struct nodo *ste; // 4 bytes
} ST_NODO;

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
    nuevoNodo->legajo = dato.legajo;
    nuevoNodo->pos = pos;
    nuevoNodo->ste = NULL;
    return nuevoNodo;
}

ST_NODO *insertarOrdenado(ST_NODO **list, ST_BIN dato, int pos)
{
    ST_NODO *nodo = crearNodo(dato, pos);
    ST_NODO *aux = *list; // Creo un puntero auxiliar que apunta a la lista (al comienzo)
    ST_NODO *nodoAnt = NULL; // Creo otro puntero auxiliar

    while(aux && dato.legajo > aux->legajo) // Mientras que aux != NULL y el dato sea mayor al dato que estoy analizando en la lista
    {
        nodoAnt = aux;
        aux = aux->ste;
    }
    if(nodoAnt == NULL)
    { *list = nodo; }
    else
    { nodoAnt->ste = nodo; }

    nodo->ste = aux;

    return nodo;   
}

void crearPup(ST_BIN lectura, ST_NODO *ultimoNodoAgregado)
{
    FILE *archivoPup = open(OUTPUT_BIN, "a+b");
    fseek(archivoPup, sizeof(ST_BIN)*lectura.legajo, SEEK_SET); // Me posiciono en el espacio correspondiente al legajo
    fwrite(&lectura, sizeof(ST_BIN), 1, archivoPup); // Escribo la wea cuántica
    fclose(archivoPup);
}

void crearBinarioDePrueba()
{
    FILE *entrada = open("entrada.bin", "w+b");
    ST_BIN dummie;
    for(int i = 0;i < CANT_ALUMNOS;i++)
    {
        dummie.legajo = rand() % 1000; // El lote de prueba lo hago con 4 dígitos en vez de 6 porque soy re heavy re jodido. Debería funcionar igual con 6 digitos por legajo :)
        strncpy(dummie.nombre, "Personita", 34+1);
        dummie.divisionAsignada = rand() % 100+1;
        fwrite(&dummie, sizeof(ST_BIN), 1, entrada);
    }
    fclose(entrada);
}

void mostrarBinarioDePrueba()
{
    FILE *entrada = open(INPUT_BIN, "a+b");
    ST_BIN dummie;
    fread(&dummie, sizeof(ST_BIN), 1, entrada);
    while( !feof(entrada) )
    {
        printf("Legajo leído: %d\n", dummie.legajo);
        fread(&dummie, sizeof(ST_BIN), 1, entrada);
    }
    fclose(entrada);
}

void mostrarSalida()
{
    FILE *salida = open("salida.bin", "r+b");
    ST_BIN dummie;
    fseek(salida, 0, SEEK_SET);
    fread(&dummie, sizeof(ST_BIN), 1, salida);
    while( !feof(salida) )
    {
        printf("Legajo: %d\n", dummie.legajo);
        fread(&dummie, sizeof(ST_BIN), 1, salida);
    }
}


int deleteFirst(ST_NODO **list)
{
    ST_NODO *aux = *list;
    *list = aux->ste;
    int valor  = aux->pos;
    free(aux);
    
    return valor;
}

int main()
{
    // Leo secuencialmente el archivo
    // Hago un algoritmo que acomode la lista según van entrando los legajos nuevos
    ST_BIN lectura;
    ST_NODO *cabecera = (ST_NODO*)malloc(sizeof(ST_NODO));
    crearBinarioDePrueba();
    mostrarBinarioDePrueba();
    //mostrarSalida();
     FILE *entrada = open("entrada.bin", "ab+");
     fread(&lectura, sizeof(ST_BIN), 1, entrada);
     int pos = 0;
     while(!feof(entrada))
    {
        insertarOrdenado(&cabecera, lectura, pos);
        fread(&lectura, sizeof(ST_BIN), 1, entrada);
        pos++;
    }

    FILE *salida = open(OUTPUT_BIN, "w+b");
    
    while(cabecera->ste)
    {
        pos = deleteFirst(&cabecera);
        printf("La pos recupera de deleteFirst: %i ",pos);
        fseek(entrada, sizeof(ST_BIN)*pos, SEEK_SET);
        fread(&lectura, sizeof(ST_BIN), 1, entrada);
        printf("Nro Legajo: %i \n", lectura.legajo);
        fwrite(&lectura, sizeof(ST_BIN), 1, salida);
    }

    
    ST_BIN dummie;
    fseek(salida, 0, SEEK_SET);
    fread(&dummie, sizeof(ST_BIN), 1, salida);
    while( !feof(salida) )
    {
        printf("Legajo: %d\n", dummie.legajo);
        fread(&dummie, sizeof(ST_BIN), 1, salida);
    }

    printf("FINAL");
    fclose(entrada);
    fclose(salida);
}


        // ultimoNodoAgregado = insertarOrdenado(&cabecera, lectura); // Insertará en la cabecera el legajo de forma ordenada
        // crearPup(lectura, ultimoNodoAgregado); // Ubicará en el archivo el registro del alumno completo
        // fread(&lectura, sizeof(ST_BIN), 1, entrada);