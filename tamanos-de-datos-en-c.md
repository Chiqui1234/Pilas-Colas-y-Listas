# Tipos de datos y su peso en memoria
Estos datos son estimativos pero por convención con el profe, es así:

 * Char: 1 byte
 * Puntero: 4 bytes
 * Entero: 4 bytes
 * Coma flotante: 8 bytes
 * Bool (enum): 4 bytes
 * Bool: 1 byte

## Si usamos "short" la cantidad de bytes es la mitad.

> short int xxx = 255;

## Si usamos "long" la cantidad de bytes es el doble.

> long int x = 2147483145;

## Si usamos "unsigned" podremos usar el doble de cantidad de números (sólo de signo positivo)

> unsigned short int x = 65535