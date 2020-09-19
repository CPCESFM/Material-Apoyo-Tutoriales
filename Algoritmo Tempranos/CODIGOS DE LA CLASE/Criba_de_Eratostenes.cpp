#include <bits/stdc++.h>

using namespace std;

bool is_prime[1000002] = {true};
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    
    /// Inicializamos el arreglo
    is_prime[0] = is_prime[1] = false;
    for(int i = 2 ; i<= 1000000 ; i++){
        is_prime[i] = true;
    }
    
    ///Hagamos la criba
    // Considerando que todos los numeros que no están tachados son primos
    for(int i = 2 ; i*i<=n ; i++){
        if(is_prime[i] ){
            /// Tachamos todos los multiplos de nuestro primo encontrado
            for(int j = i*i ; j<=n ; j+=i){
                is_prime[j] = false;
            }
        }
    }
    
    /// Imprimimos todos los primos encontrados hasta n
    for(int i = 1 ; i<=n ; i++){
        if(is_prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<"\n\n";
    return 0;
}
