#include<bits/stdc++.h>

using namespace std;
int n,choice,aux;
bool es_cola, es_pila, es_pq;

int main(){
	while(cin >> n){
		queue<int> cola;
		stack<int> pila;
		priority_queue<int> pq;
		es_cola = true;
		es_pila = true;
		es_pq = true;
		for(int i=0 ; i<n ; i++){
			cin >> choice >> aux;
			if( choice == 1){
				cola.push(aux);
				pila.push(aux);
				pq.push(aux);
			}else{
				if(cola.size()>= 1 && cola.front() == aux && es_cola){
					es_cola = true;
					cola.pop();
				}else{
					es_cola = false;
				}
				if(pila.size() >= 1 && pila.top() == aux && es_pila){
					es_pila = true;
					pila.pop();
				}else{
					es_pila = false;
				}
				if(pq.size() >= 1 && pq.top() == aux && es_pq){
					es_pq = true;
					pq.pop();
				}else{
					es_pq = false;
				}	
			}
		}
		if(es_cola && !es_pila && !es_pq){
			cout << "queue\n";
		}else{
			if(!es_cola && !es_pila && es_pq){
				cout << "priority queue\n";
			}else{
				if(!es_cola && es_pila && !es_pq){
					cout <<"stack\n";
				}else{
					if(!es_cola && !es_pila && !es_pq){
						cout << "impossible\n";
					}else{
						cout << "not sure\n";
					}
				
				}
			}
		}
	}	

	return 0;
}
