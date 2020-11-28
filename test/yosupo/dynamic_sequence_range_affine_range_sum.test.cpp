// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../bbst/rbst/rbst.cpp"
#include "../../bbst/rbst/data/lazy.cpp"
#include "../../bbst/rbst/impl/basic.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using M = Mint<int, 998244353>;
  using T = pair<M, M>;
  using E = pair<M, M>;
  auto f=[](T a,T b){return T(a.first+b.first,a.second+b.second);};
  auto g=[](T a,E b){return T(a.first*b.first+a.second*b.second,a.second);};
  auto h=[](E a,E b){return E(a.first*b.first,a.second*b.first+b.second);};
  auto flip=[](T a){return a;};
  T ti(0,0);
  E ei(1,0);

  using Data = Lazy<T, E, decltype(f), decltype(g), decltype(h),
                    decltype(flip)>;
  using Node = Data::Node;
  constexpr size_t LIM = 1e6;
  Basic<Data, LIM> G(f,g,h,flip,ti,ei);

  int n,q;
  cin>>n>>q;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  vector<Node> vt;
  for(int i=0;i<n;i++) vt.emplace_back(T(as[i],1),ei);
  auto rt=G.build(vt);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int k,x;
      cin>>k>>x;
      rt=G.insert(rt,k,Node(T(x,1),ei));
    }
    if(t==1){
      int k;
      cin>>k;
      rt=G.erase(rt,k);
    }
    if(t==2){
      int l,r;
      cin>>l>>r;
      rt=G.toggle(rt,l,r);
    }
    if(t==3){
      int l,r,b,c;
      cin>>l>>r>>b>>c;
      rt=G.update(rt,l,r,E(b,c));
    }
    if(t==4){
      int l,r;
      cin>>l>>r;
      cout<<G.query(rt,l,r).first<<newl;
    }
  }
  return 0;
}
