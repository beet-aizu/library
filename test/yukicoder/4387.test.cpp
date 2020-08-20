#define PROBLEM "https://yukicoder.me/problems/4387"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../graph/rangetorange.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,a,b;
  cin>>n>>a>>b;

  auto xs=read(n);

  RangeToRange G(n);
  SCC scc(G.size()+n+n);
  auto f=[&](int u,int v){scc.add_edge(u,v);};
  G.init(f);

  for(int i=0;i<n;i++){
    // [x - B, x - A]
    {
      int l=lower_bound(xs.begin(),xs.end(),xs[i]-b)-xs.begin();
      int r=upper_bound(xs.begin(),xs.end(),xs[i]-a)-xs.begin();
      G.add_edge(i,i+1,l,r,f,f);
    }
    // [x + A, x + B]
    {
      int l=lower_bound(xs.begin(),xs.end(),xs[i]+a)-xs.begin();
      int r=upper_bound(xs.begin(),xs.end(),xs[i]+b)-xs.begin();
      G.add_edge(i,i+1,l,r,f,f);
    }
  }

  scc.build();
  map<int, int> cnt;
  for(int i=0;i<n;i++) cnt[scc[G.idx(i)]]++;
  for(int i=0;i<n;i++) cout<<cnt[scc[G.idx(i)]]<<newl;
  return 0;
}
