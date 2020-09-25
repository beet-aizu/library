// verification-helper: PROBLEM https://judge.yosupo.jp/problem/two_edge_connected_components

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/twoedgeconnectedcomponents.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;

  TwoEdgeConnectedComponents C(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    C.add_edge(a,b);
  }

  int k=C.build();
  cout<<k<<endl;
  for(int i=0;i<k;i++){
    cout<<C[i].size();
    for(int j=0;j<(int)C[i].size();j++) cout<<" "<<C[i][j];
    cout<<"\n";
  }

  cout<<flush;
  return 0;
}
