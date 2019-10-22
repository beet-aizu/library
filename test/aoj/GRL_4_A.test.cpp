#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;

  SCC G(n);
  for(int i=0;i<m;i++){
    int s,t;
    cin>>s>>t;
    G.add_edge(s,t);
  }

  int k=G.build();
  cout<<(k<n)<<endl;
  return 0;
}
