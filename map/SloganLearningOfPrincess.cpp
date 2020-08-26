#include<bits/stdc++.h>

using namespace std;

int N,Q;
string first_line, second_line, peticion,basura;
map<string,string> slogans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	getline(cin,basura);
	for(int i=0 ; i<N ; i++){
		getline(cin,first_line);
		getline(cin,second_line);
		
		slogans[first_line] = second_line;
	}
	cin >> Q;
	getline(cin,basura);
	for(int i=0; i<Q ; i++){
		getline(cin, peticion);
		cout << slogans[peticion] << "\n";
	}	
	return 0;
}
