#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/topologicalsort.cpp"
#undef call_from_test

#define IGNORE
/**
 * @ignore
 */

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,e;
  cin>>n>>e;
  TopologicalSort ts(n);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ts.add_edge(s,t);
  }

  auto ps=ts.build();
  for(int i:ps) cout<<i<<endl;
  return 0;
}
