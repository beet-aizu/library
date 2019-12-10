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


# :warning: tools/trio.cpp
* category: tools


<a href="../../index.html">Back to top page</a>



## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T, typename U, typename V>
struct trio{
  T first;
  U second;
  V third;
  trio(){}
  trio(T first,U second,V third):
    first(first),second(second),third(third){}
  operator tuple<T&, U&, V&>(){
    return forward_as_tuple(first,second,third);
  }
  using X = tuple<T, U, V>;
  operator X() const{return make_tuple(first,second,third);}
  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}
  bool operator!=(const trio&a) const{return (X)(*this)!=(X)a;}
  bool operator< (const trio&a) const{return (X)(*this)< (X)a;}
  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}
  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}
  bool operator>=(const trio&a) const{return (X)(*this)>=(X)a;}  
};
template<typename T, typename U, typename V>
trio<T, U, V> make_trio(T first,U second,V third){
  return trio<T, U, V>(first,second,third);
}
//END CUT HERE

template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }  
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}

//INSERT ABOVE HERE
signed CPSCO2019_SESSION1_H(){  
  Int n,sum;
  cin>>n>>sum;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  
  const Int MAX = 1e5+10;
  Int ans=0;
  MFP([&](auto dfs,Int l,Int r)->void{
        if(l+1==r){
          if(a[l]*3==sum) ans++;
          return;
        }
        Int m=(l+r)>>1;
        dfs(l,m);
        dfs(m,r);
        using T = trio<Int, Int, Int>;
        vector<T> vx,vy;        
        {
          vx.reserve(r-m);
          Int res=-1,cnt=0;
          for(Int i=m;i<r;i++){
            if(res<a[i]) res=a[i],cnt=0;
            if(res==a[i]) cnt++;
            vx.emplace_back(res,cnt,a[i]);
          }
        }
        {
          vy.reserve(m-l);
          Int res=-1,cnt=0;
          for(Int i=m-1;i>=l;i--){
            if(res<a[i]) res=a[i],cnt=0;
            if(res==a[i]) cnt++;
            vy.emplace_back(res,cnt,a[i]);
          }
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        
        map<Int, Int> cx,cy;
        Int sx=vx.size(),sy=vy.size();
        Int i=0,j=0;
        while(i<sx||j<sy){
          Int k=MAX;
          if(i<sx) chmin(k,vx[i].first);
          if(j<sy) chmin(k,vy[j].first);

          vector<Int> tx,ty;
          while(i<sx&&k==vx[i].first){
            cx[vx[i].third]++;
            tx.emplace_back(i++);
          }
          while(j<sy&&k==vy[j].first){
            cy[vy[j].third]++;
            ty.emplace_back(j++);
          }

          for(Int x:tx)
            ans+=vx[x].second*cy[sum-(k+vx[x].third)];
          for(Int y:ty)
            ans+=vy[y].second*cx[sum-(k+vy[y].third)];
        }
      })(0,n);
  
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/05/09
  https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_h
*/

signed main(){
  //CPSCO2019_SESSION1_H();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

