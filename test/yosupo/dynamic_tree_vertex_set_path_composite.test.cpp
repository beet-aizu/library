#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  using M = Mint<int, 998244353>;

  struct T{
    M a,b;
    T(int a=0,int b=0):a(a),b(b){}
    T(M a,M b):a(a),b(b){}
  };

  auto f=[&](T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};

  using P = pair<T, T>;
  using Node = NodeBase<P, int>;
  auto ff=[&](P a,P b){return P(f(a.first,b.first),f(b.second,a.second));};
  auto gg=[&](P a,int){return a;};
  auto hh=[&](int a,int){return a;};
  auto flip=[&](P a){return P(a.second,a.first);};

  constexpr size_t LIM = 2e5+100;
  using LCT = Path<Node, LIM>;
  LCT lct(ff,gg,hh,flip,0);

  for(int i=0;i<n;i++) lct.create(P(T(as[i],bs[i]),T(as[i],bs[i])));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    lct.evert(lct[v]);
    lct.link(lct[u],lct[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      lct.evert(lct[u]);
      lct.cut(lct[v]);

      lct.evert(lct[x]);
      lct.link(lct[w],lct[x]);
    }

    if(t==1){
      int p,c,d;
      cin>>p>>c>>d;
      lct.set_val(lct[p],P(T(c,d),T(c,d)));
    }

    if(t==2){
      int u,v,x;
      cin>>u>>v>>x;
      lct.evert(lct[u]);
      auto res=lct.query(lct[v]).first;
      cout<<(res.a*M(x)+res.b).v<<newl;
    }
  }
  return 0;
}
