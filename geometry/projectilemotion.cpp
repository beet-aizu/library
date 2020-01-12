#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// throw from origin to (x,y) with verocity v (x>0)
// g: gravity
template<typename D>
vector< pair<D, D> > projectile_motion(D v,D g,D x,D y){
  D a=x*x+y*y;
  D b=g*x*x*y-v*v*x*x;
  D c=g*g*x*x*x*x/4;
  if(b*b<4*a*c) return {};
  vector< pair<D, D> > res;
  {
    D p=(-b+sqrt(b*b-4*a*c))/(2*a);
    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));
  }
  {
    D p=(-b-sqrt(b*b-4*a*c))/(2*a);
    if(0<p&&p<v*v) res.emplace_back(sqrt(p),sqrt(v*v-p));
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
