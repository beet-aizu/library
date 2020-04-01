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


# :x: toptree/steiner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5c8bf2a6852b9bc7e4261d66e9a6b762">toptree</a>
* <a href="{{ site.github.repository_url }}/blob/master/toptree/steiner.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 17:45:41+09:00




## Verified with

* :x: <a href="../../verify/test/yukicoder/3453.test.cpp.html">test/yukicoder/3453.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  int color;
  Vertex(int color=0):handle(nullptr),color(color){}
};

template<typename T>
struct SteinerTree{
  T con,len,lf,rg,md,chd,ans;
  SteinerTree(T len=0):con(0),len(len),lf(0),rg(0),md(0),chd(0),ans(0){}
  void toggle(){return swap(lf,rg);}
  static SteinerTree compress(SteinerTree x,Vertex* v,SteinerTree y){
    if(x.chd){
      if(!x.con){
        x.con=1;
        x.lf=x.len;
        x.rg=0;
        x.md=x.chd;
      }else{
        x.ans+=x.md+x.rg+x.chd;
        x.md=x.rg=x.chd=0;
      }
    }

    if(!x.con and !(v->color) and !y.con)
      return Cluster(x.len+y.len);

    SteinerTree nxt;
    nxt.con=1;
    nxt.lf=x.con?x.lf:(v->color?x.len:x.len+y.lf);
    nxt.rg=y.con?y.rg:(v->color?y.len:y.len+x.rg);
    nxt.ans=x.ans+y.ans;
    if(x.con and (v->color or y.con)){
      nxt.ans+=x.md+x.rg;
      x.md=0;
    }
    if(y.con and (v->color or x.con)){
      nxt.ans+=y.md+y.lf;
      y.md=0;
    }
    nxt.md=x.md+y.md;
    return nxt;
  }

  static SteinerTree rake(SteinerTree x,SteinerTree y){
    x.chd+=y.chd+y.rg+y.md;
    x.ans+=y.ans;
    return x;
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
#line 2 "toptree/steiner.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  int color;
  Vertex(int color=0):handle(nullptr),color(color){}
};

template<typename T>
struct SteinerTree{
  T con,len,lf,rg,md,chd,ans;
  SteinerTree(T len=0):con(0),len(len),lf(0),rg(0),md(0),chd(0),ans(0){}
  void toggle(){return swap(lf,rg);}
  static SteinerTree compress(SteinerTree x,Vertex* v,SteinerTree y){
    if(x.chd){
      if(!x.con){
        x.con=1;
        x.lf=x.len;
        x.rg=0;
        x.md=x.chd;
      }else{
        x.ans+=x.md+x.rg+x.chd;
        x.md=x.rg=x.chd=0;
      }
    }

    if(!x.con and !(v->color) and !y.con)
      return Cluster(x.len+y.len);

    SteinerTree nxt;
    nxt.con=1;
    nxt.lf=x.con?x.lf:(v->color?x.len:x.len+y.lf);
    nxt.rg=y.con?y.rg:(v->color?y.len:y.len+x.rg);
    nxt.ans=x.ans+y.ans;
    if(x.con and (v->color or y.con)){
      nxt.ans+=x.md+x.rg;
      x.md=0;
    }
    if(y.con and (v->color or x.con)){
      nxt.ans+=y.md+y.lf;
      y.md=0;
    }
    nxt.md=x.md+y.md;
    return nxt;
  }

  static SteinerTree rake(SteinerTree x,SteinerTree y){
    x.chd+=y.chd+y.rg+y.md;
    x.ans+=y.ans;
    return x;
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

<a href="../../index.html">Back to top page</a>

