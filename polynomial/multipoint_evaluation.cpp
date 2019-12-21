#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "formalpowerseries.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
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

  vector<T> ans;
  void multi_eval(Poly ps,int l,int r){
    if(l+1==r){
      ans[l]=FPS.mod(ps,mem[{l,r}])[0];
      return;
    }
    int m=(l+r)>>1;
    multi_eval(FPS.mod(ps,mem[{l,m}]),l,m);
    multi_eval(FPS.mod(ps,mem[{m,r}]),m,r);
  }

  vector<T> build(Poly ps,const vector<T> &cs){
    mem.clear();
    dfs(cs,0,cs.size());
    ans.resize(cs.size());
    multi_eval(ps,0,cs.size());
    return ans;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
