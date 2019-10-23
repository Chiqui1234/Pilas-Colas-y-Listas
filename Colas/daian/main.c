# include "funciones.h"

int main() {

   // STR_NODO *pila = NULL;
    //crearPila(&pila);
    STR_COLA cola;
    crearCola(&cola);

    for(int i=0; i < 9; i++)
    {
        addCola(&cola, cargaDatos(i));
    }

    while(cola.fte != NULL)
    {
        STR_INFO contenido = removeCola(&cola);
        printf("\nCOLA Numero: %i\n",contenido.dato);
       // printf("\nPila Nombre: %s",contenido.nombre);
    }

}