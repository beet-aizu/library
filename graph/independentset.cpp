#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct IndependentSet{
  int n;
  vector<int> deg,used,dead,pre,ans;
  vector<vector<int> > G;

  IndependentSet(int n):
    n(n),deg(n),used(n,0),dead(n,0),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int res,cnt,alive;
  void dfs(){
    if(cnt+alive<=res) return;

    int v=-1;
    for(int i=0;i<n;i++){
      if(used[i]||dead[i]) continue;
      if(deg[i]<=1){
        v=i;
        break;
      }
      if(v<0||deg[v]<deg[i]) v=i;
    }
    if(v<0) return;

    if(deg[v]!=1){
      dead[v]=1;
      alive--;
      for(int u:G[v]) deg[u]--;

      dfs();

      dead[v]=0;
      alive++;
      for(int u:G[v]) deg[u]++;
    }
    {
      used[v]=1;
      alive--;
      for(int u:G[v])
        if(0==dead[u]++) alive-=!used[u];
      cnt++;
      if(res<cnt) pre=used;
      res=max(res,cnt);

      dfs();

      used[v]=0;
      alive++;
      for(int u:G[v])
        if(--dead[u]==0) alive+=!used[u];
      cnt--;
    }
  }

  int build(){
    for(int i=0;i<n;i++) deg[i]=G[i].size();
    res=0,cnt=0,alive=n;
    dfs();
    for(int i=0;i<n;i++)
      if(pre[i]) ans.emplace_back(i);
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
