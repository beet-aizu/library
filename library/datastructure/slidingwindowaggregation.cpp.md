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


# :warning: datastructure/slidingwindowaggregation.cpp
* category: datastructure


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [tools/chminmax.cpp](../tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](../tools/fastio.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp](../../verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html)


## Code
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

[Back to top page](../../index.html)

