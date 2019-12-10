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


# :warning: math/combination.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/combination.cpp">View this file on GitHub</a> (Last commit date: 2019-05-26 16:24:26 +0900)




## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}
#define MOD 1000000007
#define MAX_P 200005
Int fact[MAX_P];

void init(Int mod){
  fact[0]=1;
  for(Int i=1;i<MAX_P;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

Int mod_fact(Int n,Int mod,Int& e){
  e=0;
  if(n==0) return 1;
  Int res=mod_fact(n/mod,mod,e);
  e+=n/mod;
  if(n/mod%2!=0)return res*(mod-fact[n%mod]) %mod;
  return res*fact[n%mod]%mod;
}

Int mod_comb(Int n,Int k,Int mod){
  if(n==k||k==0) return 1;
  Int e1,e2,e3;
  Int a1=mod_fact(n,mod,e1),a2=mod_fact(k,mod,e2),a3=mod_fact(n-k,mod,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inverse(a2*a3%mod,mod)%mod;
}
//END CUT HERE
//INSERT ABOVE HERE

signed main(){
  // !! not verified !!
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

