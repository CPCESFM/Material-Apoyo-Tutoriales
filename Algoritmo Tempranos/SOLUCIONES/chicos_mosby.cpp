#include <bits/stdc++.h>

using namespace std;

int N,M;
int cuad=0;

void leer(){
    cin>>N>>M;
}

void euclidRaro(int a, int b){
    int x=min(a,b);
    int y=max(a,b);
    if(y%x==0){
        cuad+=(y/x);
        return;
    }else{
        cuad+=(y/x);
        euclidRaro((y%x),x);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    leer();
    euclidRaro(N,M);
    cout<<cuad<<"\n";
    return 0;
}
