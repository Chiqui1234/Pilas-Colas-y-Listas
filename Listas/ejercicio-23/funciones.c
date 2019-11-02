#include "funciones.h"
void crearBinarioDeEntrada()
{
    FILE *entrada = open(INPUT_BIN, "wb");
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

void mostrarSalida(ST_NODO **cabecera)
{
    ST_NODO *aux = *cabecera;
    FILE *salida = open(OUTPUT_BIN, "r+b");
    ST_BIN dummie;
    int i = 0; // una grasada, pero es para probar algo
    fread(&dummie, sizeof(ST_BIN)*aux->pup, 1, salida);
    while( !feof(salida) && i < 10 )
    {
        //aux = aux->ste; // seg. fault
        printf("Legajo salida: %d\n", dummie.legajo);
        fread(&dummie, sizeof(ST_BIN)*aux->pup, 1, salida);
        i++;
    }   
}

void mostrarLista(ST_NODO **cabecera)
{
    ST_NODO *aux = *cabecera;
    while( aux->ste )
    {
        printf("Valor de la lista (%d): %d\n", aux->pup, aux->legajo);
        aux = aux->ste;
    }
}