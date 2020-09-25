// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/kruskal.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int V,E;
  cin>>V>>E;

  Kruskal<int> G(V);
  for(int i=0;i<E;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  cout<<G.build()<<endl;
  return 0;
}
