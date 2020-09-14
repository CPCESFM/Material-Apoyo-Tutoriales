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
	///Utilizamos do while para checar antes de cambiar a la siguiente permutación
	do{
        ///Vemos si con la permutación actual obtenemos el numero k
        if(calculo()==k) {
            ///Ya encontramos la buena, imprimimos la permutacion y utilizamos break para salirnos y fin, se acabó, bai
            imprime_permutacion();
            break;
        }
        ///Si no entra al if anterior pues ni modo, a seguir buscando en las permutaciones
        ///Al volver a entrar al ciclo se calcula la siguiente permutación en arre
        ///Como nos aseguran que siempre es posible formar k, este ciclo no es infinito
	}while(next_permutation(arre+1,arre+n+1)==true);
	return 0;
}
