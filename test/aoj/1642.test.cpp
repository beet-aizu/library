// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1642

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../tools/chminmax.cpp"
#include "../../math/enumerate_primes.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  auto ps=enumerate_primes(4e7);

  ll n;
  while(cin>>n,n){
    vector<ll> qs,vs;
    {
      ll t=n;
      for(auto p:ps){
        if(t<p) break;
        if(t%p) continue;
        qs.emplace_back(p);
        vs.emplace_back(0);
        while(t%p==0) t/=p,vs.back()++;
      }
      if(t!=1){
        qs.emplace_back(t);
        vs.emplace_back(1);
      }
      reverse(qs.begin(),qs.end());
      reverse(vs.begin(),vs.end());
    }

    int m=qs.size();
    ll ans=n+2;
    MFP([&](auto dfs,int t,ll x,ll y,ll z)->void{
      if(x+y+z>=ans) return;
      if(t==m){
        assert(x*y*z==n);
        chmin(ans,x+y+z);
        return;
      }
      int s=vs[t];
      vector<ll> po(s+1,1);
      for(int i=0;i<s;i++) po[i+1]=po[i]*qs[t];
      for(int i=0;i<=s;i++)
        for(int j=0;i+j<=s;j++)
          dfs(t+1,x*po[i],y*po[j],z*po[s-(i+j)]);
    })(0,1,1,1);

    cout<<ans<<endl;
  }
  return 0;
}
