# Comenzando con C++

En este video hemos visto cual es la **estructura básica de un programa en C++**, el esqueleto sobre el cual programaremos y que esta compuesto de

+ Librería
Las librerías proveen conjuntos de funciones muy útiles que ocuparemos para resolver problemas (por ejemplo `algorithm`, `vector`, `iostream`, etc.); para incluir una libreria en nuestro programa basta poner `#include <libreria>` en el inicio del código.
Como puedes imaginar **hay muchísimas librerías que podemos usar**, utilizando el encabezado `#include <bits/stdc++.h>` podemos **incluir todas las librerías estándar** y solo preocuparnos por utilizarlas, grandioso para ahorrar tiempo y ser mas prácticos.

+ Espacio de nombres estándar
Utilizando la línea `using namespace std;` podremos ahorrar mucho tiempo a la hora de escribir código, eso se debe a que muchas cosas en C++ requieren un prefijo cada vez que las escribes, con esta línea esto ya no es necesario

+ Función `main`
Como su nombre lo indica esta es la **función principal de nuestro código**, la que dirige toda la ejecución del programa y donde escribiremos las instrucciones a realizar, recuerda que por el momento __siempre debe terminar con un__ `return 0;` (que simboliza la finalización del programa)

+ Líneas optimizadoras
Las poderosas `ios_base::sync_with_stdio(0);` y `cin.tie(0);`, deben ser las primeras instrucciones dentro del `main` ya que **optimizan la lectura e impresión** de C++, lo cual se ve reflejado en ahorro de tiempo de ejecución =)

Finalmente (y en resumen) el esqueleto de un programa queda así
```C++
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Aqui va el código
	return 0;
}
```
