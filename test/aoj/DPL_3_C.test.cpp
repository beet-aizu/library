#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  cout<<largestrectangle(v)<<endl;
  return 0;
}
