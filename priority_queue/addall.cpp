#include<bits/stdc++.h>

using namespace std;
int n, aux, cost;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	while( cin >> n && n){
		cost = 0;
		for(int i=0 ; i<n; i++){
			cin >> aux;
			pq.push(aux);
		}
		int a = 0;
		int b = 0;
		while(!pq.empty()){
			if(pq.size() > 1){
				a = pq.top(); pq.pop();
				b = pq.top(); pq.pop();
				cost += a + b;
				pq.push(a + b);
			}else{
				pq.pop();
			}
		}
		cout << cost<<"\n";
	}

	return 0;
}
