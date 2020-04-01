#define PROBLEM "https://yukicoder.me/problems/3453"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#undef call_from_test

struct Vertex{
  void* handle;
  int color;
  Vertex(int color=0):handle(nullptr),color(color){}
};

using ll = long long;
struct Cluster{
  ll con,lf,lm,rg,rm,ans;
  Cluster(ll sum=0):con(0),lf(sum),lm(0),rg(sum),rm(0),ans(sum){}
  Cluster(ll con,ll lf,ll lm,ll rg,ll rm,ll ans):
    con(con),lf(lf),lm(lm),rg(rg),rm(rm),ans(ans){}
  void toggle(){swap(lf,rg);swap(lm,rm);}
  static Cluster compress(Cluster &x,Vertex* v,Cluster &y){
    ll ncon=x.con or (v->color) or y.con;
    if(!ncon) return Cluster(x.lf+y.lf);
    ll nlf=x.lf;
    if(!x.con and !(v->color)) nlf+=y.lf;
    ll nlm=x.lm;
    if(!(v->color)) nlm+=y.lm;
    ll nrg=y.rg;
    if(!y.con and !(v->color)) nrg+=x.rg;
    ll nrm=y.rm;
    if(!(v->color)) nrm+=x.rm;
    return Cluster(ncon,nlf,nlm,nrg,nrm,x.lf+x.lm+y.rg+y.rm);
  }
  static Cluster rake(Cluster &x,Cluster &y,Vertex* v){
    ll nlf=x.lf,nlm=x.lm+y.lm;
    if(!(v->color)) nlm+=y.lf;
    return Cluster(x.con,nlf,nlm,x.rg,x.rm,0);
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  const size_t LIM = 1e6;
  TopTree<Vertex, Cluster, LIM> G;

  int n;
  cin>>n;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create();

  ll sum=0;
  for(int i=1;i<n;i++){
    int u,v,w;
    cin>>u>>v>>w;
    sum+=w;
    G.link(vs[u],Cluster(w),vs[v]);
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int u,v,w,x;
      cin>>u>>v>>w>>x;
      sum-=G.get_path(vs[u],vs[v]).ans;
      G.cut(vs[u],vs[v]);
      G.link(vs[v],Cluster(x),vs[w]);
      sum+=x;
    }
    if(t==2){
      int k;
      cin>>k;
      vector<int> xs(k);
      for(int j=0;j<k;j++) cin>>xs[j];

      for(int x:xs) G.set_vertex(vs[x],Vertex(1));

      for(int x:xs)
        cout<<sum<<" "<<G.get_subtree(vs[x]).ans<<newl;
      cout<<sum-G.get_subtree(vs[xs[0]]).ans<<newl;

      for(int x:xs) G.set_vertex(vs[x],Vertex(0));
    }
  }

  return 0;
}
