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


# :heavy_check_mark: datastructure/pb_ds_cc_hash_table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/pb_ds_cc_hash_table.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:31:47 +0900




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2646.test.cpp.html">test/aoj/2646.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T,typename U, typename H=hash<T> >
using gmap = cc_hash_table<T, U, H>;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed AGC023_A(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  vector<ll> as(n);
  for(int i=0;i<n;i++) scanf("%lld",&as[i]);

  gmap<ll, ll> mp;
  ll ans=0,sum=0;
  mp[sum]++;
  for(int i=0;i<n;i++){
    sum+=as[i];
    ans+=mp[sum];
    mp[sum]++;
  }

  printf("%lld\n",ans);
  return 0;
}
/*
  verified on 2019/12/09
  https://atcoder.jp/contests/agc023/tasks/agc023_a
*/

signed main(){
  AGC023_A();
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
onlinejudge_verify.bundle.BundleError: datastructure/pb_ds_cc_hash_table.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

