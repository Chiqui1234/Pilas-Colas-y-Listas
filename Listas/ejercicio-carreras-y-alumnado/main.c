#include "funciones.h"
int main()
{
    crearTxtDePrueba(); // idCarrera, nombreCarrera, legajo (.txt)
    //crearBinarioDePrueba(); // idAlumno, nombre, direccion, email (.bin)

    FILE *txtDeEntrada = open(INPUT_TXT, "r");
    //FILE *binDeEntrada = open(INPUT_BIN, "rb");
    ST_NODO *cabeceraCarrera = NULL;
    ST_ALUMNO *cabeceraAlumno = NULL;
    ST_TXT lecturaTxt; // Acá guardo la lectura del archivo de texto (parseada)
    char buffer[100] = ""; // Acá guardo la lectura del archivo de texto, línea a línea
    fseek(txtDeEntrada, 0, SEEK_SET);
    
    while( !feof(txtDeEntrada) )
    {
        fgets(buffer, 100, txtDeEntrada);
        printf("Lectura: %s", buffer);
        lecturaTxt = parsearLinea(buffer); // Convierte la línea de texto en idCarrera, nombreCarrera y legajo
        // insertarOrdenadoNoDuplicado(&cabeceraCarrera, lecturaTxt);
    }
    // Me queda el último registro afuera OJO
    // crearTxtSalida(&cabeceraCarrera);
    fclose(txtDeEntrada);
    //fclose(binDeEntrada);
    return 0;
}