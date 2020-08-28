#include<bits/stdc++.h>

using namespace std;

long long n,day1,bill,aux,costo_total;
multiset<long long int> bills;
typedef multiset<long long int>::iterator set_it;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n && n){
		costo_total = 0;
		bills.clear();
		for(int j=0; j<n; j++){
			cin >> day1;
			for(int i=0 ; i<day1; i++){
				cin >> aux;
				bills.insert(aux);
			}
			set_it mayor = bills.begin();
			set_it menor = bills.end();
			menor--;
			costo_total += abs(*mayor - *menor);
			bills.erase(mayor);
			bills.erase(menor);
		}
		cout << costo_total << "\n";

	}
	return 0;
}
