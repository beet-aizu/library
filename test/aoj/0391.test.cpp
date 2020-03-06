#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0391"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tree/lca.cpp"
#include "../../tree/levelancestor.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;
  using P = pair<int, int>;
  vector<vector<P> > G(n);
  LCA lca(n);
  LevelAncestor la(n);
  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    lca.add_edge(u,v);
    la.add_edge(u,v);
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }

  lca.build();
  la.build();

  vector<int> dep(n,0);
  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      for(auto e:G[v]){
        int u,c;
        tie(u,c)=e;
        if(u==p) continue;
        dep[u]=dep[v]+c;
        q.emplace(u,v);
      }
    }
  }

  auto dist=[&](int u,int v){return dep[u]+dep[v]-2*dep[lca.lca(u,v)];};
  auto path=
    [&](int u,int v,int d){
      if(d==0) return u;
      int r=lca.lca(u,v);
      int x=la.distance(u,r),y=la.distance(r,v);
      if(d<=x) return la.up(u,d);
      return la.up(v,(x+y)-d);
    };

  for(int i=0;i<q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;c--;
    auto calc=
      [&](int v,int u=-1){
        return max({dist(a,v)*(a!=u),
                    dist(b,v)*(b!=u),
                    dist(c,v)*(c!=u)});
      };

    int p=lca.lca(a,b),q=lca.lca(b,c),r=lca.lca(c,a);
    int v=la.dep[p]>la.dep[q]?p:(la.dep[q]>la.dep[r]?q:r);

    int ans=min({calc(a),calc(b),calc(c),calc(v)});
    for(int u:{a,b,c}){
      if(calc(v,u)>=ans) continue;
      int l=0,r=la.distance(u,v);
      while(l+1<r){
        int m=(l+r)>>1;
        int x=path(u,v,m);
        if(calc(x,u)<dist(x,u)) r=m;
        else l=m;
      }
      chmin(ans,calc(path(u,v,l)));
      chmin(ans,calc(path(u,v,r)));
    }
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
