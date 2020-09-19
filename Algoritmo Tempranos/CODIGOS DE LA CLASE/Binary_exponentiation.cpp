#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,mod;
    cin>>a>>b>>mod;
    ll a_0 = a, b_0 = b;
    a%=mod;
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b>>=1;
    }
    cout<<a_0<<" a la "<<b_0<<" /= "<<res<<" modulo "<<mod<<"\n";


    ///PARA ENCONTRAR EL INVERSO MODULAR SIEMPRE QUE MOD SEA PRIMO
            ///Checamos que mod sea primo
    bool is_prime = true;

    for(ll i = 2 ; i*i<=mod ; i++){
        if(mod%i == 0){
            is_prime = false;
            break;
        }
    }
            ///Aqui termina el chequeo

            ///SI ES PRIMO Y PUES A!=0
    if(is_prime && (a_0%mod)>0){
        cout<<"NOTE QUE: El inverso modular de "<<a_0<<" es ";
        a = a_0%mod;
        b = mod - 2;
        res = 1;
        while(b>0){
            if(b&1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            b>>=1;
        }
        cout<<res<<"\n";
        cout<<"Ya que "<<a_0<<" * "<<res<<" = "<<((a_0*res))
        <<" /= 1 ( mod "<<mod<<")\n";
    }
    return 0;
}
