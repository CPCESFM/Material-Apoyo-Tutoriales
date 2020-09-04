# String https://www.youtube.com/watch?v=BtLSaxRnIhc

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
Si tenemos `011011110111`, Alice tira y **suma 4** dejando `01100111`, Bob tira y suma 3 dejando `01100`, Alice tira y **suma 2** dejando `000`, ya no hay caracteres '1' por lo tanto **Alice gana 6** y esa es la respuesta

Trata de ejecutar todos los casos de prueba del ejemplo y crea los tuyos

#### [Solución](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/string/Substring_Removal_Game.cpp)
Hola aqui me quede
