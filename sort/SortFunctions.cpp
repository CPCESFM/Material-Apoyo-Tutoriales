#include <bits/stdc++.h>
//Libreria algorithm

using namespace std; 

vector<int> first_list={-1, 0, 1, 32, -12, 3, 8, -120, 2, 1}; //Primera Lista
vector<int> second_list={-2, 1, 0, -2, -2, 3, 32, 12, 21, 18}; //Segunda Lista
vector<int>::iterator it1, it2; //Iteradores del vector.

bool greater_than (int i, int j) {
	//Esta es nuestra función de ordenamiento. 
	return (i>j);
}

int main() {

	ios_base::sync_with_stdio(0);

	cout << "PRIMERA LISTA\n";

	cout << "Elementos no ordenados: \n";
	for (it1=first_list.begin(); it1!=first_list.end(); it1++) {
		cout << *it1 << "\n";
	}

	sort(first_list.begin(), first_list.end()); //Ordenamos lista bajo el operador < 

	cout << "\nElementos ordenados con la funcion determinada: \n";
	for (it1=first_list.begin(); it1!=first_list.end(); it1++) {
		cout << *it1 << "\n";
	}

	cout << "\nSEGUNDA LISTA\n";
	
	cout << "Elementos no ordenados: \n";
	for (it2=second_list.begin(); it2!=second_list.end(); it2++) {
		cout << *it2 << "\n";
	}
	
	sort(second_list.begin(), second_list.end(), greater_than); //Ordenamos con nuestro criterio. 

	cout << "\nElementos ordenados con la funcion que creamos: \n";
	for (it2=second_list.begin(); it2!=second_list.end(); it2++) {
		cout << *it2 << "\n";
	}
	
	return 0;
}

