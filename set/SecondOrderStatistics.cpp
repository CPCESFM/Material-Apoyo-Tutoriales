#include <bits/stdc++.h>

using namespace std;
int n,aux;
set<int> conjunto;
set<int>::iterator it;
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> aux;
		conjunto.insert(aux);
	}
	it = conjunto.begin();
	it++;
	if(it != conjunto.end()){
		cout << *it << "\n";
	}else{
		cout << "NO\n";
	}

	return 0;
}
