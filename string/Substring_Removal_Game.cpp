#include <bits/stdc++.h>
using namespace std;
int t;
string arre;
vector <int> vec;
 
int leer() {
    int res=0;
    cin >> arre;
    for(int x=0; x<arre.size(); x++) {
        if(arre[x]=='1') {
            ///Comienzo de cadena
            int longitud=0;
            for(;x<arre.size() && arre[x]=='1'; x++) {
                longitud++;
            }
            x--;
            vec.push_back(longitud);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=vec.size()-1; i>=0; i-=2) {
        res+=vec[i];
    }
    vec.clear();
    arre.clear();
    return res;
}
 
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        cout << leer() << "\n";
    }
    return 0;
}
