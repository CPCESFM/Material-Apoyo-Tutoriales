# Análisis al problema de [Vector Dominante](https://omegaup.com/arena/problem/Vector-dominante/#problems/Vector-dominante) 

En este problema se nos pide que determinemos si los elementos de un primer conjunto siempre son mayores que los de un segundo, para ello tenemos que crear
nuestros conjuntos y por ello haremos uso de dos [vectores](http://www.cplusplus.com/reference/vector/vector/).

```c++
vector<int> v1, v2; 
```

Una vez que tenemos nuestros vectores, se nos especifíca la cantidad de elementos que habrá dentro de ellos, por tanto leemos `n`. 
 
```C++
  cin >> n;
```
Luego hacuendo uso de nuesto `n-tope` introducimos los elementos de nuestros conjuntos haciendo uso de dos ciclos `for`. 

```C++
  for(int i=0; i<n; i++) {
		cin >> val;
		v1.push_back(val);
	}
	for(int j=0; j<n; j++) {
		cin >> val;
		v2.push_back(val);
	}
```
De esta forma **estamos listos** para verificar la condición que se nos pide. La tarea la llevaremos acabo utilizando una vrariable del tipo [boleana](https://www.geeksforgeeks.org/bool-data-type-in-c/),con la cual al ir iterando de uno en uno los elementos de nuestrso conjuntos verifica la condición 
de que siempre `v1[i] > v2[i], para i en [0,n)`.

```C++
  cond=true;
	for(int k=0; k<n; k++) {
		if(v1[k]<=v2[k]) {
			cond=false;
			break;
		}
	}
	if(cond){
		cout << 1;
	}else {
		cout << 0;
	}
```
