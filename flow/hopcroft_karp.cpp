#include<bits/stdc++.h>
using namespace std;
using Int = long long;
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

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}

//INSERT ABOVE HERE
signed AOJ_GRL_7A(){
  cin.tie(0);
  ios::sync_with_stdio(0);
    
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
  verified on 2019/05/26
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp
*/

signed SPOJ_MATCHING(){  
  cin.tie(0);
  ios::sync_with_stdio(0);
    
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
  verified on 2019/05/26
  http://www.spoj.com/problems/MATCHING/
*/

signed chokudai_S002_K(){
  cin.tie(0);
  ios::sync_with_stdio(0);
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
  verified on 2019/05/26
  https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k
*/


signed main(){
  //AOJ_GRL_7A();
  //SPOJ_MATCHING();
  //chokudai_S002_K();
  return 0;
}
