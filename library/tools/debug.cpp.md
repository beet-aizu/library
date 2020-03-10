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


# :warning: tools/debug.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/debug.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 14:46:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;

#define IGNORE

//BEGIN CUT HERE
const int DEBUG = 1;
template<typename ...Ts>
void debug(Ts... ts){
  if(!DEBUG) return;
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  int a=42;
  string s="UKU";
  char c='$';
  debug(a,100,s,c);
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tools/debug.cpp"
#include<bits/stdc++.h>
using namespace std;

#define IGNORE

//BEGIN CUT HERE
const int DEBUG = 1;
template<typename ...Ts>
void debug(Ts... ts){
  if(!DEBUG) return;
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  int a=42;
  string s="UKU";
  char c='$';
  debug(a,100,s,c);
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

