#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2572"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

#define IGNORE

// area of 2 circles' intersection
signed main(){
  double uw,uh,a,b,ab;
  while(cin>>uw>>uh>>a>>b>>ab,uw!=0){
    Circle c1(Point(0,0),sqrt(a/PI));
    Circle c2(Point(0,0),sqrt(b/PI));
    bool f=0;
    if(c1.r<=c2.r) swap(c1,c2),f=1;
    double l=max(0.0,c1.r-c2.r),r=c1.r+c2.r+EPS;
    for(int k=0;k<100;k++){
      double m=(l+r)/2;
      c2.c.x=m;
      if(area(c1,c2)<=ab) r=m;
      else l=m;
    }
    c2.c.x=l;

    double EPS3=1e-4;
    assert(abs(area(c1,c2)-ab)<=EPS3);

    l=0,r=PI/2;
    for(int k=0;k<200;k++){
      double m=(l+r)/2;
      Circle t=c2;
      t.c=translate(c2.c,m);
      if(c1.r+max(c1.r,t.c.x+t.r)<=uw) r=m;
      else l=m;
    }
    c2.c=translate(c2.c,r);

    Vector v(c1.r,c1.r);
    c1.c=c1.c+v;
    c2.c=c2.c+v;

    if(f) swap(c1,c2);
    f=1;
    f&=(c1.c.x-c1.r>=-EPS3);
    f&=(c1.c.x+c1.r<=uw+EPS3);
    f&=(c1.c.y-c1.r>=-EPS3);
    f&=(c1.c.y+c1.r<=uh+EPS3);
    f&=(c2.c.x-c2.r>=-EPS3);
    f&=(c2.c.x+c2.r<=uw+EPS3);
    f&=(c2.c.y-c2.r>=-EPS3);
    f&=(c2.c.y+c2.r<=uh+EPS3);
    if(f) cout<<c1.c<<" "<<c1.r<<" "<<c2.c<<" "<<c2.r<<endl;
    else cout<<"impossible"<<endl;
  }
  return 0;
}
