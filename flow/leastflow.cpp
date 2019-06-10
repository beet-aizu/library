#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T,bool directed>
struct Dinic{
  struct edge {
    int to;
    T cap;
    int rev;
    edge(){}
    edge(int to,T cap,int rev):to(to),cap(cap),rev(rev){}
  };

  T INF;
  vector<vector<edge> > G;
  vector<int> level,iter;

  Dinic(){}
  Dinic(int n,T INF):INF(INF),G(n),level(n),iter(n){}

  void add_edge(int from,int to,T cap){
    G[from].emplace_back(to,cap,G[to].size());
    G[to].emplace_back(from,directed?0:cap,G[from].size()-1);
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
    return flow(s,t,INF);
  }
};
//BEGIN CUT HERE
template<typename T>
struct LeastFlow{
  Dinic<T, true> G;
  int X,Y;
  T sum;
  LeastFlow(int n,T INF):G(n+2,INF),X(n),Y(n+1),sum(0){}

  void add_edge(int from,int to,T low,T hgh){
    assert(low<=hgh);
    G.add_edge(from,to,hgh-low);
    G.add_edge(X,to,low);
    G.add_edge(from,Y,low);
    sum+=low;
  }

  T flow(int s,int t){
    T a=G.flow(X,Y);
    T b=G.flow(s,Y);
    T c=G.flow(X,t);
    T d=G.flow(s,t);
    return (b==c&&a+b==sum)?b+d:T(-1);
  }
};
//END CUT HERE

//INSERT ABOVE HERE
signed AOJ_1615(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  while(cin>>n>>m,n){
    vector<int> xs(m),ys(m);
    for(int i=0;i<m;i++) cin>>xs[i]>>ys[i],xs[i]--,ys[i]--;

    for(int d=0;d<=n;d++){
      for(int l=n-d;l>=0;l--){
        int r=l+d;

        LeastFlow<int> G(n+m+2,(int)1e5);
        int S=n+m,T=n+m+1;
        for(int i=0;i<m;i++){
          G.add_edge(S,i,1,1);
          G.add_edge(i,m+ys[i],0,1);
          G.add_edge(i,m+xs[i],0,1);
        }
        for(int i=0;i<n;i++)
          G.add_edge(m+i,T,l,r);

        if(G.flow(S,T)==m){
          cout<<l<<" "<<r<<endl;
          goto END;
        }
      }
    }
  END:
    ;
  }
  return 0;
}
/*
  verified on 2019/06/10
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615&lang=jp
*/

signed main(){
  //AOJ_1615();
  return 0;
}
