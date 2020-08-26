# Esta es la explicación a los ejercicios propuestos para map.

**IMPORTANTE**
Para llegar a este archivo debes haber leído previamente los ejercicios para entender a que se refiere.

[Este es link para el ejercicio SloganLearningOfPrincess.cpp](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4270)

[Este es el link para el ejercicio conformity.cpp](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2261)

[Este es el link para el ejercicio wordindex.cpp](https://github.com/meysamaghighi/UVa/blob/master/417%20-%20Word%20Index.cpp)

Si gustas hacer más ejercicios, más sencillos o más complejos puedes encontrarlos en este link

[Más ejercicios](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=631)

También puedes encontrar buenos ejercicios en distintas plataformas como codeforces etc...

## Slogan Learning Of Princess

El problema es muy sencillo solo se trata de emparejar <string,string> la cual es <first_line,second_line> dada la first_line queremos obtener second_line
la cual lo podemos hacer con un map<string,int>.

Veamos partes importantes del código.

```c++
cin >> N;
getline(cin,basura);// alternativo cin.ignore()

```
¿Por qué tenemos que leer una linea basura? pues esto es simplemente para ignorar la línea en donde estabamos y leer de la que sigue. 


```c++
for(int i=0 ; i<N ; i++){
		getline(cin,first_line);
		getline(cin,second_line);
		
		slogans[first_line] = second_line;
}
 ```
 usamos getline simplemente para leer linea completa de la entrada estándar y guardarla en first_line, en la parte
 ```c++
 slogans[first_line] = second_line;
 ```
 creamos la parejas de string que comentamos al principio, lo demás es simplemente responder a las peticiones.
 
 ## Conformity
 
 Parte del código incluye parte de la idea de solución.
 
 Había que leer cierta cantidad de líneas con alguna combinación de 5 números, y hay que contar cuantos de ellos tienen la misma combinación más popular,
 pero puede que haya más de una popular como por ejemplo que todos tengan popularidad 2 en ese caso todos tienen la más popular.
 
 ```c++
 map<set<int>,int> horario;
 ```
 ¿Por qué elegir el map así? pues, pudo haber alguna solución diferente pero lo que nos proporciona esta es que nos enfocamos simplemente en el conjunto du
 números y no en el orden, y así asociamos pares de <combinacion de materias,enteros>.
 La ídea de solución es sencilla ahora veamos otro detalle de implementación.
 
 ```c++
 for(map_it it = horario.begin(); it != horario.end(); it++){
			maximo = max(maximo,it->second);//buscamos cual es en numero el mas popular
	}
 ```
 A primer ojo esto prodría ser un poquito complicado para entender pero vayamos paso a paso.
 recordemos que es map_it, simplemente una definición que hice en el código en:
 
 ```c++
 typedef map<set<int>,int>::iterator map_it;
 ```
 recordemos que con los iteradores podemos movernos sobre el map desde inicio hasta el final, y este iterador lo podemos ver con dos componentes
 it->first y it->second que en el primer caso it->first es un set<int> por la definición del map y it->second es un entero el entero que nos dice cuantos
 escogieron la combinación del it->first, es decir buscamos el más popular.
 
 ## Word Index
 
 El problema se resume en asignando cada letra de la forma a -> 1, b->2 , ... z->26 y de ahi nos movemos con dos letras ab->27, ..., az->51... de tal forma
 que siempre las letras a la izquierda aparecen primero en el alfabeto que las más a la derecha, si no cumplen esta regla no son válidas.
 EL problema es dada la cadena de caracteres de 5 letras debemos devolver el número asociado si es válido y 0 si no lo es.
 
 Lo más complicado del problema es generar los valores de a->1, ...., esto se hace en la función generar y se guarda en el map como parejas <string,int> string->int
 ```c++
 void generar(){
	queue<string> cola;
	for(char i = 'a'; i <= 'z'; i++) cola.push(string(1,i));
	int contador = 1;
	while(!cola.empty()){
		string actual = cola.front();
		cola.pop();
		diccionario[actual] = contador++;
		if(actual.size() == 5) continue;
		for(char k = actual[actual.size() - 1] + 1; k <= 'z'; k++){
			cola.push(actual + string(1,k));
		}
	}
}
 ```
 La función void solo es para orgnizanizar el código.
 ¿Por qué usar una cola? La función de la cola aqui es para tener en el orden adecuado.
... |tercero | segundo | primero(front)
---|--- | --- | ---
..|"c" | "b" | "a"

como los codigo ASCII de los carácteres 'a','b',... son consecutivos para pasar del código ASCII de 'b' basta sumar el código ASCII 'a' más 1 y eso es lo que
el ciclo for,
```c++
for(char i = 'a'; i <= 'z'; i++) cola.push(string(1,i));
```
Mete a la cola todos las letras minúsculas en ese orden.

```c++
while(!cola.empty()){
		string actual = cola.front();
		cola.pop();
		diccionario[actual] = contador++;
		if(actual.size() == 5) continue;//no tomamos en cuenta las que tengas mas de 5 carácteres
		for(char k = actual[actual.size() - 1] + 1; k <= 'z'; k++){
			cola.push(actual + string(1,k));
    }
}
```

Mientras la cola no este vacía haremos eso, pero porque llegará a estar vacía? pues porque no meteremos strings de más de 5 carácteres y con las codiciones del
problema.

conforme las vayamos sacando de la cola les vamos ir asignando su numero en el map diccionario e incrementando ese numero cada que una pasa,
ahora es momento de crear los strigs a partir de las letras, en esta parte

```c++
for(char k = actual[actual.size() - 1] + 1; k <= 'z'; k++){
			cola.push(actual + string(1,k));
}      
```
Lo que hacemos es tomar la última letra del string, y empezamos desde la siguiente (siguiente código ASCII sumando 1) y hasta la z, y metemos a la cola
la concatenación de la string actual y el nuevo char, esto funciona por la propiedad de first in first out de la cola.
Para completar el ejercicio basta responder a las peticiones imprimiendo diccionario[petición] por cada petición.





