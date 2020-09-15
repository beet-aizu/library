#define PROBLEM "https://yukicoder.me/problems/4852"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#include "../../io/tuple.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../tree/lowestcommonancestor.cpp"
#include "../../tree/auxiliarytree.cpp"
#include "../../vector/compress.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

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
    for(int k=H.h-1;k>=0;k--){
      int p=H.par[k][r];
      if(~p and d<=dep[p]) r=p;
    }
    rs[i]=H.par[0][r];
  }

  vector<ll> pos;
  for(int i=0;i<q;i++)
    pos.emplace_back(ts[i]+dep[vs[i]]);
  pos=compress(pos);

  BIT<int> bit(pos.size());
  vector<int> cs(q);
  for(int i=0;i<q;i++)
    cs[i]=lower_bound(pos.begin(),pos.end(),ts[i]+dep[vs[i]])-pos.begin();

  queue<P> que;
  que.emplace(0,q);

  vector<int> ans(q);
  vector<vector<int>> add(n+1),sub(n+1),query(n+1);
  while(!que.empty()){
    auto [L,R]=que.front();que.pop();
    if(L+1==R) continue;
    int M=(L+R)>>1;

    vector<int> ss;
    for(int i=L;i<M;i++){
      if(type[i]==0){
        ss.emplace_back(vs[i]);
        ss.emplace_back(rs[i]);
        add[vs[i]].emplace_back(i);
        sub[rs[i]].emplace_back(i);
      }
    }

    for(int i=M;i<R;i++){
      if(type[i]==1){
        ss.emplace_back(vs[i]);
        query[vs[i]].emplace_back(i);
      }
    }

    ss.emplace_back(0);
    H.query(ss);

    auto expand=[&](int v){
      for(int i:add[v]) bit.add(cs[i],+1);
      for(int i:sub[v]) bit.add(cs[i],-1);
    };

    MFP([&](auto dfs,int v,int p)->void{
      for(int i:query[v])
        ans[i]-=bit.query(0,cs[i]+1);

      for(int u:H.T[v])
        if(u!=p) dfs(u,v);
      expand(v);

      for(int i:query[v])
        ans[i]+=bit.query(0,cs[i]+1);
    })(0,-1);

    H.clear(ss);

    for(int i=L;i<M;i++){
      if(type[i]==0){
        add[vs[i]].clear();
        sub[rs[i]].clear();
      }
    }

    for(int i=M;i<R;i++){
      if(type[i]==1){
        query[vs[i]].clear();
      }
    }

    que.emplace(L,M);
    que.emplace(M,R);
  }

  for(int i=0;i<q;i++)
    if(type[i]==1) cout<<ans[i]<<newl;

  return 0;
}
