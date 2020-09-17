#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,n;
    int aux,res,k;
    cin>>t;
    while(t--){
        cin>>n;
        aux = n;
        res = 1;
        k = 0;
        while(aux>0){
            if(aux%10>0){
                k++;
            }
            aux/=10;
        }
        cout<<k<<"\n";
        while(n>0){
            if(n%10>0){
                cout<<((n%10)*res)<<" ";
            }
            n/=10;
            res*=10;
        }
        cout<<"\n";
    }
    return 0;
}
