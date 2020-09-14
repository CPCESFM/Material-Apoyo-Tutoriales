#include <bits/stdc++.h>
using namespace std;
///Una cadena de caracteres no es mas que un arreglo de char
///Ponemos el tamaño mas grande que nos pueden dar, para estar seguros
char cadena[52];

///En la explicación mas detalles de las funciones para cadenas de caracteres

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	///En este problema nos dan cadenas y cadenas hasta que recibimos simplemente "#"
	///Leemos la primer cadena (siempre hay al menos una)
	cin >> cadena;
	///Mientras no hayamos recibido la cadena "#" que marca el final ...
	//strcmp(,) compara dos cadenas de caracteres, devuelve 0 si son iguales
	while(strcmp(cadena,"#")!=0) {
    	///Intentamos calcular la siguiente permutación lexicográfica
    	///Guardamos en la variable se_puede lo que devuelva next_permutation(,) ya que será de utilidad
		//strlen() devuelve la longitud de una cadena de caracteres
		bool se_puede=next_permutation(cadena,cadena+strlen(cadena));
		///Si next_permutation(,) devuelve true entonces si se pudo hacer la proxima permutación 
		if(se_puede) {
			///Lo imprimimos y listísimo
			cout << cadena << "\n";
			} else {
		///En cambio si next_permutation(,) devuelve false entonces no se pudo hacer, ya estabamos en la última
			///En este momento en cadena está la primera permutación, recuerdalo
			///En fin, imprimimos el "No Successor" y terminamos
			cout << "No Successor\n";
		}
		///Leemos la proxima cadena, el While se encarga del resto
		cin >> cadena;
	}
	return 0;
}
