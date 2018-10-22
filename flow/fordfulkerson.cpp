#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Fordfulkerson{
  const int INF = 1 << 28;
  struct edge{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  int n;
  vector<vector<edge> > G;
  vector<int> used;
  
  Fordfulkerson(){}
  Fordfulkerson(int sz):n(sz),G(n),used(n){}
  
  void add_edge(int from,int to,int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    // undirected
    //G[to].push_back(edge(from,cap,G[from].size()-1));
    // directed
    G[to].push_back(edge(from,0,G[from].size()-1));
  }
 
  int dfs(int v,int t,int f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0 ){
        int d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      } 
    }
    return 0;
  }
 
  int flow(int s,int t,int lim){
    int fl=0;
    for(;;){
      fill(used.begin(),used.end(),0);
      int f=dfs(s,t,lim);
      if(f==0) return fl;
      fl+=f;
      lim-=f;
    }
  }

  int flow(int s,int t){
    return flow(s,t,INF);
  }
  
};
//END CUT HERE

signed main(){
  int V,E;
  cin>>V>>E;
  Fordfulkerson flow(V);
  for(int i=0;i<E;i++){
    int u,v,c;
    cin>>u>>v>>c;
    flow.add_edge(u,v,c);
  }
  cout<<flow.flow(0,V-1)<<endl;
  return 0;
}

/*
  verified on 2018/01/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
*/
