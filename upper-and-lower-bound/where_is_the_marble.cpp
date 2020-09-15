#include <bits/stdc++.h>

using namespace std;

int marbles[10000];
int n, q, casos, question;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while((cin >> n >> q) && n && q) { 
		casos++;
		for(int i=0; i<n; i++) {
			cin >> marbles[i];
		}
		sort(marbles, marbles+n);
		cout << "CASE# " << casos << ":\n";
		for(int j=0; j<q; j++) {
			cin >> question;
			bool encontrar=binary_search(marbles,marbles+n,question);
			int indice=lower_bound(marbles,marbles+n,question)-marbles;
			if(encontrar==true) {
				cout << question << " found at " << indice+1 << "\n";
			}else {
				cout << question << " not found" << "\n";
			}
		}
	}
}