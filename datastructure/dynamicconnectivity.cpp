#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct PersistentUnionFind{
  using T = pair<int, int>;
  int n;
  vector<int> r,p;
  stack<T> st;
  PersistentUnionFind(){}
  PersistentUnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    return x==p[x]?p[x]:find(p[x]);
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    st.emplace(-1,-1);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
    st.top()=T(x,y);
  }
  void undo(int t=1){
    for(int i=0;i<t;i++){
      int x,y;
      tie(x,y)=st.top();st.pop();
      if(x<0) continue;
      r[x]-=r[y];
      p[y]=y;
    }
  }
};

struct DynamicConnectivity{
  using edge = pair<int, int>;
  using range = edge;
  
  int n,q;
  PersistentUnionFind puf;
  vector<vector<edge> > edges;
  vector<pair<range, edge> > prc;
  map<edge, int> cnt,app;
  
  DynamicConnectivity(){}
  DynamicConnectivity(int n,int q_):n(n),q(1),puf(n){
    while(q<q_) q<<=1;
    edges.resize(q*2-1);
  }
  
  void insert(int t,int u,int v){
    edge e=minmax(u,v);
    if(cnt[e]++==0) app[e]=t;
  }
  
  void erase(int t,int u,int v){
    edge e=minmax(u,v);
    if(--cnt[e]==0) prc.emplace_back(range(app[e],t),e);
  }
  
  void add(int a,int b,const edge &e,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      edges[k].emplace_back(e);
      return;
    }
    int m=(l+r)>>1;
    add(a,b,e,k*2+1,l,m);
    add(a,b,e,k*2+2,m,r);
  }
  
  void add(range &r,const edge &e){
    add(r.first,r.second,e,0,0,q);
  }
  
  void build(){
    for(auto &e:cnt){
      if(!e.second) continue;
      prc.emplace_back(range(app[e.first],q),e.first);
    }
    for(auto &s:prc)
      add(s.first,s.second);
  }

  void exec(function<void(int)> &f,int k=0){
    for(auto &e:edges[k])
      puf.unite(e.first,e.second);

    if(k<q-1){
      exec(f,k*2+1);
      exec(f,k*2+2);
    }else{
      int x=k-(q-1);
      f(x);
    }
    
    puf.undo(edges[k].size()); 
  }
};
//END CUT HERE

signed main(){
  int n,q;
  cin>>n>>q;
  DynamicConnectivity dc(n,q);
  vector<int> t(q),u(q),v(q);
  for(int i=0;i<q;i++){
    cin>>t[i]>>u[i]>>v[i];
    if(t[i]==1) dc.insert(i,u[i],v[i]);
    if(t[i]==2) dc.erase(i,u[i],v[i]);
  }
  dc.build();
  function<void(int)> f=[&](int x){
                          if(x>=q||t[x]!=3) return;
                          cout<<(dc.puf.same(u[x],v[x])?"YES":"NO")<<endl;
                        };
  dc.exec(f);
  return 0;
}
/*
  verified on 2018/01/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2235
*/
