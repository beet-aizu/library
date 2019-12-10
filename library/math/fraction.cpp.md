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


# :heavy_check_mark: math/fraction.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/fraction.cpp">View this file on GitHub</a> (Last commit date: 2019-10-22 17:20:26 +0900)




## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/1338.test.cpp.html">test/aoj/1338.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T>
struct fraction{
  T num,dom;
  fraction(){}
  fraction(T n,T d):num(n),dom(d){
    assert(dom!=0);
    if(dom<0) num*=-1,dom*=-1;
    T tmp=__gcd(abs(num),abs(dom));
    num/=tmp;
    dom/=tmp;
  }
  fraction operator+(const fraction a) const{
    return fraction(num*a.dom+a.num*dom,dom*a.dom);
  }
  fraction operator-(const fraction a) const{
    return fraction(num*a.dom-a.num*dom,dom*a.dom);
  }
  fraction operator*(const fraction a) const{
    return fraction(num*a.num,dom*a.dom);
  }
  fraction operator/(const fraction a){
    return fraction(num*a.dom,dom*a.num);
  }
  fraction operator*(T k) const{return fraction(num*k,dom);}
  fraction operator/(T k) const{return fraction(num,dom*k);}
  bool operator<(const fraction a)const{
    return num*a.dom<a.num*dom;
  }
  bool operator>(const fraction a)const{
    return num*a.dom>a.num*dom;
  }
  bool operator==(const fraction a)const{
    return num*a.dom==a.num*dom;
  }
  bool operator!=(const fraction a)const{
    return num*a.dom!=a.num*dom;
  }
  bool operator<=(const fraction a)const{
    return num*a.dom<=a.num*dom;
  }
  bool operator>=(const fraction a)const{
    return num*a.dom>=a.num*dom;
  }
};
//END CUT HERE
#ifndef call_from_test
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed CPSCO2019_Session3_G(){
  Int n,x;
  cin>>n>>x;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  using F = fraction<Int>;
  using T = tuple<F, Int, Int>;
  priority_queue<T> pq;

  Int sum=0;
  for(Int i=0;i<n;i++) sum+=a[i];

  for(Int i=0;i<n;i++){
    Int p=x*a[i]/sum;
    pq.emplace(F(1,a[i]),i,p);
    if((x*a[i])%sum!=0)
      pq.emplace(F(2*x,sum)-F(2*p+1,a[i]),i,1);
    pq.emplace(F(-1,a[i]),i,x+1);
  }

  vector<Int> b(n,0);
  Int k=x;
  while(k>0){
    Int i,l;
    tie(ignore,i,l)=pq.top();pq.pop();

    Int t=min(k,l);
    b[i]+=t;
    k-=t;
  }

  for(Int i=0;i<n;i++) cout<<b[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/07
  https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g
*/

signed main(){
  CPSCO2019_Session3_G();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

