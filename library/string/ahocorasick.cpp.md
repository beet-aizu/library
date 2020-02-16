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


# :heavy_check_mark: string/ahocorasick.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/ahocorasick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:10:12+09:00




## Depends on

* :heavy_check_mark: <a href="trie.cpp.html">string/trie.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2212.test.cpp.html">test/aoj/2212.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2257.test.cpp.html">test/aoj/2257.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3073.test.cpp.html">test/aoj/3073.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "trie.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<size_t X>
struct AhoCorasick : Trie<X+1>{
  using TRIE = Trie<X+1>;
  using TRIE::TRIE;
  using TRIE::next;
  vector<int> cnt;

  void build(int heavy=true){
    auto &vs=TRIE::vs;
    int n=vs.size();
    cnt.resize(n);
    for(int i=0;i<n;i++){
      if(heavy) sort(vs[i].idxs.begin(),vs[i].idxs.end());
      cnt[i]=vs[i].idxs.size();
    }

    queue<int> que;
    for(int i=0;i<(int)X;i++){
      if(~next(0,i)){
        next(next(0,i),X)=0;
        que.emplace(next(0,i));
      }else{
        next(0,i)=0;
      }
    }

    while(!que.empty()){
      auto &x=vs[que.front()];
      int fail=x.nxt[X];

      cnt[que.front()]+=cnt[fail];
      que.pop();

      for(int i=0;i<(int)X;i++){
        int &nx=x.nxt[i];
        if(nx<0){
          nx=next(fail,i);
          continue;
        }
        que.emplace(nx);
        next(nx,X)=next(fail,i);
        if(heavy){
          auto &idx=vs[nx].idxs;
          auto &idy=vs[next(fail,i)].idxs;
          vector<int> idz;
          set_union(idx.begin(),idx.end(),
                    idy.begin(),idy.end(),
                    back_inserter(idz));
          idx=idz;
        }
      }
    }
  }

  vector<int> match(string s,int heavy=true){
    auto &vs=TRIE::vs;
    vector<int> res(heavy?TRIE::size():1);
    int pos=0;
    for(auto &c:s){
      pos=next(pos,TRIE::conv(c));
      if(heavy) for(auto &x:vs[pos].idxs) res[x]++;
      else res[0]+=cnt[pos];
    }
    return res;
  }

  int count(int pos){
    return cnt[pos];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: string/trie.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

