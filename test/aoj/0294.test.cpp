// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0294

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/dominatortree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  DominatorTree G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }
  G.build(0);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int r;
    cin>>r;
    r--;
    cout<<(G[r]?G[r]:r)+1<<"\n";
  }
  cout<<flush;
  return 0;
}
