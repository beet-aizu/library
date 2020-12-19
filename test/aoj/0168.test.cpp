// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0168

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../convolution/naive.cpp"
#include "../../math/bostanmori.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  BostanMori<ll> bm(naive<ll>());

  using Poly = vector<ll>;
  Poly as({0,0,1}),cs({-1,-1,-1,1});

  int n;
  while(cin>>n,n)
    cout<<(bm.build(n+2,as,cs)+3650-1)/3650<<endl;

  return 0;
}
