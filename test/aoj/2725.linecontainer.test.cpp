// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2725

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../vector/zip.cpp"
#include "../../convexhulltrick/linecontainer.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n,x;
  cin>>n>>x;
  vector<ll> ts(n),ps(n),fs(n);
  for(int i=0;i<n;i++) cin>>ts[i]>>ps[i]>>fs[i];

  auto vt=zip(fs,ps,ts);
  sort(vt.begin(),vt.end());
  for(int i=0;i<n;i++) tie(fs[i],ps[i],ts[i])=vt[i];

  vector<MaxLineContainer<ll>> vh(x+1);

  ll ans=0;
  for(int i=0;i<n;i++){
    for(int j=x;j>ts[i];j--){
      if(vh[j-ts[i]].empty()) continue;
      ll val=vh[j-ts[i]].query(fs[i])+ps[i]-fs[i]*fs[i];
      vh[j].add(2*fs[i],val-fs[i]*fs[i]);
      chmax(ans,val);
    }
    vh[ts[i]].add(2*fs[i],ps[i]-fs[i]*fs[i]);
    chmax(ans,ps[i]);
  }

  cout<<ans<<endl;
  return 0;
}
