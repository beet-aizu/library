#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

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
  vs.reserve(1e5+100);

  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,1);

  for(int i=1;i<n;i++){
    int s,t;
    cin>>s>>t;
    s--;t--;
    lct.evert(vs[t]);
    lct.link(vs[s],vs[t]);
  }

  for(int i=0;i<n;i++){
    lct.evert(vs[i]);
    cout<<(n-1)*2-(vs[i]->ld)+1<<"\n";
  }

  cout<<flush;
  return 0;
}
