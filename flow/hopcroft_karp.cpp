#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct BiMatch{
  int L,R;
  vector<vector<int> > G;
  vector<int> match,level;
  
  BiMatch(){}
  BiMatch(int L,int R):L(L),R(R),G(L+R),match(L+R,-1),level(L){}
  
  void add_edge(int u,int v){
    G[u].push_back(v+L);
    G[v+L].push_back(u);
  }
  
  bool bfs(){
    queue<int> q;
    for(int i=0;i<L;i++){
      level[i]=-1;
      if(match[i]<0){
        level[i]=0;
        q.emplace(i);
      }
    }
    while(!q.empty()){
      int v=q.front();q.pop();
      for(int u:G[v]){
        int w=match[u];
        if(w<0) return true;
        if(level[w]<0){
          level[w]=level[v]+1;
          q.emplace(w);
        }
      }
    }
    return false;
  }

  bool dfs(int v){
    for(int u:G[v]){
      int w=match[u];
      if(w<0||(level[w]>level[v]&&dfs(w))){
        match[v]=u;
        match[u]=v;
        return true;
      }
    }
    return false;
  }
  
  int build(){
    int res=0;
    while(bfs())
      for(int i=0;i<L;i++)
        if(match[i]<0&&dfs(i))
          res++;
    return res;
  }
  
};
//END CUT HERE

signed AOJ_GRL_7A(){
  int X,Y,E;
  cin>>X>>Y>>E;
  BiMatch bm(X,Y);
  for(int i=0;i<E;i++){
    int x,y;
    cin>>x>>y;
    bm.add_edge(x,y);
  }
  cout<<bm.build()<<endl;
  return 0;
}
/*
  verified on 2018/02/28
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp
*/

signed SPOJ_MATCHING(){
  int X,Y,E;
  cin>>X>>Y>>E;
  BiMatch bm(X,Y);
  for(int i=0;i<E;i++){
    int x,y;
    cin>>x>>y;
    bm.add_edge(--x,--y);
  }
  cout<<bm.build()<<endl;
  return 0;
}
/*
  verified on 2018/02/28
  http://www.spoj.com/problems/MATCHING/
*/

signed main(){
  //AOJ_GRL_7A();
  SPOJ_MATCHING();
  return 0;
}
