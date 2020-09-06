#include <bits/stdc++.h>
using namespace std;
int n,k;
///Declaramos un arreglo para guardar los numeros
int arre[12];
///Declaramos el arreglo auxiliar
int aux[12];

void leer() {
	///Leemos n y k (el numero que deseamos obtener)
	cin >> n >> k;
	///Leemos los n numeros y los guardamos desde la casilla 1 a la n
	for(int i=1; i<=n; i++) {
		cin >> arre[i];
	}
	///Ordenamos para obtener la primer permutación lexicográfica
	///Recuerda que sort(,) le mandas de parametro el rango a ordenar [first,last)
	sort(arre+1, arre+n+1);
}

int calculo() {
	///Copiamos en el arreglo auxiliar la actual permutación (osea, el arreglo arre)
	for(int i=1; i<=n; i++) {
		aux[i]=arre[i];
	}
	///Ahora sacamos la respuesta haciendo la simulación de las sumas
	///Al hacer n-1 veces este proceso tendremos en aux[1] el numero correspondiente (ver la explicación)
	///La variable de este ciclo "tope" es hasta donde tenemos que seguir sumando los numeros
	///va bajando como en los ejemplos, como en piramide
	for(int tope=n-1; tope>=1; tope--) {
		///Hacemos una tanda de sumas hasta el tope actual
		for(int i=1; i<=tope; i++) {
        	///El elemento es la suma de los dos elementos de arriba
			aux[i]=aux[i]+aux[i+1];
		}
	}
	///En este punto solo retornamos el numero final que se encuentra en aux[1]
	///Te recomiendo analizar bien los dos ciclos anteriores para entender bien la idea
	return aux[1];
}

void imprime_permutacion() {
	///Para imprimir la permutacion actual solo imprimimos el contenido de arre
	for(int i=1; i<=n; i++) {
		cout << arre[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos los datos
	leer();
	///En este punto tenemos la primera permutacion lexicográfica, intentamos ver si sale la respuesta
	///La funcion calculo() se encarga de obtener el numero final de la permutacion actual
	if(calculo()==k) {
		///Le dimos al numero a la primera permutacion, imprimimos
		imprime_permutacion();
	} else {
		///LoL, vamos a tener que buscar la permutacion con next_permutation(,)
		///recuerda que esta funcion devuelve true mientras se pueda seguir permutando, asi que ...
		while(next_permutation(arre+1,arre+n+1)==true) {
			///Con haber llamado aqui arriba a next_permutation ya modificamos, en este momento
			///hay una nueva permutacion en arre, entonces preguntamos si podemos obtener k
			if(calculo()==k) {
				///Si pudimos obtener, imprimimos y usamos un poderoso break para irnos
				imprime_permutacion();
				break;
			}
			///Si no pudimos pues vuelve a entrar al ciclo y se calcula la siguiente permutacion
			///Como nos aseguran que siempre es posible formar k, este ciclo no es infinito
			///Ademas, next_permutation devuelve cero cuando vuelve a la primera permutacion, que ya revisamos por cierto
		}
	}
	return 0;
}
