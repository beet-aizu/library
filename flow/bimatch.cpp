#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct BiMatch{
  int n;
  vector<vector<int> > G;
  vector<int> match,used;
  
  BiMatch(){}
  BiMatch(int sz):n(sz),G(sz),match(sz),used(sz){}
  
  void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
  }

  bool dfs(int v){
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++){
      int u=G[v][i],w=match[u];
      if(w<0||(!used[w]&&dfs(w))){
        match[v]=u;
        match[u]=v;
        return true;
      }
    }
    return false;
  }

  int build(){
    int res=0;
    fill(match.begin(),match.end(),-1);
    for(int v=0;v<n;v++){
      if(match[v]<0){
        fill(used.begin(),used.end(),0);
        if(dfs(v)){
          res++;
        }
      }
    }
    return res;
  }
};
//END CUT HERE

signed main(){
  int X,Y,E;
  cin>>X>>Y>>E;
  BiMatch bm(X+Y);
  for(int i=0;i<E;i++){
    int x,y;
    cin>>x>>y;
    bm.add_edge(x,X+y);
  }
  cout<<bm.build()<<endl;
  return 0;
}
/*
  verified on 2017/10/29
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp
*/
