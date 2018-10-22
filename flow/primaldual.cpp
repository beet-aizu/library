#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct PrimalDual{
  const int INF = 1<<28;
  typedef pair<int,int> P;
  struct edge{
    int to,cap,cost,rev;
    edge(){}
    edge(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
  };

  int n;
  vector<vector<edge> > G;
  vector<int> h,dist,prevv,preve;

  PrimalDual(){}
  PrimalDual(int sz):n(sz),G(sz),h(sz),dist(sz),prevv(sz),preve(sz){}
  
  void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,G[to].size()));
    G[to].push_back(edge(from,0,-cost,G[from].size()-1));
  }

  int flow(int s,int t,int f){
    int res=0;
    fill(h.begin(),h.end(),0);
    while(f>0){
      priority_queue<P,vector<P>,greater<P> > que;
      fill(dist.begin(),dist.end(),INF);
      dist[s]=0;
      que.push(P(0,s));
      while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(dist[v]<p.first) continue;
        for(int i=0;i<(int)G[v].size();i++){
          edge &e=G[v][i];
          if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
            dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
            prevv[e.to]=v;
            preve[e.to]=i;
            que.push(P(dist[e.to],e.to));
          }
        }
      }
      if(dist[t]==INF){
        return -1;
      }
      for(int v=0;v<n;v++) h[v]+=dist[v];

      int d=f;
      for(int v=t;v!=s;v=prevv[v]){
        d=min(d,G[prevv[v]][preve[v]].cap);
      }
      f-=d;
      res+=d*h[t];
      for(int v=t;v!=s;v=prevv[v]){
        edge &e=G[prevv[v]][preve[v]];
        e.cap-=d;
        G[v][e.rev].cap+=d;
      }
    }
    return res;
  }
};
//END CUT HERE

int main(){
  int v,e,f;
  cin>>v>>e>>f;
  PrimalDual pd(v);
  for(int i=0;i<e;i++){
    int u,v,c,d;
    cin>>u>>v>>c>>d;
    pd.add_edge(u,v,c,d);
  }
  cout<<pd.flow(0,v-1,f)<<endl;
  return 0;
}
/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp
*/
