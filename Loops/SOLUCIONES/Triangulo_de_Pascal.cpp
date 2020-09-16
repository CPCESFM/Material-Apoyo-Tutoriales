#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll exp_2, suma;
    int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        exp_2 = 1;
        for(int i = 1 ; i <= m ; i++){
            exp_2 *= 2;
        }
        suma = exp_2;
        for(int i = m+1 ; i <= n ; i++ ){
            exp_2 *= 2;
            suma += exp_2;
        }
        cout<<suma<<"\n";

    }
    return 0;
}
