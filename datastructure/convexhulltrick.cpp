#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template <typename T,bool isMin>
struct ConvexHullTrick {
  #define F first
  #define S second
  using P = pair<T, T>;
  deque<P> H;
  bool empty()const{return H.empty();}
  void clear(){H.clear();}

  inline int sgn(T x){return x==0?0:(x<0?-1:1);}

  using D = long double;
  inline bool check(const P &a,const P &b,const P &c){
    if(b.S==a.S||c.S==b.S)
      return sgn(b.F-a.F)*sgn(c.S-b.S) >= sgn(c.F-b.F)*sgn(b.S-a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
      D(b.F-a.F)*sgn(c.S-b.S)/D(abs(b.S-a.S)) >=
      D(c.F-b.F)*sgn(b.S-a.S)/D(abs(c.S-b.S));
  }

  void addLine(T m,T b){
    if(!isMin) m*=-1,b*=-1;
    P line(m,b);
    if(empty()){
      H.emplace_front(line);
      return;
    }
    if(H.front().F<=m){
      if(H.front().F==m){
        if(H.front().S<=b) return;
        H.pop_front();
      }
      while(H.size()>=2&&check(line,H.front(),H[1])) H.pop_front();
      H.emplace_front(line);
    }else{
      assert(m<=H.back().F);
      if(H.back().F==m){
        if(H.back().S<=b) return;
        H.pop_back();
      }
      while(H.size()>=2&&check(H[H.size()-2],H.back(),line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a,const T &x){
    return a.F*x+a.S;
  }

  T query(T x){
    assert(!empty());
    int l=-1,r=H.size()-1;
    while(l+1<r){
      int m=(l+r)>>1;
      if(getY(H[m],x)>=getY(H[m+1],x)) l=m;
      else r=m;
    }
    if(isMin) return getY(H[r],x);
    return -getY(H[r],x);
  }

  T queryMonotoneInc(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.front(),x)>=getY(H[1],x)) H.pop_front();
    if(isMin) return getY(H.front(),x);
    return -getY(H.front(),x);
  }

  T queryMonotoneDec(T x){
    assert(!empty());
    while(H.size()>=2&&getY(H.back(),x)>=getY(H[H.size()-2],x)) H.pop_back();
    if(isMin) return getY(H.back(),x);
    return -getY(H.back(),x);
  }
  #undef F
  #undef S
};
//END CUT HERE
#ifndef call_from_test
template<typename T1,typename T2> void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed TENKA12016FINAL_E(){
  int n,l;
  scanf("%d %d",&n,&l);
  vector<vector<int> > a(n,vector<int>(l));
  for(int i=0;i<n;i++)
    for(int j=0;j<l;j++)
      scanf("%d",&a[i][j]);

  vector<Int> dp(l,0);

  for(int i=0;i<n;i++){
    ConvexHullTrick<Int, true> cht;
    for(Int j=0;j<l;j++)
      cht.addLine(-2*j,a[i][j]+j*j);
    for(Int j=0;j<l;j++)
      dp[j]+=j*j+cht.queryMonotoneInc(j);
  }

  printf("%lld\n",*min_element(dp.begin(),dp.end()));
  return 0;
}
/*
  verified on 2019/05/14
  https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_e
*/

signed COLOPL2018FINAL_C(){
  int n;
  scanf("%d",&n);
  vector<Int> a(n);
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  ConvexHullTrick<Int, false> cht;
  for(Int i=0;i<n;i++) cht.addLine(-2*i,-(a[i]+i*i));
  for(Int i=0;i<n;i++) printf("%lld\n",-cht.queryMonotoneDec(-i)+i*i);
  return 0;
}
/*
  verified on 2019/05/14
  https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
*/

signed main(){
  //TENKA12016FINAL_E();
  //COLOPL2018FINAL_C();
  return 0;
}
#endif
