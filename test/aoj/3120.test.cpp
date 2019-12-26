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

  vector<LCT::Node*> vs(n+1);
  for(int i=0;i<=n;i++)
    vs[i]=lct.create(i,1);

  for(int i=1;i<=n;i++)
    lct.link(vs[G.par[0][i]],vs[i]);

  for(int i=0;i<q;i++){
    int t,v;
    cin>>t>>v;
    if(t==1){
      if(lct.root(vs[v])==vs[v]){
        lct.link(vs[G.par[0][v]],vs[v]);
      }else{
        lct.cut(vs[v]);
      }
    }
    if(t==2){
      int k=lct.root(vs[v])->idx;
      int t=G.up(v,G.dep[v]-G.dep[k]-1);
      lct.cut(vs[t]);
      cout<<lct.query(vs[t])<<"\n";
      lct.link(vs[k],vs[t]);
    }
  }
  cout<<flush;
  return 0;
}
