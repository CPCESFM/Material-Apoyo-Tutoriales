#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

///VARIABLES DEL PROBLEMA
ll n,k;

///VARIABLES DEL ALGORITMO
ll coci, res, sum;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n%k == 0){
            cout<<"YES\n";
            for(ll i = 1 ; i<=k ; i++ )
                cout<<(n/k)<<" ";
            cout<<"\n";
            continue;
        }
        if(  (2*k>n && (k&1 && !(n&1))) || ( k>n && ( k&1 && n&1 ) )  || ( !(k&1) && n&1 ) || k>n  ){
            cout<<"NO\n";
            continue;
        }

        if(n&1 && k&1){ ///Dice que n es impar y k es impar, es decir, que los a_i son impar
            coci = n/k;
            res = n - k*coci;
            if((coci&1) == 0){ ///Si div es par
                res += k; ///Sumaremos k a res
                coci--;    ///Restamos en div, para que div sea impar y nos sobren valores
            }
            if(res%2 != 0){
                cout<<"NO\n";
                continue;
            }else{
                cout<<"YES\n";
                cout<<(res+coci);
                for(ll i = 2 ; i<=k ; i++){
                    cout<<" "<<coci;
                }
                cout<<"\n";
                continue;
            }
        }

        if( !(n&1) && k&1 ){ ///Dice que si n es par y k es impar
            coci = n/k;
            res = n - coci*k;
            if(coci&1 && coci>=3){
                coci--;
                res += k;
            }
            if(!(res&1)){
                cout<<"YES\n";
                cout<<res+coci;
                for(ll i = 2; i<=k ; i++)
                    cout<<" "<<coci;
                cout<<"\n";
                continue;
            }
            else{
                cout<<"NO\n";
                continue;
            }
        }

        coci = n/k;
        res  = n - coci*k;
        cout<<"YES\n";
        cout<<(coci + res);
        for(ll i = 2 ; i<=k ; i++)
            cout<<" "<<coci;
        cout<<"\n";
    }
    return 0;
}
