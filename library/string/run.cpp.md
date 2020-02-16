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


# :heavy_check_mark: string/run.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/run.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-16 18:24:01+09:00




## Depends on

* :heavy_check_mark: <a href="zalgorithm.cpp.html">string/zalgorithm.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/runenumerate.test.cpp.html">test/yosupo/runenumerate.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "zalgorithm.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
namespace Run{
  using T = tuple<int, int, int>;
  using P = pair<int, int>;
  vector<vector<P>> run;

  template<typename C>
  vector<T> sub(const vector<C> &xs,const vector<C> &ys){
    auto ps=xs;
    auto qs=ys;
    reverse(ps.begin(),ps.end());
    qs.insert(qs.end(),xs.begin(),xs.end());
    qs.insert(qs.end(),ys.begin(),ys.end());
    auto zp=zalgorithm(ps);
    auto zq=zalgorithm(qs);
    vector<T> res;
    for(int i=0;i<(int)xs.size();i++){
      int a=xs.size()-i;
      int b=i-zp[a];
      int c=max(0,(int)ys.size()-zq[ys.size()+i]);
      if((int)(xs.size()+ys.size())-b-c>=2*a)
        res.emplace_back(a,b,c);
    }
    return res;
  }

  template<typename C>
  void dfs(int l,int r,const vector<C> &cs){
    if(l+1>=r) return;
    int m=(l+r)>>1;
    vector<C> xs(cs.begin()+l,cs.begin()+m);
    vector<C> ys(cs.begin()+m,cs.begin()+r);
    {
      auto zs=sub(xs,ys);
      for(auto w:zs){
        int a,b,c;
        tie(a,b,c)=w;
        run[a].emplace_back(l+b,r-c);
      }
    }
    reverse(xs.begin(),xs.end());
    reverse(ys.begin(),ys.end());
    {
      auto zs=sub(ys,xs);
      for(auto w:zs){
        int a,b,c;
        tie(a,b,c)=w;
        run[a].emplace_back(l+c,r-b);
      }
    }
    dfs(l,m,cs);
    dfs(m,r,cs);
  }

  // return all t (not only minimal)
  template<typename C>
  vector<vector<P>> enumerate(const vector<C> &cs){
    int n=cs.size();
    run.clear();
    run.resize(n+1);
    dfs(0,n,cs);

    auto cmp=[&](P a,P b){return P(a.first,-a.second)<P(b.first,-b.second);};
    for(int i=1;i<=n;i++){
      auto &rs=run[i];
      sort(rs.begin(),rs.end(),cmp);
      int mx=-1;
      vector<P> tmp;
      for(auto p:rs){
        if(mx<p.second){
          tmp.emplace_back(p);
          mx=p.second;
        }
      }
      rs=tmp;
    }
    return run;
  }

  vector<vector<P>> enumerate(string ss){
    return enumerate(vector<char>(ss.begin(),ss.end()));
  }
};
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: string/zalgorithm.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

