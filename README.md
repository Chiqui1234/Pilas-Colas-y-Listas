# Temario
## Estructuras dinámicas
* Pilas: "filo" (primero entrado, último salido; sirve para invertir el órden del registro). Funciones "push" (agregar), "pop" (leer y sacar), empty (ver si está vacío) y init (inicializar).
* Colas: "fifo" (primero entrado primero salido; sirve para "encolar"). Funciones "push", "pop", empty y init.
* Listas: se puede leer sin sacar, ideal para operaciones de búsqueda.

## Tipos de ordenamiento
### FILO: "First input, last output"
!(FILO)[https://i.gifer.com/P09U.gif]
El primero en entrar es el último en salir. ¡Cómo el capitán del barco!
Si yo tengo una biblioteca de 4 libros y los saco para apoyarlos en una mesa, uno arriba del otro, el primer libro que puse en la mesa será el último en devolverse a la biblioteca.

### FIFO: "First input, first output"
!(FIFO)[https://alellanesimd2013.files.wordpress.com/2013/09/bhqgzn7.gif]
La primer bola en la cadena de producción será la primera en salir. La segunda bola en entrar será la segunda en salir, y así...
En otras palabras, es una forma de encolar procesos a ejecutar después (a partir del primer proceso creado).

## Conectando todo

Tenemos una cabecera que apunta a una estructura del nodo.
