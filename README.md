# Temario

### Las pilas, colas y listas son estructuras dinámicas:
* Pilas: "filo" (primero entrado, último salido; sirve para invertir el órden del registro).
* Colas: "fifo" (primero entrado primero salido; sirve para "encolar").
* Listas: se puede leer sin borrar, ideal para operaciones de búsqueda.

# Funciones imprescindibles
* push() para agregar un registro.
* pop() para leer y quitar un registro.
* empty() para chequear si el registro contiene datos.
* init() para inicializar un registro

# Tipos de ordenamiento

![Trump-reference](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/trump.gif)
Lo importante de estos conceptos es entender, antes que nada, que la cabecera apunta a un nodo y ese nodo (salvo un caso particular) tiene una referencia a otro. Seguramente si conocés el [Blockchain](https://es.wikipedia.org/wiki/Cadena_de_bloques) ésto te suene bastante conocido.

## FILO: "First input, last output" (Pila)
![FILO](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/filo.gif)

El primero en entrar es el último en salir. ¡Cómo el capitán del barco!
Si yo tengo una biblioteca de 4 libros y los saco para apoyarlos en una mesa, uno arriba del otro, el primer libro que puse en la mesa será el último en devolverse a la biblioteca.

## FIFO: "First input, first output" (Cola)
![FIFO](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/fifo.gif)

El primer vehículo en entrar en esa línea de producción será el primero en salir. El segundo en entrar será el segundo en salir, y así sucesivamente.
En otras palabras, es una forma de encolar procesos a ejecutar después (a partir del primer proceso creado).
¿Alguna vez enviaste varios archivos a imprimir y te salió "La cola de impresión"? Es tal cual :D

## Listas
(in progress...)


# Conectando todo

## Cabecera
La cabecera es cómo un dedo que apunta a un nodo, o una mano que agarra el libro (cómo el ejemplo de FILO). Esta pieza de nuestro algoritmo es vital para posicionarnos rápidamente (por dirección de memoria) al nodo correspondiente cuándo queremos agregar otro nodo (push) o sacarlo (pop).

La cabecera será del tipo de dato:
```c
typedef struct NODO
{
    int dato;
    struct NODO *partner;
} ST_NODO;
```

En nuestro tipo de dato ST_NODO tenemos dos miembros.
* **int dato**, que es el dato que guarda dicho nodo. Podría ser otro tipo de dato (depende que queremos guardar)
* **struct NODO * partner**, que es el nodo siguiente (Cola) o anterior (Pila). ¡Ojo! Ahí guardamos una dirección de memoria **que apunta a otro nodo**. Osea que en dicho puntero encontraremos tanto un nodo distinto con otro dato y otro compañero (si es que tiene).

![Anidación-de-nodos](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/anidacionDeNodos.png)
Acá podés ver que la cabecera (estructura ST_NODO). El último nodo creado tiene **80** cómo dato, y el nodo anterior tiene **85** cómo dato. Fijate cómo la cabecera apunta al nodo que tiene valor de 80, y ese a su vez apunta al nodo anterior que tenía 85 cómo dato :)

## Nodos
Dentro de nuestro buffer ordenado, ya sea Pila o Cola, hay nodos con datos que pueden variar en tipo (int, double, float, char o cualquier tipo definido por el programador (estructuras de datos)).

Debido a que los nodos se crean dentro de la función push() con malloc(), es importante entender que cuándo nuestra computadora sale de ésta función el espacio en memoria sigue en uso en nuestro programa. Sin embargo, al no ser una variable declarada en el main(), no tenemos un acceso "fácil", osea que no podemos llamar a un nodo por su nombre.
Por ende, la cabecera apunta a un nodo (ej. Libro A) que está guardado en alguna parte de nuestra memoria pero a su vez ese nodo nos indicará qué libro leer (ej. Libro B) una vez que hayamos extraído datos del **Libro A**.

## ¿Cómo actúan los Nodos dentro de una pila?

![Libros-apilados](https://github.com/Chiqui1234/Pilas-Colas-y-Listas/blob/master/assets/img/pilas-colas-listas/filo.jpg)

¿Te acordás cuándo hablabamos de que en una **pila** de libros, el primero que ponía en la mesa era el último en volver a la biblioteca? Bueno, esto lo vemos así:
* El primer libro que saco de la biblioteca y pongo sobre la mesa no tiene relación con un libro anterior, porque es el primero. Debido a ésto, su *partner apunta a **NULL**. Sin embargo, el **segundo libro** que pongo sobre la mesa (arriba del primero) apuntará al primero. 
De la misma forma, el **tercer libro** sobre la mesa apuntará al segundo y el **cuarto libro** apuntará a su anterior.

Por ende, cuándo queramos obtener la información de un libro y si estamos bajo el ordenamiento FILO, vamos a leer el libro de más arriba y luego lo sacamos de la mesa, que en programación sería el equivalente a eliminarlo del sistema. Esta tarea repetitiva sucederá con cada libro que hayamos puesto sobre la mesa y leamos.

Recordemos que la cabecera estará apuntando siempre al libro superior de la mesa (el más fácil de agarrar). Cuándo ese libro sea leído, nos quedamos con su información pero el libro en sí desaparece del sistema (osea, ese nodo es eliminado luego de leerse). 
La cabecera se va a posicionar al libro superior apoyado en la mesa, pero tené en cuenta que el cuarto libro no está más y ahora quedan tres. ¿Cómo sabe la cabecera a qué libro apuntar luego de eliminar un nodo? Antes de eliminar el nodo (el libro que leímos), la cabecera debe apuntar al **struct NODO * partner** de dicho libro.

## ¿Cómo actúan los Nodos dentro de una cola?
(in progress...)