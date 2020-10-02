#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T, bool isMin>
struct LiChao{
  const T INF = numeric_limits<T>::max();
  struct Line{
    T a,b;
    Line(T a,T b):a(isMin?a:-a),b(isMin?b:-b){}
    T operator()(T x) const{return a*x+b;}
  };

  int n;
  vector<T> xs;
  vector<Line> dat;
  LiChao(const vector<T> &xs_):xs(xs_){
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    n=xs.size();
    dat.assign(n<<1,Line(T(0),INF));
  }

  int index(T x) const{
    return lower_bound(xs.begin(),xs.end(),x)-xs.begin();
  }

  T get(T x){
    T res=INF;
    for(int i=index(x)+n;i;i>>=1) res=min(res,dat[i](x));
    return isMin?res:-res;
  }

  // [xl, xr)
  void add_segment(T a,T b,T xl,T xr){
    Line g(a,b);
    for(int l=index(xl)+n,r=index(xr)+n;l<r;l>>=1,r>>=1){
      if(l&1) update(g,l++);
      if(r&1) update(g,--r);
    }
  }

  void update(Line g,int i){
    int l=i,r=i+1;
    while(l<n) l<<=1,r<<=1;
    while(l<r){
      int m=(l+r)>>1;
      T xl=xs[l-n],xr=xs[r-1-n],xm=xs[m-n];
      Line &f=dat[i];
      if(f(xl)<=g(xl) and f(xr)<=g(xr)) return;
      if(f(xl)>=g(xl) and f(xr)>=g(xr)) return (void)(f=g);
      if(f(xm)>g(xm)) swap(f,g);
      if(f(xl)>g(xl)) i=(i<<1)|0,r=m;
      else i=(i<<1)|1,l=m;
    }
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
