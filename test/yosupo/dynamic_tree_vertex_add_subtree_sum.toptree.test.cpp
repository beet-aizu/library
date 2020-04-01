#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#undef call_from_test

using ll = long long;
struct Vertex{
  void* handle;
  ll val;
  Vertex(ll val=0):handle(nullptr),val(val){}
};

struct Cluster{
  ll res;
  Cluster(ll res=0):res(res){}
  void toggle(){}
  static Cluster compress(Cluster x,Vertex* v,Cluster y){
    return Cluster(x.res+v->val+y.res);
  }
  static Cluster rake(Cluster x,Cluster y,Vertex* v){
    return Cluster(x.res+y.res+v->val);
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 2e6;
  TopTree<Vertex, Cluster, LIM> G;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=G.create(Vertex(as[i]));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.link(vs[u],Cluster(0),vs[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      G.cut(vs[u],vs[v]);
      G.link(vs[w],Cluster(0),vs[x]);
    }

    if(t==1){
      int p,x;
      cin>>p>>x;
      as[p]+=x;
      G.set_vertex(vs[p],Vertex(as[p]));
    }

    if(t==2){
      int v,p;
      cin>>v>>p;
      cout<<as[v]+G.get_subtree(vs[p],vs[v]).res<<newl;
    }
  }
  cout<<flush;
  return 0;
}
