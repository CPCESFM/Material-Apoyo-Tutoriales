#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, suma = 0;
  cin>>n;
  for(ll i = 1 ; i<n ; i++){
  	if(i&1){ suma += i; }
  }
  cout<<suma<<"\n";
  return 0;
}
