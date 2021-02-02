// verification-helper: PROBLEM https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../math/bostanmori.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  NTT<2> ntt;
  using M = decltype(ntt)::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};

  int d;
  cin>>d;

  long long k;
  cin>>k;

  vector<M> as(d),cs(d);
  for(int i=0;i<d;i++) cin>>as[i].v;
  for(int i=0;i<d;i++) cin>>cs[i].v;

  reverse(cs.begin(),cs.end());
  for(auto &c:cs) c=-c;
  cs.emplace_back(1);

  BostanMori<M> seq(conv);
  cout<<seq.build(k,as,cs)<<endl;
  return 0;
}
