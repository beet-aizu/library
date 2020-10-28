// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/subtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using Node = NodeBase<ll>;
  constexpr size_t LIM = 2e5+100;
  using LCT = Subtree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n;i++) lct.create(as[i]);

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    lct.evert(lct[v]);
    lct.link(lct[u],lct[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      lct.evert(lct[u]);
      lct.cut(lct[v]);

      lct.evert(lct[x]);
      lct.link(lct[w],lct[x]);
    }

    if(t==1){
      int p,x;
      cin>>p>>x;
      as[p]+=x;
      lct.set_val(lct[p],as[p]);
    }

    if(t==2){
      int v,p;
      cin>>v>>p;
      lct.evert(lct[p]);
      lct.cut(lct[v]);
      cout<<lct.query(lct[v])<<newl;
      lct.link(lct[p],lct[v]);
    }
  }
  return 0;
}
