#include <iostream>

using namespace std;

int MCD(int M,int N){
    int res=M%N;
    while(res!=0){
        M=N;
        N=res;
        res=M%N;
    }
    return N;
}

int main()
{
    int M,N;
    cin>>M>>N;
    cout<<MCD(M,N)<<'\n';
    return 0;
}
