# Complejidad computacional
Has llegado al repositorio de complejidad computacional, un lugar en el que descubrirás si tu programa **terminará antes de un respiro** o **despues de miles de millones de años**

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/complejidad.gif)

Vamos a comenzar por explicar como se debe hacer el analísis de complejidad para un problema en particular a través de varias etapas

## Comenzando por el problema
Muchas veces cuando comienzas a leer un problema sirve hacerse la pregunta _¿he visto este tipo de problema antes?_, si es asi **lo ideal es que programes el algoritmo que lo soluciona rápidamente** pues ya lo conoces, sino es así es cuando comienzas a pensar ... ¿como lo resuelvo?, entonces a tu cabeza llegan ideas e ideas, en este punto lo ideal es que comiences a pensar en algunos casos que se te puedan ocurrir **para ir construyendo el algoritmo**, vaya que así es como vas a poder encontrar una solución

## ¡Ya tengo un algoritmo de solución!
Bien, ya has diseñado el algoritmo y ves que funciona para varios casos que te imaginas, los pruebas en tu mente o papel y listo, aparentemente el resto del problema es pan comido **pero antes de continuar pregúntate `¿Dada la máxima entrada del problema (dada en la descripción), puede mi algoritmo (con su respectiva complejidad de tiempo y memoria) pasar los límites dados?`**

Y esque es en esta parte donde corres peligro, tu algoritmo puede funcionar pero, **¿ya analizaste su complejidad?**, no bromeamos de hecho ese es el corazón de la programación competitiva, si se aceptaran respuestas sin límites podrías siempre mandar soluciones con algoritmos súper ineficientes y sería tomada como correcta, no habría nada que pensar vaya, sería una cuestión de programación

En fin, supongamos que no realizaste tu analísis de complejidad, vamos a hacerlo ahora mismo ya que tienes tu algoritmo construido (no necesariamente programado, por supuesto)

## Determinando la complejidad de mi algoritmo
Hay componentes de tu algoritmo que hace que la complejidad del algoritmo crezca y te los explicaré con algunos trozos de código

+ Operaciones básicas `+ O(1)`
Si haces una operación básica como una suma, una multiplicación, asignación o consulta aportas a tu algoritmo una _complejidad constante_ por cada una de ellas, por ejemplo en
```C++
cin >> aux;
aux+=5;
aux*=aux;
cout << aux;
```
hacemos un número de operaciones constante (4 específicamente), por lo tanto vamos a decir que este algoritmo tiene **complejidad constante**

+ Condicionales `+ O(1)`
Si lo piensas en realidad al hacer un `if` debemos evaluar condiciones, bueno estas pueden ser tratadas como operaciones básicas (siempre que no involucren funciones claro, sabes a que me refiero). Si el algoritmo solo tiene condicionales

+ Ciclos `+ O(n)`
Los ciclos como los `for` y `while` aportan una complejidad importante dependiendo de que haya dentro de ellos, tratemos primero que dentro tienen instrucciones básicas, digamos que por ejemplo, queremos iterar con respecto a un límite **n**
```C++
int aux=1;
for(int i=1; i<=n; i++) {
	aux*=2;
}
```
claramente este `for` está repitiendo **n** veces una operación básica, por tanto suma `O(n)` a la complejidad del algoritmo, fácil ¿no?, que tal este
```C++
int num=sqrt(n);
int i=1;
while(i<=num) {
	cout << "Hola ";
}
```
es clarísimo que suma `O(sqrt(n))` a nuestro algoritmo, en realidad los ciclos se dedican a **multiplicar la complejidad de lo que hay dentro de ellos**, si hay diez operaciones dentro de un ciclo que se repite **n** veces entonces sumamos `O(10n)` a nuestro algoritmo, de modo que podemos obtener distintas combinaciones

Haciendo un resumen de esta parte, con los ciclos podemos obtener complejidades del tipo `O(n)`, `O(2n)`, `O(n/3)`, etc, en general `O(kn)` con `k` una constante, estas complejidades se llaman **lineales sobre n** ya que dependen de este paramétro

Es posible obtener complejidades de **raiz cuadrada** como `O(sqrt(n))` que resultan ser menores que las lineales, claramente

+ Funciones y cosas mas avanzadas
Para el momento en que estas leyendo esto puede que no hayas visto complejidades famosas como las **logaritmicas** `O(log n)` (presentes en _containers_ como `map` y `set`), las **lineal logaritmicas** `O(n log n)` (presentes en varios métodos de ordenamiento como _quicksort_, _mergesort_, etc), las **factoriales** `O(n!)` (presentes en problemas relacionados con permutaciones o formulas matemáticas) o las **potenciales** `O(2^n)`, `O(n^n)` (presentes en algoritmos de arboles, DP y similares), pero realmente no importa pues te das una idea al ver de que paramétro dependen: **n**

Con todo esto trata de obtener que complejidad tiene tu algoritmo y obtén una expresión de este tipo `O(...)` que dependa de variables que te dan en los limites para usarlas en los siguientes pasos

## No se te olvide el espacio
A lo largo de todo lo que hemos estudiado has utilizado variables, arreglos y otras cosas, bueno ya debes saber mas o menos como calcular el espacio que ocupa cada uno de estos, **es fundamental saber calcular cuanto espacio en objetos vamos a necesitar en nuestro algoritmo** pues tenemos un _limite de memoria_, no podemos andar utilizando arreglos de 500 mb cuando solo nos dan 64 mb

Si al calcular el espacio que necesitarás **sobrepasas el límite** es claro que necesitas optimizar tu espacio, la verdad es muy posible que estes desaprovechando algunos lugares de memoria o incluso que no necesites otro arreglo para hacer esa tarea ... en este momento es cuestión de examinar que es lo que estás haciendo: tu algoritmo, en cuestión de espacio hay varias alternativas como las que te mencioné o incluso utilizar _containers_ del lenguaje que optimicen todo, mucho ojo con esta parte

## ¿Va a jalar el algoritmo o no?
Finalmente si tu algoritmo entra en espacio (sino, de todos modos sigue leyendo) es la hora de la verdad, **probar la complejidad que acabas de obtener con el límite dado en el problema para cada variable**, aquí es cuando normalmente se decide todo

Los tiempos límite que te dan en los problemas están dados en segundos, una buena aproximación que podemos tomar en la programación competitiva es asumir que `1 segundo = 10^8 operaciones computacionales`

Sustituye los límites en tu expresión y obtendrás **el numero de operaciones que ejecutará tu algoritmo en el peor caso**, de modo que, para comparar con el tiempo que nos dan, **divide entre 10^8 para obtener la cantidad de segundos que ejecutará**

En este punto todo esta decidido y pudieron haber sucedido estas cosas:

+ **Tu algoritmo entra en tiempo y en memoria** y terminaste, programalo y mandalo, adiós
+ Para los que no tenemos tanta suerte y **nuestro algoritmo no entra en tiempo pero si en memoria** hay dos cosas por hacer, o modificamos nuestro algoritmo actual cuanto sea necesario para reducir su complejidad o cambiamos totalmente de idea de solución y buscamos otro algoritmo; cualquier opción que tomes es un gran reto pero te ayuda a ir madurando en que tipo de estrategias de solución buscas, es decir, ganas experiencia que podrás usar después
+ Si por alguna razón tu algoritmo **no entra en memoria pero si en tiempo** puedes intentar buscar otro algoritmo que no requiera de tanto espacio, ve el lado bueno, tienes la ventaja de gastar ahora un poco de eficiencia para mejorar el espacio
+ Por último **si no entra ni en tiempo ni en memoria** definitivamente necesitas mejorar tu idea, no significa que eches a la basura este primer algoritmo, esta primera aproximación debes ir mejorandola para optimizar porque **en realidad si resuelves el problema**, ya tienes algo que si funciona (aunque no pase los límites), trabaja en ir optimizandola

## Conclusiones
Muchas personas se dejan ir por el primer algoritmo que descubren al leer un problema y trabajarlo por un ratito, en el mejor de los casos no hacen el analisis de complejidad y obtienen un poderoso **Accepted** (esto no siempre pasa, de hecho muy pocas veces) pero en el caso promedio suelen obtener un **Time limit excedeed** o un **Memory limit excedeed**, lo cual se pudo haber evitado al dedicarle un momento al analisis de complejidad

¿Conclusión?, no eches al saco roto el analisis de complejidad ya que es fundamental desarrollarlo para la programación competitiva y te ayuda a pensar en soluciones óptimas, creativas y nutritivas, llenas de experiencia

## Una tabla muy útil
Por último checa esta tabla, aquí enlistamos **las peores complejidades que pueden ser factibles según el tamaño de tu variable dependiente**, es decir, dado el tamaño de, digamos, **n** de la que depende el problema, cual es la peor complejidad que puedes meter para tu algoritmo

| Tamaño de **n**  | Peor complejidad admisible|
|:----------------:|:-------------------------:|
| <= 10 u 11       | `O(n!)`, `O(n^6)`         |
| <= 15 a 18       | `O(2^n * n^2)`            |
| <= 18 a 22       | `O(2^n * n)`         |
| <= 100       | `O(n^4)`         |
| <= 400       | `O(n^3)`         |
| <= 2,000       | `O(n^2 log n)`         |
| <= 10,000     | `O(n^2)`         |
| <= 1,000,000       | `O(n log n)`         |
| <= 100,000,000       | `O(n)`, `O(log n)`, `O(1)`|

`Hasta la próxima`
