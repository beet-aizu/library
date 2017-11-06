#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct HLDecomposition {
  int n,pos;
  vector<vector<int> > G;
  vector<int> vid, head, heavy, parent, depth, inv, type;
  
  HLDecomposition(){}
  HLDecomposition(int sz):
    n(sz),pos(0),G(n),
    vid(n,-1),head(n),heavy(n,-1),parent(n),depth(n),inv(n),type(n){}
  
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<int> rs=vector<int>(1,0)) {
    int c=0;
    for(int r:rs){
      dfs(r, -1);
      bfs(r, c++);
    }
  }
  
  using T = tuple<int,int,int,int,int,int>;
  int dfs(int curr,int prev) {
    stack<T> st;
    int result;
    int sub,max_sub,i,next;
  ENTRYPOINT:
    parent[curr] = prev;
    sub=1;
    max_sub=0;
    for(i=0;i<(int)G[curr].size();i++){
      next=G[curr][i];
      if(next!=prev) {
	depth[next]=depth[curr]+1;
	{
	  st.emplace(curr,prev,sub,max_sub,i,next);
	  prev=curr;curr=next;
	  goto ENTRYPOINT;
	}
      RETURNPOINT:
	T t=st.top();st.pop();
	tie(curr,prev,sub,max_sub,i,next)=t;
	
	int sub_next=result;
	sub+=sub_next;
	if(max_sub<sub_next)
	  max_sub=sub_next,heavy[curr]=next;
      }
    }
    while(!st.empty()){
      result=sub;
      goto RETURNPOINT;
    }
    return sub;
  }

  void bfs(int r,int c) {
    int &k=pos;
    queue<int> q({r});
    while(!q.empty()){
      int h=q.front();q.pop();
      for(int i=h;i!=-1;i=heavy[i]) {
	type[i]=c;
	vid[i]=k++;
	inv[vid[i]]=i;
	head[i]=h;
	for(int j:G[i])
	  if(j!=parent[i]&&j!=heavy[i]) q.push(j);
      }
    }
  }
  
  // for_each(vertex)
  // [l,r] <- attention!!
  void for_each(int u, int v, const function<void(int, int)>& f) {
    while(1){
      if (vid[u] > vid[v]) swap(u, v);
      f(max(vid[head[v]], vid[u]), vid[v]);
      if (head[u] != head[v]) v=parent[head[v]];
      else break;
    }
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  void for_each_edge(int u, int v, const function<void(int, int)>& f) {
    while(1){
      if(vid[u] > vid[v]) swap(u,v);
      if(head[u] != head[v]){
	f(vid[head[v]],vid[v]);
        v=parent[head[v]];
      } else{
	if(u!=v) f(vid[u]+1,vid[v]);
	break;
      }
    }
  }

  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=parent[head[v]];
    }
  }

  int distance(int u,int v){
    return depth[u]+depth[v]-2*depth[lca(u,v)];
  }
};
//END CUT HERE


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


struct RMQ{
  int n;
  vector<set<int> > dat;
  RMQ(){}
  RMQ(int n_){init(n_);}
   void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1);
  }
   void update(int k,int a){
    k+=n-1;
    dat[k].insert(a);
    while(k){
      k=(k-1)>>1;
      dat[k].insert(a);
    }
  }
   void remove(int k,int a){
    k+=n-1;
    dat[k].erase(a);
    while(k){
      k=(k-1)>>1;
      dat[k].erase(a);
    }
  }
  int get(int k){
    if(dat[k].empty()) return -1;
    return *--dat[k].end();
  }
  int query(int a,int b){
    int vl=-1,vr=-1;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=max(vl,get((l++)-1));
      if(r&1) vr=max(get((--r)-1),vr);
    }
    return max(vl,vr);
  }
};

signed main(){
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
  RMQ rmq(V);
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
      rmq.update(m[w],w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.belong[s];
      t=big.belong[t];
      int ans=-1;
      hl.for_each(s, t, [&](int l, int r) {
	  ans = max(ans,rmq.query(l, r + 1));
	});
      printf("%d\n",ans);
      if(~ans) rmq.remove(m[ans],ans),num--;
    }
  }
  return 0;
}

/* verified on 2017/10/29
https://yukicoder.me/problems/no/529
*/

