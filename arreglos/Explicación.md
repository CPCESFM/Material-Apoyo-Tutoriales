# Arreglos
En este apartado se explican los ejercicios de este tema y al final se dejan muchos mas ejercicios con la finalidad de que practiques =)

### Saltador alegre

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

#### Código
```C++
#include <bits/stdc++.h>
using namespace std;
int t;
int arre[3002];
bool aux[3002];

void leer() {
	///Leemos n de esta secuencia
	cin >> n;
	///Leemos los n numeros y los vamos guardando en el arreglo arre[]
	for(int i=1; i<=n; i++) {
		cin >> arre[i];
	}
}

void dife() {
	///Vamos recorriendo el arreglo elemento por elemento hasta uno antes del final
	for(int i=1; i<n; i++) {
		///Obtenemos el numero que queremos
		int diferencia=abs(arre[i]-arre[i+1]);
		///Checamos que no se salga del rango que nos interesa
		if(diferencia<n) {
			///No se sale del rango, lo marcamos como obtenido en nuestro arreglo aux[] que es bool, apto para esto =)
			aux[diferencia]=1;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Primero leemos la cantidad de casos que resolveremos
	cin >> t;
	///Ahora leemos esta cantidad de casos, uno a la vez
	for(int z=1; z<=t; z++) {
		///Leemos toda la secuencia con la función leer()
		leer();
		///Hacemos las diferencias entre los elementos consecutivos con nuestra función dife()
		dife();
		///Hacemos una función para comprobar 
	}
	return 0;
}
```








