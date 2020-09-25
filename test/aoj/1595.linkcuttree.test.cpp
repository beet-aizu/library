// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/farthest.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Node = NodeBase<int>;
  constexpr size_t LIM = 1e6;
  using LCT = Farthest<Node, LIM>;
  LCT lct;

  int n;
  cin>>n;
  for(int i=0;i<n;i++) lct.create(1);

  for(int i=1;i<n;i++){
    int s,t;
    cin>>s>>t;
    s--;t--;
    lct.evert(lct[t]);
    lct.link(lct[s],lct[t]);
  }

  for(int i=0;i<n;i++){
    lct.evert(lct[i]);
    cout<<(n-1)*2-(lct[i]->ld)+1<<"\n";
  }

  cout<<flush;
  return 0;
}
