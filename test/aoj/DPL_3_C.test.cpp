#define PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
#define main moin
#include "../../algorithm/largestrectangle.cpp"
#undef main

signed main(){
  using ll = long long;
  ll n;
  cin>>n;
  vector<ll> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  cout<<largestrectangle(v)<<endl;
  return 0;
}
