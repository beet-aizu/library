#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#define double long double
#include "../../convolution/fastfouriertransform.cpp"
#undef double
#include "../../convolution/arbitrarymod.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  using M = Mint<int>;
  ArbitraryMod<M> arb;

  vector<M> as(n),bs(m);
  for(int i=0;i<n;i++) cin>>as[i].v;
  for(int i=0;i<m;i++) cin>>bs[i].v;
  auto cs=arb.multiply(as,bs);
  for(int i=0;i<(int)cs.size();i++){
    if(i) cout<<" ";
    cout<<cs[i];
  }
  cout<<endl;
  return 0;
}
