#include <bits/stdc++.h>

using namespace std;

int colores[100];
int n,m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> m;
    for(int i=0; i<n; i++) {
        cin >> colores[i];
    }
    sort(colores, colores+n);
    for(int j=0; j<m; j++) {
        cout << j+1 << ": " << count(colores, colores+n,j+1) << "\n";
    }
    return 0;
}
