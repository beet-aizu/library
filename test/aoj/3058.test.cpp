#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../maxflow/dinic.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  int S=n,T=n+1;
  Dinic<int, true> G(n+2);

  for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    if(x>y) swap(x,y);
    G.add_edge(x,y,z);
  }

  for(int i=0;i<n;i++){
    if(s[i]=='R') G.add_edge(S,i,as[i]);
    if(s[i]=='L') G.add_edge(i,T,as[i]);
  }

  cout<<G.flow(S,T)<<endl;
  return 0;
}
