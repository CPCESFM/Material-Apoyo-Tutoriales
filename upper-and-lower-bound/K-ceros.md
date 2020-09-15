# Solución al problema [K ceros](https://omegaup.com/arena/problem/kceros/#problems)

Para este problema debes partir del resultado de que los ceros al del factorial de un número se pueden calcular con la suma de las divisiones enteras
del numero entre algunas potencias de 5 `n/5 + n/5^2 + ... + n/5^i`. Si meditamos un poco este resultado, este proviene del hecho de que 5 y sus múltiplos generan los **0s** al multiplicar, por ejemplo `10!=3,628,800` tiene dos **0s** al final y `10/5` parte entera es `2`. 

Una vez que tenemos el análisis anterior podemos generar una función que nos permita revisar la cantidad de ceros en los que podemos descomponer un número, esto lo haremos por medio de un contador y un ciclo `while()`. 

```C++
long long int divide(long long int val) {
	long long int acumulado=0;
	while(val>0) {
		val/=5;
		acumulado+=val;
	}
	return acumulado;
  }
```

**Nota** que esta es una función del tipo `long long int` ya que los límites de los números que se solicitan no caben en un `int` común. 

Con la primera parte resulta el siguiente paso es buscar el número cuyo factorial tenga `m-ceros`, bueno esto lo haremos con una `binary searh`, pero no la que está implementada ya que esta es una función **buleanea** que usa el algoritmo revisado en el video, en este caso nos tocará hacer nuestra propia implementación que como parámetro de comparación use nuestra función de `divide()`. Para implementar una `binary search` haremos uso de tres variables `izq`, `der` y `mitad`, en un principio las primeras dos apuntaran a `0` y `2000000000000` respectivamente ya que son nuestros límites de rango, luego mitad se calculará con la parte entera de la división `(izq+der)/2` y justo ahí es donde hacemos la primer pregunta en caso de que no encontremos preguntamos si es que la mitad es menor que el valor preguntado en ese caso nos movemos a la izquierda de caso contrario hacia la derecha, esto lo hacemos de forma iterativa con un ciclo `while()` que parará justo antes de que los dos límites se toquen. 

```C++
long long int BusquedaBinaria() {
	long long int izq=0;
	long long int der=2000000000000;
	long long int mitad;
	long long int aux;
	while(izq+1<der) { 
		mitad=(izq+der)/2;
		aux=divide(mitad);
        if(aux<m) {
        	izq=mitad;
        }else if(aux>=m) {
        	der=mitad;
        }
    } 
    return izq+1; 
} 
```

**Nota** que pudimos implementar este tipo de busqueda ya que estamos buscando un número entero y por su propia **construcción** estos son **ordenados** y convenientemente de menor a mayor.

Prácticamente lo anterior concluye nuestro problema, ya sólo resta la impresión.

```C++
cout << BusquedaBinaria();

```

