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


# :warning: segtree/count/static.cpp
* category: segtree/count


<a href="../../../index.html">Back to top page</a>



## Verified
* :warning: <a href="../../../verify/test/aoj/2674.count.test.cpp.html">test/aoj/2674.count.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename T>
struct SegmentTree{
  using P = pair<int, T>;
  int n;
  vector<P> v;
  vector< vector<T> > dat;
  SegmentTree(){};
  SegmentTree(int n,vector<P> v):v(v){init(n);build();};

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,vector<int>());
  }

  void build(){
    for(auto p:v)
      dat[p.first+n].emplace_back(p.second);

    for(int i=0;i<n;i++)
      sort(dat[i+n].begin(),dat[i+n].end());

    for(int i=n-1;i;i--){
      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),
            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),
            back_inserter(dat[i]));
    }
  }

  // [a,b) * [c,d)
  inline int query(int a,int b,T c,T d){
    int res=0;
    auto calc=[a,b,c,d](vector<T> &x){
                auto latte=lower_bound(x.begin(),x.end(),d);
                auto malta=lower_bound(x.begin(),x.end(),c);
                return int(latte-malta);
              };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) res+=calc(dat[l++]);
      if(r&1) res+=calc(dat[--r]);
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed ABC106_D(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++) scanf("%d %d",&x[i],&y[i]);

  using P = pair<int, int>;
  vector<P> vp;
  for(int i=0;i<m;i++) vp.emplace_back(x[i],y[i]);

  SegmentTree<int> seg(n+1,vp);

  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",seg.query(a,b+1,a,b+1));
  }
  return 0;
}

signed main(){
  ABC106_D();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

