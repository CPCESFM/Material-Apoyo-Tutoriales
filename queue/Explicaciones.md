# Esta es la explicación a los ejercicios propuestos para queue.

**IMPORTANTE**
Para llegar a este archivo debes haber leído previamente los ejercicios para entender a que se refiere.

[Este es link para el ejercicio Printerqueue.cpp](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=629&page=show_problem&problem=3252)


Si gustas hacer más ejercicios, más sencillos o más complejos puedes encontrarlos en este link

[Más ejercicios](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=629)

También puedes encontrar buenos ejercicios en distintas plataformas como codeforces etc...

## Printer queue

El problema es simple, necesitamos calcular el tiempo que nos tomará imprimir nuestro documento y necesitamos observar cuantos documentos tienen una prioridad más alta que la nuestra 
y resperataremos el orden que llevamos en la fila.

Veamos partes importantes del código.

```c++
queue < pair <int,int> > imprime;

        memset( prioridad , 0 , sizeof prioridad );

        cin >> m >> p ;
```
Lo anterior esta dentro de un ciclo while para realizar los n-casos que nos soliciten. Es necesario declarar la cola
cada vez que entremos al ciclo para que no arrastremos basura, guardaremos dentro de la cola un pair de enteros donde
el primer entero denotará la prioridad del documento y el segundo entero llevará que número de documento es el que ingresó a la cola (el primer documento lleva el número 1, el segundo 
el 2 y así consecutivamente). El memset lo utilizaremos para rellenar el arreglo llamado prioridad de puros 0, para inicializarlo.


```c++
for (int i=0 ;i < m ; i++){

            cin >> aux;

            prioridad[aux]++;

            imprime.push(make_pair(aux,i));

        }
}
 ```
 Aquí podemos observar lo descrito anteriormente de una manera más detallada, guardamos en la cola el pair con la prioridad y
 el número de documento y en el arreglo con la posición de la prioridad del documento introducido (aux es la prioridad del documento)
 daremos un incremento para indicar cuantos documentos tienen esa prioridad.
 ```c++
 int minutos=0;

        bool seimp = false ;

        while (seimp!=true){

            bool masimport = true ;

            pair <int , int > act = imprime.front();

            for (int i = act.first + 1 ; i < 10 ; i++){
                if (prioridad[i] > 0){

                    masimport = false ;

                    break;

                }
            }

            if (masimport!=false){

                minutos++;

                if (act.second == p){
                    seimp = true ;
                    cout << minutos << "\n";
                    break;
                }
                prioridad[act.first]--;
            }

            else imprime.push(act);

            imprime.pop();

        }
 ```
 Ahora, notemos que debemos inicializar la variable minutos en cero cada vez que hacemos un caso nuevo para no arrastrar basura, 
 de igual manera inicializamos la variable seimp en false para que entre al ciclo.
 
  ```c++
  
        while (seimp!=true){

            bool masimport = true ;

            pair <int , int > act = imprime.front();

            for (int i = act.first + 1 ; i < 10 ; i++){
                if (prioridad[i] > 0){

                    masimport = false ;

                    break;

                }
            }
        }
 ```
 Aquí veremos si el documento que sacamos de la cola es nuestro documento y si es el que tiene la prioridad más alta, procederemos a imprimirlo.
 Declaramos un pair con nombre act (actual) para poder comparar el documento que esta al frente de la cola. Luego entramos a un ciclo inicializando
 el contador del ciclo en la prioridad del documento que esta al frente de la cola más una unidad ya que así nos lo indica el problema, luego 
 comprobamos si existe algún documento más importante que el que tenemos, si es así no lo imprimimos, en caso contrario lo sacamos de la cola.
 
 
  ```c++
 if (masimport!=false){

                minutos++;

                if (act.second == p){
                    seimp = true ;
                    cout << minutos << "\n";
                    break;
                }
                prioridad[act.first]--;
            }

            else imprime.push(act);

            imprime.pop();
 ```
 Observamos que si nuestra variable masimport es verdadera, significa que procedemos a imprimirla por lo que debemos agregar uno al contador de minutos y debemos comprobar otra condición
 si el documento que imprimos es el nuestro, la forma de saber si es nuestro documento la marcamos desde el inicio ya que el pair llevaba la prioridad y el número de documento en la cola
 así solamente nos es necesario verificar si el segundo entero del pair coincide con nuestro número del documento, si es así, terminamos y mostramos cuantos minutos nos tomó imprimirlo
 en caso contrario, solo lo "imprimimos" y agregamos uno al contador. Si nuestra variable masimport es falsa entonces quiere decir que el documento no se puede imprimir todavía
 por lo que deberemos ingresarlo a la cola y debemos "sacarlo" del inicio de la cola, por lo que ocupamos el pop.
 
