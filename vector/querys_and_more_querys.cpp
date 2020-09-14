#include <bits/stdc++.h>

using namespace std;

//vector<int> vcubeta;
int acubeta[1000000];
int n, n_i, q, q_i;

/*void vsolucion() {
	cin >> n;
	vcubeta.reserve(1000000);
	for(int i=0; i<n; i++) {
		cin >> n_i;
		vcubeta[n_i]++;
	}
	cin >> q;
	for(int j=0; j<q; j++) {
		cin >> q_i;
		cout << vcubeta[q_i] << "\n";
	}
}*/

void asolucion() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> n_i;
		acubeta[n_i]++;
	}
	cin >> q;
	for(int j=0; j<q; j++) {
		cin >> q_i;
		cout << acubeta[q_i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	//vsolucion();

	asolucion();

	return 0;
}