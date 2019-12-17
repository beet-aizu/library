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


# :heavy_check_mark: tools/all_permutations.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/all_permutations.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01 +0900




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2187.test.cpp.html">test/aoj/2187.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3053.test.cpp.html">test/aoj/3053.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename F>
void all_permutations(int n,F f){
  vector<int> vs(n);
  iota(vs.begin(),vs.end(),0);
  do f(vs); while(next_permutation(vs.begin(),vs.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ABC054_C(){
  int n,m;
  cin>>n>>m;
  int es[10][10]={};
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    es[a][b]=es[b][a]=1;
  }
  int ans=0;
  auto f=
    [&](const auto &vs){
      if(!es[0][vs[0]+1]) return;
      for(int i=0;i+1<n-1;i++)
        if(!es[vs[i]+1][vs[i+1]+1]) return;
      ans++;
    };
  all_permutations(n-1,f);
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/12/09
  https://atcoder.jp/contests/abc054/tasks/abc054_c
*/

signed main(){
  ABC054_C();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: tools/all_permutations.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

