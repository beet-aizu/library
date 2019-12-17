#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct BiMatch{
  int L,R;
  vector<vector<int> > G;
  vector<int> match,level;

  BiMatch(){}
  BiMatch(int L,int R):L(L),R(R),G(L+R),match(L+R,-1),level(L+R){}

  void add_edge(int u,int v){
    G[u].emplace_back(v+L);
    G[v+L].emplace_back(u);
  }

  bool bfs(){
    fill(level.begin(),level.end(),-1);
    queue<int> q;
    for(int i=0;i<L;i++){
      if(match[i]<0){
        level[i]=0;
        q.emplace(i);
      }
    }
    bool found=false;
    while(!q.empty()){
      int v=q.front();q.pop();
      for(int u:G[v]){
        if(~level[u]) continue;
        level[u]=level[v]+1;
        int w=match[u];
        if(w==-1){
          found=true;
          continue;
        }
        if(~level[w]) continue;
        level[w]=level[u]+1;
        q.emplace(w);
      }
    }
    return found;
  }

  bool dfs(int v){
    for(int u:G[v]){
      if(level[v]+1!=level[u]) continue;
      level[u]=-1;
      int w=match[u];
      if(w<0||dfs(w)){
        match[v]=u;
        match[u]=v;
        level[v]=-1;
        return true;
      }
    }
    level[v]=-1;
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
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/compress.cpp"
#undef call_from_test

//INSERT ABOVE HERE
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
  verified on 2019/12/17
  http://www.spoj.com/problems/MATCHING/
*/

signed chokudai_S002_K(){
  int n;
  cin>>n;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i]>>bs[i];

  vector<int> vs;
  for(int x:as) vs.emplace_back(x);
  for(int x:bs) vs.emplace_back(x);
  vs=compress(vs);
  auto dc=dict(vs);

  BiMatch bm(n,dc.size());
  for(int i=0;i<n;i++){
    bm.add_edge(i,dc[as[i]]);
    bm.add_edge(i,dc[bs[i]]);
  }

  cout<<bm.build()<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k
*/


signed main(){
  //SPOJ_MATCHING();
  //chokudai_S002_K();
  return 0;
}
#endif
