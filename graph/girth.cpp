#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// size of minimum cycle
int girth(vector< vector<int> > G){
  int n=G.size();
  int res=n+1;
  vector<int> dp(n),pr(n);
  for(int s=0;s<n;s++){
    fill(dp.begin(),dp.end(),-1);
    fill(pr.begin(),pr.end(),-1);
    queue<int> que;
    dp[s]=0;
    que.emplace(s);
    while(!que.empty()){
      int v=que.front();que.pop();
      if(res<=dp[v]*2) break;
      for(int u:G[v]){
        if(u==pr[v]) continue;
        if(~dp[u]){
          res=min(res,dp[u]+dp[v]+1);
          continue;
        }
        dp[u]=dp[v]+1;
        pr[u]=v;
        que.emplace(u);
      }
    }
  }
  if(res>n) res=-1;
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE

signed CFR580_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  sort(as.rbegin(),as.rend());

  if(as[0]==0){
    cout<<-1<<endl;
    return 0;
  }

  while(as.back()==0) as.pop_back();
  n=as.size();

  if(n>=200){
    cout<<3<<endl;
    return 0;
  }

  vector< vector<int> > G(n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if((i!=j)&&(as[i]&as[j]))
        G[i].emplace_back(j);

  cout<<girth(G)<<endl;
  return 0;
}
/*
  verified on 2019/08/21
  https://codeforces.com/contest/1205/problem/B
*/

signed main(){
  CFR580_B();
  return 0;
}
