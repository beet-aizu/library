// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/totient.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  ll n;
  cin>>n;
  cout<<totient(n)<<endl;
  return 0;
}
