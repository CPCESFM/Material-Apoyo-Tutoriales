# [ALGORITMOS TEMPRANOS SOLUCIONES A LA TAREA]()

## PROBLEMAS POR DIFIULTAD

### [MCD Euclides](https://omegaup.com/arena/problem/MCD-Euclides/#problems)
  Simplemente hay que usar el algoritmo de Euclides, leer a y b, luego imprimir el gcd(a,b).

### [ Mayor gcd ](https://codeforces.com/problemset/problem/1370/A)
  Suponga que k es un entero entre 1 y n, ¿cuál es mayor gcd(k,k^2) o gcd(k,2k)?, ¿por qué?,
  ¿de que nos sirve saber esto?, pues esa es la idea de como encontramos la respuesta. Esta 
  sencillo el problema, por lo que deberías de intentarlo de nuevo.
  
  Por lo que note que si tomamos la parte entera por abajo de sqrt(n) es menor o igual que la
  parte entera de (n/2), la segunda en este caso es mayor, ¿cierto?, por lo que usaremos esto
  como la respuesta para cada caso, es decir, la parte entera por debajo de (n/2).

### [ Problema del LCM ](https://codeforces.com/problemset/problem/1389/A)
  ¿Cómo obtenemos un lcm más pequeño?, primero que nada es mejor si uno es multiplo de otro,
  porque si suponemos que k es un numero cualquiera entonces lcm(k,2k) = 2k, por lo que ahí
  esta nuestra respuesta si lcm(l,2l) es menor o igual que r, encontraremos una respuesta. 

### [ Chicos Mosby ](https://omegaup.com/arena/problem/OMI-2016-Chicos-Mosby/#problems)
  ¿Cuál es su primer pensamiento sobre el problema?, ¿Ya pensaron en el mejor caso?, ¿en 
  el peor caso?, exploren diferentes valores e intenten de nuevo, pero note que incluso tiene
  la pelicualiaridad de que tenemos cuadrados dentro de rectangulos, ¿Cómo optimizamos el
  número de cajas?, ¿Que su área sea pequeña o grande?, Si vamos el cuadrado más grande al más
  pequeño, ¿qué implica esto?
  
  Pues la respuesta esta en la última parte, primero sea m el lado pequeño y M el lado grande.
  Luego de notemos que si tomamos cuadrados de lado m, podremos meter al menos 1 cuadrado, pero serán
  exactamente M/m, y te sobrará un rectangulo de tamaño (M%n) y M, y repetimos este proceso
  hasta donde no un lado sea 0, y vamos sumando la cantidad de cuadrados que podemos meter.
