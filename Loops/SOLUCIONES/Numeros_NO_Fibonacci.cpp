#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;

    for(int f2 = 1, f1 = 2, fn; f1<=n ; f2 = f1, f1 = fn){
        fn = f1 + f2;
        for(int i = f1 + 1 ; i<fn && i<n ; i++){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
