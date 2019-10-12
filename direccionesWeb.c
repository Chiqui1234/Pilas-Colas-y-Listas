#include "general.h"
int main()
{
    ST_HISTORIAL *cabecera = NULL;
    char dir[WEB_LENGHT] = "";
    char flag = '_';
    while( dir[0] != '.' )
    {
        printf("Digite \".\" para cancelar o escriba una dirección: ");
        printf("Dirección web: ");
        scanf("%s", dir);
        printf("pushChar: %d\n", pushChar(&cabecera, dir));
    }

    while( (*cabecera).sig != NULL )
    {
        printf("URL: %s\n", popChar(&cabecera));
    }
}