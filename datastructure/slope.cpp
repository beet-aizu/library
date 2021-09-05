#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
template<typename T>
struct Slope{

  template<template<typename> typename Comp_>
  struct PQ{
    template<typename X> using Comp = Comp_<X>;
    inline static constexpr Comp<T> comp{};
    using P = pair<T, T>;
    priority_queue<P, vector<P>, Comp<P>> pq;
    bool empty()const{return pq.empty();}

    T offset;
    PQ():offset(0){}
    bool compare(T a){return comp(a,pq.top().first+offset);}

    // f_{new}(x) =  f_{old}(x - diff)
    void shift(T diff){offset+=diff;}

    void push(T pos,T num){
      if(num!=T(0)) pq.emplace(pos-offset,num);
    }

    P pop(){
      auto[pos,num]=pq.top();pq.pop();
      return P(pos+offset,num);
    }
  };

  PQ<less> L;
  PQ<greater> R;
  T entire;
  Slope():entire(0){}

  inline T relu(T x){return max<T>(0,x);}

  template<typename From,typename To>
  void fix(T a,T cnt,From &from,To &to){
    T use(0);
    while(use<cnt and not from.empty() and from.compare(a)){
      auto[pos,num]=from.pop();
      T tmp=min(cnt-use,num);
      to.push(pos,tmp);
      from.push(pos,relu(num-tmp));
      from.push(a,tmp);
      entire+=max(a-pos,pos-a)*tmp;
      use+=tmp;
    }
    to.push(a,cnt-use);
  }

  // _/
  void add_x_minus_a(T a,T cnt=T(1)){
    fix(a,cnt,L,R);
  }

  // \_
  void add_a_minus_x(T a,T cnt=T(1)){
    fix(a,cnt,R,L);
  }

  // f_{new}(x) =  \min_{x-b<=y<=x-a} f_{old}(y)
  void shift(T a,T b){
    assert(a<=b);
    L.shift(a);
    R.shift(b);
  }

  // f_{new}(x) = f_{old}(x - a)
  void shift(T a){shift(a,a);}

  // f_{new}(x) = min_{y<=x} f_{old}(y)
  void apply_cumulative_min(){
    while(!R.empty()) R.pop();
  }

  T get_min(){return entire;}

  T get_val(T x){
    T res=entire;
    auto vectorize=[](auto pq){
      vector<pair<T, T>> vp;
      vp.reserve(pq.pq.size());
      while(!pq.empty()) vp.emplace_back(pq.pop());
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

// test shift(a, b)
signed ABC217_H(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  Slope<ll> S;
  S.add_a_minus_x(0,1e9);
  S.add_x_minus_a(0,1e9);

  ll n;
  cin>>n;
  ll l=0;
  for(ll i=0;i<n;i++){
    ll t,d,x;
    cin>>t>>d>>x;
    S.shift(l-t,t-l);
    l=t;
    if(d==0) S.add_a_minus_x(x);
    if(d==1) S.add_x_minus_a(x);
  }

  cout<<S.get_min()<<endl;
  return 0;
}

signed main(){
  ABC217_H();
  return 0;
}
#endif
