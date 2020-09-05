#include <bits/stdc++.h>

using namespace std;

int n;  //Utilizaremos unicamente un dato, por lo tanto solo declaramos una variable

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;         //Leemos n

    cout<<(n*n*n)/2;    //Imprimimos el valor de (n^3)/2
    
    return 0;
}
