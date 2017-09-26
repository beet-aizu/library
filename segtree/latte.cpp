#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,E)> G;
  typedef function<T(E,E)> H;
  int n;
  G g;
  H h;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(int n_,G g,H h,T d1,E d0,
	      vector<T> v=vector<T>()){
    this->g=g;
    this->h=h;
    this->d1=d1;
    this->d0=d0;
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(n,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i]=v[i];
  }
  void update(int a,int b,E x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
  }
  void update(int a,int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(int k){
    T c=dat[k];
    k+=n-1;
    E x=laz[k];
    while(k>0){
      k=(k-1)/2;
      x=h(x,laz[k]);
    }
    return g(c,x);
  }
};
//END CUT HERE
signed main(){
  return 0;
}
