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


# :heavy_check_mark: datastructure/kdtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/kdtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 16:34:45+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_C.test.cpp.html">test/aoj/DSL_2_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct KDTree{
  static const int NIL = -1;

  class Node{
  public:
    int pos,p,l,r;
    Node(){pos=p=l=r=NIL;}
  };

  class Point{
  public:
    int id;
    T x,y;
    Point(){}
    Point(int id,T x,T y): id(id),x(x),y(y){}
    bool operator<(const Point &p)const{
      return id<p.id;
    }
  };

  vector<Point> ps;
  vector<Node> ts;
  int np;

  void add_point(int i,int x,int y){
    ps.emplace_back(i,x,y);
    ts.emplace_back();
  }

  static bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}
  static bool lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}

  int dfs(int l,int r,int depth){
    if(l>=r) return NIL;
    int mid=(l+r)/2;
    int t=np++;
    if(depth%2==0){
      sort(ps.begin()+l,ps.begin()+r,lessX);
    }else{
      sort(ps.begin()+l,ps.begin()+r,lessY);
    }
    ts[t].pos=mid;
    ts[t].l=dfs(l,mid,depth+1);
    ts[t].r=dfs(mid+1,r,depth+1);
    return t;
  }

  int build(){
    np=0;
    return dfs(0,ps.size(),0);
  }

  // [sx, tx] * [sy, ty]
  void find(int v,T sx,T tx,T sy,T ty,int depth,vector<Point> &ans){
    T x=ps[ts[v].pos].x;
    T y=ps[ts[v].pos].y;
    if(sx<=x&&x<=tx&&sy<=y&&y<=ty)
      ans.push_back(ps[ts[v].pos]);

    if(depth%2==0){
      if(ts[v].l!=NIL){
        if(sx<=x) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(ts[v].r!=NIL){
        if(x<=tx) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }else{
      if(ts[v].l!=NIL){
        if(sy<=y) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(ts[v].r!=NIL){
        if(y<=ty) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }
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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: datastructure/kdtree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

