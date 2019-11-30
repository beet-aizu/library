#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/independentset.cpp"
#undef call_from_test

signed main(){
  int n,m;
  cin>>n>>m;
  IndependentSet G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }
  int X=G.build();
  cout<<X<<endl;
  for(int i=0;i<X;i++){
    if(i) cout<<" ";
    cout<<G.ans[i];
  }
  cout<<endl;
  return 0;
}
