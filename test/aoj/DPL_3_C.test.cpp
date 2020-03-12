#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../algorithm/largestrectangle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  vector<ll> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];

  cout<<largestrectangle(vs)<<endl;
  return 0;
}
