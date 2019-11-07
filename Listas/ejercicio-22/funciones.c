#include "funciones.h"
void error(const char *texto)
{
    printf("%s\n", texto);
    exit(EXIT_FAILURE);
}

ST_NODO *crearNodo(ST_ALUMNO dato)
{
    ST_NODO *nuevoNodo = (ST_NODO*) malloc(sizeof(ST_NODO));
    if( nuevoNodo == NULL ) // Es importante chequear esto sobretodo cuándo pedimos mucha memoria (no es el caso), porque malloc() pide un sector contínuo de memoria y podría fallar si la RAM no está desfragmentada (algo bastante normal)
        error("La creación del nuevo nodo falló exitosamente."); // ;D

    nuevoNodo->registro = dato;
    nuevoNodo->ste = NULL;
    return nuevoNodo;
}

void insertarOrdenado(ST_NODO **cabecera, ST_ALUMNO dato)
{
    ST_NODO *aux = *cabecera; // Creo una cabecera auxiliar, así la original nunca deja de apuntar al principio
    ST_NODO *nodoAnterior = NULL; // Acá me guardo el nodo anterior para enlazar una vez que agregue el nodo nuevo
    ST_NODO *nuevoNodo = crearNodo(dato); // Creo el nodo nuevo
    while( aux && aux->registro.legajo > nuevoNodo->registro.legajo )
    {
        *nodoAnterior = *aux;
        *cabecera = aux->ste; // Algo así cómo 'i++' de los viejos tiempos
    }
    if( aux == NULL ) // Si aux/cabecera == NULL, es porque no existió ningún nodo antes. Por ende, el while() no corre y hay que vincular el nodo manualmente
        *cabecera = nuevoNodo;
    else // Si aux/cabecera != NULL, sólo resta agarrar el nodo anterior al que agregamos y decirle "hola flaco, acá tenés un nuevo compañero"
        nodoAnterior->ste = nuevoNodo;
    
    nuevoNodo->ste = aux; // Si nuevoNodo está ANTES que otro nodo de mayor legajo, tendrá una dir. de memoria a dicho nodo. Sino será NULL :)
}

void crearListaDePrueba(ST_NODO **cabecera, int cantRegistros)
{
    ST_ALUMNO dato;
    for(int i = 0;i < cantRegistros;i++)
    {
        dato.legajo = rand() % 1000;
        strncpy(dato.nombre, "Persona", STD_SIZE);
        insertarOrdenado(cabecera, dato);
    }
}