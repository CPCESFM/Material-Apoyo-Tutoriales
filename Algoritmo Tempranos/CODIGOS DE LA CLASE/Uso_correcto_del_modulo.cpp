#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a, b, M;
    ///Leemos dos numeros enteros y un entero positivo el cual ocuparemos
    ///Para que actue de modulo (M), es decir, a%M.
    cin>>a>>b>>M;
    
    ///Recordemos que el modulo debe de ser positivo y mayor que 1
    if(M<=1){
      cout<<"ERROR\n";
      return 0;
    }
    
    ///Ahora si pongamos todos los operadores correctamente.
    cout<<a<<" + "<<b<<" modulo "<<M<<" = "<<(( (a%M) + (b%M) )% M)<<"\n";
    cout<<a<<" - "<<b<<" modulo "<<M<<" = "<<(( (a%M) (M- (b%M))%M )% M)<<"\n";
    cout<<a<<" * "<<b<<" modulo "<<M<<" = "<<(( (a%M) * (b%M) )% M)<<"\n";
    ///Aún no estamos listos para la división
    
    return 0;
}
