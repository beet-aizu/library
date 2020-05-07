#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/diameterforedge.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  DiameterForEdge<int> G(n);
  for(int i=1;i<n;i++){
    int s,t,w;
    cin>>s>>t>>w;
    G.add_edge(s,t,w);
  }
  cout<<G.build()<<endl;
  return 0;
}
