#include <stdio.h>
#include <stdlib.h>

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
int main()
{
    unsigned short int x = 4;
}