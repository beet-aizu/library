#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct HLDecomposition {
  int n,pos;
  vector<vector<int> > G;
  vector<int> vid, head, sub, hvy, par, dep, inv, type, ps, pt;
  
  HLDecomposition(){}
  HLDecomposition(int sz):
    n(sz),pos(0),G(n),
    vid(n,-1),head(n),sub(n,1),hvy(n,-1),
    par(n),dep(n),inv(n),type(n),ps(n),pt(n){}
  
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0;
    for(int r:rs){
      dfs(r);
      bfs(r, c++);
    }
  }
  
  void dfs(int rt) {
    using T = pair<int, int>;
    stack<T> st;
    par[rt]=-1;
    dep[rt]=0;
    st.emplace(rt,0);
    while(!st.empty()){
      int v=st.top().first;
      int &i=st.top().second;
      if(i<(int)G[v].size()){
	int u=G[v][i++];
	if(u==par[v]) continue;
	par[u]=v;
	dep[u]=dep[v]+1;
	st.emplace(u,0);
      }else{
	st.pop();
	for(int j=0;j<(int)G[v].size();j++){
	  int &u=G[v][j];
	  if(u==par[v]) swap(u,G[v].back());
	  if(u==par[v]) continue;
	  sub[v]+=sub[u];
	  if(sub[u]>sub[G[v].front()]) swap(u,G[v].front());
	}
      }
    }
  }

  void bfs(int r,int c) {
    using T = tuple<int, int, int>;
    stack<T> st;
    st.emplace(r,r,0);
    while(!st.empty()){
      int v,h;
      tie(v,h,ignore)=st.top();
      int &i=get<2>(st.top());
      if(!i){
	type[v]=c;
	ps[v]=vid[v]=pos++;
	inv[vid[v]]=v;
	head[v]=h;
        hvy[v]=(G[v].empty()?-1:G[v][0]);
	if(hvy[v]==par[v]) hvy[v]=-1;
      }
      if(i<(int)G[v].size()){
	int u=G[v][i++];
	if(u==par[v]) continue;
	st.emplace(u,(hvy[v]==u?h:u),0);
      }else{
	st.pop();
	pt[v]=pos;
      }
    }
  }
  
  // for_each(vertex)
  // [l,r] <- attention!!
  void for_each(int u, int v, const function<void(int, int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }

  template<typename T,typename Q,typename F>
  T for_each(int u,int v,T ti,const Q &q,const F &f){
    T l=ti,r=ti;
    while(1){
      if(vid[u]>vid[v]){
	swap(u,v);
	swap(l,r);
      }
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  void for_each_edge(int u, int v, const function<void(int, int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
	f(vid[head[v]],vid[v]);
        v=par[head[v]];
      }else{
	if(u!=v) f(vid[u]+1,vid[v]);
	break;
      }
    }
  }

  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};
//END CUT HERE


signed AOJ_GRL5C(){
  int n;
  cin>>n;
  HLDecomposition lca(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int c;
      cin>>c;
      lca.add_edge(i,c);
    }
  }
  lca.build();
  int q;
  cin>>q;
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<lca.lca(u,v)<<endl;
  }
  return 0;
}
/*
  verified on 2017/12/31
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp
*/


struct BiconectedGraph{
  typedef pair<int,int> P;
  int n;
  vector<vector<int> > G,C,T;
  vector<int> ord,low,belong;
  vector<P> B;
  BiconectedGraph(){}
  BiconectedGraph(int sz):n(sz),G(sz),C(sz),T(sz){}
  
   void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

   void input(int m,int offset){
    int a,b;
    for(int i=0;i<m;i++){
      scanf("%d %d",&a,&b);
      add_edge(a+offset,b+offset);
    }
  }
  
   bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }
  
  void dfs(int u,int p,int &k){
    ord[u]=low[u]=k;
    ++k;
    for(int v:G[u]){
      if(v==p) continue;
      if(ord[v]>=0){
	low[u]=min(low[u],ord[v]);
      }else{
	dfs(v,u,k);
	low[u]=min(low[u],low[v]);
      }
      if(is_bridge(u,v)) B.push_back(P(u,v));
    }
  }
  
  void fill_component(int c,int u){
    C[c].push_back(u);
    belong[u]=c;
    for(int v:G[u]){
      if(belong[v]>=0||is_bridge(u,v)) continue;
      fill_component(c,v);
    }
  }
  
  void add_component(int u,int &k){
    if(belong[u]>=0) return;
    fill_component(k++,u);
  }
  
  int build(){
    int k=0;
    ord.resize(n);
    low.resize(n);
    belong.resize(n);
    fill(ord.begin(),ord.end(),-1);
    fill(belong.begin(),belong.end(),-1);
    for(int u=0;u<n;u++){
      if(ord[u]>=0) continue;
      dfs(u,-1,k);
    }
    k=0;
    for(int i=0;i<(int)B.size();i++){
      add_component(B[i].first,k);
      add_component(B[i].second,k);
    }
    for(int u=0;u<n;u++) add_component(u,k);
    for(int i=0;i<(int)B.size();i++){
      int u=belong[B[i].first],v=belong[B[i].second];
      T[u].push_back(v);
      T[v].push_back(u);
    }
    return k;
  }
};

template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):
    f(f),g(g),d1(d1){
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  inline T query(int a,int b){
    T vl=d1,vr=d1;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[(l++)-1]);
      if(r&1) vr=f(dat[(--r)-1],vr);
    }
    return f(vl,vr);
  }
  
};

signed YUKI_529(){
  int n,e,q;
  scanf("%d %d %d",&n,&e,&q);
  
  BiconectedGraph big(n);
  big.input(e,-1);

  int E=0,V=big.build();
  HLDecomposition hl(V);
  for(int i=0;i<V;i++)
    for(int j:big.T[i])
      if(i<j) hl.add_edge(i,j),E++;
  
  hl.build();
  SegmentTree<int,int> rmq(V,
			   [](int a,int b){return max(a,b);},
			   [](int a,int b){a++;return b;},
			   -1);
  vector<priority_queue<int> > pq(V);
  map<int,int> m;
  int num=0;
  for(int i=0;i<q;i++){
    int d;
    scanf("%d",&d);
    if(d==1){
      int u,w;
      scanf("%d %d",&u,&w);
      u--;
      u=big.belong[u];
      u=hl.vid[u];
      m[w]=u;
      if(pq[u].empty()||pq[u].top()<w) rmq.update(u,w);
      pq[u].push(w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.belong[s];
      t=big.belong[t];
      auto f=[&](int l, int r)->int{return rmq.query(l, r + 1);};
      int ans=hl.for_each(s, t, -1, f, rmq.f);
      printf("%d\n",ans);
      if(~ans){
	int k=m[ans];
	pq[k].pop();
	rmq.update(k,(!pq[k].empty()?pq[k].top():-1));		 
	num--;
      }
    }
  }
  return 0;
}

/* verified on 2017/12/31
https://yukicoder.me/problems/no/529
*/

signed main(){
  //AOJ_GRL5C();
  YUKI_529();
  return 0;
};
