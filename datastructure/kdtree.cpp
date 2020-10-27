#ifndef call_from_test
#include <bits/stdc++.h>
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
    if(sx<=x and x<=tx and sy<=y and y<=ty)
      ans.emplace_back(ps[ts[v].pos]);

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
