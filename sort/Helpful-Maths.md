# Solución al problema de [Helpful Maths](https://codeforces.com/problemset/problem/339/A)

Nuestra misión es ayudar a Xenia a realizar la suma de los elementos en la forma que es mejor para ella. Para esta tarea es importante visualizar que por la forma de
la entrada necesitamos usar `strings`.

Primero declararemos nuestro `string` que nos permitirá guardar la representación de la suma

```C++
string s;
```

Después un `string` auxiliar que nos permitirá hacer un proceso de `tokenizing`, al igual que un vector.

```C++
string inter;
vector<string> snumeros;
```

Así, leemos el `string` con nuestro ya conocido `cin` ya que no hay espacios en él

```C++
cin >> s;
```

Una vez que lo leemos, entonces lo partimos por un `tokenizing` 

```C++
  stringstream check(s);
	while(getline(check, inter, '+')) {
		snumeros.push_back(inter);
	}
	inter.clear();
```

Esto consiste en convertir nuestro `string` a un `stream` con `stringstream` luego lo leemos con `getline()` y lo guardamos en un `substring` hasta que encuentre
el caracter `'+'`, luego introducimos estos `substrings` en el `vector` que declaramos y por último limpiamos el auxiliar que nos permitó llevar a cabo esto. Una
vez que tenemos todos nuestros `substrings` guardados en el `vector` procedemos a guardarlos en un arreglo pero como números enteros por la función `stoi()`.

```C++
  for(int i=0; i<snumeros.size(); i++) {
		numeros[i]=stoi(snumeros[i]);
	}
```

Luego ordenamos estos elementos con la función `sort()`

```C++
sort(numeros, numeros+snumeros.size());
```

Y por último imprimimos en la forma que se nos solicita

```C++
  for(int j=0; j<(snumeros.size()-1); j++) {
		cout << numeros[j] << "+";
	}
	cout << numeros[snumeros.size()-1];
```


