# Solución al problema de [Querys And More Querys](https://omegaup.com/arena/problem/Querys-and-more-Querys/#problems) 

Se seleccionó este problema ya que permite ver que en gran parte el uso de vector y arreglos es un poco más de preferencia que de obligación, pero mucho 
**cuidado**, siempre ten en cuenta el costo en tiempo que representa usar vectores. Con esto en mente, se nos pide que determinemos cuantas veces aparece un 
valor dentro de un rango **relativamente comedido**, a priori podría venir a tu mente usar una búsqueda binaria para encontrar estos valores, pero existe 
una solción mucho más óptima. 

Primero haremos uso de una `cubeta`, que puede venir en dos presentación, una `estática` y otra `dinámica`. Usemos ambas. 

+ Vector

```C++
  vector<int> vcubeta;
```

+ Arreglo

```C++
  int acubeta[1000000];
```

Tal vez en este punto te estás preguntando sobre el uso de la cubeta, bueno esta nos va a permitir contabilizar la cantidad de veces que aparece un elemento, esto
al conciderar los índices de nuestras estructuras como los números en la entrada. Es decir, cada que nos den un valor `x` entonces nos dirijiremos al miembro
`vcubeta[x]` ó `acubeta[x]` y a estos les sumaremos uno, ya que encontramos el elemento i.e. ya existía. 

+ Vector

```C++
  cin >> n;
  vcubeta.reserve(1000000);
  for(int i=0; i<n; i++) {
		cin >> n_i;
		vcubeta[n_i]++;
	}
```

+ Arreglo 

```C++ 
  cin >> n;
  for(int i=0; i<n; i++) {
		cin >> n_i;
		acubeta[n_i]++;
	}
```

**Notemos** que aparece la función `.reserve()` y esto porque los vectores almacenan información hasta el tiempo de ejecución, por tanto no podríamos utilizar 
la técnica que deseamos. 

Una vez que tenemos nuestra contabilidad de veces que aparece un valor, entonce sólo falta imprimir los resultados respecto a las **querys**, por tanto
leemos el valor de estas en una variable `q` y a la vez que las leemos hacemos un proceso muy parecido al que usamos durante la lectura
aunque esta vez imprimimos en vez de sumar un elemento, por medio de un ciclo `for()`.

+ Vector 

```C++
  	cin >> q;
	for(int j=0; j<q; j++) {
		cin >> q_i;
		cout << vcubeta[q_i] << "\n";
	}
```
+ Arreglo

```C++
  	cin >> q;
	for(int j=0; j<q; j++) {
		cin >> q_i;
		cout << acubeta[q_i] << "\n";
	}
```


