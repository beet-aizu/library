// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3056
// verification-helper: ERROR 1e-5

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#include "../../../tools/chminmax.cpp"
#undef call_from_test


signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  for(int i=0;i<n;i++) ps.emplace_back(Point(ps[i]));
  for(int i=0;i<n;i++) ps.emplace_back(Point(ps[i]));

  double ans=1e18;
  int l=n,r=n+1;
  for(int i=n;i<n+n;i++){
    while(r<i+1) r++;
    double th=arg(ps[i+1]-ps[i]);
    Vector v1=polar(100,th+2*PI/3);
    Vector v2=polar(100,th+4*PI/3);

    Line b(ps[i],ps[i+1]);

    auto calc=
      [&](int k,Vector v,int w)->double{
        Point p=getCrossPointLL(b,Line(ps[k],ps[k]+v));
        if(abs(p-ps[i+w])<abs(p-ps[i+!w])) return -1;
        return abs(p-ps[i+w]);
      };

    while(calc(l,v2,1)<0) l++;
    while(calc(l,v2,1)<calc(l-1,v2,1)) l--;
    while(calc(l,v2,1)<calc(l+1,v2,1)) l++;
    while(calc(r,v1,0)<calc(r-1,v1,0)) r--;
    while(calc(r,v1,0)<calc(r+1,v1,0)) r++;

    Point p1=getCrossPointLL(b,Line(ps[r],ps[r]+v1));
    Point p2=getCrossPointLL(b,Line(ps[l],ps[l]+v2));
    chmin(ans,abs(p1-p2));
  }

  cout<<ans<<endl;
  return 0;
}
