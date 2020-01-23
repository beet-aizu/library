#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../convolution/garner.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  vector<int> as(n),bs(m);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<m;i++) cin>>bs[i];

  const int MOD = 1e9+7;
  Garner arb;
  auto cs=arb.multiply(as,bs,MOD);
  for(int i=0;i<(int)cs.size();i++){
    if(i) cout<<" ";
    cout<<cs[i];
  }
  cout<<endl;
  return 0;
}
