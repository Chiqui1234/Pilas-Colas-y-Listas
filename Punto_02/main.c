#include "funciones.h"


int main()
{
    STR_NODO *pila = NULL;
    int nCant = 0;
    int nNum = 0;

    printf("ingrese cantidad de Numeros en la pila: ");
    scanf("%i", &nCant);
    printf("\nNumero para La tercer pos de la pila: ");
    scanf("%i", &nNum);
    int i = 0;
    while(i < nCant)
    {
        if(nCant - 2 == i)
        {
            push(&pila, nNum);
        }
        push(&pila, i);
        i++;
    }

    while(pila != NULL)
    {
        printf("Pila Num: %i\n", pop(&pila));
    }
}