#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/subtree.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,as[i]);

  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    lct.link(vs[p],vs[i]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int u,x;
      cin>>u>>x;
      as[u]+=x;
      lct.set_val(vs[u],as[u]);
    }
    if(t==1){
      int u;
      cin>>u;
      Node* p=lct.parent(vs[u]);
      if(p) lct.cut(vs[u]);
      cout<<lct.query(vs[u])<<"\n";
      if(p) lct.link(p,vs[u]);
    }
  }
  cout<<flush;
  return 0;
}
