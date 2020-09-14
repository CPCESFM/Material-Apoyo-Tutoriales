#include <bits/stdc++.h>
using namespace std;
///Declaramos una variable, n que nos dan de entrada para el numero de elementos
int n;
///Creamos el arreglo de acuerdo al maximo numero de elementos que nos dan en el problema
int arre[1002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos cuantos numeros
    cin >> n;
	///Leemos cada numero y lo guardamos en el arreglo iniciando en 1 y terminando en n
    for(int i=1; i<=n; i++) {
        cin >> arre[i];
    }
	///Recorremos el arreglo pero ahora de n a 1 y vamos imprimiendo cada uno separado por un espacio
    for(int i=n; i>=1; i--) {
        cout << arre[i] << " ";
    }
    return 0;
}
