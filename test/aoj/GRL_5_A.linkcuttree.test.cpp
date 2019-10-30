#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/chminmax.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/farthest.cpp"
#undef call_from_test

signed main(){
  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs;
  vector<LCT::Node*> es;
  vs.reserve(1e5+100);
  es.reserve(1e5+100);

  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,0);

  for(int i=1;i<n;i++){
    int s,t,w;
    cin>>s>>t>>w;
    es[i]=lct.create(n+i,w);
    lct.evert(vs[s]);
    lct.evert(vs[t]);
    lct.link(es[i],vs[s]);
    lct.link(es[i],vs[t]);
  }

  int ans=0;
  for(int i=0;i<n;i++){
    lct.evert(vs[i]);
    chmax(ans,vs[i]->ld);
  }

  cout<<ans<<endl;
  return 0;
}
