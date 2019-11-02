#include <stdio.h>
#include <stdlib.h>
#define TXT_OUTPUT "salida.txt"
// Lectura del binario
typedef struct
{
    int idAlumno;
    char nombre[40+1];
    char direccion[60+1];
    char email[20+1];
} ST_BIN;

typedef struct
{
    int idCarrera;
    int idAlumno;
    char nombreCarrera[20+1];
} ST_TXT;

typedef struct alumno
{
    int idAlumno;
    struct alumno *bot;
} ST_ALUMNO;

typedef struct nodo
{
    int idCarrera;
    // char nombreCarrera[20+1];
    struct nodo *ste;
    struct alumno *bot;
} ST_NODO;

ST_NODO *insertarOrdenadoNoDuplicado(ST_NODO **cabecera, ST_TXT idCarrera);
ST_NODO *crearCarrera(ST_NODO *aux, int idCarrera);
ST_ALUMNO *crearAlumno(ST_ALUMNO *bot, int idAlumno);
void crearTxtSalida(ST_NODO **cabecera);
/**
 * DIAGRAMA DE LISTA DE LISTA
 * CARRERA001       CARRERA002      CARRERA003
 * legajo+pos      legajo30+pos    legajo41+pos
 * legajo2+pos     legajo31+pos    legajo43+pos
 * legajo9+pos     legajo33+pos    legajo49+pos
 */

/**
 * Generar archivo de texto. Un registro así, cómo el siguiente (por alumno):
 * CARRERA (0001): Tecnicatura en Sistemas
 * LEGAJO   NOMBRE Y APELLIDO       E-Mail                   Dirección  
 *  0001    Santiago Gimenez    santiago@outlook.com    El sapo pepe, 1234
 *  0002    Daian d'Espósito    daian@outlook.com       El sapo pepa, 1234
 * 
 * CARRERA (0002): Medicina
 * LEGAJO   NOMBRE Y APELLIDO       E-Mail                   Dirección  
 *  0040    Valeria González    valeria@gmail.com       lalala, 777
 *  0050    Santiago Barbier    santi@gmail.com         lelele, 666
 */