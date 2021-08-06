#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename F>
struct Grid{
  const int h,w;
  const F f;
  Grid(int h_,int w_,F f_):h(h_),w(w_),f(f_){}
  int idx(int y,int x){return y*w+x;}
  using T = typename invoke_result<F, int, int>::type;
  T operator[](int k){return f(k/w,k%w);}
  decltype(auto) edges(){
    vector<pair<int, int>> es;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(i+1<h) es.emplace_back(idx(i,j),idx(i+1,j));
        if(j+1<w) es.emplace_back(idx(i,j),idx(i,j+1));
      }
    }
    return es;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
