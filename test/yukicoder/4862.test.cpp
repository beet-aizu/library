// verification-helper: PROBLEM https://yukicoder.me/problems/4862

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../toptree/toptree.cpp"
#include "../../toptree/distancesum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;
  const char newl = '\n';

  int n,m,q;
  cin>>n>>m>>q;

  auto cs=read(m);
  vector<ll> cnt(n,0);
  for(int &c:cs) cnt[--c]++;

  constexpr size_t N = 1e5;
  using Cluster = DistanceSum<ll>;
  TopTree<Vertex, Cluster, N> G;
  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create(cnt[i]);

  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.link(vs[a],1,vs[b]);
  }

  int flg=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int p,d;
      cin>>p>>d;
      p--;d--;
      G.set_vertex(vs[cs[p]],--cnt[cs[p]]);
      cs[p]=d;
      G.set_vertex(vs[cs[p]],++cnt[cs[p]]);
    }
    if(t==2){
      int e;
      cin>>e;
      e--;
      cout<<G.get_subtree(vs[e]).ans<<newl;
      flg=1;
    }
  }
  if(!flg) cout<<newl;
  return 0;
}
