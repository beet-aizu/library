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

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/fraction.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:37:46+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1338.test.cpp.html">test/aoj/1338.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
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
  using ll = long long;

  int n,x;
  cin>>n>>x;

  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using F = fraction<ll>;
  using T = tuple<F, int, int>;
  priority_queue<T> pq;

  int sum=0;
  for(int i=0;i<n;i++) sum+=as[i];

  for(int i=0;i<n;i++){
    int p=x*as[i]/sum;
    pq.emplace(F(1,as[i]),i,p);
    if((x*as[i])%sum!=0)
      pq.emplace(F(2*x,sum)-F(2*p+1,as[i]),i,1);
    pq.emplace(F(-1,as[i]),i,x+1);
  }

  vector<int> bs(n,0);
  int k=x;
  while(k>0){
    int i,l;
    tie(ignore,i,l)=pq.top();pq.pop();

    int t=min(k,l);
    bs[i]+=t;
    k-=t;
  }

  for(int i=0;i<n;i++) cout<<bs[i]<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/cpsco2019-s3/tasks/cpsco2019_s3_g
*/

signed main(){
  //CPSCO2019_Session3_G();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: math/fraction.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

