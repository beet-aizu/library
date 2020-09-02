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


# :heavy_check_mark: segtree/count/static.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8c0b38b9c664244572b7839d3b5c6123">segtree/count</a>
* <a href="{{ site.github.repository_url }}/blob/master/segtree/count/static.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-03 00:55:21+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2674.count.test.cpp.html">test/aoj/2674.count.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Key>
struct SegmentTree{
  using P = pair<int, Key>;
  int n;
  vector< vector<Key> > dat;
  SegmentTree(){}
  SegmentTree(int n,vector<P> vs):n(n){
    dat.assign(n<<1,vector<Key>());
    for(auto p:vs)
      dat[p.first+n].emplace_back(p.second);

    for(int i=0;i<n;i++)
      sort(dat[i+n].begin(),dat[i+n].end());

    for(int i=n-1;i;i--){
      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),
            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),
            back_inserter(dat[i]));
    }
  }

  // [a, b) * [c, d)
  inline int query(int a,int b,Key c,Key d){
    int res=0;
    auto calc=[a,b,c,d](vector<Key> &xs){
      auto latte=lower_bound(xs.begin(),xs.end(),d);
      auto malta=lower_bound(xs.begin(),xs.end(),c);
      return int(latte-malta);
    };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(dat[l++]);
      if(r&1) res+=calc(dat[--r]);
    }
    return res;
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
#line 1 "segtree/count/static.cpp"

#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Key>
struct SegmentTree{
  using P = pair<int, Key>;
  int n;
  vector< vector<Key> > dat;
  SegmentTree(){}
  SegmentTree(int n,vector<P> vs):n(n){
    dat.assign(n<<1,vector<Key>());
    for(auto p:vs)
      dat[p.first+n].emplace_back(p.second);

    for(int i=0;i<n;i++)
      sort(dat[i+n].begin(),dat[i+n].end());

    for(int i=n-1;i;i--){
      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),
            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),
            back_inserter(dat[i]));
    }
  }

  // [a, b) * [c, d)
  inline int query(int a,int b,Key c,Key d){
    int res=0;
    auto calc=[a,b,c,d](vector<Key> &xs){
      auto latte=lower_bound(xs.begin(),xs.end(),d);
      auto malta=lower_bound(xs.begin(),xs.end(),c);
      return int(latte-malta);
    };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(dat[l++]);
      if(r&1) res+=calc(dat[--r]);
    }
    return res;
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

<a href="../../../index.html">Back to top page</a>

