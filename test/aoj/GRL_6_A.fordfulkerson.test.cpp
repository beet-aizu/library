#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/fordfulkerson.cpp"
#undef call_from_test

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int V,E;
  cin>>V>>E;
  FordFulkerson<int, true> G(V);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    G.add_edge(u,v,c);
  }
  cout<<G.flow(0,V-1)<<endl;
  return 0;
}
