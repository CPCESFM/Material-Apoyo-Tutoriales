#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,p,q,gcd,lcm;
    cin>>a>>b;
    
    ///CONDICIONES NECESARIAS
    if(a<0) p = 0-a;
    else p = a;

    if(b<0) q = 0-b;
    else q = b;
    
    //Algoritmo de Euclides
    while(q!=0){
        p %= q;
        swap(p,q);
        ///cout<<"a = "<<p<<",\tb= "<<q<<"\n";
    }
    ///Asignacion
    gcd = p;
    lcm = (a*b)/gcd;

    cout<<"gcd( "<<a<<" , "<<b<<") = "<<gcd<<"\n";
    cout<<"lcm( "<<a<<" , "<<b<<") = "<<lcm<<"\n";
    return 0;
}
