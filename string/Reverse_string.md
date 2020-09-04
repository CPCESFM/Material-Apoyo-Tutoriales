##### Recorriendo la cadena en reversa
```C++
#include <bits/stdc++.h>
using namespace std;
///Declaramos el string
string cadena;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos la cadena
	cin >> cadena;
	///Imprimos la cadena al revés con un ciclo desde la ultima letra a la primera
	///Recordar que en string se almacena desde el indice 0 al n-1 con n el tamaño de la cadena
	for(int i=cadena.size()-1; i>=0; i--) {
		cout << cadena[i];
	}
	return 0;
}
```
##### Utilizando la función `std::reverse(,)`
```C++
#include <bits/stdc++.h>
using namespace std;
///Declaramos el string
string cadena;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos la cadena
	cin >> cadena;
	/**La función reverse(,) recibe dos parametros, apuntadores al inicio y fin del rango que deseamos invertir
		estos apuntadores los obtenemos con .begin() y .end() precisamente, tras su ejecución se habrá invertido el contenido
		Como nota, reverse(,) funciona para varios containers y tiene complejidad O(n/2) con n la longitud del container
	**/
	///Invocamos a la poderosa
	reverse(cadena.begin(), cadena.end());
	///Y listo, el contenido se invirtió, imprimimos
	cout << cadena;
	return 0;
}
```
