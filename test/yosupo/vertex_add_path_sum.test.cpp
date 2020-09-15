#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/heavylightdecomposition.cpp"
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  HLD G(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }
  G.build();

  using ll = long long;
  BIT<ll> bit(n);
  for(int i=0;i<n;i++)
    bit.add(G.vid[i],as[i]);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,x;
      cin>>p>>x;
      bit.add(G.vid[p],x);
    }
    if(t==1){
      int u,v;
      cin>>u>>v;
      ll res=0;
      auto f=[&](int l,int r){res+=bit.query(l,r);};
      G.for_each(u,v,f);
      cout<<res<<'\n';
    }
  }
  return 0;
}
