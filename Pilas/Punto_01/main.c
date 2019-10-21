#include "funciones.h"


int main()
{
    STR_NODO *pila = NULL;
    int nCant = 0;
    int nNum = 0;

    printf("ingrese cantidad de Numeros en la pila: ");
    scanf("%i", &nCant);
    printf("\nNumero a posicionar Primero en la  pila: ");
    scanf("%i", &nNum);
    int i = 0;
    while(i < nCant)
    {
        push(&pila, i);
        i++;
    }
    
    printf("\nnumero eliminado: %i\n", pila->numero);
    pop(&pila);
    printf("numero eliminado: %i\n", pila->numero);
    pop(&pila);

    push(&pila, nNum);

    while(pila != NULL)
    {
        printf("Pila Num: %i\n", pila->numero);
        pop(&pila);
    }
}