// verification-helper: PROBLEM https://yukicoder.me/problems/9158

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/unionfind.cpp"
#include "../../toptree/toptree.cpp"
#include "../../toptree/farthest.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const char newl = '\n';

  const size_t N = 2e5+10;
  using Cluster = Farthest<ll>;
  TopTree<Vertex, Cluster, N> G;

  int n;
  ll x;
  int q;
  cin>>n>>x>>q;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create();

  UnionFind uf(n);
  for(int t=0;t<q;t++){
    int k;
    cin>>k;
    if(k==1){
      int v;
      ll w;
      cin>>v>>w;
      G.link(vs[v],Cluster(w,v,x),vs[x]);
      uf.unite(v,x);
    }
    if(k==2){
      int u,v;
      cin>>u>>v;
      if(uf.same(u,v)){
        ll len=(u==v?0:G.get_path(vs[u],vs[v]).len);
        cout<<len<<newl;
        x+=len;
        x%=n;
      }else{
        cout<<-1<<newl;
      }
    }
    if(k==3){
      int v;
      cin>>v;
      auto p=G.get_subtree(vs[v]).md;
      if(p.dist==0){
        cout<<0<<newl;
      }else{
        cout<<G.get_subtree(vs[p.idx]).md.dist<<newl;
      }
    }
    if(k==4){
      int value;
      cin>>value;
      x+=value;
      x%=n;
    }
  }

  return 0;
}
