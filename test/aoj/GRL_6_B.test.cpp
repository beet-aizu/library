// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mincostflow/primaldual.cpp"
#undef call_from_test

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int v,e,f;
  cin>>v>>e>>f;

  PrimalDual<int, int> G(v);
  for(int i=0;i<e;i++){
    int u,v,c,d;
    cin>>u>>v>>c>>d;
    G.add_edge(u,v,c,d);
  }

  if(!G.build(0,v-1,f))
    cout<<-1<<endl;
  else
    cout<<G.get_cost()<<endl;
  return 0;
}
