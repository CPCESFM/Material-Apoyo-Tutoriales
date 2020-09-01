# Arreglos
En este apartado se explican los ejercicios de este tema y al final se dejan muchos mas ejercicios con la finalidad de que practiques =)

## Arrays-DS
#### Descripción y análisis del problema
Dados **n** enteros dados en cierto orden, imprimirlos _de reversa_, sí, básicamente es eso

#### Ejemplitos
**n=4**, `1 2 3 4` tenemos que imprimir `4 3 2 1`

**n=6**, `-1 0 56 13 -2 8` tenemos que imprimir `8 -2 13 56 0 -1`

#### Solución
Basta con leer el número n y los n números en un arreglo en orden del 1 al n, luego recorrer los elementos del arreglo al revés, es decir de n a 1 e ir imprimiendo

## Saltador alegre
#### Descripción y análisis del problema
Se dice que una secuencia de **n** numeros es _saltador alegre_ si los valores absolutos de las diferencias entre elementos contiguos de toda la secuencia toman todos los valores entre **1** y **n-1**

#### Ejemplitos
Por ejemplo en la secuencia `1, 4, 2, 3` tenemos 4 elementos (i.e. **n=4**), veamos que las diferencias son **|1-4|=_3_**, **|4-2|=_2_** y **|2-3|=_1_**, logramos obtener todos los valores entre 1 y 3, por lo tanto esta secuencia es saltador alegre =)

Ahora, en la secencia `2, 6, 3, 1, 5, 2, 0` donde claramente **n=7** vemos que las diferencias que obtenemos son **|2-6|=_4_**, **|6-3|=_3_**, **|3-1|=_2_**, **|1-5|=_4_**, **|5-2|=_3_**, **|2-0|=_2_**, logramos obtener los numeros 2, 3 y 4 pero nos faltan 1, 5 y 6, por lo tanto esta secuencia no es saltador alegre =(

#### Solución
La solución propuesta es muy sencilla, para una secuencia dada hacer las respectivas diferencias entre todos los elementos e ir obteniendo los resultados, luego revisar si logramos obtener los numeros del 1 al n-1, si es así es saltador alegre, en caso contrario pues no lo es.
El algoritmo es intuitivo, para cada secuencia de numeros podemos hacer esto:
+ Leemos **n**
+ Con un ciclo **leemos los n números** y los vamos **guardando en un arreglo**
+ Con un ciclo **recorremos el arreglo elemento por elemento**, **obtenemos el abs de la diferencia** entre dos consecutivos, **checamos si entra en el rango de _1_ a _n-1_** y si es así **marcamos este numero como obtenido en un arreglo auxiliar**
+ Luego, **recorremos este arreglo auxiliar viendo que numeros están marcados como obtenidos**, si en el transcurso hace falta alguno pues **no es saltador alegre**, si logramos terminar el recorrido entonces juntamos todos los valores y **es saltador alegre**
+ Finalmente, **limpiamos todos los arreglos** para una proxima secuencia (para que no obtengamos errores por el cálculo anterior)
