# Solución al problema de [Where Is The Marble?](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415)

Primero haremos un arreglo para guaradar nuestras **marbles**.

```C++
int marbles[10000];
```

Dada la forma en la que se nos pide leer utilizaremos un ciclo `while()` con la condición de que para caundo lea los dobles ceros.

```C++
while((cin >> n >> q) && n && q) {
```

Luego utilizamos una varibale de casos que aumente en cada iteración para la impresión. 

```C++
casos++;
```

Y así proseguimos a leer nuestro marbles

```C++
		for(int i=0; i<n; i++) {
			cin >> marbles[i];
		}
```

Luego ordenamos estos para entonces poder aplicar una  `binary search` en ellos

```C++
  sort(marbles, marbles+n);
```

Imprimimos el número de casos 

```C++
  cout << "CASE# " << casos << ":\n";
```

Luego para cada pregunta que se nos haga buscamos si es que el **marble** está en nuestro conjunto de **marbles**, para hacer esto utilizamos la función `binary_search()` que nos devuelve un verdadero ó falso en caso de que encuentre el valor o no, después por medio del `lower_bound()` podremos hubicar perfectamente el índice en el que se encuentra nuestro valor. 

```C++
      for(int j=0; j<q; j++) {
			  cin >> question;
			  bool encontrar=binary_search(marbles,marbles+n,question);
			  int indice=lower_bound(marbles,marbles+n,question)-marbles;
			  if(encontrar==true) {
				  cout << question << " found at " << indice+1 << "\n";
			  }else {
				  cout << question << " not found" << "\n";
			}
		}
	}
}
```
Ya con esto logramos resolver nuestro problema. 

