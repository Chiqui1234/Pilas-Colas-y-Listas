#include "funciones.h"
int main()
{
    crearTxtDePrueba(); // idCarrera, nombreCarrera, legajo (.txt)
    crearBinarioDePrueba(); // idAlumno, nombre, direccion, email (.bin)

    FILE *txtDeEntrada = open(INPUT_TXT, "r");
    FILE *binDeEntrada = open(INPUT_BIN, "rb");
    ST_NODO *cabeceraCarrera = NULL;
    ST_ALUMNO *cabeceraAlumno = NULL;
    ST_TXT lecturaTxt; // Acá guardo la lectura línea a línea del archivo de texto
    while( txtDeEntrada )
    {
        insertarOrdenadoNoDuplicado(&cabeceraCarrera, lecturaTxt);
    }
    
}