#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/bellmanford.cpp"
#undef call_from_test

signed main(){
  int n,m,r;
  cin>>n>>m>>r;

  BellmanFord<int> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  int neg_loop;
  auto res=G.build(0,neg_loop);
  if(neg_loop){
    cout<<-1<<endl;
    return 0;
  }

  for(int x:res) cout<<x<<"\n";
  cout<<flush;
  return 0;
}
