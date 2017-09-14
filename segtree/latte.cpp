#include<bits/stdc++.h>
using namespace std;
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f;
  G g;
  T d1;
  vector<T> dat;
  SegmentTree(int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()){
    this->f=f;
    this->g=g;
    this->d1=d1;
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int a,int b,E x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      dat[k]=g(dat[k],x);
      return;
    }
    update(a,b,k*2+1,l,(l+r)/2);
    update(a,b,k*2+2,(l+r)/2,r);
  }
  void update(int a,int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(int k){
    k+=n-1;
    T res=dat[k];
    while(k>0){
      k=(k-1)/2;
      res=f(res,dat[k]);
    }
    return res;
  }
};
signed main(){
  return 0;
}
