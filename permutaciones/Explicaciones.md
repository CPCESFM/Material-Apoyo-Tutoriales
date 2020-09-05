# Permutaciones
En este apartado se comentan las soluciones de los problemas para `std::next_permutation` y `std::prev_permutation`
Antes de continuar, [en esta página](https://juanitobanca.com/2017/03/07/draft-permutaciones-lexicograficas/#:~:text=En%20el%20campo%20de%20las,dispuestos%20es%20un%20factor%20clave.) se describe un algoritmo muy sencillo para determinar la siguiente permutación lexicográfica:

Sea `P` un contenedor de nuestra permutación, velo como un arreglo de un tipo de dato como `char` o `int`

+ Encontrar el mayor valor de `x` tal que `P[x] < P[x+1]`. Si dicho valor de `x` no existe, entonces `P` es la última permutación lexicográfica que puede ser concebida por medio del conjunto de elementos que la conforman.
+ Encontrar el mayor valor de `y` tal que `P[x]<P[y]`. Si dicho valor de `y` no existe, entonces `P` es la última permutación lexicográfica que puede ser concebida por medio del conjunto de elementos que la conforman.
+ Intercambiar `P[x]` por `P[y]` y viceversa.
+ Invertir los elementos desde `P[x+1]` hasta `P[n]`.

Sin más preámbulo, aquí la solución a los problemas

## [ID Codes](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=625&page=show_problem&problem=82)
#### Descripción del problema
Después de leer el problema puedes darte cuenta que los códigos no son mas que permutaciones =D, en estos términos el problema dice que, **dada una cadena de caracteres**, imprimas **la siguiente permutación** en orden lexicográfico si esta existe, si no existe (caso en el que estamos en la ultima permutación lexicográfica) entonces imprimir **"No Successor"**

#### Detalles de funciones para cadenas de caracteres necesarias (SPOILER DE STRINGS)
Esto bien podría resolverse con un tema un poco mas avanzado (`std::string`) pero no, vamos a ocupar **arreglos de char** para almacenar las cadenas de caracteres y un par de funciones para manejarlas, si alguna vez programaste en `C` tal vez sean familiares para ti porque este es el estilo de manejo de strings en `C` (posteriormente veremos el manejo de cadenas en `C++` que difiere, por el momento utilizamos esta forma para no adelantarnos, también es útil sin duda y esta soportada en `C++`)
+ `strcmp(,)`
	+ Esta función (como puedes intuir por su nombre) **compara strings** (cadenas de caracteres)
	+ Recibe de parametros dos apuntadores a donde tienes almacenadas las cadenas, como vamos a manejarlas en arreglos de char va a recibir por parametro **los nombres de los arreglos** o bien, **una cadena entre comillas " "**
	+ Esta función **devuelve 0** si las cadenas son iguales, devuelve **algo menor a 0** si el primer string, además de ser diferente, es menor lexicográficamente que la segunda y devuelve **algo mayor a 0** si la segunda cadena, ademas de ser mayor, es menor lexicográficamente que la primera
	+ Para mas detalles consulta [su referencia aquí](http://www.cplusplus.com/reference/cstring/strcmp/?kw=strcmp)
	+ Esta función la ocuparemos fundamentalmente para ver cuando terminamos, es decir, cuando nos dan la cadena **"#"**
+ `strlen()`
	+ Esta función **devuelve la longitud de un string**
	+ Recibe de parametro **un apuntador a la cadena** que deseas saber su longitud, en este caso **el nombre del arreglo** por como lo estamos manejando
	+ **Devuelve un entero**, el número de caracteres de la cadena
	+ Para mas detalles consulta [su referencia aquí](http://www.cplusplus.com/reference/cstring/strlen/?kw=strlen)
	+ Esta función la ocuparemos fundamentalmente para usar `next_permutation(,)` porque recibe el rango a cambiar (y para eso ocuparemos el tamaño)

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/permutaciones/ID_Codes.cpp)
La solución de este problema es en realidad muy sencilla. Para cada cadena que nos den simplemente usamos la función `next_permutation(,)` sobre esta, si devuelve `true` entonces es posible encontrar la siguiente permutación y directamente la imprimimos, si devuelve `false` entonces esa era la última permutación lexicográfica e imprimimos `No Successor`. En la implementación nos auxiliamos de las dos funciones descritas anteriormente, echale un ojo para entender mejor su uso y funcionamiento

## [Sumas consecutivas](https://omegaup.com/arena/problem/sumasconsecutivas#problems)
#### Descripción del problema
Se tiene una secuencia de **n** numeros. Se describe un proceso para construir otra secuencia de **n-1** sumando de cierta manera los primeros **n** numeros, si repetimos este proceso eventualmente vamos a obtener un solo número. El problema es encontrar como ordenar los primeros **n** numeros que nos dan para poder obtener al final un número **k** que nos proporcionan

#### Ejemplitos
Primero, dejemos en claro como funciona el proceso de sumas con la secuencia `2 1 5 6 3`. ¿Has visto el triangulo de Pascal? le da un aire a como debemos construir la secuencia, podría decirse que cada nuevo número es la suma de los dos _que estan arriba_. De nuevo un ejemplo dice más que mil palabras

+ De `2 1 5 6 3` pasamos a `2+1 1+5 5+6 6+3` = `3 6 11 9`
+ De `3 6 11 9` pasamos a `3+6 6+11 11+9` = `9 17 20`
+ De `9 17 20` pasamos a `9+17 17+20` = `26 37`
+ Y de `26 37` pasamos a `65`

Con todo este proceso obtuvimos `65`, el problema nos pide ordenar los primeros números `2 1 5 6 3` de cierta manera para obtener un número dado **k**. Tomate la libertad de ordenar los numeros en otro orden y ver que obtienes otro número distinto =)

Me quede aqui
