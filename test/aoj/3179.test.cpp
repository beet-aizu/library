// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3179

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test
using M = Mint<int, 998244353>;

struct Vertex{
  M v;
  void* handle;
  Vertex():v(0),handle(nullptr){}
  Vertex(M v):v(v),handle(nullptr){}
};

struct Cluster{
  M len;
  M sum_v;
  M sum_l,sum_r;
  M rake_v,rake_d;
  Cluster(M len=M(0)):len(len),sum_v(0),sum_l(0),sum_r(0),rake_v(0),rake_d(0){}
  void toggle(){
    swap(sum_l,sum_r);
  }
  static Cluster compress(Cluster x,Vertex *v,Cluster y){
    Cluster nxt(x.len+y.len);
    nxt.sum_v=x.sum_v+x.rake_v+(v->v)+y.sum_v;
    nxt.sum_l=x.sum_l+x.rake_d+y.sum_l+(x.sum_v+(v->v)+x.rake_v)*y.len;
    nxt.sum_r=x.sum_r+x.rake_d+y.sum_r+(y.sum_v+(v->v)+x.rake_v)*x.len;
    return nxt;
  }
  static Cluster rake(Cluster x,Cluster y){
    x.rake_v+=y.sum_v+y.rake_v;
    x.rake_d+=y.sum_l+y.rake_d;
    return x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl ='\n';

  int n;
  cin>>n;

  vector<M> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i].v;

  vector<int> as(n),bs(n);
  vector<M> ws(n);
  for(int i=1;i<n;i++){
    cin>>as[i]>>bs[i]>>ws[i].v;
    as[i]--;bs[i]--;
  }

  const size_t N = 2e5;
  TopTree<Vertex, Cluster, N> G;

  vector<Vertex*> ptr(n);
  for(int i=0;i<n;i++) ptr[i]=G.create(vs[i]);

  for(int i=1;i<n;i++)
    G.link(ptr[as[i]],Cluster(0),ptr[bs[i]]);

  M ans{0};
  for(int i=1;i<n;i++){
    Cluster x=G.get_subtree(ptr[bs[i]],ptr[as[i]]);
    Cluster y=G.get_subtree(ptr[as[i]],ptr[bs[i]]);
    ans+=ws[i]*(x.sum_v+x.rake_v+vs[as[i]])*(y.sum_v+y.rake_v+vs[bs[i]]);
    G.set_edge(ptr[as[i]],ptr[bs[i]],Cluster(ws[i]));
  }
  cout<<ans<<newl;

  Vertex* rt=G.create(Vertex(0));

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int c,a;
      cin>>c>>a;
      c--;
      G.link(rt,Cluster(0),ptr[c]);
      Cluster x=G.get_subtree(rt,ptr[c]);
      G.cut(rt,ptr[c]);
      ans+=M(a)*(x.sum_l+x.rake_d);
      vs[c]+=M(a);
      G.set_vertex(ptr[c],Vertex(vs[c]));
    }

    if(t==2){
      int e,a;
      cin>>e>>a;

      Cluster x=G.get_subtree(ptr[bs[e]],ptr[as[e]]);
      Cluster y=G.get_subtree(ptr[as[e]],ptr[bs[e]]);
      ans+=M(a)*(x.sum_v+x.rake_v+vs[as[e]])*(y.sum_v+y.rake_v+vs[bs[e]]);

      ws[e]+=M(a);
      G.set_edge(ptr[as[e]],ptr[bs[e]],Cluster(ws[e]));
    }
    cout<<ans<<newl;
  }
  return 0;
}
