#define PROBLEM "https://yukicoder.me/problems/4852"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#include "../../io/tuple.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../tree/sack.cpp"
#include "../../tree/eulertourforvertex.cpp"
#include "../../tree/lowestcommonancestor.cpp"
#include "../../tree/auxiliarytree.cpp"
#include "../../vector/compress.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';
  using ll = long long;
  using P = pair<int, ll>;

  int n,q;
  cin>>n>>q;
  vector<vector<P>> G(n+1);
  AuxiliaryTree H(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
    H.add_edge(a,b);
  }
  // add 0 for root
  H.add_edge(0,1);
  H.build(0);

  const ll INF = 1e15;
  G[0].emplace_back(1,INF);

  vector<ll> dep(n+1);
  MFP([&](auto dfs,int v,int p,ll d)->void{
    dep[v]=d;
    for(auto [u,c]:G[v])
      if(u!=p) dfs(u,v,d+c);
  })(0,-1,0);

  auto [type,vs,ts,ls]=read_tuple<int, int, ll, ll>(q);

  // vanish vertices
  vector<int> rs(q);
  for(int i=0;i<q;i++){
    if(type[i]!=0) continue;
    int r=vs[i];
    ll d=dep[vs[i]]-ls[i];
    for(int k=H.lca.h-1;k>=0;k--){
      int p=H.lca.par[k][r];
      if(~p and d<=dep[p]) r=p;
    }
    rs[i]=H.lca.par[0][r];
  }

  vector<ll> pos;
  for(int i=0;i<q;i++)
    pos.emplace_back(ts[i]+dep[vs[i]]);
  pos=compress(pos);

  BIT<int> bit(pos.size());
  vector<int> cs(q);
  for(int i=0;i<q;i++)
    cs[i]=lower_bound(pos.begin(),pos.end(),ts[i]+dep[vs[i]])-pos.begin();

  // inverse of ss
  vector<int> rev(n+1);

  queue<P> que;
  que.emplace(0,q);

  vector<int> ans(q);
  while(!que.empty()){
    auto [L,R]=que.front();que.pop();
    if(L+1==R) continue;
    int M=(L+R)>>1;

    vector<int> ss;
    for(int i=L;i<M;i++){
      if(type[i]==0){
        ss.emplace_back(vs[i]);
        ss.emplace_back(rs[i]);
      }
    }

    for(int i=M;i<R;i++)
      if(type[i]==1) ss.emplace_back(vs[i]);

    if(ss.empty()){
      que.emplace(L,M);
      que.emplace(M,R);
      continue;
    }

    ss.emplace_back(0);

    H.query(ss);

    int m=ss.size();
    for(int i=0;i<m;i++) rev[ss[i]]=i;

    vector<vector<int>> add(m),sub(m);
    for(int i=L;i<M;i++){
      if(type[i]==0){
        add[rev[vs[i]]].emplace_back(i);
        sub[rev[rs[i]]].emplace_back(i);
      }
    }

    auto expand=[&](int v){
      for(int i:add[v]) bit.add0(cs[i],+1);
      for(int i:sub[v]) bit.add0(cs[i],-1);
    };
    auto shrink=[&](int v){
      for(int i:add[v]) bit.add0(cs[i],-1);
      for(int i:sub[v]) bit.add0(cs[i],+1);
    };
    auto query=[&](int i){
      ans[i]+=bit.sum0(cs[i]);
    };
    auto reset=[&](int){};

    Sack S(m,expand,shrink,query,reset);

    for(int v:ss)
      for(int u:H.T[v])
        if(v<u) S.add_edge(rev[u],rev[v]);

    for(int i=L;i<M;i++){
      if(type[i]==0){
        S.add_query(rev[vs[i]],i);
        S.add_query(rev[rs[i]],i);
      }
    }

    for(int i=M;i<R;i++)
      if(type[i]==1) S.add_query(rev[vs[i]],i);

    S.build(rev[0]);

    H.clear(ss);

    que.emplace(L,M);
    que.emplace(M,R);
  }

  for(int i=0;i<q;i++)
    if(type[i]==1) cout<<ans[i]<<newl;

  return 0;
}
