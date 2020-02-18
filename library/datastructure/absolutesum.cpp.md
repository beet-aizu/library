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


# :heavy_check_mark: datastructure/absolutesum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/absolutesum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-15 16:16:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/2600.test.cpp.html">test/yukicoder/2600.test.cpp</a>


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
struct AbsoluteSum{
  multiset<T> lp,rp;
  T sum;
  AbsoluteSum():sum(0){}
  T insert(T x){
    if(lp.empty()){
      lp.emplace(x);
      rp.emplace(x);
      return T(0);
    }
    auto p=interval();
    lp.emplace(x);
    rp.emplace(x);
    if(p.first<=x&&x<=p.second) return T(0);
    if(*lp.rbegin()>*rp.begin()){
      T a=*lp.rbegin();
      T b=*rp.begin();
      lp.erase(lp.find(a));
      rp.erase(rp.find(b));
      rp.emplace(a);
      lp.emplace(b);
    }
    T res=min(abs(p.first-x),abs(p.second-x));
    sum+=res;
    return res;
  }

  T erase(T x){
    assert(lp.count(x)+rp.count(x)>=2);
    if(lp.count(x)&&rp.count(x)){
      lp.erase(lp.find(x));
      rp.erase(rp.find(x));
      return T(0);
    }
    if(lp.count(x)){
      lp.erase(lp.find(x));
      lp.erase(lp.find(x));
      lp.emplace(*rp.begin());
      rp.erase(rp.begin());
    }else{
      rp.erase(rp.find(x));
      rp.erase(rp.find(x));
      rp.emplace(*lp.rbegin());
      lp.erase(lp.rbegin().base());
    }
    auto p=interval();
    if(p.first<=x&&x<=p.second) return T(0);
    T res=min(abs(p.first-x),abs(p.second-x));
    sum-=res;
    return res;
  }

  pair<T, T> interval(){
    assert(!lp.empty());
    return make_pair(*lp.rbegin(),*rp.begin());
  }

  T value(){return sum;}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

// test interval()
signed ABC127_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin>>q;
  using ll = long long;
  AbsoluteSum<ll> as;
  ll sum=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      ll a,b;
      cin>>a>>b;
      as.insert(a);
      sum+=b;
    }
    if(t==2){
      cout<<as.interval().first<<" "<<sum+as.value()<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/19
  https://atcoder.jp/contests/abc127/tasks/abc127_f
*/

signed main(){
  //ABC127_F();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: datastructure/absolutesum.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

