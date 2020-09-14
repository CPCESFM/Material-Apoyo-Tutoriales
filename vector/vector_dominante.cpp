#include <bits/stdc++.h> 

using namespace std;

int n, val;
bool cond;
vector<int> v1, v2; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> val;
		v1.push_back(val);
	}
	for(int j=0; j<n; j++) {
		cin >> val;
		v2.push_back(val);
	}
	cond=true;
	for(int k=0; k<n; k++) {
		if(v1[k]<=v2[k]) {
			cond=false;
			break;
		}

	}
	if(cond){
		cout << 1;
	}else {
		cout << 0;
	}
	return 0; 
}