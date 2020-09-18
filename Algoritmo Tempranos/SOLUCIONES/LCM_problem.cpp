#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    int t;
    ll l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        if(2*l<=r){
            cout<<l<<" "<<(2*l)<<"\n";
            continue;
        }else{
            cout<<"-1 -1\n";
        }
    }
}
