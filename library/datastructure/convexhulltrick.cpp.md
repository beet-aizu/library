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


# :warning: datastructure/convexhulltrick.cpp
* category: datastructure


<a href="../../index.html">Back to top page</a>



## Dependencies
* :warning: <a href="../tools/chminmax.cpp.html">tools/chminmax.cpp</a>


## Verified
* :warning: <a href="../../verify/test/aoj/2725.test.cpp.html">test/aoj/2725.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T,bool isMin>
struct ConvexHullTrick {
  #define F first
  #define S second
  using P = pair<T, T>;
  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.S==a.S||c.S==b.S)
      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S)) >=
      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));
  }

  void addLine(T m,T b){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b);
    if(empty()){
      H.emplace_front(line);
      return;
    }
    if(H.front().F<=m){
      if(H.front().F==m){
        if(H.front().S<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&
            check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().F);
      if(H.back().F==m){
        if(H.back().S<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&
            check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a,const T &x){
    return a.F*x+a.S;
  }

  T query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return -getY(H[r],x);
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return -getY(H.front(),x);
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&
          getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return -getY(H.back(),x);
  }
  #undef F
  #undef S
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed TENKA12016FINAL_E(){
  using ll = long long;

  int n,l;
  scanf("%d %d",&n,&l);
  vector<vector<int> > as(n,vector<int>(l));
  for(int i=0;i<n;i++)
    for(int j=0;j<l;j++)
      scanf("%d",&as[i][j]);

  vector<ll> dp(l,0);

  for(int i=0;i<n;i++){
    ConvexHullTrick<ll, true> cht;
    for(ll j=0;j<l;j++)
      cht.addLine(-2*j,as[i][j]+j*j);
    for(ll j=0;j<l;j++)
      dp[j]+=j*j+cht.queryMonotoneInc(j);
  }

  printf("%lld\n",*min_element(dp.begin(),dp.end()));
  return 0;
}
/*
  verified on 2019/11/11
  https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_e
*/

signed COLOPL2018FINAL_C(){
  using ll = long long;

  int n;
  scanf("%d",&n);
  vector<ll> as(n);
  for(int i=0;i<n;i++) scanf("%lld",&as[i]);
  ConvexHullTrick<ll, false> cht;
  for(ll i=0;i<n;i++) cht.addLine(-2*i,-(as[i]+i*i));
  for(ll i=0;i<n;i++) printf("%lld\n",-cht.queryMonotoneDec(-i)+i*i);
  return 0;
}
/*
  verified on 2019/11/11
  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/

signed main(){
  //TENKA12016FINAL_E();
  //COLOPL2018FINAL_C();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

