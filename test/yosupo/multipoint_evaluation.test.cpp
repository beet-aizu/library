#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#include "../../polynomial/multipoint_evaluation.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  MultiEval<M> me(conv);

  vector<M> cs(n),ps(m);
  for(int i=0;i<n;i++) cin>>cs[i].v;
  for(int i=0;i<m;i++) cin>>ps[i].v;

  auto ans=me.build(cs,ps);
  for(int i=0;i<m;i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
