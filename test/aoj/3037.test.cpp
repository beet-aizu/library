// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3037

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../toptree/toptree.cpp"
#undef call_from_test

using ll = long long;
struct Vertex{
  void* handle;
  ll val;
  Vertex(ll val=0):handle(nullptr),val(val){}
};

struct Cluster{
  ll sm,md,chd,ma;
  Cluster():sm(0),md(0),chd(0),ma(0){}
  void toggle(){}
  static Cluster compress(Cluster x,Vertex *v,Cluster y){
    Cluster z;
    z.sm=x.sm+(v->val)+y.sm;
    z.md=max({x.md,x.chd,y.md});
    z.ma=x.sm+(v->val)+y.sm;
    return z;
  }
  static Cluster rake(Cluster x,Cluster y){
    x.sm+=y.sm;
    x.chd=max({x.chd,y.chd,y.ma});
    return x;
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n;
  cin>>n;
  vector<int> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];

  const size_t N = 1e5 + 10;
  TopTree<Vertex, Cluster, N> G;

  vector<Vertex*> vs(n);
  for(int i=0;i<n;i++) vs[i]=G.create(ws[i]);

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.link(vs[u],Cluster(),vs[v]);
  }

  Vertex* da=G.create(0);
  Vertex* db=G.create(0);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;

    G.link(da,Cluster(),vs[a]);
    G.link(db,Cluster(),vs[b]);

    cout<<G.get_path(da,db).md<<newl;

    G.cut(da,vs[a]);
    G.cut(db,vs[b]);
  }
  return 0;
}
