// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3120

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/subtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e5+100;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  int n,q;
  cin>>n>>q;

  for(int i=0;i<=n;i++) lct.create(1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    lct.evert(lct[b]);
    lct.link(lct[a],lct[b]);
  }
  lct.evert(lct[1]);
  lct.link(lct[0],lct[1]);

  vector<int> par(n+1);
  for(int i=1;i<=n;i++) par[i]=lct.idx(lct.parent(lct[i]));

  for(int i=0;i<q;i++){
    int t,v;
    cin>>t>>v;
    if(t==1){
      if(lct.root(lct[v])==lct[v]){
        lct.link(lct[par[v]],lct[v]);
      }else{
        lct.cut(lct[v]);
      }
    }
    if(t==2){
      auto r=lct.root(lct[v]);
      lct.evert(lct[v]);
      auto u=lct.parent(r);
      lct.evert(r);
      lct.cut(u);
      cout<<lct.query(u)<<"\n";
      lct.link(r,u);
    }
  }
  cout<<flush;
  return 0;
}
