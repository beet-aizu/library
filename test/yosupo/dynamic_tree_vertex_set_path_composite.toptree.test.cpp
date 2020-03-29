#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test

using M = Mint<int, 998244353>;

struct T{
  M a,b;
  T(int a=0,int b=0):a(a),b(b){}
  T(M a,M b):a(a),b(b){}
};

using P = pair<T, T>;
T mul(T x,T y){return T(x.a*y.a,x.b*y.a+y.b);};
P mul(P x,P y){return P(mul(x.first,y.first),mul(y.second,x.second));}

struct Vertex{
  void* handle;
  T val;
  Vertex(T val=T()):handle(nullptr),val(val){}
};

struct Cluster{
  P res;
  Cluster(){}
  Cluster(T val):res(val,val){}
  Cluster(P res):res(res){}
  void toggle(){swap(res.first,res.second);}
  static Cluster compress(Cluster x,Vertex* v,Cluster y){
    return Cluster(mul(x.res,mul(P(v->val,v->val),y.res)));
  }
  static Cluster rake(Cluster x,Cluster,Vertex*){
    return x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const size_t LIM = 1e6;
  TopTree<Vertex, Cluster, LIM> G(Cluster(T(1,0)));

  int n,q;
  cin>>n>>q;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=G.create(Vertex(T(as[i],bs[i])));

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    G.link(vs[u],Cluster(T(1,0)),vs[v]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;

    if(t==0){
      int u,v,w,x;
      cin>>u>>v>>w>>x;

      G.cut(vs[u],vs[v]);
      G.link(vs[w],Cluster(T(1,0)),vs[x]);
    }

    if(t==1){
      int p,c,d;
      cin>>p>>c>>d;
      G.set_vertex(vs[p],Vertex(T(c,d)));
    }

    if(t==2){
      int u,v,x;
      cin>>u>>v>>x;
      if(u==v){
        auto res=vs[u]->val;
        cout<<(res.a*M(x)+res.b).v<<"\n";
      }else{
        auto res=G.query(vs[u],vs[v]).res.first;
        res=mul(vs[u]->val,mul(res,vs[v]->val));
        cout<<(res.a*M(x)+res.b).v<<"\n";
      }
    }
  }
  cout<<flush;
  return 0;
}
