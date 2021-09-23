// verification-helper: PROBLEM https://judge.yosupo.jp/problem/subset_convolution

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/bitwise/fwht.cpp"
#include "../../convolution/bitwise/or.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using M = Mint<int, 998244353>;
  using V = valarray<M>;

  int sz=1<<n;

  vector<V> as(sz,V(n+1)),bs(sz,V(n+1));
  for(int i=0;i<sz;i++) cin>>as[i][__builtin_popcount(i)].v;
  for(int i=0;i<sz;i++) cin>>bs[i][__builtin_popcount(i)].v;

  fwht(as,bitwise_or::zeta);
  fwht(bs,bitwise_or::zeta);

  vector<V> cs(sz,V(n+1));
  for(int i=0;i<sz;i++)
    for(int j=0;j<=n;j++)
      for(int k=0;j+k<=n;k++)
        cs[i][j+k]+=as[i][j]*bs[i][k];

  fwht(cs,bitwise_or::moebius);

  for(int i=0;i<sz;i++){
    if(i) cout<<' ';
    cout<<cs[i][__builtin_popcount(i)];
  }
  cout<<endl;
  return 0;
}
