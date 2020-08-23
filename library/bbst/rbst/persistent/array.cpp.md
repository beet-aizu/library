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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: bbst/rbst/persistent/array.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b6fd322919b1d6679fc1d8023177c526">bbst/rbst/persistent</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/rbst/persistent/array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-22 15:37:31+09:00




## Depends on

* :heavy_check_mark: <a href="../basic/array.cpp.html">bbst/rbst/basic/array.cpp</a>
* :heavy_check_mark: <a href="../basic/base.cpp.html">bbst/rbst/basic/base.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo/persistent_queue.test.cpp.html">test/yosupo/persistent_queue.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/array.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentArray : Array<Node, LIM>{
  using super = Array<Node, LIM>;
  using super::super;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    Node* b=super::create();
    *b=*a;
    return b;
  }

  Node* eval(Node* a){
    a=clone(a);
    if(a->rev){
      a->l=clone(a->l);
      a->r=clone(a->r);
    }
    return super::eval(a);
  }

  Node* rebuild(Node* a){
    auto v=super::dump(a);
    super::ptr=0;
    return super::build(v);
  }

  bool almost_full() const{
    return super::ptr>LIM*9/10;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed JOISC2012_COPYPASTE(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int m;
  string buf;
  cin>>m>>buf;

  using Node = NodeBase<char>;
  const size_t LIM = 1e7;
  PersistentArray<Node, LIM> pa;

  vector<char> v(buf.begin(),buf.end());
  auto rt=pa.build(v);

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    auto s=pa.split(rt,a);
    auto t=pa.split(s.second,b-a);
    auto u=pa.split(rt,c);
    rt=pa.merge(pa.merge(u.first,t.first),u.second);

    if((int)pa.count(rt)>m)
      rt=pa.split(rt,m).first;

    if(pa.almost_full()) rt=pa.rebuild(rt);
  }

  auto ds=pa.dump(rt);
  buf.resize(ds.size());
  for(int i=0;i<(int)ds.size();i++) buf[i]=ds[i];
  cout<<buf<<endl;
  return 0;
}
/*
  verified on 2019/10/22
  https://atcoder.jp/contests/joisc2012/tasks/joisc2012_copypaste
*/

signed main(){
  JOISC2012_COPYPASTE();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bbst/rbst/persistent/array.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

