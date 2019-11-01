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

ST_NODO *crearCarrera(ST_NODO *aux, int idCarrera)
{
    ST_NODO *nuevaCarrera = (ST_NODO*) malloc(sizeof(ST_NODO));
    aux->ste = nuevaCarrera;
    nuevaCarrera->ste = NULL;
    // nuevaCarrera->bot = NULL;
    nuevaCarrera->bot = aux->bot; // en la misma línea del txt, levanto un legajo y lo meto junto con la carrera
    return nuevaCarrera;
}

ST_ALUMNO *crearAlumno(ST_ALUMNO *bot, int idAlumno)
{
    ST_ALUMNO *nuevoAlumno = (ST_ALUMNO*) malloc(sizeof(ST_ALUMNO));
    bot->bot = nuevoAlumno->bot;

    nuevoAlumno->idAlumno = idAlumno;
    nuevoAlumno->bot = NULL;
    return nuevoAlumno;
}

ST_NODO parsearLinea(const char *buffer)
{
    
}

void crearTxtDePrueba()
{
    FILE *txtDePrueba = open(INPUT_TXT, "w");
    fprintf(txtDePrueba, "01;Tecnicatura Superior en Sistemas Informáticos;1234\n01;Tecnicatura Superior en Sistemas Informáticos;1224\n02;Medicina;03\n02;Medicina;04");
    fclose(txtDePrueba);
}

void crearBinarioDePrueba()
{

}

FILE *open(const char *nombre, const char *permiso)
{
    FILE *aux = NULL;
    if( (aux = fopen(nombre, permiso)) == NULL )
    {
        printf("Imposible abrir el archivo.\n");
        return 1;
    }
    return aux;
}