#include<bits/stdc++.h>

using namespace std;
/*Quitando la parte de la historia el problema basicamente nos dice que nos van a dar n lineas de 5 elementos y debemos ver cuantas lineas son de las mas populares,
 * podemos tener el caso cuando sean 3 lineas repetidas 2 veces cada uno en distinto orden la cantidad de lineas que son mas populares son 6, debido a que todas tienen
 * popularidad 3 tienen popularidad 2 por lo que es 6.
 */


int n, aux,respuesta,maximo; //variables auxiliares 
typedef map<set<int>,int>::iterator map_it;//definiciones de escritura para no escribir tanto a la hora de declarar un iterador del tipo
map_it iterador;//un iterador


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	while(cin >> n  && n){//mientras la entrada no sea 0
		respuesta = 0;//limpiamos las variables
		maximo = 0;
		map<set<int>,int> horario;//map conjuntos -> int conjunto es la linea
		set<int> personal;//aqui guardaremos la linea
		for(int k = 0 ; k<n ; k++){
			for(int i=0 ; i<5 ; i++){
				cin >> aux;
				personal.insert(aux);		
			}
			horario[personal] += 1;//si ya existe solo se aumentara en uno si no, se creara
			personal.clear();//limpiamos
		}
		for(map_it it = horario.begin(); it != horario.end(); it++){
			maximo = max(maximo,it->second);//buscamos cual es en numero el mas popular
		}
		int iguales=0;
		for(map_it it = horario.begin(); it!=horario.end(); it++){
			if(it -> second == maximo){//cuantasl lineas tienen la misma popularidad
			       	iguales++;
			}
		}
		cout << iguales * maximo <<"\n";//fin
	}
	return 0;
}
