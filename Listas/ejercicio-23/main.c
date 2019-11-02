#include "funciones.h"

/**
 * Dado un archivo de registros de alumnos ARCHA sin ningún orden, donde cada registro contiene:
 * a) Apellido y Nombre del alumno (34 caracteres) 
 * b) Número de legajo (6 dígitos) c) División asignada (1 a 100).
 * Se debe desarrollar el algoritmo y codificación del programa que genere un archivo ARCHL igual al anterior pero ordenado por número de legajo.
 * Nota: Memoria estática 64 KB; dinámica suficiente si ningún​ ​nodo​ ​ocupa​ ​más​ ​de​ ​12​ ​bytes. 
 */
// ftell se divide por la posición del registro, porque ftell() devuelve un long int

<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
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
    int pos; // 4 bytes
    int legajo; // 4 bytes
    struct nodo *ste; // 4 bytes
} ST_NODO;

=======
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
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

<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
ST_NODO *crearNodo(ST_BIN dato)
=======
ST_NODO *crearNodo(ST_BIN dato, int pos)
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
{
    ST_NODO *nuevoNodo = (ST_NODO*) malloc(sizeof(ST_NODO));
    // chequear el espacio en memoria
    nuevoNodo->legajo = dato.legajo;
<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
=======
    nuevoNodo->pup = pos;
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
    nuevoNodo->ste = NULL;
    // nuevoNodo->pos lo modifico con crearPup
    return nuevoNodo;
}

<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
ST_NODO *insertarOrdenado(ST_NODO **cabecera, ST_BIN dato)
{
    ST_NODO *nuevoNodo = crearNodo(dato);
=======
ST_NODO *insertarOrdenado(ST_NODO **cabecera, ST_BIN dato, int pos)
{
    ST_NODO *nuevoNodo = crearNodo(dato, pos);
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
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

void crearPup(ST_BIN lectura, ST_NODO *ultimoNodoAgregado, int *pos)
{
    
    ultimoNodoAgregado->pos = *pos;
}

<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
void crearBinarioDeEntrada()
{
    FILE *entrada = open(INPUT_BIN, "a+b");
    ST_BIN dummie;
    for(int i = 0;i < CANT_ALUMNOS;i++)
    {
        dummie.legajo = rand() % 1000000;
        strncpy(dummie.nombre, "Personita", 34+1);
        dummie.divisionAsignada = rand() % 100+1;
        fwrite(&dummie, sizeof(ST_BIN), 1, entrada);
    }
    fclose(entrada);
}

void mostrarBinarioDeEntrada()
{
    FILE *entrada = open(INPUT_BIN, "a+b");
    ST_BIN dummie;
    fread(&dummie, sizeof(ST_BIN), 1, entrada);
    while( !feof(entrada) )
    {
        printf("Legajo entrada: %d\n", dummie.legajo);
        fread(&dummie, sizeof(ST_BIN), 1, entrada);
    }
    fclose(entrada);
}

void mostrarListaOrdenada(ST_NODO *cabecera)
{
    FILE *entrada = open(INPUT_BIN, "rb");
    while( !feof(entrada) && cabecera->ste )
    {
        fseek(entrada, sizeof(ST_NODO)*(cabecera->pos), SEEK_SET);
        cabecera = cabecera->ste;
    }
    
}

=======
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
int main()
{
    // Leo secuencialmente el archivo
    // Hago un algoritmo que acomode la lista según van entrando los legajos nuevos
    ST_BIN lectura;
    ST_NODO *cabecera = NULL;
    ST_NODO *ultimoNodoAgregado = NULL;
    int pos = 0, i = 0;
    crearBinarioDeEntrada();
    //mostrarBinarioDeEntrada();
    FILE *entrada = open(INPUT_BIN, "r+b");
    fread(&lectura, sizeof(ST_BIN), 1, entrada);
    ultimoNodoAgregado = insertarOrdenado(&cabecera, lectura); // Insertará en la cabecera el legajo de forma ordenada
    crearPup(lectura, ultimoNodoAgregado, &pos);
    while( !feof(entrada) )
    {
<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
        i++;
        ultimoNodoAgregado = insertarOrdenado(&cabecera, lectura); // Insertará en la cabecera el legajo de forma ordenada
        pos = ftell(entrada) / i;
        crearPup(lectura, ultimoNodoAgregado, &pos); // Ubicará en el archivo el registro del alumno completo
=======
        ultimoNodoAgregado = insertarOrdenado(&cabecera, lectura, pos); // Insertará en la cabecera el legajo de forma ordenada
        // crearPup(lectura, ultimoNodoAgregado, pos); // Ubicará en el archivo el registro del alumno completo
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
        fread(&lectura, sizeof(ST_BIN), 1, entrada);
        pos++;
    }
    fclose(entrada);
<<<<<<< HEAD:Listas/ejercicio-23/ejercicio23.c
=======
    //mostrarSalida(&cabecera);
    mostrarLista(&cabecera);
>>>>>>> 51b957e48c47e0d68c678cca358277ee061e8816:Listas/ejercicio-23/main.c
}