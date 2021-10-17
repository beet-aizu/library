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
    if(b.m==a.m or c.m==b.m)
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

  vector<pair<T, T>> getVertices(){
    vector<pair<T, T>> res;
    for(int i=0;i+1<(int)size();i++){
      auto l0=at(i+0),l1=at(i+1);
      assert(l0.k!=l1.k);
      T x=(l1.m-l0.m)/(l0.k-l1.k);
      res.emplace_back(x,at(i)(x)*objective);
    }
    return res;
  }
};
template<typename T>
using MinConvexHullTrick = ConvexHullTrick<T, Objective::MINIMIZE>;
template<typename T>
using MaxConvexHullTrick = ConvexHullTrick<T, Objective::MAXIMIZE>;

template<typename T>
void chmin(optional<T> &a,const T& b){if(!a or *a>b) a=b;}

// O(n \log n) (n = as.size())
template<typename T, Objective objective>
optional<T> solve_lp(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){
  auto calc=[&](T y0,T y1){return y0*p0+y1*p1;};
  using P = pair<T, T>;
  vector<P> vp;
  for(int i=0;i<(int)as.size();i++)
    vp.emplace_back(-bs[i]/as[i],cs[i]/as[i]);
  sort(vp.begin(),vp.end());

  ConvexHullTrick<T, objective> cht;
  for(auto[k,m]:vp) cht.add(k,m);

  optional<T> res;
  for(auto[y1,y0]:cht.getVertices())
    if(y0>=0 and y1>=0) chmin(res,calc(y0,y1));
  return res;
}

// minimize_{y0, y1 >=0} p0 y0 + p1 y1
// s.t. as[i] * y0 + bs[i] * y1 >= cs[i]
// assume as[i], bs[i] >0
template<typename T>
T solve_lp_min(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){
  T y0=0,y1=0;
  for(int i=0;i<(int)as.size();i++){
    y0=max(y0,cs[i]/as[i]);
    y1=max(y1,cs[i]/bs[i]);
  }
  auto res=solve_lp<T, Objective::MAXIMIZE>(+p0,+p1,as,bs,cs);
  chmin(res,p0*y0);
  chmin(res,p1*y1);
  return *res;
}

// maximize_{y0, y1 >=0} p0 y0 + p1 y1
// s.t. as[i] * y0 + bs[i] * y1 <= cs[i]
// assume as[i], bs[i] >0, cs[i] >=0
template<typename T>
T solve_lp_max(T p0,T p1,vector<T> as,vector<T> bs,vector<T> cs){
  T y0=cs[0]/as[0],y1=cs[0]/bs[0];
  for(int i=0;i<(int)as.size();i++){
    y0=min(y0,cs[i]/as[i]);
    y1=min(y1,cs[i]/bs[i]);
    as[i]=-as[i];bs[i]=-bs[i];cs[i]=-cs[i];
  }
  auto res=solve_lp<T, Objective::MINIMIZE>(-p0,-p1,as,bs,cs);
  chmin(res,-p0*y0);
  chmin(res,-p1*y1);
  return -*res;
}


//END CUT HERE
#ifndef call_from_test

signed ARC128_C(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s;
  cin>>n>>m>>s;

  using D = double;
  vector<D> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  vector<D> bs(n+1,0),cs(n+1,0);
  for(int i=0;i<=n;i++) bs[i]=n-i;
  for(int i=n;i>0;i--) cs[i-1]=as[i-1]+cs[i];

  D ans=solve_lp_min<D>(m,s,vector<D>(n+1,1),bs,cs);
  cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
/*
  verified on 2021/10/17
  https://atcoder.jp/contests/arc128/tasks/arc128_c
*/

signed main(){
  ARC128_C();
  return 0;
}
#endif
