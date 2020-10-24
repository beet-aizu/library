// verification-helper: PROBLEM https://yukicoder.me/problems/4474

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/pow.cpp"
#include "../../mod/order.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int T;
  cin>>T;
  while(T--){
    long long n;
    cin>>n;
    cout<<order(2LL,2*n-1)<<newl;
  }
  return 0;
}
