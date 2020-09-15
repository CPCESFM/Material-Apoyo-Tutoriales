#include <bits/stdc++.h>

using namespace std;

long long int m;

long long int divide(long long int val) {
	long long int acumulado=0;
	while(val>0) {
		val/=5;
		acumulado+=val;
	}
	return acumulado;
}

long long int BusquedaBinaria() {
	long long int izq=0;
	long long int der=2000000000000;
	long long int mitad;
	long long int aux;
	while(izq+1<der) { 
		mitad=(izq+der)/2;
		aux=divide(mitad);
        if(aux<m) {
        	izq=mitad;
        }else if(aux>=m) {
        	der=mitad;
        }
    } 
    return izq+1; 
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m; 
	cout << BusquedaBinaria();
	return 0; 
}