# Explicación para los ejercicios para set.

### Para Llegar a este punto debiste de haber intentado resolver los ejercicios propuestos.

[Link para SecondOrderStatistics.cpp](https://codeforces.com/problemset/problem/22/A)

[Link para HoaxOrWhat.cpp](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077)

[Link para hilbert.cpp](https://codeforces.com/problemset/problem/1344/A)

[Más Ejercicios](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=632)

##  Second Order Statistics Codeforces

Podemos resolver el ejercicio de forma sencilla aprovechando la propiedad de que set los ordena y no ingresa duplicados, así el segundo elemento siempre
es mayor estricto al primero, solo tenemos que revisar si exista.

## Hoax or What Uva Online Judge

Sólo debemos mantener ordenado el conjunto en cualquier momento para obtener el primero y el último y agregarlos al costo,
definiendo de la forma

```c++
typedef multiset<long long int>::iterator set_it;
```
y navegando obtienedo los iteradores de

```c++
set_it mayor = bills.begin();
set_it menor = bills.end();
menor--;
```
*Cuidado* iterador .end() no apunta al último elemento, uno antes si, por eso lo decrementamos en uno.
Añadimos el precio y eliminamos los tickets que usamos.

```c++

bills.erase(mayor);
bills.erase(menor);

```

Lo demás es simulación de problema.

## Hilber Hotel Codeforces

Usando la regla de como mover los clientes del hotel podemos usar un set para saber si alguna habitación se empalmó,
si dos clientes terminan en una misma habitación(número) solo se ingresará una única vez en el set, por lo que el número de 
elementos en el set sera menor a n, que es el número total de clientes. Solo basta implementar adecuadamente lo anterior.

### Entendiendo Código
Definimos esto de esta forma para poder calcular el módulo correctamente para números negativos
```c++
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))// n%k
```
El paso de mover el cliente a la otra habitación según la regla se hace la forma siguiente para cada i,

```c++
ocupado.insert(MOD(i + a[i],n));
```

al final si el tamaño de nuestro set disminuyó significa hubo alguno que coincidió su habitación por lo que ya estamos listo para ejecutar la salida.

```c++
if( ocupado.size() == n){
         cout <<"YES\n";
 }else{
         cout << "NO\n";
 }
```
