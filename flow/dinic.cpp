#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T,bool directed>
struct Dinic{
  struct edge {
    int to;
    T cap;
    int rev;
    edge(){}
    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
  };

  vector<vector<edge> > G;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int n):G(n),level(n),iter(n){}

  int add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
    return G[to].back().rev;
  }

  void bfs(int s){
    fill(level.begin(),level.end(),-1);
    queue<int> que;
    level[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      for(int i=0;i<(int)G[v].size();i++){
        edge &e=G[v][i];
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[v]+1;
          que.emplace(e.to);
        }
      }
    }
  }

  T dfs(int v,int t,T f){
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++){
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to]){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d==0) continue;
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
    return 0;
  }

  T flow(int s,int t,T lim){
    T fl=0;
    while(1){
      bfs(s);
      if(level[t]<0||lim==0) break;
      fill(iter.begin(),iter.end(),0);

      while(1){
        T f=dfs(s,t,lim);
        if(f==0) break;
        fl+=f;
        lim-=f;
      }
    }
    return fl;
  }

  T flow(int s,int t){
    return flow(s,t,numeric_limits<T>::max()/2);
  }

  T cut(int s,int t,int x,int a){
    static_assert(directed, "must be directed");
    auto &e=G[x][a];
    int y=e.to;
    T ce=e.cap,cr=G[y][e.rev].cap;
    if(cr==0) return 0;
    e.cap=G[y][e.rev].cap=0;
    T cap=cr-flow(x,y,cr);
    if(x!=s&&cap!=0) flow(x,s,cap);
    if(t!=y&&cap!=0) flow(t,y,cap);
    e.cap=ce+cr;
    return cap;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed GRL_6_A(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int V,E;
  cin>>V>>E;
  Dinic<int, true> G(V);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    G.add_edge(u,v,c);
  }
  cout<<G.flow(0,V-1)<<endl;
  return 0;
}
/*
  verified on 2019/06/10
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/


signed SPOJ_FASTFLOW(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,m;
  cin>>n>>m;
  Dinic<Int, false> G(n);
  for(Int i=0;i<m;i++){
    Int a,b,c;
    cin>>a>>b>>c;
    if(a==b) continue;
    a--;b--;
    G.add_edge(a,b,c);
  }
  cout<<G.flow(0,n-1)<<endl;
  return 0;
}
/*
  verified on 2019/06/10
  https://www.spoj.com/problems/FASTFLOW/
*/

signed SPOJ_BANKROB(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  const int INF=5050;
  Dinic<int, true> G(n*2);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G.add_edge(n+x,y,INF);
    G.add_edge(n+y,x,INF);
  }

  for(int i=0;i<n;i++)
    G.add_edge(i,n+i,1);

  cout<<G.flow(n+s,t)<<endl;
  return 0;
}
/*
  verified on 2019/06/10
  https://www.spoj.com/problems/BANKROB/
*/

signed main(){
  //GRL_6_A();
  //SPOJ_FASTFLOW();
  //SPOJ_BANKROB();
  return 0;
}
#endif
