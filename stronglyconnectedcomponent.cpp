#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct SCC{
  int n;
  vector<vector<int> > G,rG,T,C;
  vector<int> vs,used,belong;
  SCC(){}
  SCC(int sz):n(sz),G(sz),rG(sz),used(sz),belong(sz){}
  
  void add_edge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  
  void dfs(int v){
    used[v]=1;
    for(int i=0;i<(int)G[v].size();i++){
      if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  
  void rdfs(int v,int k){
    used[v]=1;
    belong[v]=k;
    C[k].push_back(v);
    for(int i=0;i<(int)rG[v].size();i++){
      if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
  }
  
  int build(){
    fill(used.begin(),used.end(),0);
    vs.clear();
    for(int v=0;v<n;v++){
      if(!used[v]) dfs(v);
    }
    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
      if(!used[vs[i]]){
	T.push_back(vector<int>());
	C.push_back(vector<int>());
	rdfs(vs[i],k++);
      }
    }
    for(int i=0;i<n;i++)
      for(int u:G[i])
	if(belong[i]!=belong[u])
	  T[belong[i]].push_back(belong[u]);
    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
};
//END CUT HERE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  vector<vector<int> > G(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    G[i].resize(k);
    for(int j=0;j<k;j++){
      cin>>G[i][j];
      G[i][j]--;
    }
  }
  SCC scc(m*2);
  auto add_edge=[&](vector<int> &a,vector<int> &b){
    int x=min(a.size(),b.size());
    int i;
    for(i=0;i<x;i++){
      if(a[i]==b[i]) continue;
      if(a[i]<b[i]){
	scc.add_edge(m+b[i],m+a[i]);
	scc.add_edge(a[i],b[i]);
      }else{
	scc.add_edge(a[i],m+a[i]);
	scc.add_edge(m+b[i],b[i]);
      }
      break;
    }
    if(i==x){
      if(a.size()>b.size()){
	cout<<"No"<<endl;
	exit(0);
      }
    }
  };
  for(int i=0;i<n-1;i++)
    add_edge(G[i],G[i+1]);
  
  scc.build();
  auto belong=scc.belong;
  for(int i=0;i<m;i++){
    //cout<<belong[i]<<" "<<belong[m+i]<<endl;
    if(belong[i]==belong[m+i]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  
  vector<int> ans;
  for(int i=0;i<m;i++)
    if(belong[i]<belong[m+i]) ans.push_back(i);
  
  cout<<ans.size()<<endl;
  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}
/*
verified 2017/10/29
http://codeforces.com/contest/875/problem/C
*/
