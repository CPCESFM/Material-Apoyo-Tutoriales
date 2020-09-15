#include <bits/stdc++.h>

using namespace std;

string s, inter;
vector<string> snumeros;
int numeros[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	stringstream check(s);
	while(getline(check, inter, '+')) {
		snumeros.push_back(inter);
	}
	inter.clear();
	for(int i=0; i<snumeros.size(); i++) {
		numeros[i]=stoi(snumeros[i]);
	}
	sort(numeros, numeros+snumeros.size());
	for(int j=0; j<(snumeros.size()-1); j++) {
		cout << numeros[j] << "+";
	}
	cout << numeros[snumeros.size()-1];
	return 0; 
}