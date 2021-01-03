// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/cycle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  UndirectedCycle G(n);
  for(int i=0;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
  }

  auto vs=G.build();
  unordered_set<int> namori(vs.begin(),vs.end());

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    cout<<1+(namori.count(a) and namori.count(b))<<'\n';
  }
  return 0;
}
