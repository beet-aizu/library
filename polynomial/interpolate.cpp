#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "formalpowerseries.cpp"
#include "multieval.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O(N log^2 N)
template<typename T>
struct Interpolate : MultiEval<T>{
  using super=MultiEval<T>;
  using super::super;

  using typename super::Poly;
  using super::FPS;
  using super::mem;

  Poly interpolate(const vector<T> &xs,const vector<T> &ws,int l,int r){
    if(l+1==r) return Poly({ws[l]});
    int m=(l+r)>>1;
    return FPS.add(FPS.mul(interpolate(xs,ws,l,m),mem[{m,r}]),
                   FPS.mul(interpolate(xs,ws,m,r),mem[{l,m}]));
  }

  vector<T> build(const vector<T> &xs,const vector<T> &ys){
    int n=xs.size();
    mem.clear();
    super::dfs(xs,0,n);
    auto ls=FPS.diff(mem[{0,n}]);
    ls.resize(n,T(0));
    vector<T> ws(n);
    super::multi_eval(ls,ws,0,n);
    for(int i=0;i<n;i++) ws[i]=ys[i]/ws[i];
    return interpolate(xs,ws,0,n);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
