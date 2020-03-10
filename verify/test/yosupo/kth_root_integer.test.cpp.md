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


# :heavy_check_mark: test/yosupo/kth_root_integer.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/kth_root_integer.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:02:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/kth_root_integer">https://judge.yosupo.jp/problem/kth_root_integer</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/tools/int128.cpp.html">tools/int128.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/int128.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;

  using ll = __int128_t;
  for(int t=0;t<T;t++){
    ll A,K;
    cin>>A>>K;

    ll L=0,R=A+1;
    while(L+1<R){
      ll M=(L+R)>>1;

      ll res=1;
      for(int i=0;i<K;i++){
        res*=M;
        if(res>A) break;
      }

      if(res<=A) L=M;
      else R=M;
    }

    cout<<L<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/kth_root_integer.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/yosupo/../../tools/int128.cpp"

#line 3 "test/yosupo/../../tools/int128.cpp"
using namespace std;
/*
  multiprecision:
  #include <boost/multiprecision/cpp_int.hpp>
  using ll = boost::multiprecision::cpp_int;
*/
#endif
//BEGIN CUT HERE
__int128_t abs128(__int128_t val){return val<0?-val:val;}

ostream &operator<<(ostream &os,__int128_t val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,__int128_t &val){
  string s;
  is>>s;
  val=0;
  for(int i=0;i<(int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/kth_root_integer.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin>>T;

  using ll = __int128_t;
  for(int t=0;t<T;t++){
    ll A,K;
    cin>>A>>K;

    ll L=0,R=A+1;
    while(L+1<R){
      ll M=(L+R)>>1;

      ll res=1;
      for(int i=0;i<K;i++){
        res*=M;
        if(res>A) break;
      }

      if(res<=A) L=M;
      else R=M;
    }

    cout<<L<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

