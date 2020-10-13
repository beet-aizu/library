#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../combinatorics/enumeration.cpp"
#include "../formalpowerseries/base.cpp"
#include "../formalpowerseries/inv.cpp"
#include "../formalpowerseries/div.cpp"
#include "../formalpowerseries/mod.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O(N log^2 N)
template<typename T>
struct MultiEval{
  FormalPowerSeries<T> FPS;
  using Poly = typename FormalPowerSeries<T>::Poly;
  using Conv = typename FormalPowerSeries<T>::Conv;

  MultiEval(Conv conv):FPS(conv){}

  using P = pair<int, int>;
  map<P, Poly> mem;
  void dfs(const vector<T> &cs,int l,int r){
    if(l+1==r){
      mem[{l,r}]=Poly({-cs[l],T(1)});
      return;
    }
    int m=(l+r)>>1;
    dfs(cs,l,m);
    dfs(cs,m,r);
    mem[{l,r}]=FPS.mul(mem[{l,m}],mem[{m,r}]);
  }

  void multi_eval(Poly ps,vector<T> &ws,int l,int r){
    if(l+1==r){
      ws[l]=FPS.mod(ps,mem[{l,r}])[0];
      return;
    }
    int m=(l+r)>>1;
    multi_eval(FPS.mod(ps,mem[{l,m}]),ws,l,m);
    multi_eval(FPS.mod(ps,mem[{m,r}]),ws,m,r);
  }

  vector<T> build(Poly ps,const vector<T> &cs){
    int n=cs.size();
    mem.clear();
    dfs(cs,0,n);
    vector<T> ws(n);
    multi_eval(ps,ws,0,n);
    return ws;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
