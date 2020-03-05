#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/stronglyconnectedcomponent.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  SCC G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  int k=G.build();
  cout<<k<<endl;
  for(int i=0;i<k;i++){
    cout<<G.C[i].size();
    for(int v:G.C[i]) cout<<" "<<v;
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}
