#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#include "../../polynomial/multieval.cpp"
#include "../../polynomial/interpolate.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  Interpolate<M> ip(conv);

  vector<M> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i].v;
  for(int i=0;i<n;i++) cin>>ys[i].v;

  auto ans=ip.build(xs,ys);
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
