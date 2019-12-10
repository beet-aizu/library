---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: mod/tetration.cpp
* category: mod


<a href="../../index.html">Back to top page</a>



## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T>
T totient(T n){
  T res=n;
  for(T i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      for(;n%i==0;n/=i);
    }
  }
  if(n!=1) res=res/n*(n-1);
  return res;
}

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
//END CUT HERE
//INSERT ABOVE HERE

signed YUKI_181(){
  int a,n,m,f=0;
  cin>>a>>n>>m;
  cout<<tetration(a,n,m,f)%m<<endl;
  return 0;
}
/*
  verified on 2019/10/08
  https://yukicoder.me/problems/no/181
*/

signed SUMMERFES2018_F(){
  using ll = long long;

  ll a,m,k;
  cin>>a>>m>>k;
  ll ans=0;

  k--;
  for(ll i=0,p=-1;i<k;i++){
    ll f=0;
    ll x=tetration(a,i,m,f)%m;
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
  verified on 2019/10/08
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
    ll a,n,m,f=0;
    cin>>a>>n>>m;
    cout<<tetration(a,n,m,f)%m<<endl;;
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

