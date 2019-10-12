# Temario
## Estructuras dinámicas
* Pilas: "filo" (primero entrado, último salido; sirve para invertir el órden del registro). Funciones "push" (agregar), "pop" (leer y sacar), empty (ver si está vacío) y init (inicializar).
* Colas: "fifo" (primero entrado primero salido; sirve para "encolar"). Funciones "push", "pop", empty y init.
* Listas: se puede leer sin sacar, ideal para operaciones de búsqueda.

## Tipos de ordenamiento
### FILO: "First input, last output" (Pila)
![FILO](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/filo.gif)
El primero en entrar es el último en salir. ¡Cómo el capitán del barco!
Si yo tengo una biblioteca de 4 libros y los saco para apoyarlos en una mesa, uno arriba del otro, el primer libro que puse en la mesa será el último en devolverse a la biblioteca.

### FIFO: "First input, first output" (Cola)
![FIFO](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/fifo.gif)
La primer bola en la cadena de producción será la primera en salir. La segunda bola en entrar será la segunda en salir, y así...
En otras palabras, es una forma de encolar procesos a ejecutar después (a partir del primer proceso creado).

### Listas
(falta agregar)

## Conectando todo

### Cabecera
La cabecera es cómo un dedo que apunta a un nodo, o una mano que agarra el libro (cómo el ejemplo de FILO). Esta pieza de nuestro algoritmo es vital para posicionarnos rápidamente (por dirección de memoria) al nodo correspondiente cuándo queremos agregar otro nodo (push) o sacarlo (pop).

### Nodos
Dentro de una secuencia de datos, ya sea Pila o Cola, hay nodos. Estos nodos tienen una estructura de datos similar a la siguiente:
```c
typedef struct NODO
{
    int dato;
    struct NODO *partner;
} ST_NODO;
```
En nuestro tipo de dato ST_NODO tenemos dos miembros.
* **int dato**, que es el dato que queremos guardar en nuestro nodo. Podría ser otro tipo de dato (depende que queremos guardar)
* **struct NODO * partner**, que es el nodo siguiente (Cola) o anterior (Pila).

¿Te acordás cuándo hablabamos de que en una **pila** de libros, el primero que ponía en la mesa era el último en volver a la biblioteca? Bueno, esto lo vemos así:
* El primer libro que saco de la biblioteca y pongo sobre la mesa no tiene relación con un libro anterior, porque es el primero. Debido a ésto, su *partner apunta a **NULL**. Sin embargo, el **segundo libro** que pongo sobre la mesa (arriba del primero) apuntará al primero. 
De la misma forma, el **tercer libro** sobre la mesa apuntará al segundo y el **cuarto libro** apuntará a su anterior.

Por ende, cuándo queramos obtener la información de un libro y si estamos bajo el ordenamiento FILO, vamos a leer el libro de más arriba y luego lo sacamos de la mesa. Esta tarea repetitiva sucederá con cada libro que hayamos puesto sobre la mesa.