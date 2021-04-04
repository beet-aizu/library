#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
template<typename T>
struct Slope{
  using P = pair<T, T>;
  priority_queue<P, vector<P>, less<P>> L;
  priority_queue<P, vector<P>, greater<P>> R;
  T offset,entire;
  Slope():offset(0),entire(0){}

  inline T relu(T x){return max<T>(0,x);}

  template<typename PQ>
  inline void push(PQ &pq,T pos,T num){
    if(num!=T(0)) pq.emplace(pos,num);
  }

  template<typename From,typename To,typename Compare>
  void fix(T a,T cnt,From &from,To &to,Compare comp){
    T use(0);
    while(use<cnt and not from.empty() and comp(a,from.top().first)){
      auto[pos,num]=from.top();from.pop();
      T tmp=min(cnt-use,num);
      push(to,pos,tmp);
      push(from,pos,relu(num-tmp));
      push(from,a,tmp);
      entire+=max(a-pos,pos-a)*tmp;
      use+=tmp;
    }
    push(to,a,cnt-use);
  }

  void add_x_minus_a(T a,T cnt=T(1)){
    a-=offset;
    fix(a,cnt,L,R,[](T x,T y){return x<y;});
  }

  void add_a_minus_x(T a,T cnt=T(1)){
    a-=offset;
    fix(a,cnt,R,L,[](T x,T y){return x>y;});
  }

  // f_{new}(x) =  f_{old}(x + diff)
  void shift(T diff){offset-=diff;}

  // f_{new}(x) = min_{y<=x} f_{old}(y)
  void apply_cumulative_min(){
    while(!R.empty()) R.pop();
  }

  T get_val(T x){
    x-=offset;
    T res=entire;
    auto vectorize=[](auto pq){
      vector<P> vp;
      vp.reserve(pq.size());
      while(!pq.empty()) vp.emplace_back(pq.top()),pq.pop();
      return vp;
    };
    for(auto[pos,num]:vectorize(L)) res+=relu(pos-x)*num;
    for(auto[pos,num]:vectorize(R)) res+=relu(x-pos)*num;
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
