# Arreglos
En este apartado se explican los ejercicios de este tema

## [Arrays-DS](https://www.hackerrank.com/challenges/arrays-ds/problem)
#### Descripción del problema
Dados **n** enteros en cierto orden, imprimirlos _de reversa_, sí, básicamente es eso

#### Ejemplitos
**n=4**, `1 2 3 4` tenemos que imprimir `4 3 2 1`

**n=6**, `-1 0 56 13 -2 8` tenemos que imprimir `8 -2 13 56 0 -1`

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/arreglos/arraysDS.cpp)
Basta con leer el número n y los n números en un arreglo en orden del 1 al n, luego recorrer los elementos del arreglo al revés, es decir de n a 1 e ir imprimiendo


## [Stones on the table](https://codeforces.com/problemset/problem/266/A)
#### Descripción del problema
Dadas **n** piedras que estan alineadas en una mesa y que pueden ser de colores _Red_, _Green_ y _Blue_ nos piden **imprimir el minimo numero de piedras que debemos quitar para que no hayan dos piedras cosecutivas con el mismo color**

#### Ejemplitos
Tomemos por ejemplo las piedras `RRG`, no podemos no quitar piedras porque hay dos piedras rojas juntas, podemos quitar solamente la primer piedra y quedarian `RG` (esto completa la tarea) o bien podemos quitar la segunda piedra y obtener de nuevo `RG`, en cualquier caso el minimo numero de piedras que necesitamos quitar es `1` y es la respuesta

Si tenemos `RRRRRGB` hay muchas rojas juntas y estas son las únicas que nos impiden cumplir el objetivo, no podemos quitar 1, 2 o 3 piedras rojas pues nos quedan 4, 3 y 2 piedras juntas aún, por lo tanto debemos quitar `4`para que solo nos quede una roja y obtener `RGB`

Por ultimo consideremos `RGRRRBBGRGBGRBBRGGG`, hay secciones que son las que causan el problema como `RRR`, `BB`, `BB` y `GGG`, en cada una debemos eliminar 2, 1, 1 y 2 piedras respectivamente, por lo tanto la respuesta es 2+1+1+2=`6`

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/arreglos/Stones_on_the_table)
Analizando varios casos como los anteriores podemos ver que el problema en si son **los grupos de piedras del mismo color** (hay secciones en la linea como `RGBRG` que ya cumplen el objetivo, no tener dos del mismo color juntas) y encontramos que, para cumplir el objetivo, si tenemos un grupito de **m** piedras consecutivas del mismo color debemos eliminar **m-1** (para que solo quede una piedra de ese color)

Entonces basta con recorrer todas las piedras en la linea e ir encontrando estos grupitos de piedras del mismo color y cuantas piedras tienen, sumando a la respuesta ese numero menos una piedra y listo, al final la respuesta acumulada es el minimo numero de piedras que se deben eliminar para que no haya dos del mismo color juntas en toda la linea

El algoritmo queda mas o menos asi:
+ Leemos **n**
+ Leemos las **n piedras** en un **arreglo de tipo caracter** por el formato en que nos dan los colores (letras _R_, _G_ y _B_)
+ Con un ciclo **vamos recorriendo el arreglo de piedras** una por una. **Para cada una de ellas** con ayuda de un ciclo **buscamos si las que siguen son del mismo color**, vaya, buscamos que formen un grupito, **si lo forman, vamos contandolas** y en cuanto se termine ese grupito (**haya un cambio de color**) **sumamos a la respuesta general el numero de piedras de ese grupito menos una**
+ Al final, **imprimimos la respuesta acumulada que encontramos**


## [Saltador alegre](https://omegaup.com/arena/problem/Saltador-alegre/#problems/Saltador-alegre)
#### Descripción del problema
Se dice que una secuencia de **n** numeros es _saltador alegre_ si los valores absolutos de las diferencias entre elementos contiguos de toda la secuencia toman todos los valores entre **1** y **n-1**

#### Ejemplitos
Por ejemplo en la secuencia `1, 4, 2, 3` tenemos 4 elementos (i.e. **n=4**), veamos que las diferencias son **|1-4|=_3_**, **|4-2|=_2_** y **|2-3|=_1_**, logramos obtener todos los valores entre 1 y 3, por lo tanto esta secuencia es saltador alegre =)

Ahora, en la secencia `2, 6, 3, 1, 5, 2, 0` donde claramente **n=7** vemos que las diferencias que obtenemos son **|2-6|=_4_**, **|6-3|=_3_**, **|3-1|=_2_**, **|1-5|=_4_**, **|5-2|=_3_**, **|2-0|=_2_**, logramos obtener los numeros 2, 3 y 4 pero nos faltan 1, 5 y 6, por lo tanto esta secuencia no es saltador alegre =(

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/arreglos/saltador_alegre.cpp)
La solución propuesta es muy sencilla, para una secuencia dada hacer las respectivas diferencias entre todos los elementos e ir obteniendo los resultados, luego revisar si logramos obtener los numeros del 1 al n-1, si es así es saltador alegre, en caso contrario pues no lo es.

El algoritmo es intuitivo, para cada secuencia de numeros podemos hacer esto:
+ Leemos **n**
+ Leemos los **n números** y los vamos **guardando en un arreglo**
+ Con un ciclo **recorremos el arreglo elemento por elemento**, **obtenemos el abs de la diferencia** entre dos consecutivos, **checamos si entra en el rango de _1_ a _n-1_** y si es así **marcamos este numero como obtenido en un arreglo auxiliar**
+ Luego, **recorremos este arreglo auxiliar viendo que numeros están marcados como obtenidos**, si en el transcurso hace falta alguno pues **no es saltador alegre**, si logramos terminar el recorrido entonces juntamos todos los valores y **es saltador alegre**
+ Finalmente, **limpiamos todos los arreglos** para una proxima secuencia (para que no obtengamos errores por el cálculo anterior)

`Hasta la próxima amigos`
