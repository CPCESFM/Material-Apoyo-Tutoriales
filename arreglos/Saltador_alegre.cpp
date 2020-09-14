#include <bits/stdc++.h>
using namespace std;
int t,n;
int arre[3002];
bool aux[3002];

void leer() {
	///Leemos n de esta secuencia
	cin >> n;
	///Leemos los n numeros y los vamos guardando en el arreglo arre[]
	for(int i=1; i<=n; i++) {
		cin >> arre[i];
	}
}

void dife() {
	///Vamos recorriendo el arreglo elemento por elemento hasta uno antes del final
	for(int i=1; i<n; i++) {
		///Obtenemos el numero que queremos
		int diferencia=abs(arre[i]-arre[i+1]);
		///Checamos que no se salga del rango que nos interesa
		if(diferencia<n) {
			///No se sale del rango, lo marcamos como obtenido en nuestro arreglo aux[] que es bool, apto para esto =)
			aux[diferencia]=1;
		}
	}
}

bool comprueba() {
	/***Recorremos el arreglo uno por uno, si nos falta algun
	numero entre 1 y n-1 retornamos FALSE pues no es saltador alegre,
	si hemos obtenido todos los numeros del 1 al n-1 (es decir,
	terminamos el ciclo) entonces retornamos TRUE***/
	for(int i=1; i<n; i++) {
		///Que una casilla sea cero implica que no obtuvimos este numero
		if(aux[i]==0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	///Primero leemos la cantidad de casos que resolveremos
	cin >> t;
	///Ahora leemos esta cantidad de casos, uno a la vez
	for(int z=1; z<=t; z++) {
		///Leemos toda la secuencia con la función leer()
		leer();
		///Hacemos las diferencias entre los elementos consecutivos con nuestra función dife()
		dife();
		///Hacemos una función bool para comprobar, si regresa TRUE es saltador alegre, sino lo contrario
		if(comprueba()) {
			cout << "Alegre\n";
		} else {
			cout << "No alegre\n";
		}
		///Por ultimo limpiamos, basta con llenar de 0's ambos arreglos
		for(int i=1; i<=n; i++) {
			arre[i]=0;
			aux[i]=0;
		}
	}
	return 0;
}
