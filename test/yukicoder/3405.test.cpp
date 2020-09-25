// verification-helper: PROBLEM https://yukicoder.me/problems/3405

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/levelancestor.cpp"
#include "../../tree/eulertourforbfs.cpp"
#include "../../segtree/basic/chien.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  EulerTourForBFS G(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }
  G.build();

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using ll = long long;
  auto f=[&](ll a,ll b){return a+b;};
  auto g=[&](ll a,ll b){return a*b;};
  SegmentTree<ll, ll> seg(f,g,g,0,1);

  vector<ll> vs(n);
  for(int i=0;i<n;i++)
    vs[G.idx(i)]=as[i];
  seg.build(vs);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x;
    cin>>x;

    ll sum=0;
    auto apply=
      [&](int l,int r){
        sum+=seg.query(l,r);
        seg.update(l,r,0);
      };

    int p=G.par[0][x];
    if(~p){
      int pp=G.par[0][p];
      if(~pp) G.exec(pp,0,apply);

      G.exec(p,0,apply);
      G.exec(p,1,apply);
    }

    G.exec(x,0,apply);
    G.exec(x,1,apply);
    G.exec(x,2,apply);

    seg.set_val(G.idx(x),sum);
    cout<<sum<<"\n";
  }

  return 0;
}
