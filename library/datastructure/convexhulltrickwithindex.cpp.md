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


# :warning: datastructure/convexhulltrickwithindex.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/convexhulltrickwithindex.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 21:51:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// index siyou kimattenai
template <typename T,bool isMin>
struct ConvexHullTrickWithIndex {
  struct P{
    T m,b;
    int idx;
    P(T m,T b,int idx):m(m),b(b),idx(idx){};
    bool operator<(const P &a){
      return m!=a.m?m<a.m:b<a.b;
    }
  };

  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.b==a.b||c.b==b.b)
      return sgn(b.m-a.m)*sgn(c.b-b.b) >= sgn(c.m-b.m)*sgn(b.b-a.b);
    return D(b.m-a.m)*sgn(c.b-b.b)/D(abs(b.b-a.b))
      >= D(c.m-b.m)*sgn(b.b-a.b)/D(abs(c.b-b.b));
  }

  void addLine(T m,T b,int idx){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b,idx);
    if(empty()){
      H.emplace_front(line);
      return;
    }

    if(empty()||H.front().m<=m){
      if(H.front().m==m){
        if(H.front().b<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().m);
      if(H.back().m==m){
        if(H.back().b<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline pair<T, int> getY(const P &a,const T &x){
    return make_pair(a.m*x+a.b,a.idx);
  }

  pair<T, int> query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return make_pair(-getY(H[r],x).first,H[r].idx);
  }

  pair<T, int> queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return make_pair(-getY(H.front(),x).first,H.front().idx);
  }

  pair<T, int> queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return make_pair(-getY(H.back(),x).first,H.back().idx);
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  ll n,m;
  cin>>n>>m;

  using CHT = ConvexHullTrickWithIndex<ll, true>;

  CHT cht;
  ll bs=0,ss=0,len=n;
  cht.addLine(0,-bs,0);

  for(int i=0;i<m;i++){
    int t;
    cin>>t;
    if(t==1){
      ll k;
      cin>>k;
      cht.clear();
      cht.addLine(0,-bs,0);
      len+=k;
    }
    if(t==2){
      ll k;
      cin>>k;
      cht.addLine(len,-(bs+len*ss),len);
      len+=k;
    }
    if(t==3){
      ll b,s;
      cin>>b>>s;
      bs+=b;
      ss+=s;
    }
    auto p=cht.queryMonotoneInc(ss);
    cout<<p.second+1<<" "<<bs+p.first<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/05/14
  https://codeforces.com/contest/1137/problem/E
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/convexhulltrickwithindex.cpp"
#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
// index siyou kimattenai
template <typename T,bool isMin>
struct ConvexHullTrickWithIndex {
  struct P{
    T m,b;
    int idx;
    P(T m,T b,int idx):m(m),b(b),idx(idx){};
    bool operator<(const P &a){
      return m!=a.m?m<a.m:b<a.b;
    }
  };

  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.b==a.b||c.b==b.b)
      return sgn(b.m-a.m)*sgn(c.b-b.b) >= sgn(c.m-b.m)*sgn(b.b-a.b);
    return D(b.m-a.m)*sgn(c.b-b.b)/D(abs(b.b-a.b))
      >= D(c.m-b.m)*sgn(b.b-a.b)/D(abs(c.b-b.b));
  }

  void addLine(T m,T b,int idx){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b,idx);
    if(empty()){
      H.emplace_front(line);
      return;
    }

    if(empty()||H.front().m<=m){
      if(H.front().m==m){
        if(H.front().b<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().m);
      if(H.back().m==m){
        if(H.back().b<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline pair<T, int> getY(const P &a,const T &x){
    return make_pair(a.m*x+a.b,a.idx);
  }

  pair<T, int> query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return make_pair(-getY(H[r],x).first,H[r].idx);
  }

  pair<T, int> queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return make_pair(-getY(H.front(),x).first,H.front().idx);
  }

  pair<T, int> queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return make_pair(-getY(H.back(),x).first,H.back().idx);
  }
};
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  ll n,m;
  cin>>n>>m;

  using CHT = ConvexHullTrickWithIndex<ll, true>;

  CHT cht;
  ll bs=0,ss=0,len=n;
  cht.addLine(0,-bs,0);

  for(int i=0;i<m;i++){
    int t;
    cin>>t;
    if(t==1){
      ll k;
      cin>>k;
      cht.clear();
      cht.addLine(0,-bs,0);
      len+=k;
    }
    if(t==2){
      ll k;
      cin>>k;
      cht.addLine(len,-(bs+len*ss),len);
      len+=k;
    }
    if(t==3){
      ll b,s;
      cin>>b>>s;
      bs+=b;
      ss+=s;
    }
    auto p=cht.queryMonotoneInc(ss);
    cout<<p.second+1<<" "<<bs+p.first<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/05/14
  https://codeforces.com/contest/1137/problem/E
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

