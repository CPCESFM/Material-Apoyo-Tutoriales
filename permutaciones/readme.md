# Permutaciones

Bienvenido al apartado de permutaciones, en este directorio encontrarás una presentación sencilla del tema, ejercicios propuestos y soluciones

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/colors.jpg)

## Ejercicios propuestos
+ [ID Codes](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=625&page=show_problem&problem=82)
+ [Sumas consecutivas](https://omegaup.com/arena/problem/sumasconsecutivas#problems)

## Un algoritmo para la determinar permutaciones

[En esta página](https://juanitobanca.com/2017/03/07/draft-permutaciones-lexicograficas/#:~:text=En%20el%20campo%20de%20las,dispuestos%20es%20un%20factor%20clave.) se describe un algoritmo muy sencillo para determinar la siguiente permutación lexicográfica:

Sea `P` un contenedor de nuestra permutación, velo como un arreglo de un tipo de dato como `char` o `int`

+ Encontrar el mayor valor de `x` tal que `P[x] < P[x+1]`. Si dicho valor de `x` no existe, entonces `P` es la última permutación lexicográfica que puede ser concebida por medio del conjunto de elementos que la conforman.
+ Encontrar el mayor valor de `y` tal que `P[x] < P[y]`. Si dicho valor de `y` no existe, entonces `P` es la última permutación lexicográfica que puede ser concebida por medio del conjunto de elementos que la conforman.
+ Intercambiar `P[x]` por `P[y]` y viceversa.
+ Invertir los elementos desde `P[x+1]` hasta `P[n]`.
