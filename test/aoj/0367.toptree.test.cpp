// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../toptree/toptree.cpp"
#undef call_from_test

using ll = long long;

ll K;
ll calc(ll val){return val%K?val:0;}

struct Vertex{
  ll w;
  void* handle;
  Vertex(ll w=0):w(w),handle(nullptr){}
};

struct Cluster{
  ll edge,all,lft,rgh;
  Cluster(ll edge=-1):edge(edge),all(0),lft(0),rgh(0){}
  void toggle(){
    swap(lft,rgh);
  }
  static Cluster compress(Cluster x,Vertex *v,Cluster y){
    Cluster nxt;
    nxt.all=x.all+y.all;

    if(~x.edge) x.lft=x.edge+(v->w);
    else nxt.all+=calc(x.rgh+(v->w));

    if(~y.edge) y.rgh=(v->w)+y.edge;
    else nxt.all+=calc((v->w)+y.lft);

    nxt.lft=x.lft;
    nxt.rgh=y.rgh;
    return nxt;
  }
  static Cluster rake(Cluster x,Cluster){
    return x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n>>K;

  const size_t N = 1e5;
  TopTree<Vertex, Cluster, N> T;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=T.create();

  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    T.link(vs[a],Cluster(c),vs[b]);
  }

  vector<ll> ws(n,0);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    string op;
    cin>>op;
    if(op=="add"){
      int x,d;
      cin>>x>>d;
      ws[x]+=d;
      T.set_vertex(vs[x],Vertex(ws[x]));
    }
    if(op=="send"){
      int s,t;
      cin>>s>>t;
      Cluster res=T.get_path(vs[s],vs[t]);
      if(~res.edge) cout<<calc(ws[s]+res.edge+ws[t])<<newl;
      else cout<<res.all+calc(ws[s]+res.lft)+calc(res.rgh+ws[t])<<newl;
    }
  }
  return 0;
}
