#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2405"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/nicetree.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  while(cin>>n>>m,n){
    NiceTree G(n);
    using P = pair<int, int>;
    set<P> es;
    for(int i=0;i<n;i++){
      int j=(i+1)%n;
      G.add_edge(i,j);
      es.emplace(i,j);
      es.emplace(j,i);
    }
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      G.add_edge(a,b);
      es.emplace(a,b);
      es.emplace(b,a);
    }
    if(n&1){
      cout<<0<<endl;
      continue;
    }
    G.build();
    auto &T=G.T;
    auto &buff=G.buff;

    using M = Mint<int, 1000003>;
    vector<vector<M>> dps(T.size());

    auto base=
      [&](int v){
        const auto &bag=T[v].bag;
        auto &dp=dps[v];
        dp.assign(1<<bag.size(),0);
      };

    auto leaf=
      [&](int v){
        base(v);
        auto &dp=dps[v];
        dp[0]=M(1);
      };

    auto join=
      [&](int v){
        base(v);
        const auto &chd=T[v].child;
        auto &dp=dps[v];

        for(int i=0;i<(int)dp.size();i++)
          for(int j=0;j<(int)dp.size();j++)
            if((i&j)==0) dp[i|j]+=dps[chd[0]][i]*dps[chd[1]][j];
      };

    auto introduce=
      [&](int v,int){
        base(v);
        const auto &chd=T[v].child;

        const auto &chd_bag=T[chd[0]].bag;
        const auto &pr=dps[chd[0]];

        auto &dp=dps[v];
        for(int i=0;i<(int)pr.size();i++){
          int bit=0;
          for(int j=0;j<(int)chd_bag.size();j++)
            if((i>>j)&1) bit|=buff[chd_bag[j]];
          dp[bit]=pr[i];
        }
      };

    auto forget=
      [&](int v,int rmv){
        base(v);
        const auto &bag=T[v].bag;
        const auto &chd=T[v].child;

        const auto &chd_bag=T[chd[0]].bag;
        const auto &pr=dps[chd[0]];

        auto &dp=dps[v];
        for(int i=0;i<(int)pr.size();i++){
          int bit=0,used=0;
          for(int j=0;j<(int)chd_bag.size();j++){
            if((~i>>j)&1) continue;
            if(rmv==chd_bag[j]) used=1;
            if(rmv!=chd_bag[j]) bit|=buff[chd_bag[j]];
          }
          if(!used){
            for(int j=0;j<(int)bag.size();j++){
              if((bit>>j)&1) continue;
              if(es.count(P(bag[j],rmv))) dp[bit|(1<<j)]+=pr[i];
            }
          }else{
            dp[bit]+=pr[i];
          }
        }
      };

    G.dfs(0,leaf,join,introduce,forget);

    cout<<dps[0][1]<<endl;
  }
  return 0;
}
