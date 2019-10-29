#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2603"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../algorithm/monotoneminima.cpp"
#undef call_from_test

signed main(){
  int s,n,m;
  cin>>s>>n>>m;
  vector<int> xs(s);
  for(int i=0;i<s;i++) cin>>xs[i];

  vector<int> ts(n),ps(n);
  for(int i=0;i<n;i++) cin>>ts[i]>>ps[i],ps[i]--;

  vector<int> vs(n);
  for(int i=0;i<n;i++) vs[i]=ts[i]-xs[ps[i]];
  sort(vs.begin(),vs.end());

  vector<int> sm(n+1,0);
  for(int i=0;i<n;i++) sm[i+1]=sm[i]+vs[i];

  const int INF = 1e9;
  vector<int> dp(n+1,INF);
  dp[0]=0;
  for(int k=0;k<m;k++){
    auto dist=
      [&](int i,int j){
        return i<j?INF:dp[j]+(i?vs[i-1]:0)*(i-j)-(sm[i]-sm[j]);
      };
    auto res=MonotoneMinima::args<int>(n+1,n+1,dist);
    vector<int> nx(n+1);
    for(int i=0;i<=n;i++) nx[i]=dist(i,res[i]);
    swap(dp,nx);
  }
  cout<<dp[n]<<endl;
  return 0;
}
