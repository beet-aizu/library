#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../tree/diameterforedge.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;
  int n;
  cin>>n;
  DiameterForEdge<ll> G(n);
  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  auto seq=G.restore();
  cout<<G.build()<<' '<<seq.size()<<newl;
  for(int i=0;i<(int)seq.size();i++){
    if(i) cout<<' ';
    cout<<seq[i];
  }
  cout<<newl;
  return 0;
}
