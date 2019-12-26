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


# :heavy_check_mark: datastructure/slidingwindowaggregation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/slidingwindowaggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html">test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,typename S>
struct SWAG{
  using F = function<S(S,T)>;
  F f;
  S id;
  vector<T> lt,rt;
  vector<S> ls,rs;
  SWAG(F f,S id):f(f),id(id),ls(1,id),rs(1,id){}

  void push(T x){
    rt.emplace_back(x);
    rs.emplace_back(f(rs.back(),x));
  }

  void pop(){
    if(lt.empty()){
      reverse(rt.begin(),rt.end());
      for(auto x:rt){
        lt.emplace_back(x);
        ls.emplace_back(f(ls.back(),x));
      }
      rt.resize(0);
      rs.resize(1);
    }
    lt.pop_back();
    ls.pop_back();
  }

  template<typename Q>
  void fold(Q q){q(ls.back(),rs.back());}
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE

class Crypto {
public:
  Crypto() {
    sm = cnt = 0;
    seed();
  }

  int decode(int z) {
    z ^= next();
    z ^= (next() << 8);
    z ^= (next() << 16);
    z ^= (next() << 22);
    return z;
  }

  void query(long long z) {
    const long long B = 425481007;
    const long long MD = 1000000007;
    cnt++;
    sm = ((sm * B % MD + z) % MD + MD) % MD;
    seed();
  }
private:
  long long sm;
  int cnt;

  uint8_t data[256];
  int I, J;

  void swap_data(int i, int j) {
    uint8_t tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }

  void seed() {
    uint8_t key[8];
    for (int i = 0; i < 4; i++) {
      key[i] = (sm >> (i * 8));
    }
    for (int i = 0; i < 4; i++) {
      key[i+4] = (cnt >> (i * 8));
    }

    for (int i = 0; i < 256; i++) {
      data[i] = i;
    }
    I = J = 0;

    int j = 0;
    for (int i = 0; i < 256; i++) {
      j = (j + data[i] + key[i%8]) % 256;
      swap_data(i, j);
    }
  }

  uint8_t next() {
    I = (I+1) % 256;
    J = (J + data[I]) % 256;
    swap_data(I, J);
    return data[(data[I] + data[J]) % 256];
  }
};

signed JAG2018_DAY2_D(){
  int MOD;
  cin>>MOD;
  int q;
  cin>>q;
  Crypto c;

  using ll = long long;
  const ll INF = 1e18;
  using T = pair<ll, ll>;
  using S = array<ll, 512>;
  auto f=
    [&](S x,T y){
      S z(x);
      for(int i=0;i<MOD;i++){
        int j=(i+y.first)%MOD;
        chmax(z[j],x[i]+y.second);
      }
      return z;
    };

  S id;
  fill(id.begin(),id.end(),-INF);
  id[0]=0;

  SWAG<T, S> swag(f,id);

  for(int i=0;i<q;i++){
    int t,w,v,l,r;
    cin>>t>>w>>v>>l>>r;
    t = c.decode(t);
    w = c.decode(w);
    v = c.decode(v);
    l = c.decode(l);
    r = c.decode(r);
    if(t == 1) swag.push(T(w,v));
    else swag.pop();

    r++;
    auto ask=
      [&](S x,S y){
        SWAG<ll, ll> rmq([](ll a,ll b){return max(a,b);},-INF);
        for(int i=0;i<r;i++) rmq.push(x[i]);
        for(int i=0;i<l;i++) rmq.pop();

        ll ans=-1;
        for(int i=MOD;i>0;i--){
          rmq.fold([&](ll a,ll b){chmax(ans,max(a,b)+y[i%MOD]);});
          rmq.push(x[(r+(MOD-i))%MOD]);
          rmq.pop();
        }
        c.query(ans);
        cout<<ans<<"\n";
      };
    swag.fold(ask);
  }
  return 0;
}
/*
  verified on 2019/11/29
  https://atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_d
*/

signed main(){
  JAG2018_DAY2_D();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: datastructure/slidingwindowaggregation.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

