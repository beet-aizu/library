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


# :heavy_check_mark: test/yosupo/associative_array.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/associative_array.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 17:44:55+09:00


* see: <a href="https://judge.yosupo.jp/problem/associative_array">https://judge.yosupo.jp/problem/associative_array</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/pb_ds_cc_hash_table.cpp.html">datastructure/pb_ds_cc_hash_table.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/cc_hash.cpp.html">tools/cc_hash.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/cc_hash.cpp"
#include "../../datastructure/pb_ds_cc_hash_table.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;
  gmap<ll, ll, cc_hash<ll>> mp;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      ll k,v;
      cin>>k>>v;
      mp[k]=v;
    }
    if(t==1){
      ll k;
      cin>>k;
      cout<<mp[k]<<newl;
    }
  }
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/associative_array.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "tools/cc_hash.cpp"

#ifndef call_from_test
#line 5 "tools/cc_hash.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct cc_hash{
  uint64_t operator()(T x) const{
    uint64_t y(x);
    y += 0x9e3779b97f4a7c15;
    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
    return y ^ (y >> 31);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "datastructure/pb_ds_cc_hash_table.cpp"

#line 3 "datastructure/pb_ds_cc_hash_table.cpp"
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
signed main(){
  return 0;
}
#endif
#line 9 "test/yosupo/associative_array.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  using ll = long long;
  gmap<ll, ll, cc_hash<ll>> mp;

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      ll k,v;
      cin>>k>>v;
      mp[k]=v;
    }
    if(t==1){
      ll k;
      cin>>k;
      cout<<mp[k]<<newl;
    }
  }
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

