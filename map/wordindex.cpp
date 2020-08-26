#include<bits/stdc++.h>

using namespace std;

map<string,int> diccionario;
string entrada;
void generar(){
	queue<string> cola;
	for(char i = 'a'; i <= 'z'; i++) cola.push(string(1,i));
	int contador = 1;
	while(!cola.empty()){
		string actual = cola.front();
		cola.pop();
		diccionario[actual] = contador++;
		if(actual.size() == 5) continue;
		for(char k = actual[actual.size() - 1] + 1; k <= 'z'; k++){
			cola.push(actual + string(1,k));
		}
	}
}

int main(){
//	ios_base::sync_with_stdio(0); cin.tie(0);
	generar();
	while(cin >> entrada){
		map<string,int>::iterator it = diccionario.find(entrada);
		if(it == diccionario.end()){
			cout << "0\n";
		}else{
			cout << it -> second << "\n";
		}
	}
	return 0;
}
