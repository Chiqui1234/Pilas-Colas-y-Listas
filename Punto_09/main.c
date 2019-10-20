#include "funciones.h"


int main()
{
    STR_NODO *pila = NULL;
    int nNum []= {8, 4, 3, 5, 9, 1, 6};
    
    printf("\nLos numeros a ordenar son : ");
   
    int i = 0;
    while(i < 7)
    {
        printf("  [%i] ", nNum[i]);
        push(&pila, nNum[i]);
        i++;
    }

    STR_NODO *aux = NULL;
    STR_NODO *aux2 = NULL;

        while( pila != NULL)
        {
            
            int numero = pop(&pila);
            if(aux == NULL)
            {
                push(&aux, numero);
                
            }
            else{
            
                
                while(aux != NULL && numero >= aux->numero)
                {
                    printf("WHILE AUX->NUM: %i\n",aux->numero);
                    
                    push(&aux2, pop(&aux));
               
                    
                }

                push(&aux, numero);
               
                while(aux2 != NULL)
                {   
                    
                    push(&aux, pop(&aux2));
                }
            }
        }

        while(aux != NULL)
        {
            push(&pila, pop(&aux));
        }

    while(pila != NULL)
    {
        printf("Pila Num: %i\n", pop(&pila));
    }
}
