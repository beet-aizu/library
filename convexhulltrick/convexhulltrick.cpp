#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};

template<typename T> struct Line {
  T k,m;
  T operator()(const T x)const{return k*x+m;}
};

template <typename T, Objective objective>
struct ConvexHullTrick : deque<Line<T>>{
  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const Line<T> &a,const Line<T> &b,const Line<T> &c){
    if(b.m==a.m||c.m==b.m)
      return sgn(b.k-a.k)*sgn(c.m-b.m) >= sgn(c.k-b.k)*sgn(b.m-a.m);
    // return (b.k-a.k)*(c.m-b.m) >= (b.m-a.m)*(c.k-b.k);
    return
      D(b.k-a.k)*sgn(c.m-b.m)/D(abs(b.m-a.m)) >=
      D(c.k-b.k)*sgn(b.m-a.m)/D(abs(c.m-b.m));
  }

  using super = deque<Line<T>>;
  using super::empty,super::size,super::front,super::back;
  using super::emplace_front,super::emplace_back;
  using super::pop_front,super::pop_back;
  const Line<T> at(int i) const{return (*this)[i];}

  void add(T k_,T m_){
    Line<T> l({k_*objective,m_*objective});
    if(empty()){
      emplace_front(l);
      return;
    }
    if(front().k<=l.k){
      if(front().k==l.k){
        if(front().m<=l.m) return;
        pop_front();
      }
      while(size()>=2 and check(l,at(0),at(1))) pop_front();
      emplace_front(l);
    }else{
      assert(l.k<=back().k);
      if(back().k==l.k){
        if(back().m<=l.m) return;
        pop_back();
      }
      while(size()>=2 and check(at(size()-2),at(size()-1),l)) pop_back();
      emplace_back(l);
    }
  }

  T query(T x){
    assert(!empty());
    int l=-1,r=size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(at(m)(x)>=at(m+1)(x)) l=m;
      else r=m;
    }
    return at(r)(x)*objective;
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(size()>=2 and at(0)(x)>=at(1)(x)) pop_front();
    return front()(x)*objective;
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(size()>=2 and at(size()-1)(x)>=at(size()-2)(x)) pop_back();
    return back()(x)*objective;
  }
};
template<typename T>
using MinConvexHullTrick = ConvexHullTrick<T, Objective::MINIMIZE>;
template<typename T>
using MaxConvexHullTrick = ConvexHullTrick<T, Objective::MAXIMIZE>;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
