#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2308"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/drop.cpp"
#include "../../io/precision.cpp"
#include "../../geometry/projectilemotion.cpp"
#undef call_from_test

using D = double;
struct Point{
  D x,y;
  Point(){}
  Point(D x,D y):x(x),y(y){}
};

istream &operator>>(istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

signed main(){
  int n;
  D v;
  cin>>n>>v;
  Point t;
  cin>>t;
  vector<Point> ps(n),qs(n);
  for(int i=0;i<n;i++) cin>>ps[i]>>qs[i];
  for(int i=0;i<n;i++) chmin(qs[i].x,t.x);

  D g=9.8;

  if(t.x==0){
    D ti=v/g;
    D y=v*ti-g/2*ti*ti;
    if(y>=t.y) drop("Yes");
    drop("No");
  }

  const D EPS = 1e-10;
  vector<D> cand;
  auto push=
    [&](Point s){
      for(auto pq:projectile_motion(v,g,s.x,s.y)){
        D d=pq.first;
        cand.emplace_back(d);
        cand.emplace_back(d+EPS);
        cand.emplace_back(d-EPS);
      }
    };

  for(int i=0;i<n;i++){
    if(ps[i].x>=t.x) continue;
    push(ps[i]);
    push(qs[i]);
    push(Point(ps[i].x,qs[i].y));
    push(Point(qs[i].x,ps[i].y));
  }
  push(t);

  auto getY=
    [&](D p,D q,D x){
      D ti=x/p;
      return q*ti-g/2*ti*ti;
    };

  auto in=
    [&](int k,D p,D q)->int{
      if(ps[k].x>=t.x) return 0;

      if(ps[k].y<getY(p,q,ps[k].x) && getY(p,q,ps[k].x)<qs[k].y) return 1;
      if(ps[k].y<getY(p,q,qs[k].x) && getY(p,q,qs[k].x)<qs[k].y) return 1;

      if(ps[k].y<getY(p,q,ps[k].x) && getY(p,q,qs[k].x)<ps[k].y) return 1;
      if(ps[k].y<getY(p,q,qs[k].x) && getY(p,q,ps[k].x)<ps[k].y) return 1;

      if(qs[k].y<getY(p,q,ps[k].x) && getY(p,q,qs[k].x)<qs[k].y) return 1;
      if(qs[k].y<getY(p,q,qs[k].x) && getY(p,q,ps[k].x)<qs[k].y) return 1;

      D ti=q/g;
      Point top(p*ti,getY(p,q,p*ti));
      if(ps[k].x<top.x && top.x<qs[k].x &&
         ps[k].y<top.y && top.y<qs[k].y) return 1;

      return 0;
    };


  for(D p:cand){
    D q=sqrt(v*v-p*p);

    if(getY(p,q,t.x)<t.y) continue;

    int flg=1;
    for(int i=0;i<n;i++)
      if(in(i,p,q)) flg=0;

    if(flg) drop("Yes");
  }

  cout<<"No"<<endl;
  return 0;
}
