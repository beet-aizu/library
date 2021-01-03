// verification-helper: PROBLEM https://judge.yosupo.jp/problem/cycle_detection

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/cycle.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  DirectedCycle G(n);
  vector<map<int, int>> I(n);

  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
    I[u][v]=i;
  }

  auto vs=G.build();

  if(vs.empty()){
    cout<<-1<<endl;
    return 0;
  }

  int l=vs.size();
  cout<<l<<endl;
  for(int i=0;i<l;i++)
    cout<<I[vs[i]][vs[(i+1)%l]]<<'\n';

  return 0;
}
