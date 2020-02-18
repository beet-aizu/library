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


# :heavy_check_mark: tools/dice.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/dice.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0502.test.cpp.html">test/aoj/0502.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1197.test.cpp.html">test/aoj/1197.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_11_A.test.cpp.html">test/aoj/ITP1_11_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_11_B.test.cpp.html">test/aoj/ITP1_11_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_11_C.test.cpp.html">test/aoj/ITP1_11_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_11_D.test.cpp.html">test/aoj/ITP1_11_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Die{
  int s[6];
  int &top()   {return s[0];}
  int &south() {return s[1];}
  int &east()  {return s[2];}
  int &west()  {return s[3];}
  int &north() {return s[4];}
  int &bottom(){return s[5];}
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    string b("EWNSRL");
    int v[6][4]={{0,3,5,2},
                 {0,2,5,3},
                 {0,1,5,4},
                 {0,4,5,1},
                 {1,2,4,3},
                 {1,3,4,2}};
    for(int k=0;k<6;k++){
      if(b[k]!=c) continue;
      int t=s[v[k][0]];
      s[v[k][0]]=s[v[k][1]];
      s[v[k][1]]=s[v[k][2]];
      s[v[k][2]]=s[v[k][3]];
      s[v[k][3]]=t;
    }
  }
  using ll = long long;
  ll hash(){
    ll res=0;
    for(int i=0;i<6;i++) res=res*256+s[i];
    return res;
  }
  bool operator==(const Die &d) const{
    for(int i=0;i<6;i++) if(s[i]!=d.s[i]) return 0;
    return 1;
  }
};

vector<Die> makeDice(Die d){
  vector<Die> res;
  for(int i=0;i<6;i++){
    Die t(d);
    if(i==1) t.roll('N');
    if(i==2) t.roll('S');
    if(i==3) t.roll('S'),t.roll('S');
    if(i==4) t.roll('L');
    if(i==5) t.roll('R');
    for(int k=0;k<4;k++){
      res.push_back(t);
      t.roll('E');
    }
  }
  return res;
}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tools/dice.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

