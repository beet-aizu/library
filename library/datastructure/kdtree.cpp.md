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


# :heavy_check_mark: datastructure/kdtree.cpp
* category: datastructure


[Back to top page](../../index.html)



## Verified
* :heavy_check_mark: [test/aoj/DSL_2_C.test.cpp](../../verify/test/aoj/DSL_2_C.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct KDTree{
  class Node{
  public:
    int location;
    int p,l,r;
    Node(){}
  };
  class Point{
  public:
    int id,x,y;
    Point(){}
    Point(int id,int x,int y): id(id),x(x),y(y){}
    bool operator<(const Point &p)const{
      return id<p.id;
    }
    void print(){
      printf("%d\n",id);
    }
  };

  static const int NIL = -1;

  int N;
  vector<Point> P;
  vector<Node> T;
  int np;

  KDTree(){}
  KDTree(int N){init(N);}

  void init(int N_){
    N=N_;
    P.clear();
    T.clear();
    P.resize(N);
    T.resize(N);
  }

  static bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}
  static bool lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}

  int makeKDTree(int l,int r,int depth){
    if(!(l<r)) return NIL;
    int mid=(l+r)/2;
    int t = np++;
    if(depth%2==0){
      sort(P.begin()+l,P.begin()+r,lessX);
    }else{
      sort(P.begin()+l,P.begin()+r,lessY);
    }
    T[t].location=mid;
    T[t].l=makeKDTree(l,mid,depth+1);
    T[t].r=makeKDTree(mid+1,r,depth+1);
    return t;
  }

  void find(int v,int sx,int tx,int sy,int ty,int depth,vector<Point> &ans){
    int x=P[T[v].location].x;
    int y=P[T[v].location].y;
    if(sx<=x&&x<=tx&&sy<=y&&y<=ty){
      ans.push_back(P[T[v].location]);
    }
    if(depth%2==0){
      if(T[v].l!=NIL){
        if(sx<=x) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(T[v].r!=NIL){
        if(x<=tx) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
      }
    }else{
      if(T[v].l!=NIL){
        if(sy<=y) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
      }
      if(T[v].r!=NIL){
        if(y<=ty) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
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

```
{% endraw %}

[Back to top page](../../index.html)

