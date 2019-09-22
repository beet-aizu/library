#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2790"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../tree/centroid.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> gs(n);
  for(int i=0;i<n;i++) cin>>gs[i];
  using P = pair<int, int>;
  vector< vector<P> > G(n);
  Centroid C(n);
  for(int i=1;i<n;i++){
    int a,b,d;
    cin>>a>>b>>d;
    a--;b--;
    G[a].emplace_back(b,d);
    G[b].emplace_back(a,d);
    C.add_edge(a,b);
  }

  int ans=1;
  queue<int> que;
  que.emplace(0);
  while(!que.empty()){
    int rt=C.build(que.front())[0];
    que.pop();
    for(int uku=0;uku<2;uku++){
      int len=0;
      MFP([&](auto dfs,int v,int p,int d)->void{
            chmax(len,d);
            for(auto e:G[v]){
              int u=e.first;
              if(u==p||!C.alive(u)) continue;
              dfs(u,v,d+1);
            }
          })(rt,-1,1);

      const int INF = 1e9;
      vector<int> dat(len+1,INF);
      dat[0]=-INF;
      for(auto e:G[rt]){
        int ch=e.first,cost=e.second;
        if(!C.alive(ch)) continue;
        // calc path
        MFP([&](auto dfs,int v,int p,int d,int sum,int val)->void{
              if(val>=0) chmax(ans,d+1);
              int k=--upper_bound(dat.begin(),dat.end(),val)-dat.begin();
              if(k) chmax(ans,k+1+d);
              for(auto e:G[v]){
                int u=e.first,c=e.second;
                if(u==p||!C.alive(u)) continue;
                dfs(u,v,d+1,sum-c+gs[u],min(val,sum-c));
              }
            })(ch,rt,1,gs[rt]-cost+gs[ch],gs[rt]-cost);

        // update dat
        MFP([&](auto dfs,int v,int p,int d,int sum,int val)->void{
              if(val>=0){
                chmin(dat[d],-sum);
                chmax(ans,d+1);
              }
              for(auto e:G[v]){
                int u=e.first,c=e.second;
                if(u==p||!C.alive(u)) continue;
                dfs(u,v,d+1,sum+(gs[u]-c),(val>0?0:val)+(gs[u]-c));
              }
              chmin(dat[d],dat[d+1]);
            })(ch,rt,1,gs[ch]-cost,gs[ch]-cost);
      }

      reverse(G[rt].begin(),G[rt].end());
    }
    C.disable(rt);
    for(int u:C.G[rt])
      if(C.alive(u)) que.emplace(u);
  }
  cout<<ans<<endl;
  return 0;
}
