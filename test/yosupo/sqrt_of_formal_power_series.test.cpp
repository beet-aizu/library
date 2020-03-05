#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../mod/sqrt.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  deque<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  while(!as.empty()&&as.front()==0) as.pop_front();

  if(as.empty()){
    for(int i=0;i<n;i++){
      if(i) cout<<" ";
      cout<<0;
    }
    cout<<endl;
    return 0;
  }

  int m=as.size();
  if((n-m)&1) drop(-1);

  auto ss=mod_sqrt(as[0],ntt.md);
  if(ss.empty()) drop(-1);

  vector<M> ps(n,M(0));
  for(int i=0;i<m;i++) ps[i]=M(as[i])/M(as[0]);

  auto bs=FPS.sqrt(ps,n);
  bs.insert(bs.begin(),(n-m)/2,M(0));
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<bs[i]*ss[0];
  }
  cout<<endl;
  return 0;
}
