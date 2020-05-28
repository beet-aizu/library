#define PROBLEM "https://yukicoder.me/problems/3912"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/centroid.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../tools/chminmax.cpp"
#include "../../segtree/basic/dual.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  Centroid G(n);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b);
  }

  vector<int> xs(q),ys(q),zs(q);
  for(int i=0;i<q;i++) cin>>xs[i]>>ys[i]>>zs[i];

  vector<vector<int>> H(n);
  for(int i=0;i<q;i++){
    xs[i]--;
    H[xs[i]].emplace_back(i);
  }

  vector<int> dep(n);

  using ll = long long;
  vector<ll> ans(q,0);
  auto h=[&](ll a,ll b){return a+b;};
  SegmentTree<ll> seg(h,0);
  seg.init(n*2);

  queue<int> que;
  que.emplace(G.build(0)[0]);
  while(!que.empty()){
    int r=que.front();que.pop();
    dep[r]=0;

    // add for all
    {
      int len=1;
      vector<int> qs(H[r]);
      for(int t:G[r]){
        if(!G.alive(t)) continue;
        MFP([&](auto dfs,int v,int p,int d)->void{
          dep[v]=d;
          chmax(len,d+1);
          for(int i:H[v]) qs.emplace_back(i);
          for(int u:G[v]){
            if(u==p) continue;
            if(!G.alive(u)) continue;
            dfs(u,v,d+1);
          }
        })(t,r,1);
      }
      seg.init(len);
      sort(qs.begin(),qs.end());
      for(int i:qs){
        ans[i]+=seg.get_val(dep[xs[i]]);
        if(ys[i]>=dep[xs[i]])
          seg.update(0,min(len,ys[i]-dep[xs[i]]+1),zs[i]);
      }
    }

    // sub for subtree
    {
      for(int t:G[r]){
        if(!G.alive(t)) continue;
        int len=1;
        vector<int> qs;
        MFP([&](auto dfs,int v,int p,int d)->void{
          dep[v]=d;
          chmax(len,d+1);
          for(int i:H[v]) qs.emplace_back(i);
          for(int u:G[v]){
            if(u==p) continue;
            if(!G.alive(u)) continue;
            dfs(u,v,d+1);
          }
        })(t,r,1);
        seg.init(len);
        sort(qs.begin(),qs.end());
        for(int i:qs){
          ans[i]-=seg.get_val(dep[xs[i]]);
          if(ys[i]>=dep[xs[i]])
            seg.update(0,min(len,ys[i]-dep[xs[i]]+1),zs[i]);
        }
      }
    }

    G.disable(r);
    for(int t:G[r])
      if(G.alive(t))
        que.emplace(G.build(t)[0]);
  }

  for(auto a:ans) cout<<a<<"\n";
  cout<<flush;
  return 0;
}
