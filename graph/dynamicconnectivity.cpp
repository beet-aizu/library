#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct PersistentUnionFind{
  using T = pair<int, int>;
  vector<int> rs,ps;
  stack<T> st;
  PersistentUnionFind(){}
  PersistentUnionFind(int n):
    rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x){
    return x==ps[x]?ps[x]:find(ps[x]);
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    st.emplace(-1,-1);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    ps[y]=x;
    st.top()=T(x,y);
  }
  void undo(int t=1){
    for(int i=0;i<t;i++){
      int x,y;
      tie(x,y)=st.top();st.pop();
      if(x<0) continue;
      rs[x]-=rs[y];
      ps[y]=y;
    }
  }
};

struct DynamicConnectivity{
  using edge = pair<int, int>;
  using range = pair<int, int>;

  int q;
  PersistentUnionFind puf;
  vector< vector<edge> > edges;
  vector <pair<range, edge> > prc;
  map<edge, int> cnt,app;

  DynamicConnectivity(){}
  DynamicConnectivity(int n,int q_):q(1),puf(n){
    while(q<q_) q<<=1;
    edges.resize(q*2);
  }

  void insert(int t,int u,int v){
    edge e=minmax(u,v);
    if(cnt[e]++==0) app[e]=t;
  }

  void erase(int t,int u,int v){
    edge e=minmax(u,v);
    if(--cnt[e]==0) prc.emplace_back(range(app[e],t),e);
  }

  void add(int a,int b,edge e,int k,int l,int r){
    if(r<=a or b<=l) return;
    if(a<=l and r<=b){
      edges[k].emplace_back(e);
      return;
    }
    int m=(l+r)>>1;
    add(a,b,e,(k<<1)|0,l,m);
    add(a,b,e,(k<<1)|1,m,r);
  }

  void add(range r,edge e){
    add(r.first,r.second,e,1,0,q);
  }

  void build(){
    for(auto &e:cnt){
      if(!e.second) continue;
      prc.emplace_back(range(app[e.first],q),e.first);
    }
    for(auto &s:prc)
      add(s.first,s.second);
  }

  template<typename F>
  void exec(const F &f,int k=1){
    for(auto &e:edges[k])
      puf.unite(e.first,e.second);

    if(k<q){
      exec(f,(k<<1)|0);
      exec(f,(k<<1)|1);
    }else{
      f(k-q);
    }

    puf.undo(edges[k].size());
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
