#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct SCC{
  int n;
  vector<vector<int> > G,rG,T,C;
  vector<int> vs,used,blg;
  SCC(){}
  SCC(int n):n(n),G(n),rG(n),used(n),blg(n){}
  
  void add_edge(int from,int to){
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
  }
  
  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }
  
  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    C[k].emplace_back(v);
    for(int u:rG[v])
      if(!used[u]) rdfs(u,k);
  }
  
  int build(){
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);
    
    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
      if(!used[vs[i]]){
        T.emplace_back();
        C.emplace_back();
        rdfs(vs[i],k++);
      }
    }
    for(int v=0;v<n;v++)
      for(int u:G[v])
        if(blg[v]!=blg[u])
          T[blg[v]].push_back(blg[u]);
    
    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
};
//END CUT HERE

signed main(){
  int n,m;
  scanf("%d %d",&n,&m);
  
  vector<vector<int> > G(n);
  for(int i=0;i<n;i++){
    int k;
    scanf("%d",&k);
    G[i].assign(k,0);
    for(int &v:G[i]){
      scanf("%d",&v);
      v--;
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
                      puts("No");
                      exit(0);
                    }
                  }
                };
  
  for(int i=0;i<n-1;i++)
    add_edge(G[i],G[i+1]);
  
  scc.build();
  auto blg=scc.blg;
  for(int i=0;i<m;i++){
    if(blg[i]==blg[m+i]){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  
  vector<int> ans;
  for(int i=0;i<m;i++)
    if(blg[i]<blg[m+i]) ans.emplace_back(i);

  printf("%d\n",(int)ans.size());
  for(int i=0;i<(int)ans.size();i++){
    if(i) printf(" ");
    printf("%d",ans[i]+1);
  }  
  puts("");

  return 0;
}
/*
  verified 2017/10/29
  http://codeforces.com/contest/875/problem/C
*/
