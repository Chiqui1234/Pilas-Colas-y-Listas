#include "funciones.h"
int main()
{
    //crearTxtDePrueba(); // idCarrera, nombreCarrera, legajo (.txt)
    //crearBinarioDePrueba(); // idAlumno, nombre, direccion, email (.bin)

    FILE *txtDeEntrada = open(INPUT_TXT, "r");
    FILE *binDeEntrada = open(INPUT_BIN, "rb");
    ST_NODO *cabeceraCarrera = NULL;
    ST_ALUMNO *cabeceraAlumno = NULL;
    ST_TXT lecturaTxt; // Acá guardo la lectura del archivo de texto (parseada)
    char buffer[100] = ""; // Acá guardo la lectura del archivo de texto, línea a línea
    while( txtDeEntrada )
    {
        printf("leyendo...\n");
        fgets(buffer, 100, txtDeEntrada);
        // insertarOrdenadoNoDuplicado(&cabeceraCarrera, lecturaTxt);
    }
    // crearTxtSalida(&cabeceraCarrera);
}