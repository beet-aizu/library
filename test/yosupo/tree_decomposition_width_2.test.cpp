#define PROBLEM "https://judge.yosupo.jp/problem/tree_decomposition_width_2"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../graph/nicetree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  {string s;cin>>s;}
  {string s;cin>>s;}

  int n,m;
  cin>>n>>m;
  NiceTree G(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v);
  }

  G.build();
  auto T=G.T;
  if(T.empty()) drop(-1);

  assert((int)T.size()<=3*n+m+10);
  cout<<"s td "<<T.size()<<' '<<2<<' '<<n<<newl;

  for(int i=0;i<(int)T.size();i++){
    cout<<"b "<<i+1;
    for(int v:T[i].bag) cout<<' '<<v+1;
    cout<<newl;
  }

  for(int i=0;i<(int)T.size();i++)
    for(int j:T[i].child) cout<<i+1<<' '<<j+1<<newl;

  for(int i=1;i<(int)T.size();i++)
    if(T[i].is_root) cout<<1<<' '<<i+1<<newl;
  return 0;
}
