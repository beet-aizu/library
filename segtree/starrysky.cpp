#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  typedef function<T(E,E)> H;
  typedef function<E(E,int)> P;
  int n;
  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,H h,T d1,E d0,
	      vector<T> v=vector<T>(),P p=[](E a,int b){return a;}):
    f(f),g(g),h(h),d1(d1),d0(d0),p(p){
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int a,int b,E x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
    dat[k]=f(g(dat[k*2+1],p(laz[k*2+1],(r-l)>>1)),
	     g(dat[k*2+2],p(laz[k*2+2],(r-l)>>1)));
  }
  void update(int a,int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return g(dat[k],p(laz[k],r-l));
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return g(f(vl,vr),p(laz[k],min(r,b)-max(l,a)));
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
};
//END CUT HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  Int n,q;
  cin>>n>>q;
  SegmentTree<Int,Int> ss(n,
			  [](Int a,Int b){return max(a,b);},
			  plus<Int>(),
			  plus<Int>(),
			  INT_MIN,0,vector<Int>(n,0));
  for(Int i=0;i<q;i++){
    Int t,a,b;
    cin>>t>>a>>b;
    if(t==1){
      Int x;
      cin>>x;
      ss.update(a,b,x);
    }
    if(t==2){
      cout<<ss.query(a,b)<<endl;
    }
  }
  return 0;
}
/*
  verified on 2017/12/01
  https://hoj.hamako-ths.ed.jp/onlinejudge/problems/860
*/
