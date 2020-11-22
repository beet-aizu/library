#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
enum Objective{
  MINIMIZE = +1,
  MAXIMIZE = -1,
};

template <typename T,Objective objective>
struct SegmentContainer{
  const T INF = numeric_limits<T>::max() / 2;
  struct Segment{
    T a,b;
    T operator()(T x) const{return a*x+b;}
  };

  int n;
  vector<T> xs;
  vector<Segment> dat;
  SegmentContainer(const vector<T> &xs_):xs(xs_){
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    n=xs.size();
    dat.assign(n<<1,Segment({T(0),INF}));
  }

  inline int index(T x) const{
    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();
  }

  // [xl, xr)
  void add(T a,T b,T xl,T xr){
    Segment g({a*objective,b*objective});
    for(int l=index(xl)+n,r=index(xr)+n;l<r;l>>=1,r>>=1){
      if(l&1) update(g,l++);
      if(r&1) update(g,--r);
    }
  }

  void update(Segment g,int i){
    int l=i,r=i+1;
    while(l<n) l<<=1,r<<=1;
    while(l<r){
      int m=(l+r)>>1;
      T xl=xs[l-n],xr=xs[r-1-n],xm=xs[m-n];
      Segment &f=dat[i];
      if(f(xl)<=g(xl) and f(xr)<=g(xr)) return;
      if(f(xl)>=g(xl) and f(xr)>=g(xr)) return (void)(f=g);
      if(f(xm)>g(xm)) swap(f,g);
      if(f(xl)>g(xl)) i=(i<<1)|0,r=m;
      else i=(i<<1)|1,l=m;
    }
  }

  T query(T x){
    T res=INF;
    for(int i=index(x)+n;i;i>>=1) res=min(res,dat[i](x));
    return res*objective;
  }
};
template<typename T>
using MinSegmentContainer = SegmentContainer<T, Objective::MINIMIZE>;
template<typename T>
using MaxSegmentContainer = SegmentContainer<T, Objective::MAXIMIZE>;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
