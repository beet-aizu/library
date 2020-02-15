#define PROBLEM "https://yukicoder.me/problems/143"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/bigint.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  bigint MOD = 1000000000;
  ll n,m;
  cin>>n>>m;
  n/=1000;
  n%=m;
  bigint res(1);
  for(int i=0;i<n;i++){
    res*=m-i;
    res/=i+1;
  }
  cout<<res%MOD<<endl;
  return 0;
}
