#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3102"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/twosatisfiability.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  TwoSat G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_if(a,b);
  }
  G.build();

  for(int i=0;i<n;i++){
    int flg=0;
    for(int j=0;j<n;j++){
      if(G.scc.blg[i]!=G.scc.blg[j]) continue;
      if(flg) cout<<" ";
      flg=1;
      cout<<j+1;
    }
    cout<<endl;
  }
  return 0;
}
