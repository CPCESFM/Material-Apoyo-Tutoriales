#include <bits/stdc++.h>

using namespace std;

int w1,h1,w2,h2; //Declaramos las variables que vamos a leer

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>w1>>h1>>w2>>h2;  //Leemos los datos

    cout<<2*(w1 + h1 + h2) + 4;     //Mostramos la solución

    return 0;
}
