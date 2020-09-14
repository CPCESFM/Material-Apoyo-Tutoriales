# Permutaciones
En este apartado se comentan las soluciones de los problemas para `std::next_permutation` y `std::prev_permutation`

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
+ Y de `26 37` pasamos a `26+37` = `65`

Con todo este proceso obtuvimos `65`, el problema nos pide ordenar los primeros números `2 1 5 6 3` de cierta manera para obtener un número dado **k**. Tomate la libertad de ordenar los numeros en otro orden y ver que obtienes otro número distinto =)

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/permutaciones/Sumas_consecutivas.cpp)
Probar todas las posibles permutaciones de los números que nos dan, calcular que número se obtiene con el proceso en cada permutación e ir comparando con **k**, como nos aseguran que se puede formar **k** con alguna permutación esta solución es válida

**_¿Pero cual es la complejidad de hacer todas las permutaciones de n números?_** Por supuesto tenemos **n!** permutaciones distintas, si utilizamos la función `next_permutation(,)` que transforma un rango en la siguiente permutación en O(n/2) tendremos aproximadamente (en el peor caso por supuesto) una complejidad de O(n/2*n!)que aprox es O(n*n!), a esto debemos todavia agregar la complejidad del proceso de sumas (que describiremos a continuación) pero **acotemos la complejidad de nuestra solución en O(m n!)** con **m** una constante que represente la complejidad del calculo para cada permutación. Como **1<=n<=10** esto es perfecto para este problema con 1 segundo de tiempo de ejecución (recuerda que una complejidad de n! necesita limites pequeñisimos para entrar en tiempo)

**¿Como hacer el proceso de sumas?** Tomemos la secuencia `1 2 3 4` para ejemplificar y supongamos está guardada en un arreglo, entonces se ve así: `[1] [2] [3] [4]`. Hagamos el proceso de sumas sobre este mismo arreglo, te dejo una imagen de como se haría a mano y ve viendo como se va haciendo con el algoritmo

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/sumas_consecutivas.jpg)

+ Tenemos `[1] [2] [3] [4]`, obtengamos los siguientes tres números **sumando en cada casilla el número actual con el siguiente**: `[1+2] [2+3] [3+4] [4]`, observa que solo lo hacemos para los primeros tres y el cuarto ya no se modifica. Entonces tenemos ahora `[3] [5] [7] [4]`
+ Tenemos `[3] [5] [7] [4]`, obtengamos los dos siguientes comoo lo hicimos en el paso anterior pero solo con los dos primeros: `[3+5] [5+7] [7] [4]` (ahora no modificamos el tercer número, solo necesitabamos dos). Así obtuvimos `[8] [12] [7] [4]`
+ Tenemos `[8] [12] [7] [4]`, otengamos el siguiente numero (el ultimo, la respuesta) poniendo en el primero la suma con el segundo: `[8+12] [12] [7] [4]` (ahora no modificamos ni el segundo, solo el primero). El arreglo queda así `[20] [12] [7] [4]`

**El número obtenido es el que esta en el primer indice del arreglo**, es decir, `20` es el número obtenido para la permutación `1 2 3 4`, ¿que tal eh? ya describimos una forma de hacer esas sumas en un solo arreglo

Con todo esto esclarecido, podemos enunciar que el algoritmo de la solución queda así:

+ Leemos `n`, `k` y los n numeros en un arreglo llamado (por decir un nombre) `arre`
+ Ordenamos este arreglo de menor a mayor, para esto utilizamos `sort(,)` sobre `arre`, hacemos esto para obtener **la primer permutación lexicográfica**
+ Con un ciclo `do while` checamos si la permutación nos da el resultado que queremos: `k` **(este proceso lo haremos con otra función llamada** `calcula()`**, devuelve el número obtenido por el proceso de sumas)**, si obtenemos `k` terminamos y se acaba el programa, sino se calcula la suguiente permutación con `next_permutation(,)` y se reintenta este mismo paso **(checa como se implementa el** `next_permutation(,)` **aprovechandonos de que devuelve** `true` **mientras puede seguir generando)**

Para la función `calcula()` queda así:

+ La permutación está en `arre` así que vamos a copiar sus elementos a otro arreglo `aux` para trabajar solo con este último, esto lo hacemos para seguir calculando las permutaciones directamente en `arre` sin verse afectado
+ Tal como describimos más arriba, con ayuda de un ciclo vamos a ir retrocediento una variable llamada `tope` que **inicia en n-1 y termina en 1, disminuyendo de 1 en 1**
	+ Con un ciclo, vamos recorriendo `aux` **casilla por casilla desde el primer indice hasta el indice** `tope`
		+ Dentro de este último ciclo simplemente **sumamos la casilla actual con la siguiente casilla y la guardamos en la casilla actual** (si la variable del ciclo fuese `i` esto sería `aux[i]=aux[i]+aux[i+1]`)
+ Al finalizar la respuesta se queda **en el primer indice de** `aux`, por lo que lo retornamos y listo

Checa el código, de seguro te quedará mucho mas claro si lo sigues a tu ritmo =)

## Para finalizar
Los problemas sobre permutaciones en programación competitiva no son los más frecuentes pero preparate para obtener un AC en cuanto veas uno, te dejaré un par de problemas relacionados con permutaciones, recuerda que el uso de las funciones `next_permutation(,)` debe ser controlado pues existen **n!** permutaciones distintas de un conjunto con **n** elementos, mucho ojo

+ [K-th Beautiful String](https://codeforces.com/contest/1328/problem/B) (mucho ojo, insisto)
+ [Wordfish](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=625&page=show_problem&problem=3650)

`Hasta la proxima amigos`
