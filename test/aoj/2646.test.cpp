#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2646"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/fixpoint.cpp"
#include "../../math/convertbase.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,m;
  cin>>n>>m;

  m++;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++) cin>>as[i];
  for(int i=1;i<m;i++) cin>>bs[i];

  vector<ll> hs;
  MFP([&](auto dfs,int l,int r)->void{
        int x=lower_bound(as.begin(),as.end(),r)-as.begin();
        if(as[x-1]<=l&&r<=as[x]) return;
        hs.emplace_back(((ll)l<<31)|r);
        int m=(l+r)>>1;
        dfs(l,m);
        dfs(m,r);
      })(0,(1<<n));

  sort(hs.begin(),hs.end());
  hs.erase(unique(hs.begin(),hs.end()),hs.end());
  unordered_map<ll, int> idx;
  for(int i=0;i<(int)hs.size();i++) idx[hs[i]]=i;

  vector<vector<int> > dp(n+1,vector<int>(hs.size(),-1));

  int ans=(1<<n)-
    MFP([&](auto dfs,int l,int r,int d,int k)->int{
          int x=lower_bound(as.begin(),as.end(),r)-as.begin();
          if(as[x-1]<=l&&r<=as[x]){
            int v=bs[x],tmp=0;
            tmp+=(k==v);
            tmp+=(r-l)>>(n-v+1);
            return tmp;
          }

          if(~dp[k][idx[((ll)l<<31)|r]]) return dp[k][idx[((ll)l<<31)|r]];
          int &res=(dp[k][idx[((ll)l<<31)|r]]=0);

          int m=(l+r)>>1;
          res=max(res,dfs(l,m,d+1,d)+dfs(m,r,d+1,k));
          res=max(res,dfs(l,m,d+1,k)+dfs(m,r,d+1,d));
          return res;
        })(0,1<<n,1,0);

  cout<<ans<<endl;
  return 0;
}
