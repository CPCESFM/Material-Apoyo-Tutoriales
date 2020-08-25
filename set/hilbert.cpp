#include<bits/stdc++.h>//incluimos las librerarias necesarias

#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))// n%k

using namespace std;
typedef long long ll;
set <int> ocupado;

ll a[200005];
ll tc, n;

void solve(){
        cin >> tc;
        while(tc--){// cuando lleguemos a cero para
                cin >> n;
                for(int i=1 ; i<=n ; i++){
                        cin >> a[i];
                        ocupado.insert(MOD(i + a[i],n));             
                }
                if( ocupado.size() == n){
                        cout <<"YES\n";
                }else{
                        cout << "NO\n";
                }
                ocupado.clear();
        }
}
int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        solve();
        return 0;
}

