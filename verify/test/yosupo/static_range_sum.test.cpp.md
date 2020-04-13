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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/static_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/static_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 16:26:16+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/cumulativesum.cpp.html">datastructure/cumulativesum.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/cumulativesum.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  CumulativeSum cs(as);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<cs.query(l,r)<<newl;
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/static_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "datastructure/cumulativesum.cpp"

#line 3 "datastructure/cumulativesum.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct CumulativeSum{
  vector<T> sm;
  CumulativeSum(const vector<T> &as){
    int n=as.size();
    sm.resize(n+1);
    sm[0]=T();
    for(int i=0;i<n;i++)
      sm[i+1]=sm[i]+as[i];
  }
  // [l, r)
  T query(int l,int r){return -sm[l]+sm[r];}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/static_range_sum.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  CumulativeSum cs(as);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    cout<<cs.query(l,r)<<newl;
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

