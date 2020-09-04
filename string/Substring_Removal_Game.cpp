#include <bits/stdc++.h>
using namespace std;
int t;
///Declaramos nuestro string binario
string arre;
///Declaramos nuestro vector de lontigudes
vector <int> vec;
 
int cadena() {
	///Leemos el string s original
    cin >> arre;
	///Recorremos el string caracter a caracter (recuerda que string guarda desde 0 hasta el tamaño menos 1)
    for(int x=0; x<arre.size(); x++) {
		///Si nos encontramos con un caracter 1 ...
        if(arre[x]=='1') {
            ///Comienzo de substring, calculemos su longitud, creamos variable auxiliar
            int longitud=0;
			///Con otro ciclo seguimos avanzando la variable x (ojo aquí) comprobando que estemos en el substring
			///Tambien debemos comprobar que no nos salgamos del string
            for(;x<arre.size() && arre[x]=='1'; x++) {
				///Mientras las condiciones del for sean ciertas seguimos en el substring, aumentamos en 1 la longitud
                longitud++;
            }
			///Siempre al terminar el for de arriba nos quedamos en un '0', retrocedemos 1 para que el for de más arriba anule el efecto y quedemos en el mismo '0'
			///Esto se podia evitar con un while LoL pero me gusta mas for ok?
            x--;
			///Metemos al vector de longitudes de substring la longitud del que acabamos de encontrar
            vec.push_back(longitud);
        }
    }
	///Ordenamos el vector de longitudes, en este caso de menor a mayor
    sort(vec.begin(),vec.end());
	///Declaramos nuestra variable local de respuesta
    int res=0;
	///Finalmente recorremos de mayor a menor (en este caso de fin a inicio) para ir asignando el puntaje
	///Observa que vamos restando de dos en dos, de esta forma
	///Alice se queda con el mas grande, el tercer mas grande, el quinto mas grande y asi sucesivamente
    for(int i=vec.size()-1; i>=0; i-=2) {
		///Sumamos la longitud a la variable respuesta
        res+=vec[i];
    }
	///Y listo, en res ya tenemos la respuesta pero antes de irnos limpiamos los containers para otra ejecución
    vec.clear();
    arre.clear();
	///Retornamos la respuesta
    return res;
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	///Leemos el número de casos
    cin >> t;
	///Vamos leyendo cada una de las cadenas ...
    while(t--) {
		///Imprimimos lo que devuelva nuestra función, ella hará todo el trabajo
        cout << cadena() << "\n";
    }
    return 0;
}
