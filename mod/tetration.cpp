#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../math/totient.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
T mpow(T a,T n,T m,T &f){
  using ull = unsigned long long;
  if(a==1||n==0) return 1;
  ull v=1,x=a,z=m;
  f|=x>=z;
  x%=m;
  while(1){
    if(n&1) v*=x;
    if(v>=z) f=1,v%=m;
    n>>=1;
    if(!n) break;
    x=x*x;
    if(x>=z) f=1,x%=m;
  }
  return v;
}

template<typename T>
T tetration(T a,T n,T m,T &f){
  if(a==0) return ~n&1;
  if(m==1) return f=1;
  if(a==1||n==0) return 1;
  if(n==1){
    f|=a>=m;
    return a%m+f*m;
  }
  T z=tetration(a,n-1,totient(m),f);
  T r=mpow(a,z,m,f);
  return r+f*m;
}

template<typename T>
T tetration(T a,T n,T m){
  T f=0;
  return tetration(a,n,m,f)%m;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

signed YUKI_181(){
  int a,n,m;
  cin>>a>>n>>m;
  cout<<tetration(a,n,m)<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://yukicoder.me/problems/no/181
*/

signed SUMMERFES2018_F(){
  using ll = long long;

  ll a,m,k;
  cin>>a>>m>>k;
  ll ans=0;

  k--;
  for(ll i=0,p=-1;i<k;i++){
    ll x=tetration(a,i,m);
    if(p==x){
      ans+=(k-i)%m*x%m;
      ans%=m;
      break;
    }
    ans+=x;
    ans%=m;
    p=x;
  }
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/summerfes2018-div1/tasks/summerfes2018_f
*/

signed SPOJ_POWTOW(){
  using ll = long long;

  int T;
  cin>>T;
  while(T--){
    ll a,n,f=0;
    cin>>a>>n;
    stringstream ss;
    ss<<tetration(a,n,ll(1e9),f)%ll(1e9);
    auto s=ss.str();
    if(f){
      while(s.size()<9u) s='0'+s;
      cout<<"..."<<s<<endl;
    }else{
      cout<<s<<endl;
    }
  }
  return 0;
}
/*
  verified on 2019/10/08
  https://www.spoj.com/problems/POWTOW/
*/

signed SPOJ_MTETRA(){
  using ll = long long;
  int T;
  cin>>T;
  while(T--){
    ll a,n,m;
    cin>>a>>n>>m;
    cout<<tetration(a,n,m)<<endl;;
  }
  return 0;
}
/*
  verified on 2019/10/08
  https://www.spoj.com/problems/MTETRA/
*/

signed main(){
  //YUKI_181();
  //SUMMERFES2018_F();
  //SPOJ_POWTOW();
  //SPOJ_MTETRA();
}
#endif
