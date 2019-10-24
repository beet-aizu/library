#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
// find x s.t. a^x = b (x >= 0)
template<typename T>
T mod_log(T a,T b,T mod){
  using ll = long long;
  ll g=1;
  {
    ll m=mod;
    while(m){
      g=(ll)g*a%mod;
      m>>=1;
    }
  }
  g=__gcd(g,(ll)mod);
  ll c=0,t=1;
  while(t%g){
    if(t==b) return c;
    t=t*a%mod;
    c++;
  }
  // not found
  if(b%g) return mod;
  t/=g;b/=g;
  const ll n=mod/g;
  ll h=0,gs=1;
  while(h*h<n){
    gs=gs*a%n;
    ++h;
  }
  unordered_map<ll, ll> bs;
  {
    ll s=0,e=b;
    while(s<h){
      e=e*a%n;
      bs[e]=++s;
    }
  }
  {
    ll s=0,e=t;
    while(s<n){
      e=e*gs%n;
      s+=h;
      if(bs.count(e))
        return c+s-bs[e];
    }
  }
  // not found
  return mod;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "mint.cpp"
#include "../math/kitamasa.cpp"
#include "../math/extgcd.cpp"
#include "../tools/drop.cpp"
#include "../tools/fastio.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR536_F(){
  const int MOD = 998244353;
  using M = Mint<int, MOD>;
  using P = Mint<int, MOD-1>;

  int k;
  cin>>k;

  vector<P> bs(k);
  for(int i=0;i<k;i++){
    int b;
    cin>>b;
    bs[i]=P(b);
  }

  int n,m;
  cin>>n>>m;

  reverse(bs.begin(),bs.end());
  Kitamasa<P> ktms(bs);
  vector<P> as(k,0);
  as[k-1]=1;

  int v=ktms.calc(as,--n).v;
  int h=mod_log(3,m,MOD)%(MOD-1);

  if(v!=0||h!=0){
    int g=__gcd(v,h);
    v/=g;
    h/=g;
  }

  if(h!=0&&__gcd(v,MOD-1)!=1){
    cout<<-1<<endl;
    return 0;
  }

  cout<<M(3).pow((long long)h*mod_inverse(v,MOD-1))<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://codeforces.com/contest/1106/problem/F
*/

signed BBC002_F(){
  using ll = long long;
  ll n,p;
  cin>>n>>p;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];
  ll x;
  cin>>x;
  if(x==1) drop(0);

  ll s=1;
  for(ll a:as) s=s*a%p;

  const ll INF = 1e18;
  ll ans=INF;
  ll v=1;
  for(int i=0;i<n;i++){
    ll y=x*mod_inverse(v,p)%p;
    ll t=mod_log(s,y,p);
    if(t!=p) chmin(ans,t*n+i);
    v*=as[i];
    v%=p;
  }

  if(ans==INF) drop("Fracture");
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/10/24
  https://www.hackerrank.com/contests/bbc002/challenges/bbc002-f/problem
*/

signed main(){
  //CFR536_F();
  //BBC002_F();
  return 0;
}
#endif
