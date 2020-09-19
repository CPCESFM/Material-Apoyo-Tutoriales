#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll z,p;
    int t;
    bool divisble;
    ///Consideramos que vamos a leer t casos
    cin>>t;
    
    ///Leemos los t casos
    while(t--){
        ///Para cada caso leemos un entero z
        cin>>z;
        
        cout<<z<<" Factores primos:\n\n";
        if(z<0) z*=-1;
        
        ///Si no podemos factorizarlo imprimimos -1
        if(z<2)
        {
            cout<<"-1\n";
            continue;
        }
        
        ///Iniciamos con el primer primo que es 2
        p = 2;
        ///Factorizamos a z
        while(z!=1)
        {
            divisble = false;
            while( z%p == 0)
            {
                cout<<p<<" ";
                z/=p;
                divisble = true;
            }
            if(divisble) cout<<"\n";
            p++;
        }
        cout<<"\n\n";
    }
    return 0;
}
