// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2687

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../datastructure/rotcev.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  string s;
  cin>>s;

  vector< vector<int> > G(n);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  using ll = long long;
  ll ans=0;
  vector< Rotcev<int> > dp1(n),dp2(n);
  MFP([&](auto dfs,int v,int p)->void{
      int idx=v;
      for(int u:G[v]){
        if(u==p) continue;
        dfs(u,v);
        if(dp1[idx].size()+dp2[idx].size()<
           dp1[u].size()+dp2[u].size()) idx=u;
      }
      auto &dx=dp1[v];
      auto &dy=dp2[v];

      if(idx!=v){
        for(int u:G[v]){
          if(u==p) continue;
          if(u==idx) continue;
          auto &py=dp2[u];
          int sy=py.size();
          if(s[v]=='('){
            for(int i=0;i+1<sy;i++)
              if(i<(int)dp1[idx].size())
                ans+=(ll)dp1[idx][i]*py[i+1];
          }else{
            for(int i=0;i<sy;i++)
              if(i+1<(int)dp1[idx].size())
                ans+=(ll)dp1[idx][i+1]*py[i];
          }
        }
        swap(dx,dp1[idx]);
        swap(dy,dp2[idx]);
      }else{
        dx.assign(1,0);
        dy.assign(1,0);
      }

      for(int u:G[v]){
        if(u==p) continue;
        if(u==idx) continue;
        auto &px=dp1[u];
        auto &py=dp2[u];
        int sx=px.size();
        int sy=py.size();

        if((int)dx.size()<sx){
          Rotcev<int> tmp(dx);
          dx.assign(sx,0);
          for(int j=0;j<(int)tmp.size();j++) dx[j]+=tmp[j];
        }
        for(int j=0;j<sx;j++) dx[j]+=px[j];

        if((int)dy.size()<sy){
          Rotcev<int> tmp(dy);
          dy.assign(sy,0);
          for(int j=0;j<(int)tmp.size();j++) dy[j]+=tmp[j];
        }
        for(int j=0;j<sy;j++) dy[j]+=py[j];
      }

      // top
      if(s[v]=='('){
        if(1<dy.size()) ans+=dy[1];
      }else{
        if(1<dx.size()) ans+=dx[1];
      }

      //lca
      for(int u:G[v]){
        if(u==p) continue;
        if(u==idx) continue;
        auto &px=dp1[u];
        auto &py=dp2[u];
        int sx=px.size();
        int sy=py.size();
        if(s[v]=='('){
          for(int i=0;i<sx;i++){
            if(i+1<(int)dy.size())
              ans+=(ll)px[i]*dy[i+1];
            if(i+1<sy)
              ans-=(ll)px[i]*py[i+1];
          }
        }else{
          for(int i=0;i+1<sx;i++){
            if(i<(int)dy.size())
              ans+=(ll)px[i+1]*dy[i];
            if(i<sy)
              ans-=(ll)px[i+1]*py[i];
          }
        }
      }

      for(int u:G[v]){
        if(u==p) continue;
        dp1[u].clear();
        dp2[u].clear();
      }

      if(dx.empty()) dx.assign(1,0);
      if(dy.empty()) dy.assign(1,0);
      dx[0]+=1;
      dy[0]+=1;

      if(s[v]=='('){
        dx.emplace_front(0);
        dy.pop_front();
      }else{
        dx.pop_front();
        dy.emplace_front(0);
      }
    })(0,-1);

  cout<<ans<<endl;
  return 0;
}
