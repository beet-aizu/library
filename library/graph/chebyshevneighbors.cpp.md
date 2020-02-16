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


# :heavy_check_mark: graph/chebyshevneighbors.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/chebyshevneighbors.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-21 16:50:01+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0403.test.cpp.html">test/aoj/0403.test.cpp</a>


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
struct ChebyshevNeighbors{
  struct Point{
    T x,y;
    int idx,idy;
    Point(){}
    Point(T x,T y,int idx):x(x),y(y),idx(idx),idy(-1){}
    bool operator<(const Point &a)const{
      if(y!=a.y) return y>a.y;
      return x<a.x;
    }
  };

  vector<T> xs,ys;
  ChebyshevNeighbors(vector<T> xs,vector<T> ys):xs(xs),ys(ys){}

  vector<Point> ps,bk;

  void chk(int idx,int j){
    if(idx<0) return;
    int &idy=ps[j].idy;
    if(idy<0||xs[idy]<xs[idx]) idy=idx;
  }

  void upd(int &idx,int i){
    if(idx<0||xs[idx]<ps[i].x) idx=ps[i].idx;
  }

  void dfs(int l,int r){
    if(l+1==r) return;
    int m=(l+r)>>1;
    dfs(l,m);dfs(m,r);

    {
      int i=l,j=m,idx=-1;
      while(i<m||j<r){
        if(i==m||j==r){
          if(i==m) chk(idx,j++);
          if(j==r) upd(idx,i++);
          continue;
        }
        ps[i].x+ps[i].y<=ps[j].x+ps[j].y?upd(idx,i++):chk(idx,j++);
      }
    }

    {
      int i=l,j=m,k=l;
      for(int i=l;i<r;i++) bk[i]=ps[i];
      while(i<m||j<r){
        if(i==m||j==r) ps[k++]=bk[(j==r?i:j)++];
        else ps[k++]=bk[(bk[i].x+bk[i].y<=bk[j].x+bk[j].y?i:j)++];
      }
    }
  }

  vector< pair<int, int> > build(){
    vector< pair<int, int> > res;
    int n=xs.size();
    ps.resize(n);bk.resize(n);
    for(int b=0;b<4;b++){
      for(int i=0;i<n;i++){
        if(b&1) swap(xs[i],ys[i]);
        if(b&2) xs[i]*=-1;
        ps[i]=Point(xs[i],ys[i],i);
      }
      sort(ps.begin(),ps.end());
      dfs(0,n);
      for(int i=0;i<n;i++){
        if(b&1) swap(xs[i],ys[i]);
        if(b&2) xs[i]*=-1;
        if(ps[i].idy<0) continue;
        int u=ps[i].idx,v=ps[i].idy;
        if(u>v) swap(u,v);
        res.emplace_back(u,v);
      }
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/chebyshevneighbors.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

