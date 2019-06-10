#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE

template<typename T,bool directed>
struct Fordfulkerson{
  struct edge{
    int to,cap,rev;
    edge(){}
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
  };

  vector<vector<edge> > G;
  vector<int> used;

  Fordfulkerson(){}
  Fordfulkerson(int n):G(n),used(n){}

  void add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
  }

  T dfs(int v,int t,T f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to]&&e.cap>0){
        T d=dfs(e.to,t,min(f,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }

  int flow(int s,int t,T lim){
    T fl=0;
    while(1){
      fill(used.begin(),used.end(),0);
      T f=dfs(s,t,lim);
      if(f==0) break;
      fl+=f;
      lim-=f;
    }
    return fl;
  }

  int flow(int s,int t){
    return flow(s,t,numeric_limits<T>::max()/2);
  }

};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int V,E;
  cin>>V>>E;
  Fordfulkerson<int, true> G(V);
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
