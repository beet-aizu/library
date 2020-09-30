// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3084

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#include "../../tree/centroid.cpp"
#include "../../tools/fixpoint.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  NTT<2> ntt;
  using M = decltype(ntt)::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);
  using Poly = decltype(FPS)::Poly;

  int n,m;
  cin>>n>>m;

  Poly as(n);
  for(int i=0;i<n;i++) cin>>as[i].v;

  Centroid G(n+1);
  G.add_edge(n,0);
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.add_edge(u,v);
  }

  vector<int> par(n+1,-1);
  {
    queue<int> que;
    que.emplace(n);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int u:G.G[v]){
        if(u==par[v]) continue;
        par[u]=v;
        que.emplace(u);
      }
    }
  }

  vector<int> dead(n+1,0);
  auto disable=[&](int k){
    dead[k]=1;
    G.disable(k);
  };
  disable(n);

  const int deg = 1<<18;
  Poly ps(n,M(1));
  ps=FPS.exp(FPS.mul(FPS.log(ps,deg),M(m)),deg);

  queue<int> que;
  que.emplace(G.build(0)[0]);

  Poly ans(n);
  while(!que.empty()){
    int r=que.front();que.pop();

    Poly qs;
    MFP([&](auto dfs,int v,int p,int h)->void{
      while(!(h<(int)qs.size())) qs.emplace_back(0);
      qs[h]+=as[v];
      for(int u:G.G[v]){
        if(u==p) continue;
        if(dead[u]) continue;
        dfs(u,v,h+1);
      }
    })(r,par[r],0);
    reverse(qs.begin(),qs.end());

    vector<int> bs;
    int p=r;
    while(~p&&!dead[p]){
      bs.emplace_back(p);
      p=par[p];
    }

    int len=qs.size()-1;
    qs.resize(len+bs.size(),M(0));
    auto rs=FPS.mul(FPS.pre(ps,qs.size()),qs);

    for(int i=0;i<(int)bs.size();i++) ans[bs[i]]+=rs[len+i];

    disable(r);
    for(int u:G.G[r])
      if(!dead[u]) que.emplace(G.build(u)[0]);
  }

  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
