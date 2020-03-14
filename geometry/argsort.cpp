#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// (-pi, pi], atan2(0, 0) = 0
template<typename P>
void argsort(vector<P> &ps){
  auto getA=
    [&](P p){
      if(p.x>=0 and p.y>=0) return 0;
      if(p.y>=0) return 1;
      if(p.x<=0) return -2;
      return -1;
    };
  auto cross=[&](P a,P b){return a.x*b.y-a.y*b.x;};
  auto cmp=
    [&](P a,P b){
      if(getA(a)!=getA(b)) return getA(a)<getA(b);
      if(a.x==0 and a.y==0) return !(b.x==0 and b.y==0);
      if(b.x==0 and b.y==0) return false;
      return cross(a,b)>0;
    };
  sort(ps.begin(),ps.end(),cmp);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
