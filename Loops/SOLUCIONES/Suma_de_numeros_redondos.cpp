#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int i=0 ; i<T  ; i++){
        string str;
        cin>>str;
        int k = 0;
        for(int j = 0 ; j<(int)str.size() ; j++){
            if(str[j] != '0') k++;
        }
        cout<<k<<"\n";
        for(int j = str.size() - 1, e = 1 ; j>=0 ; j-- , e*=10){
            if(str[j] != '0' ){
                cout<< (int)((str[j] - '1' + 1)*e) << " ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
