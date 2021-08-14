// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../math/linearfunction.cpp"
#include "../../math/twoway.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test

using M = Mint<int, 998244353>;
using L = LinearFunction<M>;
using P = TwoWay<L>;

struct Vertex{
  void* handle;
  L val;
  Vertex(L val=L()):handle(nullptr),val(val){}
};

struct Cluster{
  P res;
  Cluster():res(L(1,0)){}
  Cluster(L val):res(val){}
  Cluster(P res):res(res){}
  void toggle(){swap(res.x,res.y);}
  static Cluster compress(Cluster x,Vertex* v,Cluster y){
    return Cluster(x.res*P(v->val)*y.res);
  }
  static Cluster rake(Cluster x,Cluster){
    return x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t N = 2e5;
  TopTree<Vertex, Cluster, N> G;

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=G.create(L(as[i],bs[i]));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.link(vs[u],Cluster(L(1,0)),vs[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      G.cut(vs[u],vs[v]);
      G.link(vs[w],Cluster(L(1,0)),vs[x]);
    }

    if(t==1){
      int p,c,d;
      cin>>p>>c>>d;
      G.set_vertex(vs[p],Vertex(L(c,d)));
    }

    if(t==2){
      int u,v,x;
      cin>>u>>v>>x;
      if(u==v){
        auto res=vs[u]->val;
        cout<<res(x)<<newl;
      }else{
        auto res=G.get_path(vs[u],vs[v]).res.x;
        res=vs[u]->val*res*vs[v]->val;
        cout<<res(x)<<newl;
      }
    }
  }
  return 0;
}
