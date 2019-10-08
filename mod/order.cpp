#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template<typename T>
map<T, T> factorize(T x){
  map<T, T> res;
  for(T i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

template<typename T>
T mod_pow(T a,long long n,T mod){
  using ll = long long;
  T res(1);
  while(n){
    if(n&1) res=(ll)res*a%mod;
    a=(ll)a*a%mod;
    n>>=1;
  }
  return res;
}

#endif
//BEGIN CUT HERE
template<typename T>
T order(T x,T MOD){
  static map<T, vector<T>> dp;
  vector<T> &ps=dp[MOD];
  if(ps.empty()){
    auto fs=factorize(MOD-1);
    for(auto p:fs) ps.emplace_back(p.first);
  }
  T res=MOD-1;
  for(T p:ps){
    while(res%p==0){
      if(mod_pow(x,res/p,MOD)!=1) break;
      res/=p;
    }
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed AOJ_3062(){
  using ll = long long;
  ll MOD;
  cin>>MOD;

  int T;
  cin>>T;
  while(T--){
    ll n;
    cin>>n;

    vector<ll> g(n);
    for(ll i=0;i<n;i++) cin>>g[i];

    ll a;
    cin>>a;

    if(a==1){
      cout<<1<<"\n";
      continue;
    }

    sort(g.rbegin(),g.rend());
    if(g[0]==1){
      cout<<0<<"\n";
      continue;
    }
    while(g.back()==1) g.pop_back();

    auto mlcm=[&](ll a,ll b){return a/__gcd(a,b)*b;};

    ll res=order(g[0],MOD);
    for(ll x:g) res=mlcm(res,order(x,MOD));

    cout<<(res%order(a,MOD)==0?1:0)<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3062
*/

signed main(){
  AOJ_3062();
  return 0;
}
#endif
