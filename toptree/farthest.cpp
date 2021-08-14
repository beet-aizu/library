#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  Vertex():handle(nullptr){}
};

template<typename T>
struct Farthest{
  struct pi{
    T dist;
    int idx;
    pi():dist(0),idx(-1){}
    pi(T dist,int idx):dist(dist),idx(idx){}
    bool operator<(const pi &o)const{return dist<o.dist;}
    pi operator+(const T e)const{return pi(dist+e,idx);}
  };
  pi md,lf,rg;
  T len;
  Farthest():lf(0,-1),rg(0,-1),len(0){}
  Farthest(T d,int f,int t):lf(d,t),rg(d,f),len(d){}
  Farthest(pi md,pi lf,pi rg,T len):md(md),lf(lf),rg(rg),len(len){}
  void toggle(){swap(lf,rg);}
  static Farthest compress(Farthest &x,Vertex*,Farthest &y){
    return Farthest(
      max(x.rg,y.lf),
      max(x.lf,y.lf+x.len),
      max(y.rg,x.rg+y.len),
      x.len+y.len);
  }
  static Farthest rake(Farthest &x,Farthest &y){
    return Farthest(pi(),max(x.lf,y.rg+x.len),max(x.rg,y.rg),x.len);
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
