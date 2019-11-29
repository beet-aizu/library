#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,typename S>
struct SWAG{
  using F = function<S(S,T)>;
  F f;
  S id;
  vector<T> lt,rt;
  vector<S> ls,rs;
  SWAG(F f,S id):f(f),id(id),ls(1,id),rs(1,id){}

  void push(T x){
    rt.emplace_back(x);
    rs.emplace_back(f(rs.back(),x));
  }

  void pop(){
    if(lt.empty()){
      reverse(rt.begin(),rt.end());
      for(auto x:rt){
        lt.emplace_back(x);
        ls.emplace_back(f(ls.back(),x));
      }
      rt.resize(0);
      rs.resize(1);
    }
    lt.pop_back();
    ls.pop_back();
  }

  template<typename Q>
  void fold(Q q){q(ls.back(),rs.back());}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
