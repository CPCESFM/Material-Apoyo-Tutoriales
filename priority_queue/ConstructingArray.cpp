#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int arreglo[200005];
int t,n;

struct comparador{
	bool operator ()(const pair<int, ii>& a, const pair<int, ii>& b) const{
		if(a.first == b.first){
			return b.second < a.second;
		}else{
			return a.first < b.first;
		}
	}
};

priority_queue<iii,vector<iii>, comparador> pq;

void solve(){
	cin >> n;
	pq.push(make_pair(n,make_pair(0,n-1)));
	int i = 1;
	while( i <= n){
		iii actual = pq.top();
		pq.pop();
		int l= actual.second.first;
		int r= actual.second.second;
		if(l > r) continue;
		int distancia = actual.first;
		int mid = ( r + l ) / 2;
		arreglo[mid] = i++;
		pq.push(make_pair(mid - l + 1, make_pair(l, mid - 1)));
		pq.push(make_pair(r - mid + 1, make_pair(mid + 1, r)));
	}
	for(int i=0 ; i<n; i++){
		cout << arreglo[i] << " ";
		arreglo[i]= 0;
	}
	cout << "\n";

}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
