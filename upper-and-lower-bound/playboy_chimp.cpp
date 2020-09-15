#include<bits/stdc++.h>

using namespace std;

int n, q, Luchu;
int chimps[50000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie();
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> chimps[i];
	}
	cin >> q;
	for(int j=0; j<q; j++) {
		cin >> Luchu;
		int *t_chimp=upper_bound(chimps, chimps+n, Luchu);
		int *s_chimp=t_chimp;
		s_chimp--;
		while(s_chimp>=chimps && *s_chimp==Luchu){
			s_chimp--;
		}
			if(s_chimp>=chimps) {
				cout << *s_chimp << " "; 
			}else {
				cout << "X ";
			}
			if(t_chimp==chimps+n) {
				cout << "X\n";
			}else {
				cout << *t_chimp << "\n";
		}
	}
}