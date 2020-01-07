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


# :heavy_check_mark: datastructure/nonmonotonicconvexhulltrick.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/nonmonotonicconvexhulltrick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 08:27:21+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html">test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.test.cpp.html">test/aoj/3069.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, bool isMin, typename number = double>
struct NonmonotonicConvexHullTrick {
  static constexpr number INF = numeric_limits<T>::max();
  struct Line {
    T m,b,val;
    number x;
    bool q;
    Line(T m=0,T b=0):m(m),b(b),val(0),x(-INF),q(false){}

    T eval(T x) const{return m*x+b;}
    bool parallel(const Line &l) const{return m==l.m;}
    number intersect(const Line &l) const{
      return parallel(l)?number(INF):number(l.b-b)/number(m-l.m);
    }
    bool operator<(const Line &l) const{
      if(l.q) return x<l.val;
      return m<l.m;
    }
  };

  set<Line> hull;
  using iter = typename set<Line>::iterator;

  bool cPrev(iter it){return it!=hull.begin();}
  bool cNext(iter it){return it!=hull.end()&&next(it)!=hull.end();}

  bool bad(const Line &l1,const Line &l2,const Line &l3){
    return l1.intersect(l3) <= l1.intersect(l2);
  }
  bool bad(iter it){
    return cPrev(it)&&cNext(it)&&bad(*prev(it),*it,*next(it));
  }

  iter update(iter it){
    if(!cPrev(it)) return it;
    number x=it->intersect(*prev(it));
    Line tmp(*it);
    tmp.x=x;
    it=hull.erase(it);
    return hull.insert(it,tmp);
  }

  void addLine(T m,T b){
    if(isMin) m=-m,b=-b;
    Line l(m,b);
    iter it=hull.lower_bound(l);
    if(it!=hull.end()&&l.parallel(*it)){
      if(it->b<b) it=hull.erase(it);
      else return;
    }
    it=hull.insert(it,l);
    if(bad(it)){
      hull.erase(it);
      return;
    }
    while(cPrev(it)&&bad(prev(it))) hull.erase(prev(it));
    while(cNext(it)&&bad(next(it))) hull.erase(next(it));

    it=update(it);
    if(cPrev(it)) update(prev(it));
    if(cNext(it)) update(next(it));
  }

  bool empty() const{
    return hull.empty();
  }

  T query(T x){
    assert(!empty());
    Line q;
    q.val=x;q.q=1;
    iter it=--hull.lower_bound(q);
    if(isMin) return -(it->eval(x));
    return it->eval(x);
  }
} ;
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 173, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 66, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 98, in main
    exec_command([cxx, *shlex.split(utils.CXXFLAGS), '-I', '.', '-o', shlex.quote(str(directory / 'a.out')), shlex.quote(str(path))])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['g++', '--std=c++17', '-O2', '-Wall', '-g', '-I', '.', '-o', '.verify-helper/cache/988b27744f33205dfbbff10b1fb99080/a.out', 'test/aoj/3120.test.cpp']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: datastructure/nonmonotonicconvexhulltrick.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

