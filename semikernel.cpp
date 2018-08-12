#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
// https://link.springer.com/content/pdf/10.1007%2FBFb0066192.pdf
struct SemiKernel{
  int n;
  vector<vector<int> > G,R;
  vector<int> used,dp,S;
  SemiKernel(int n):n(n),G(n),R(n),used(n,0),dp(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }
  
  void dfs(int v){
    if(v==n) return;
    if(used[v]){
      dfs(v+1);
      return;
    }
    used[v]=1;
    for(int u:G[v]) used[u]=1;
    dfs(v+1);
    dp[v]=1;
    for(int u:R[v]) dp[v]&=!dp[u];
    if(dp[v]) S.emplace_back(v);
  }

  vector<int> build(){
    dfs(0);
    reverse(S.begin(),S.end());
    return S;
  }
};

signed CFR503_C(){
  int n,m;
  scanf("%d %d",&n,&m);

  SemiKernel sk(n);
  
  for(int i=0;i<m;i++){
    int a,b;    
    scanf("%d %d",&a,&b);
    a--;b--;
    sk.add_edge(a,b);
  }
  
  auto ans=sk.build();
  printf("%d\n",(int)ans.size());
  for(int i=0;i<(int)ans.size();i++){
    if(i) printf(" ");
    printf("%d",ans[i]+1);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/08/12
  http://codeforces.com/contest/1019/problem/C
*/

signed main(){
  CFR503_C();
  return 0;
}
