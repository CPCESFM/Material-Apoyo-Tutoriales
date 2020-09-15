# Solución al problema de [Polycarp Training](https://codeforces.com/problemset/problem/1165/B)

En este problema Polycarp necesita entrenar lo suficiente para dar lo mejor de él en las competencias, tal como nosotros, pero el problema es que, a diferencia de 
nosotros, él sólo puede resolver un problema de práctica el primer día, dos el segundo y así consecutivamente. Claramente, va a necesitar de una estrategia de estudio ya que en cada **contest** que hace necesita resolver la mayor cantidad de problemas.

 Es importante almacenar los problemas que habrá en este **contest** por tanto vamos a utilizar un arreglo. 
 
 ```C++
 int contests[200000];
 ```
 
 Luego leemos cuantos de estos habrá con un `n-tope`.
 
 ```C++
 cin >> n;
 ```
 
 Entonces estamos listos para comenzar a leer con un ciclo `for()` estos.
 
 ```C++
 for(int i=0; i<n; i++) {
		cin >> contests[i];
	}
 ```
 
 Luego, por el método de aprendizaje de Polycarp tenemos que ordenar los **contest** de menor a mayor, para así poder asegurar que podrá responder la mayor cantidad
 de problemas en él, esto lo hacemos con la función `sort()`
 
 ```C++
 sort(contests, contests+n);
 ```
 Después de eso nos ponemos a contabilizar los días de estudio con una varibale del tipo entero `D`, que después actualizaremos conforme si hay más o al menos la misma cantidad de problemas en el **contest**, esto lo hacemos al recorrer todos nuestros **contest** ya ordenados.
 
 ```C++
 for(int j=0; j<n; j++) {
		if(contests[j]>=D) {
			D++;
		}
	}
 ```
 
 Por último, ya sólo resta imprimir la variable `D`
 
 ```C+
 cout << D-1 << "\n";
 ```
 
