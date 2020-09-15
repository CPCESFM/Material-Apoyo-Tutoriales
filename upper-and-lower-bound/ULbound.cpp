#include <bits/stdc++.h>

using namespace std;

vector<int> vlist={-2, 2, -1, 0, 2, 4, 6}; 
vector<int>::iterator it, low, up;


int main(){
	
	ios_base::sync_with_stdio(0);

	cout << "Lista:\n";

	for (it=vlist.begin(); it!=vlist.end(); it++) {
		cout << *it << "\n";
	}

	sort(vlist.begin(), vlist.end());

	cout << "Lista (ordenada):\n";

	for (it=vlist.begin(); it!=vlist.end(); it++) {
		cout << *it << "\n";
	}

	low=lower_bound(vlist.begin(), vlist.end(), -6);

	up=upper_bound(vlist.begin(), vlist.end(), 3);

	cout << "El pimero elemento no menor o igual que -6 es: " << *low<< "\n";
	
	cout << "El primer elemento mayor que 3 es: " << *up << "\n";

	return 0;
}