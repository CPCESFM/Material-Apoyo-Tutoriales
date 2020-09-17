# EXPLICACION DE LOS PROBLEMAS

Ordenemoslos por dificultad, y expliquemos cada parte.

### [ Impares hasta N](https://omegaup.com/arena/problem/Impares-hasta-N/#problems)
  Pues este proceso lo podemos hacer de una forma sencilla, lo cual es iterando desde 1 hasta (n-1) y sumar los que sean impares.  
  **Preguntar si (x&1) o (x%2) es lo mismo si queremos saber si x es número impar.**

### [Triangulo de Pascal](https://omegaup.com/arena/problem/Triangulo-de-Pascal-Niveles/#problems)
  Ptimero recordemos que leeremos una cantidad t de casos. Luego en cada caso nos basaremos en el hecho de que (1+1)^n = 2^n es lo mismo que si sumaramos únicamente los coeficientes binomiales de cada nivel (lo pueden ver si buscan la formula para calcular (a+b)^n ), y a su vez primero calcularemos 2^m, y de ahí sumaremos 2^m + 2^(m+1) + ... + 2^(n-1) + 2^n, y luego lo imprimimos.
  
### [Suma de números redondos](https://codeforces.com/contest/1352/problem/A)
  Leeremos una cantidad t de casos, por lo que necesitaremos un loop, para leer estos t casos, donde por cada caso vamos a leer un número n, al cual descompondremos
  por unidades, decenas, centenas, millares y así en adelante, y hay que decir cuantos de estos digitos son distintos de 0. Por lo que por cada caso necesitamos:
  
  - **Checar cuantos digitos son distintos de 0**: lo que podremos obtener al usar aux%10, y si es distinto de cero incrementamos en nuestro contador de dígitos distintos de cero (k), y de ahí dividiremos aux, es decir, aux/=10, luego imprimiremos k.
  - **Si los digitos son distintos a 0 imprimirlos:** para esto utilizaremos una variable para indicar en que potencia de 10 nos encontramos, empezando por 10^0, 
  e imprimos el digito por la potencia de 10 en la que nos encontramos.
  
### [ Números no Fibonacci ](https://omegaup.com/arena/problem/nofib/#problems)
  Agarrense. porque ahora si se van a poner recios los problemas, porque vamos a necesitar saber lo que es Fibonacci, lo cual ya vimos, pero si se dan cuenta, al
  ir calculando el siguiente termino, nos van a quedar saltos o espacios, por lo que para calcular los **_NO_ números de Fibonacci**, por lo que empezaremos a imprimir los números
  desde (F_n)+1 hasta (F_(n+1) - 1) siempre y cuando sean **MENORES A n**.

### [ Paridad de sumandos ](https://codeforces.com/contest/1352/problem/B)
  Ahora si viene el más complicado, recordemos que cuando sumamos numeros obtenemos lo siguiente:
  - ***Par + Impar = Impar + Par = Impar***
  - ***Par + Par = Impar + Impar = Par***
  
  Ahora, pensemos en la paridad de n y k, en base a lo que previamente hablamos, porque si hay una cantidad impar de elementos, si cada uno es impar
  entonces obtendremos un numero impar lo que sería una respuesta invalida si n es par, y eso ser lo que analizaremos si cada a_i debe de ser par(P),
  impar (I), ambos(A) o ninguno (N). Todo esto en la siquiente tabla:
  
  -  |##########|  k impar  |  k par |
  -  |#n impar##| I (k<=n)  |  N     |
  -  |###n par##| P (2k<=n) |  B     |
  
  Dado este cuadro podemos descartar opciones para poder avanzar más rápido y que no haya errores (puede que me falle al acentuar).
  
  Por lo que de esta forma tomaremos la parte entera de la division de n/k y su residuo (n%k), y lo ajustaremos para que podamos obtener la paridad deseada en cada caso,
  y busquemos que el residuo siempre sea par, de esa forma no afectará ya sea que busquemos que a_i sea par o impar, pero aun podemos modificar el dividendo y el residuo
  para ver si así se podrían obtener una solución, en caso contrario imprimir un NO, en caso de encontrar la solución pues bastará con imprimir YES y el valor base de todos
  los (a_i+res) y de ahí imprimir k-1 veces a_i.
  
  Para más información pueden darle a la parte del tutorial del problema y ahí les podrá venir a lo mejor, una mejor explicación que esta.
