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


# :heavy_check_mark: test/aoj/DSL_2_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-12 16:34:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/kdtree.cpp.html">datastructure/kdtree.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/kdtree.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  KDTree<int> kd;
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    kd.add_point(i,x,y);
  }
  int root=kd.build();

  int q;
  cin>>q;
  int sx,tx,sy,ty;
  vector<decltype(kd)::Point> ans;
  for(int i=0;i<q;i++){
    cin>>sx>>tx>>sy>>ty;
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(auto p:ans) cout<<p.id<<"\n";
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/aoj/../../tools/fastio.cpp"

#line 3 "test/aoj/../../tools/fastio.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 1 "test/aoj/../../datastructure/kdtree.cpp"

#line 3 "test/aoj/../../datastructure/kdtree.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct KDTree{
  static const int NIL = -1;

  class Node{
  public:
    int pos,p,l,r;
    Node(){pos=p=l=r=NIL;}
  };

  class Point{
  public:
    int id;
    T x,y;
    Point(){}
    Point(int id,T x,T y): id(id),x(x),y(y){}
    bool operator<(const Point &p)const{
      return id<p.id;
    }
  };

  vector<Point> ps;
  vector<Node> ts;
  int np;

  void add_point(int i,int x,int y){
    ps.emplace_back(i,x,y);
    ts.emplace_back();
  }

  static bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}
  static bool lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}

  int dfs(int l,int r,int depth){
    if(l>=r) return NIL;
    int mid=(l+r)/2;
    int t=np++;
    if(depth%2==0){
      sort(ps.begin()+l,ps.begin()+r,lessX);
    }else{
      sort(ps.begin()+l,ps.begin()+r,lessY);
    }
    ts[t].pos=mid;
    ts[t].l=dfs(l,mid,depth+1);
    ts[t].r=dfs(mid+1,r,depth+1);
    return t;
  }

  int build(){
    np=0;
    return dfs(0,ps.size(),0);
  }

  // [sx, tx] * [sy, ty]
  void find(int v,T sx,T tx,T sy,T ty,int depth,vector<Point> &ans){
    T x=ps[ts[v].pos].x;
    T y=ps[ts[v].pos].y;
    if(sx<=x&&x<=tx&&sy<=y&&y<=ty)
      ans.push_back(ps[ts[v].pos]);

    if(depth%2==0){
      if(ts[v].l!=NIL){
        if(sx<=x) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(ts[v].r!=NIL){
        if(x<=tx) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }else{
      if(ts[v].l!=NIL){
        if(sy<=y) find(ts[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(ts[v].r!=NIL){
        if(y<=ty) find(ts[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 9 "test/aoj/DSL_2_C.test.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  KDTree<int> kd;
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    kd.add_point(i,x,y);
  }
  int root=kd.build();

  int q;
  cin>>q;
  int sx,tx,sy,ty;
  vector<decltype(kd)::Point> ans;
  for(int i=0;i<q;i++){
    cin>>sx>>tx>>sy>>ty;
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(auto p:ans) cout<<p.id<<"\n";
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

