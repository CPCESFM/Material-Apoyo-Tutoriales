# Solución al problema de Permutation Arrays

Este problema exige mucho en tanto análisis como en implementación, así que vayamos por partes. Se nos da una lista de valores con su respectivo índice, luego 
se nos pide que ordenemos los índices en forma hacendente y que de acuerdo a este nuevo órden imprimamos los reales.

Si analisamos a profundidad el problema, requerimos de una estructura tal que podamos conocer el índice y valor en todo momento, por eso es que la propuesta que
haremos es la de 

```C++
vector<pair<int,string>> lista;
```

Parece muy extraña la elección del segundo parámetro de nuestro `pair<>`, pero aquí es donde está uno de los principales errores que podemos tener, esto porque 
se nos pide que **imprimamos tal como leímos** nuestros valores, pero esto mismo nos conlleva a leer tanto nuestros índices como nuestros valores en un `string`.
Antes de empezar a leer aquí ocurre otro pequeño detalle, este se debe al **enter en la primera entrada**, ahora sí con esto en mente comensamos la lectura como 
se nos pide 

```C++
  cin >> casos;
	getline(cin, enter1);
	for(int s=0; s<casos; s++) {	    
		getline(cin, enter2);
    		getline(cin, s_i);
```

**Notemos** que ya entramos a un ciclo `for()` y esto porque vamos a iterar tantas veces como `casos`. 

El siguiente, problema en el que nautralmente puedes pensar es sobre la separación de los valores en el `string`, ya que necesitamos hacer operaciones en ellos 
bueno, aquí es donde entra el proceso `tokenizing`, para esto haremos uso de un `string` de paso, un `vector` y un ciclo `while()` tal como se muestra a continuación

```C++
      	    stringstream check_i(s_i);
	    while(getline(check_i, intermedia, ' ')) {
	       	indices.push_back(intermedia);
	   	}
	   	intermedia.clear();
	   	getline(cin, s_v);
	   	stringstream check_v(s_v);
    		while(getline(check_v, intermedia, ' ')) {
	       		valores.push_back(intermedia);
	    	}
```

Lo que puede saltarte a la vista en este proceso es `tringstream check_i(s_i)` y `getline(check_i, intermedia, ' ')` y sus correspondientes equivalentes
al leer los valores, bueno pues lo primero nos permite leer un `string` como si fuera un `stream` y lo segundo parte nuestro `string` principal en 
`substrings` de acuerdo al parametro que le demos en este caso `' '` i.e. vamos a cortar donde encuentre el caracter `' '`, luego estos `substrings` los vamos
a almacenar en nuestro `vector`. 

Una vez que tenemos nuestros `substrings` el siguiente paso es meterlos en nuestra estructura extraña, para esto usaremos la función `stoi()` y un ciclo.

```C++
        for(int i=0; i<indices.size(); i++) {
           	lista.push_back(make_pair(stoi(indices[i]), valores[i]));
        }
```

**Notemos** que la función `stoi()` nos permite convertir el primer los `substrings` en valores enteros.

Ahora, sólo falta ordenar los índices, correspondientes al `first` de nuestro pair en el `vector`, para ello usamos la función `sort()` que en estructuras como
la nuestra hace el ordenamiento priorizando la primer entrada. 

```C++
        sort(lista.begin(), lista.end());
```
Así, con el odenamiento tenemos lo que se nos solicita, pero no tanto, ya que la impresión también tiene su truco.

```C++
        if(s>0) {
        	cout << "\n";
        }
        for(int j=0; j<lista.size(); j++) {
           	cout << lista[j].second << "\n";
       	}
```

Luego, sólo restará limpiar la memoria y habremos finalizado. 

```C++
        intermedia.clear();
        enter2.clear();
        s_i.clear();
        s_v.clear();
        indices.clear();
        valores.clear();
        lista.clear();  
	} 
	enter1.clear();
```


