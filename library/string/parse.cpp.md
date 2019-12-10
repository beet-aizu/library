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


# :heavy_check_mark: string/parse.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/parse.cpp">View this file on GitHub</a> (Last commit date: 2019-10-22 00:17:44 +0900)




## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/0109.test.cpp.html">test/aoj/0109.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
int expression(string,int&);
int term(string,int&);
int factor(string,int&);
int number(string,int&);

bool f;

int expression(string s,int& p){
  int res=term(s,p);
  while(p<(int)s.size()){
    if(s[p]=='+'){
      p++;
      res+=term(s,p);
      continue;
    }
    if(s[p]=='-'){
      p++;
      res-=term(s,p);
      continue;
    }
    break;
  }
  return res;
}

int term(string s,int& p){
  int res=factor(s,p);
  while(p<(int)s.size()){
    if(s[p]=='*'){
      p++;
      res*=factor(s,p);
      continue;
    }
    if(s[p]=='/'){
      p++;
      int tmp=factor(s,p);
      if(tmp==0){
        f=1;
        break;
      }
      res/=tmp;
      continue;
    }
    break;
  }
  return res;
}

int factor(string s,int& p){
  int res;
  if(s[p]=='('){
    p++;
    res=expression(s,p);
    p++;
  }else{
    res=number(s,p);
  }
  return res;
}

int number(string s,int& p){
  int res=0;
  while(p<(int)s.size()&&isdigit(s[p]))
    res=res*10+s[p++]-'0';
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

<a href="../../index.html">Back to top page</a>

