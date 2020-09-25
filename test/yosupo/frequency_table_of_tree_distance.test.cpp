// verification-helper: PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/centroid.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../convolution/fastfouriertransform.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  Centroid G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }

  queue<int> que;
  que.emplace(G.build(0)[0]);

  using ll = long long;
  vector<ll> ans(n,0);
  while(!que.empty()){
    int r=que.front();que.pop();

    vector<ll> cnt;
    cnt.emplace_back(1);
    for(int c:G[r]){
      if(!G.alive(c)) continue;
      vector<ll> num;
      MFP([&](auto dfs,int v,int p,int d)->void{
        while((int)cnt.size()<=d)
          cnt.emplace_back(0);
        while((int)num.size()<=d)
          num.emplace_back(0);
        cnt[d]++;
        num[d]++;
        for(int u:G[v]){
          if(u==p or !G.alive(u)) continue;
          dfs(u,v,d+1);
        }
      })(c,r,1);
      auto ns=FFT::multiply(num,num);
      for(int i=0;i<(int)min(ans.size(),ns.size());i++) ans[i]-=ns[i];
    }
    auto cs=FFT::multiply(cnt,cnt);
    for(int i=0;i<(int)min(ans.size(),cs.size());i++) ans[i]+=cs[i];

    G.disable(r);
    for(int c:G[r])
      if(G.alive(c))
        que.emplace(G.build(c)[0]);
  }

  for(int i=1;i<n;i++){
    if(i!=1) cout<<' ';
    cout<<ans[i]/2;
  }
  cout<<endl;
  return 0;
}
