# Repaso de arreglos

Los arreglos son estructuras diseñadas para contener muchas variables, si pensamos que una variable es un pequeño contenedor entonces un arreglo es un grupo de contenedores, en la memoria estos se almacenan _consecutivamente_ por lo que nos gusta representarlos así:

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/arre_contenedor.png)

## Datos importantes de los arreglos
+ **Se declaran igual que variables pero añadiendo número de casillas**
	+ Por ejemplo, un arreglo de cinco casillas de tipo entero se declara `int arre[5];`, fácil ¿no?
	+ Un arreglo de un millón de casillas de tipo entero largo se declara `long long int arreglote[1000000];`
	+ No puedes ponerle _tamaño negativo_ (¿por qué lo harías?) y además **si declaras un arreglo demasiado grande tu programa no compilará**
+ **Declaración global o local**
	+ Dependiendo donde declares tu arreglo en tu programa, éste iniciará con valores todos cero (si es global, recomendado) o iniciará con todos sus valores basura (si es local, no recomendado). Checa este código:
```C++
#include <bits/stdc++.h>
using namespace std;
///Aqui se declaran las cosas globales, arreglos todos iniciando en cero
int arre[100000];

void lectura() {
	///Todo, todo dentro de funcion es local, inicio con basura
	long long int arregloLocal[12312312];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Dentro de una función se declaran cosas locales, todo iniciando en basura
	int arre_local[1002];
	return 0;
}
```
+ **Númeración de las casillas, desde cero**
	+ Las casillas en un arreglo se enumeran desde el índice 0 ya van aumentando de 1 en 1
	+ Por ejemplo, el arreglo `int casillas[12];` tiene efectivamente 12 casillas, **la primera tiene el índice 0**, la segunda el indice 1 y así, puede imaginar entonces que **la última casilla tiene el indice 11**
	+ Esto de la numeración es para todos los arreglos, en general _si un arreglo tiene **n** casillas entonces están enumeradas del **0** a la **n-1**_

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/arre_numeracion.png)

+ **Tip personal para guardar en arreglos**
	+ Como las casillas de un arreglo se enumeran desde cero, si quisiera guardar **n** datos e imprimirlos se vería mas o menos así:
```C++
///A lo mas 1000 datos, espacios justitos
int arre[1000];
int n;

int main() {
	cin >> n;
	///Guardamos en las primeras n casillas, del 0 al n-1
	for(int i=0; i<n; i++) {
		cin >> arre[i];
	}
	///Observa los limites de los for
	for(int i=0; i<n; i++) {
		cout << arre[i] << " ";
	}
	return 0;
}
```

![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/arre_forma_cero.png)

Ahora, si no te gusta que las cosas se guarden así (con índices del **0** al **n-1**) entonces prueba **declarar tu arreglo con dos casillas extra** para poder guardar los datos del **1** al **n**, me explico:

```C++
///Dos espacios mas de los máximos necesarios
int arre[1002];
int n;

int main() {
	cin >> n;
	///Guardamos a partir de la primera casilla, es decir de la 1 a la n (mas intuitivo)
	for(int i=1; i<=n; i++) {
		cin >> arre[i];
	}
	///Observa ahora que nos movemos en los for de la 1 a la n, no de la 0 a la n-1
	for(int i=1; i<=n; i++) {
		cout << arre[i] << " ";
	}
	return 0;
}
```
![](https://github.com/CPCESFM/Material-Apoyo-Tutoriales/blob/master/commun/arre_forma_uno.png)

Es tu elección la forma en como guardas los datos en los arreglos, elige la que mas se te acomode, recuerda que este tip (la segunda forma) es por comodidad y claridad

## Cálculo de memoria de un arreglo
En realidad esto es muy fácil, el número de bytes que ocupa un arreglo es sencillamente **el número de casillas del arreglo** multiplicado por **el peso en bytes del tipo de dato del arreglo**, para esto tienes que saberte cuanto espacio ocupa una sola variable de cada tipo de dato

Por ejemplo, `int arre[25000];`, sabemos que un `int` ocupa `4 bytes` por variable, entonces `arre` pesa `100000 bytes`, si dividimos entre `1024` obtendremos los `kilobytes` y si volvemos a hacerlo obtendremos los `megabytes`, de modo que este arreglo pesa `97.65 kb` o bien `0.095 mb`

Otro ejemplo, `long long int arreglo[10000002]` ocupa `10000002 * 8 bytes = 80000016 bytes` o bien `78125.01 kb` o bien `76.293 mb` de memoria

Recuerda que **los problemas siempre te indican una memoria limite que puedes usar**, calcula siempre cuanta vas a ocupar con tus arreglos para que no te vayas a salir del límite, si necesitas saber cuanto pesa cada tipo de dato revisa nuestro repositorio de variables y tipos de datos =)

## ¿Algo más?
En realidad manejar arreglos es muy sencillo, trata de pensar en ellos cuando te indiquen el número de variables que te van a dar, si necesitas guardar datos, si necesitas tener una lista o si necesitas ir calculando y guardadndo cosas, esto se arregla resolviendo problemas y tomando experiencia, no entres en pánico

Puede ser útil leer otra fuente sobre los arreglos, [esta página](https://www.programarya.com/Cursos/C++/Estructuras-de-Datos/Arreglos-o-Vectores) tiene una explicación alternativa que puede ser útil =)

Eso es todo de arreglos, `hasta la proxima`
	
	
	
	
