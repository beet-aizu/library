#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../tools/trio.cpp"
#include "../../tree/heavylightdecomposition.cpp"
#include "../../segtree/basic/ushi.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n,k;
  cin>>n>>k;

  HLD hld(n);
  using P = pair<int, int>;
  map<P, int> es;
  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    hld.add_edge(a,b);
    es[P(a,b)]=es[P(b,a)]=c;
  }
  hld.build();

  vector<ll> dep(n);
  MFP([&](auto dfs,int v,int p,ll d)->void{
        dep[v]=d;
        for(int u:hld.G[v])
          if(u!=p) dfs(u,v,d+es[P(u,v)]);
      })(0,-1,0);

  vector<ll> ws(n,0);
  auto con=[&](int a,int b){return hld.par[a]==b||hld.par[b]==a;};
  auto cst=
    [&](int a,int b)->ll{
      if(!con(a,b)) return 0;
      ll res=ws[a]+ws[b]+abs(dep[a]-dep[b]);
      return res%k?res:0;
    };

  using T = trio<int, int, ll>;
  T ti(-1,-1,-1);
  auto f=
    [&](T a,T b){
      if(a.first<0||a.second<0) return b;
      if(b.first<0||b.second<0) return a;
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          if(con(a.first,b.first))
            return T(a.second,b.second,a.third+b.third+cst(a.first,b.first));
          swap(a.first,a.second);
        }
        swap(b.first,b.second);
      }
      return ti;
    };

  SegmentTree<T> seg(f,ti);
  vector<T> vt;
  for(int i=0;i<n;i++)
    vt.emplace_back(hld.inv[i],hld.inv[i],0);
  seg.build(vt);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    string op;
    cin>>op;
    if(op=="add"){
      int x,d;
      cin>>x>>d;
      ws[x]+=d;
      seg.set_val(hld.vid[x],T(x,x,0));
    }
    if(op=="send"){
      int s,t;
      cin>>s>>t;
      int u=hld.lca(s,t);
      T r1(ti),r2(ti);
      hld.for_each(s,u,[&](int l,int r){r1=f(r1,seg.query(l,r));});
      hld.for_each_edge(t,u,[&](int l,int r){r2=f(r2,seg.query(l,r));});
      cout<<f(r1,r2).third<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
