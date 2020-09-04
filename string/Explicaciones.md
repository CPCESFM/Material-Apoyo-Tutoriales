# String
En este apartado se comentan las soluciones a los problemas recomendados de cadenas de caracteres =D

## [Reverse string](https://omegaup.com/arena/problem/Reverse-String/#problems)
#### Descripción del problema
Dada una cadena de caracteres, imprimirla al revés

#### Ejemplitos
Si nos dan `Perro` imprimimos `orreP`

Si nos dan `AnitaLavaLaTina` imprimimos `aniTaLavaLatinA`

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/string/Reverse_string.md)
En este ejercicio revisa el código solución en el repositorio, ahí mostraré directamente dos formas de hacerlo =)

## [String de fibonacci](https://omegaup.com/arena/problem/Fibonacci-String/#problems)
#### Descripción del problema
¿Conoces la sucesión de Fibonacci?, en esta sucesión cada termino es la suma de los dos anteriores, por ejemplo si los primeros dos términos fueran `1`y `1` tendriamos la sucesión `1 1 2 3 5 8 13 21 34 55 ...` donde por ejemplo el 1er termino es `1`, el 4to es `3`, el 7mo es `13` y así

Bueno pues en este problema reemplaza la suma por **concatenación** y los términos son **cadenas de caracteres**, entonces (en el ejemplo del problema) si tenemos los terminos `A` y `B` tendriamos la sucesión `A B AB BAB ABBAB BABABBAB ABBABBABABBAB ...` donde por ejemplo el 2do termino es `B`, el 4to es `BAB`, el 7mo es `ABBABBABABBAB` y así

El problema es, dado un número **n**, imprimir el **n-ésimo** termino de la sucesión con los dos string iniciales que te dan

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/string/String_de_Fibonacci.cpp)
La solución es muy sencilla y se parece mucho a la forma tradicional (iterativa) de calcular terminos de la sucesión de Fibonacci, el algoritmo queda así (nota que **A**, **B** y **C** son nuestras variables `string` y **n** es un `int`)
+ Leemos el primer término **A**, el segundo término **B** y el número del término que deseamos calcular **n**
+ Si nos dan **n=1** imprimimos **A** directo, si nos dan **n=2** imprimimos **B** directo, si no continuamos el algoritmo
+ Con ayuda de un ciclo de **3** hasta **n** vamos calculando los string de la sucesión de esta manera:
	+ Calculamos el siguiente término (concatenando **A** y **B**) y lo guardamos en **C**
	+ Para la próxima iteración preparamos las variables para que sigan calculando términos, en **A** guardamos lo que tenga **B**
	+ En **B** guardamos lo que tenga **C**, con esto aseguramos que la próxima vez que entremos al ciclo, **C** será la concatenación de los nuevos valores de **A** y **B**, resultando en un nuevo término, tomate un momento para pensar en esta idea
+ Una vez finalizado el ciclo el n-ésimo término quedó almacenado en **C**, por lo tanto imprimimos este string

Los detalles de implementación los puedes consultar en el código solución, eres libre de intentar hacer la concatenación de otra manera y ver como se desempeña tu programa =)

## [Substring Removal Game](https://codeforces.com/contest/1398/problem/B)
#### Descripción del problema
Alice y Bob están jugando un juego e inicialmente tienen un string `s` que solo tiene los caracteres `1` y `0`, sabes que Alice tira primero, después Bob y así sucesivamente

En un tiro puedes eliminar grupitos (en realidad se llaman _substrings_ o subcadenas) de caracteres consecutivos, por ejemplo en `0111100111000` puedes eliminar por ejemplo los substrings `1111`, `111`, `0` y `000` (si eliges eliminar los que mas puedas claro), la curiosidad es que si eliminas un substring este desaparece y queda otro string, por ejemplo si eliminamos de `0111100111000` el substring `1111` entonces el string pasa a ser `000111000`. La puntuación del juego es simple, es el número de caracteres `1` que eliminó el jugador durante sus movimientos en el juego

Por cada caso de prueba imprime **el puntaje que logra obtener Alice** suponiendo que los dos jugadores juegan óptimamente (checa la consideración final)

#### Ejemplitos
Si tenemos `011011110111`, Alice tira y **suma 4** dejando `01100111`, Bob tira y suma 3 dejando `01100`, Alice tira y **suma 2** dejando `000`, ya no hay caracteres `1` por lo tanto **Alice gana 6** y esa es la respuesta

Trata de ejecutar todos los casos de prueba del ejemplo y crea los tuyos

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/string/Substring_Removal_Game.cpp)
Al hacer varios casos de prueba podemos anotar los siguientes hechos importantes
+ El string original `s` tiene varios substrings de solo caracteres `1` y **estos están separados por substrings de solo caracteres** `0`, de modo que al eliminar un substring de solo caracteres `1` nunca se forma otro mas grande al recorrerse los otros substrings. Esto puede ser un poco enredado, en otras palabras **todos los substrings** (ya sea de solo caracteres `1` o `0`) **estan uno tras otro** (pues sí, ¿no?)
+ Cada jugador en su respectivo turno decide eliminar el mayor substring de `1` que hay en ese momento (para poder ganar mas puntos)
+ Por los hechos anteriores, Alice al principio elimina el substring de mayor longitud de `s`, luego Bob elimina el segundo substring de mayor longitud, Alice luego elimina el tercero de mayor longitud, Bob el cuarto y así sucesivamente

Con estos hechos concluimos que **basta con obtener la longitud de todos los substring de solo caracteres `1` de la cadena `s`, ordenar estas longitudes y finalmente asignar a Alice las que tengan indices impares, sumarlas e imprimir la respuesta**

_Un ejemplo dice mas que mil palabras_. Consideremos `11100100011111011111000010110111101111111`, de donde obtenemos los siguientes substrings de solo caracteres `1`: `111`, `1`, `11111`, `11111`, `1`, `11`, `1111`, `1111111` que tienen estas longitudes respectivamente: **3, 1, 5, 5, 1, 2, 4, 7**, ordenamos **de mayor a menor** y tenemos **7,5,5,4,3,2,1,1**, entonces asignamos el **7** a Alice, el **5** a Bob, el **5** a Alice, el **4** a Bob y así, solo Alice le corresponden los impares (si vemos esos numeros indexados desde 1), entonces a Alice le corresponden (los números en negrita): **7**,5,**5**,4,**3**,2,**1**,1 y por tanto su puntuación es **7+5+3+1=_16_**

¿Que tal eh? me he tomado la libertad de explicar directamente la solución, una primera aproximación podría haber pensado como realizar la ejecución del juego paso a paso, tiro a tiro, esto es más complicado (aunque no imposible) e inecesario una vez que te das cuenta de este trucazo cuando haces varios casos de prueba y los resuelves a mano =)

El algoritmo queda asi para cada cadena:
+ Leemos la cadena en un string
+ Con un ciclo recorremos la cadena caractere a caracter
	+ Si es un `1` entonces comenzamos otro ciclo (sobre la misma variable) para ir contando de cuantos caracteres se compone este substring de solo `1`'s (esto con ayuda de otra variable)
	+ Cuando acabemos este substring (es decir, encontremos un `0` el el camino) tendremos ya en nuestra variable la longitud del substring, insertamos este valor en un vector (es necesario ya que no sabemos cuantos substring hay, es decir, va creciendo el numero ded longitudes)
+ Ordenamos el vector de longitudes, podemos usar `std::sort` que los ordenará de menor a mayor o bien, podemos usar nuestra propia función de comparación para ordenar de mayor a menor, el punto es saber como van las longitudes de mayor a menor
+ Con un ciclo vamos recorriendo este vector ya ordenado de mayor a menor y hacemos una variable de respuesta para Alice
	+ El elemento mas grande se suma a la respuesta, el siguiente no se suma, el siguiente se suma a la respuesta y así sucesivamente, ir avanzando de dos en dos (regresa al ejemplo para que te quede mas claro si es necesario)
+ Finalmente imprimimos la variable de respuesta seguida de un salto de línea

### [¡Ya soy genial manejando string!](https://www.youtube.com/watch?v=BtLSaxRnIhc)
Manejar cadenas de caracteres es útil en concursos de programación competitiva, aprenderte funciones útiles para estos objetos, trucazos para hacer algoritmos y combinarlos con temas pasados (y futuros) te hará tener mas experiencia y habilidad, aquí te dejo otros ejercicios introductorios que deberías intentar para afianzar conocimiento
+ [Palindromos](https://omegaup.com/arena/problem/COMI-Palindromos/#problems)
+ [K-th Beautiful String](https://codeforces.com/contest/1328/problem/B)
+ [Carretes](https://omegaup.com/arena/problem/Carretes/#problems)
+ [Short substrings](https://codeforces.com/problemset/problem/1367/A)
+ [Fila de hormigas](https://omegaup.com/arena/problem/Fila-de-hormigas#problems)
+ [Longest Palindrome](https://codeforces.com/problemset/problem/1304/B)
+ [Baker](https://omegaup.com/arena/problem/Baker/#problems)
+ No podiamos olvidar [el repositorio del CP3 para problemas AdHoc de string](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=737) aunque te recomiendo ver esto al final pues está un poco mas disperso y tendrás que manejar bien todas las herramientas sugeridas en los problemas anteriores

`Hasta la proxima amigos`
