#include <bits/stdc++.h>

using namespace std;
int n, D;
int contests[200000]; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> contests[i];
	}
	sort(contests, contests+n);
	D=1;
	for(int j=0; j<n; j++) {
		if(contests[j]>=D) {
			D++;
		}
	}
	cout << D-1 << "\n"; 
	return 0;
}