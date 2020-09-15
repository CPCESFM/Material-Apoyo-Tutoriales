# Solución al problema [Ordenando En Cubetas](https://omegaup.com/arena/problem/Ordenando-en-cubetas/#problems)

En este problema se nos pide ordenar las pelotas en la cubeta correspondiente a su color, para esto usaremos un arreglo para guardar nuestras pelotas.

```C++
  int colores[100];
```
Luego leemos nuestro `n-tope` y el mayor color que se tiene, tal como lo describe el problema y ya por último hacemos un cilco`for()` para leer nuestras pelotas.

```C++
    cin >> n;
    cin >> m;
    for(int i=0; i<n; i++) {
        cin >> colores[i];
    }
```

Después ordenamos de menor a mayor nuestras pelotas usando la función `sort()`

```C++
sort(colores, colores+n);
```

Esto lo hacemos con intención de reducir costos de la función `count`, que como se puede ver en la sección de vectores nos permite contabilizar cuantas veces aparece
un elemento en nuestro conjunto.

```C++
for(int j=0; j<m; j++) {
        cout << j+1 << ": " << count(colores, colores+n,j+1) << "\n";
    }
```
Como se puede notar, sólo resta imprimir en la forma que se nos pide y así habremos concluido. 
