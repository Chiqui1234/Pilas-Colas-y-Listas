#include <stdio.h>
#include <stdlib.h>

FILE *open(const char *nombre, const char *modo)
{
    FILE *aux = NULL;
    if( (aux = fopen(nombre, modo)) == NULL )
        printf("Imposible abrir el archivo.\n");

    return aux;
}

int main()
{
    FILE *archivo = open("test.bin", "wb");
}