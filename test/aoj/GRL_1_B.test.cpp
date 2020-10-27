// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../graph/bellmanford.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,r;
  cin>>n>>m>>r;

  BellmanFord<int> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  int neg_loop;
  auto res=G.build(r,neg_loop);
  if(neg_loop) drop("NEGATIVE CYCLE");

  for(int x:res){
    if(x==numeric_limits<int>::max()) cout<<"INF\n";
    else cout<<x<<"\n";
  }
  cout<<flush;
  return 0;
}
