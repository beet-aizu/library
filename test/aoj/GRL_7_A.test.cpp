// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../matching/bipartite.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int X,Y,E;
  cin>>X>>Y>>E;
  Bipartite bm(X+Y);
  for(int i=0;i<E;i++){
    int x,y;
    cin>>x>>y;
    bm.add_edge(x,X+y);
  }
  cout<<bm.build()<<endl;
  return 0;
}
