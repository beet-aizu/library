#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T>
struct VoronoiMST{
  int n;
  using E = pair<int, T>;
  using P = pair<T, int>;
  vector<vector<E> > G;
  VoronoiMST(vector<T> &x){
    n=x.size();
    G.assign(n<<1,vector<E>());
    for(int i=0;i<n;i++) G[i].emplace_back(n+i,x[i]);
  }
  void add_edge(int u,int v,T c){
    G[u+n].emplace_back(v+n,c);
    G[v+n].emplace_back(u+n,c);
  }  
  vector<vector<E> > build(){
    priority_queue<P, vector<P>, greater<P> > pq;
    const T INF = numeric_limits<T>::max();
    vector<T> dist(n<<1,INF);
    vector<int> from(n<<1,-1);
    for(int i=0;i<n;i++){
      dist[i]=0;from[i]=i;
      pq.emplace(dist[i],i);
    }
    while(!pq.empty()){
      T d;
      int v;
      tie(d,v)=pq.top();pq.pop();
      if(dist[v]<d) continue;
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(dist[u]<=dist[v]+c) continue;
        dist[u]=dist[v]+c;
        from[u]=from[v];
        pq.emplace(dist[u],u);
      }
    }
    vector<vector<E> > H(n);
    for(int v=0;v<(n<<1);v++){
      for(E e:G[v]){
        int u=e.first;
        T c=e.second;
        if(from[v]==from[u]) continue;
        int x=from[v],y=from[u];
        T z=dist[v]+dist[u]+c;
        H[x].emplace_back(y,z);
        H[y].emplace_back(x,z);
      }
    }
    return H;
  }
};
//END CUT HERE



template<typename T>
struct Kruskal{
  
  struct edge{
    int from,to;
    T cost;
    int used;
    edge(){}
    edge(int from,int to,T cost):
      from(from),to(to),cost(cost),used(0){}
    bool operator<(const edge& e) const{
      return cost<e.cost;
    }
  };

  int n;
  vector<int> p,r;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(int n):n(n){}

  void init(int n){
    r.assign(n,1);
    p.resize(n);
    iota(p.begin(),p.end(),0);
  }
  
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }

  bool same(int x,int y){
    return find(x)==find(y);
  }

  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }

  void add_edge(int u,int v,T c){
    edges.emplace_back(u,v,c);
  }
  
  T build(){
    sort(edges.begin(),edges.end());
    init(n);
    T res=0;
    for(auto &e:edges){
      if(!same(e.from,e.to)){
        res+=e.cost;
        unite(e.from,e.to);
        e.used=1;
      }
    }
    return res;
  }
};


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE

signed CF17FINAL_J(){
  int n;
  cin>>n;
  vector<Int> x(n);
  for(int i=0;i<n;i++) cin>>x[i];
  VoronoiMST<Int> vo(x);
  for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    vo.add_edge(a,b,c);
  }
  auto G=vo.build();
  Kruskal<Int> ks(n);
  for(int v=0;v<n;v++){
    for(auto e:G[v]){
      int u=e.first;
      Int c=e.second;
      if(v<u) ks.add_edge(v,u,c);
    }
  }
  cout<<ks.build()<<endl;
  return 0;
}
/*
  verified on 2019/01/16
  https://atcoder.jp/contests/cf17-final/tasks/cf17_final_j
*/

signed KEYENCE2019_E(){
  int n,d;
  cin>>n>>d;
  vector<Int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  VoronoiMST<Int> vo(a);
  for(int i=1;i<n;i++){
    vo.add_edge(i-1,i,d);
  }
  auto G=vo.build();
  Kruskal<Int> ks(n);
  for(int v=0;v<n;v++){
    for(auto e:G[v]){
      int u=e.first;
      Int c=e.second;
      if(v<u) ks.add_edge(v,u,c);
    }
  }
  cout<<ks.build()<<endl;
  return 0;
}
/*
  verified on 2019/01/16
  https://atcoder.jp/contests/keyence2019/tasks/keyence2019_e
*/

signed main(){
  //CF17FINAL_J();
  //KEYENCE2019_E();
  return 0;
}
