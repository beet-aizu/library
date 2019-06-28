#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
namespace MonotoneMinima{
  vector<int> ar;

  template<typename T,typename F>
  void induce(int l,int r,int a,int b,vector<T> &dp,F dist){
    if(l==r) return;
    int m=(l+r)>>1;
    int &idx=(ar[m]=a);
    T res=dist(idx,m);
    for(int i=a;i<b;i++){
      T tmp=dist(i,m);
      if(tmp<res) res=tmp,idx=i;
    }
    induce(l,m,a,idx+1,dp,dist);
    induce(m+1,r,idx,b,dp,dist);
  }

  template<typename T,typename F>
  vector<int> args(int n,F dist){
    ar.assign(n,-1);
    vector<T> dp;
    induce(0,n,0,n,dp,dist);
    return ar;
  }
}
//END CUT HERE

//INSERT ABOVE HERE
signed COLOPL2018FINAL_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto dist=[&](int i,int j){return as[i]+(ll)(i-j)*(i-j);};
  auto res=MonotoneMinima::args<ll>(n,dist);

  for(int i=0;i<n;i++) cout<<dist(res[i],i)<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/28
  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/
signed AOJ_2603(){
  cin.tie(0);
  ios::sync_with_stdio(0);

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
        return i>j?INF:dp[i]+vs[j-1]*(j-i)-(sm[j]-sm[i]);
      };
    auto res=MonotoneMinima::args<int>(n+1,dist);
    vector<int> nx(n+1);
    for(int i=0;i<=n;i++) nx[i]=dist(res[i],i);
    swap(dp,nx);
  }
  cout<<dp[n]<<endl;
  return 0;
}
/*
  verified on 2019/06/28
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2603
*/

signed main(){
  //COLOPL2018FINAL_C();
  //AOJ_2603();
  return 0;
}
