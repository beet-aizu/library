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


# :heavy_check_mark: test/yosupo/sort_points_by_argument.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sort_points_by_argument.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-14 17:16:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/sort_points_by_argument">https://judge.yosupo.jp/problem/sort_points_by_argument</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/geometry/argsort.cpp.html">geometry/argsort.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../geometry/argsort.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  struct Point{ll x,y;};
  vector<Point> ps(n);
  for(int i=0;i<n;i++) cin>>ps[i].x>>ps[i].y;

  argsort(ps);

  for(int i=0;i<n;i++) cout<<ps[i].x<<" "<<ps[i].y<<"\n";
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/sort_points_by_argument.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "geometry/argsort.cpp"

#ifndef call_from_test
#line 5 "geometry/argsort.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
// (-pi, pi], atan2(0, 0) = 0
template<typename P>
void argsort(vector<P> &ps){
  auto getA=
    [&](P p){
      if(p.x>=0 and p.y>=0) return 0;
      if(p.y>=0) return 1;
      if(p.x<=0) return -2;
      return -1;
    };
  auto cross=[&](P a,P b){return a.x*b.y-a.y*b.x;};
  auto cmp=
    [&](P a,P b){
      if(getA(a)!=getA(b)) return getA(a)<getA(b);
      if(a.x==0 and a.y==0) return !(b.x==0 and b.y==0);
      if(b.x==0 and b.y==0) return false;
      return cross(a,b)>0;
    };
  sort(ps.begin(),ps.end(),cmp);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/sort_points_by_argument.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  struct Point{ll x,y;};
  vector<Point> ps(n);
  for(int i=0;i<n;i++) cin>>ps[i].x>>ps[i].y;

  argsort(ps);

  for(int i=0;i<n;i++) cout<<ps[i].x<<" "<<ps[i].y<<"\n";
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

