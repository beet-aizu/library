#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct TopologicalSort{
  int n;
  vector<set<int> > G;
  vector<bool> used;
  vector<int> indeg,p;
  
  TopologicalSort(){}
  TopologicalSort(int sz):n(sz),G(n),used(n),indeg(n),p(0){}

  void add_edge(int s,int t){
    G[s].insert(t);
  }
  
  void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s]=1;
    while(!q.empty()){
      int v=q.front();q.pop();
      p.push_back(v);
      for(int u:G[v]){
        indeg[u]--;
        if(indeg[u]==0&&!used[u]){
          used[u]=1;
          q.push(u);
        }
      }
    }
  }
  
  vector<int>  build(){
    fill(used.begin(),used.end(),0);
    fill(indeg.begin(),indeg.end(),0);
    
    for(int i=0;i<n;i++)
      for(int v:G[i]) indeg[v]++;
    
    for(int i=0;i<n;i++)
      if(indeg[i]==0&&!used[i]) bfs(i);
    
    return p;
  }
};
//END CUT HERE

signed main(){
  int n,e;
  cin>>n>>e;
  TopologicalSort ts(n);
  for(int i=0;i<e;i++){
    int s,t;
    cin>>s>>t;
    ts.add_edge(s,t);
  }
  auto p=ts.build();
  for(int i:p) cout<<i<<endl;
  return 0;
}

/*
  verified on 2017/12/09
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
*/
