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


# :heavy_check_mark: string/rectanglehash.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rectanglehash.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-21 14:48:19 +0900




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1312.test.cpp.html">test/aoj/1312.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_C.test.cpp.html">test/aoj/ALDS1_14_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T,T MOD,T B>
struct RollingHash{
  using ll = long long;
  vector<T> hash,p;
  RollingHash(){}
  RollingHash(vector<T> vs){init(vs);}
  RollingHash(string &s){
    vector<T> vs;
    for(char c:s) vs.emplace_back(c);
    init(vs);
  }
  void init(vector<T> vs){
    int n=vs.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(int i=0;i<n;i++){
      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
      p[i+1]=(ll)p[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(int l,int r){
    T res=(ll)hash[r]+MOD-(ll)hash[l]*p[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};
#endif
//BEGIN CUT HERE
template<typename T,T MOD,T B1,T B2>
auto rectangle_hash(vector<string> vs,int r,int c){
  vector< RollingHash<T, MOD, B1> > hs;
  for(string s:vs) hs.emplace_back(s);

  int h=vs.size(),w=vs[0].size();
  vector< vector<T> > res(h-r+1,vector<T>(w-c+1));

  for(int j=0;j+c<=w;j++){
    vector<T> ts(h);
    for(int i=0;i<h;i++)
      ts[i]=hs[i].find(j,j+c);

    RollingHash<T, MOD, B2> rh(ts);
    for(int i=0;i+r<=h;i++)
      res[i][j]=rh.find(i,i+r);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 345, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 125, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: string/rectanglehash.cpp: line 35: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

