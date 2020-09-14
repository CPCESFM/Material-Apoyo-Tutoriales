#include <bits/stdc++.h>

using namespace std;

#define ii vector<int>

ii miVector; /* Declaracion: 
				1. vector -> Estructura
				2. <***> -> Tipo de dato 
				3. miVector -> Nombre de la variable*/
int n; //n-tope
int primer_elemento, ultimo_elemento;

void lectura(int n) {
	int aux; //Variable auxiliar
	for(int i=0; i<n; i++) {
		cin >> aux;
		miVector.push_back(aux);/*.push_back() -> Introduce el valor que indiquemos 
								  por detras del vector*/	
	}
}

void it_impresion() {
	ii::iterator it; //Iterador
	for(it=miVector.begin(); it!=miVector.end(); it++) {
		cout << " " << *it; 
	}
	/*.begin() -> Apuntador al primer elemento del vector
	  .end() -> Apuntador al tope de nuestro vector
	*/
	cout << "\n";
}

void i_impresion() {
	//.size() -> Retorna el tamaño del vector
    for(int i=0; i<miVector.size(); i++) {
        cout << " " << miVector[i]; /*[] -> Nos permite
        							   consultar la información de 
        							   un elemento especifico*/
    }
    cout << "\n";
}

void limpiar() {
	while(!miVector.empty()) {
		/*.empty() -> Devuelve verdadero en caso
		de que el tamaño de nuestro vector sea 0*/
		miVector.pop_back();
		/*pop_back() -> Elimina el ultimo elemento
		de nuestro vector*/
	}
}

bool encuentrame(int a) {
	ii::iterator it; //Iterador
	it=find(miVector.begin(), miVector.end(), a);
	/*find() -> Devuelve un apuntadoral primer elemento encontrado en un rango.
	  Si no lo encuentra, apunta al final*/
	if(it!=miVector.end()) {
		return true;
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); 
	
	cout << "Digite el numero de elementos en el vector: ";

	cin >> n;
	
	lectura(n);
	
    cout << "Elementos del vector:";

	it_impresion();
	
	primer_elemento=miVector.front(); /*.front() -> Devuelve el primer 
										elemento de nuestro vector*/

	ultimo_elemento=miVector.back(); /*.back() -> Devuelve el ultimo 
										elemento de nuestro vector*/

	cout << "El primer elemento de nuestro vector es: " << primer_elemento << "\n";

	cout << "El ultimo elemento de nuestro vector es: " << ultimo_elemento << "\n";

	cout << "Vector sin el elemento " << *(miVector.begin()+2) << ":";
	
	miVector.erase(miVector.begin()+2); /*.erase() -> Elimina un elemento determinado, 
										  en cualquier parte del vector*/
    
    i_impresion();
	
	cout << "Vector sin los elementos en el rango [";
	cout << *(miVector.begin()) << ","  << *(miVector.begin()+4)<< "):";

	miVector.erase(miVector.begin(), miVector.begin()+4); /*.erase() -> Tambien puede
													      	eliminar un rango de 
													      	elementos*/
    
    it_impresion();

    cout << "Eliminando los elementos del vector ...\n";

    limpiar();
    
    cout << "Elementos del vector: " << miVector.size() << "\n";

 //--------------------------------------------------------------------------

    ii rango={8, 9, 10};

    ii::iterator it;

    cout << "Digite el numero de elementos en el vector: ";

    cin >> n;

    lectura(n);

    cout << "Nuevos elementos del vector: ";
    
    i_impresion();

    cout << "Las veces que aparece el elemento 3 en nuestro vector es: ";
    cout << count(miVector.begin(), miVector.end(), 3) << "\n";
    //count()-> Devuelve las veces que aparece un elemento en un vector

    if(encuentrame(6)) {
    	cout << "El 6 esta en el vector.\n";
    }else {
    	cout << "El 6 no esta en el vector.\n";
    }

    cout << "El rango ";

    for(int i=0; i<rango.size(); i++) {
    	cout << " " << rango[i];
    }

    it=search(miVector.begin(), miVector.end(), rango.begin(), rango.end());
    /*search() -> Devuelve un apuntador al primer elemento del rango
      buscado, en el vector. 
      Si no encuentra el rango entonces devuelve el apuntador al final\
      del vector.
    */
    if(it!=miVector.end()) {
    	cout << " esta en el vector\n";
    }else {
    	cout << " no esta en el vector\n";
    }

    reverse(miVector.begin(), miVector.end());
    /*reverse() -> Invierte el orden de los elementos en nuestro vector*/

    cout << "Los elementos del vector son: ";

    it_impresion();

    cout << "Eliminando los elementos del vector...\n";
    
    miVector.clear();
    
    cout << "Elementos del vector: " << miVector.size() << "\n";
    
	return 0;
}