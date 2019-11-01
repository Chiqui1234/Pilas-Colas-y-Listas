#include "funciones.h"

ST_NODO *insertarOrdenadoNoDuplicado(ST_NODO **cabecera, ST_TXT dato)
{
    ST_NODO *aux = *cabecera;
    ST_NODO *nuevaCarrera = NULL;
    ST_ALUMNO *nuevoAlumno = NULL;
    while( aux )
    {
        if( aux->idCarrera != dato.idCarrera ) // Hay que crear carrera
        {
            nuevaCarrera = crearCarrera(aux, dato.idCarrera); // crea un nodo dónde ste = NULL y dato.idCarrera = idCarrera
            aux->ste = nuevaCarrera; // el último nodo de carrera apunta al nuevo nodo de carrera
        }
        else // Hay que crear al alumno
        {
            nuevoAlumno = crearAlumno(aux->bot, dato.idAlumno); // crea un nodo dónde bot = NULL y dato.idAlumno = idAlumno
            aux->bot = nuevoAlumno; // el último nodo leído de alumno apunta al nuevo nodo de alumno
        }
        
    }
}