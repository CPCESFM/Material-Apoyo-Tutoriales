# Explicacion para los ejercicios propuesta para priority_queue usando libreria STL.

##  IMPORTANTE 
Debiste de haber intentado resolver los problemas o haberlos leído al menos para ver esta parte.

**UVA Online Judge puede dejar de funcionar en ocasiones por la noche**

### LINKS

[Este es el link para el ejercicio addall.cpp](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895)

[Este es el link para el ejercicio icanguess.cpp](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3146)

[Este es el link para el ejercicio ConstructingArray.cpp](https://codeforces.com/contest/1353/problem/D)

## ADD ALL Uva Online Judge

Dada una lista de números debemos sumarlos de tal forma que teniendo el costo de sumar dos elementos es su propia suma cost(a + b) = a + b
debemos minimizar el costo y sumarlos todos.

Con el ejemplo nos enseñan en el problema nos podemos dar cuenta fácilmente que únicamente basta sumar los más pequeños entre si y el resultado
volverlo a tomar como un elemento de la lista y volver a tomar el más pequeño y así continuar.
Lo cual basta colocarlos en una priority_queue de menores para a la hora de extraer alguno siempre sea el más pequeño.

### Entendiendo código

¿Por qué se declaró la priority_queue así?
```c++
priority_queue<int,vector<int>,greater<int>> pq;

```
Pues de esta forma la estamos declarando con el criterio de primero menores ya que por default esta por mayores.

después de leer las variables e insertarlas en la cola de prioridad falta procesar los datos y este fragmento de código lo hace.

```c++
while(!pq.empty()){
	if(pq.size() > 1){
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		cost += a + b;
		pq.push(a + b);
	}else{
		pq.pop();
	}
}
```    
Lo que hacemos aqui es simplemente que mientras la cola de prioridad tenga elementos, si tiene más de un elemento extraeremos los dos más pequeños
y volveremos a meter su suma y añadiremos el costo, si la lista solo tiene un elemento significa que hemos terminado pues ya no podemos sumar, acabando este
ciclo estamos listos para imprimir el resultado.
    
## I Can guess the data structure Uva online Judge    

En este problema jugaremos a un juego de adivinar que estructura de datos se esta usando, una pila, cola o una cola de prioridad.

Dadas dos operaciones enumeradas.

* 1 x, lo cual significa ingresar x en la estrucutura de datos

* 2 x, lo cual significa se tomo el elemento de esas estructuras de datos y el resultado fue x.

Hay que tener en claro que cada una de estas estructuras de datos solo puede tomar un único elemento, en el caso de la cola es el front o frente, en el caso
de la pila es el top, y en el caso de la cola de prioridad es el top que es el elemento maximo.

Dadas estas reglas debemos adivinar que estrcutura de datos es.

lo cual es simple cuando venga la instrucción 1 únicamente lo ingresamos y cuando sea la dos corroboramos que se obtiene el que se debe obtener.
```c++
if( choice == 1){
		cola.push(aux);
		pila.push(aux);
		pq.push(aux);
	}else{
		if(cola.size()>= 1 && cola.front() == aux && es_cola){
			es_cola = true;
			cola.pop();
		}else{
			es_cola = false;
		}
		if(pila.size() >= 1 && pila.top() == aux && es_pila){
			es_pila = true;
			pila.pop();
		}else{
			es_pila = false;
		}
		if(pq.size() >= 1 && pq.top() == aux && es_pq){
			es_pq = true;
			pq.pop();
		}else{
			es_pq = false;
		}	
	}
 }
```    
Notemos que una vez que encontremos un elemento que no concuerde ya no puede ser esa estrcutura asi que solo debemos verificar siempre y cuando
nunca haya fallado y siempre y cuando tenga elementos.

Para saber cual es después de esto solo debemos que verificar solo cumpla una sola, y si cumple una sola imprimimos que tipo de estructura es.

Si hay más de una posibilidad imprimimos not sure, y si ninguna cumple impossible.

## Constructing the Array Codeforces

En este ejercicios debemos construir un arreglo de tamaño n (0,n-1) bajo ciertas reglas, las cuales son

* Escogemos el sub-arreglo de longitud máxima que solo tenga ceros consecutivos, si hay empate escogemos el que 
se encuentre más a la izquierda.

* tomamos el segmento [l,r] segun lo anterior.
  1. si r-l + 1 es impar colocamos arreglo[(l + r ) / 2 ] = i, aumentamos i
  2. si r - l + 1 es par colocamos arreglo[(l + r -1) / 2] = i; aumentamos i
  
  Imprimimos el arreglo.

Para poder resolver este problema basta únicamente saber como elegir los sub arreglos adecuadamente,
notemos que dado el sub arreglo[l,r] de puros ceros si colocamos un elemento en mid digamos se generaran dos 
sub arreglos de puros cero lo cuales son [l,mid -1 ] y [ mid + 1, r] cada uno lleno de cero y tendran longitud mid - l +1 
y r - mid + 1, pueden detenerse a comprobarlo.
y siempre queremos tomar el que tenga mayor longitud, y este más a la izquierda, perfecto entonces una cola de prioridad es
claramente una estrcutura de datos nos servirá.

si hacemos una pareja de la forma(longitud,(l,r)) de  y las ordenamos de tal forma que se saque primero por mayor longitud,
y por menor l lograremos siempre sacar de la cola de prioridad el que deseamos y eso se hace en esta parte.

```c++

struct comparador{
  bool operator ()(const pair<int, ii>& a, const pair<int, ii>& b) const{
		if(a.first == b.first){
			return b.second < a.second;
		}else{
			return a.first < b.first;
		}
	}
};

priority_queue<iii,vector<iii>, comparador> pq;
```    
Creamos nuestro propio orden tomando una pareja de la forma(int,(int,int)) que representa(longitud,(l,r)) y priorizamos
tenga mas distancia y despues por el que este más a la izquierda.

Y declaramos nuestra cola de prioridad que lo haga con ese orden y lo llamamos de ese orden.

Ahora basta colocar el número hasta que este lleno el arreglo y eso será cuando nuestro numero llegue a la longitud del 
arreglo i==n,

notemos que solo habrá arreglos válidos cuando (l<r) en otro caso no es uno válido y debemos ignorarlo.
```c++
pq.push(make_pair(n,make_pair(0,n-1)));
int i = 1;
while( i <= n){
	iii actual = pq.top();//sacamos el que cumpla la prioridad.
	pq.pop();
	int l= actual.second.first;
	int r= actual.second.second;
	if(l > r) continue; // no es válido
	int distancia = actual.first;
	int mid = ( r + l ) / 2;//equivalente a la regla
	arreglo[mid] = i++;//asignamos y aumentamos
	pq.push(make_pair(mid - l + 1, make_pair(l, mid - 1)));//los dos sub arreglos generados
	pq.push(make_pair(r - mid + 1, make_pair(mid + 1, r)));
}
```  
 El código anterios hace una simple simulación de lo que el problema nos dice que hagamos, después de generar el arreglo
 estamos listos para imprimir el arreglo y solcuionar el problema.
  
  
  
  
  
  
  
  
  
  
  
  



    
    
