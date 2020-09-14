#include <bits/stdc++.h>

using namespace std; 

vector<pair<int,string>> lista;
vector<string> indices, valores;
string s_i, s_v, intermedia, enter1, enter2;
int casos;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> casos;
	getline(cin, enter1);
	for(int s=0; s<casos; s++) {	    
		getline(cin, enter2);
    	getline(cin, s_i);
	    stringstream check_i(s_i);
	    while(getline(check_i, intermedia, ' ')) {
	       	indices.push_back(intermedia);
	   	}
	   	intermedia.clear();
	   	getline(cin, s_v);
	   	stringstream check_v(s_v);
    	while(getline(check_v, intermedia, ' ')) {
	       	valores.push_back(intermedia);
	    }
        for(int i=0; i<indices.size(); i++) {
           	lista.push_back(make_pair(stoi(indices[i]), valores[i]));
        }
        sort(lista.begin(), lista.end());
        if(s>0) {
        	cout << "\n";
        }
        for(int j=0; j<lista.size(); j++) {
           	cout << lista[j].second << "\n";
       	}
        intermedia.clear();
        enter2.clear();
        s_i.clear();
        s_v.clear();
        indices.clear();
        valores.clear();
        lista.clear();  
	} 
	enter1.clear();
	return 0;
}