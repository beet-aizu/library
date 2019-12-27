#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3120"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tree/levelancestor.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/subtree.cpp"
#undef call_from_test

signed main(){
  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  int n,q;
  cin>>n>>q;

  LevelAncestor G(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  G.add_edge(0,1);
  G.build(0);

  for(int i=0;i<=n;i++) lct.create(1);

  for(int i=1;i<=n;i++)
    lct.link(lct[G.par[0][i]],lct[i]);

  for(int i=0;i<q;i++){
    int t,v;
    cin>>t>>v;
    if(t==1){
      if(lct.root(lct[v])==lct[v]){
        lct.link(lct[G.par[0][v]],lct[v]);
      }else{
        lct.cut(lct[v]);
      }
    }
    if(t==2){
      int k=lct.idx(lct.root(lct[v]));
      int t=G.up(v,G.dep[v]-G.dep[k]-1);
      lct.cut(lct[t]);
      cout<<lct.query(lct[t])<<"\n";
      lct.link(lct[k],lct[t]);
    }
  }
  cout<<flush;
  return 0;
}
