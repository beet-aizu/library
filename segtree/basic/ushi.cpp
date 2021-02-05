#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int max_right(int s,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?-1:k-n;
    }
    int m=(l+r)>>1;
    if(m<=s) return max_right(s,check,acc,(k<<1)|1,m,r);
    if(s<=l and check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=max_right(s,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return max_right(s,check,acc,(k<<1)|1,m,r);
  }

  // max t s.t. check(query(s,t))
  // O(\log N)
  template<typename C>
  int max_right(int s,C &check){
    assert(s<n and check(ti) and not check(query(s,n)));
    T acc=ti;
    return max_right(s,check,acc,1,0,n);
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
