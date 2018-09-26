#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using P = function<E(E,size_t)>;
  int n;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  P p;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,H h,T ti,E ei,
	      P p=[](E a,size_t b){b++;return a;}):
    f(f),g(g),h(h),ti(ti),ei(ei),p(p){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,ti);
    laz.clear();
    laz.resize(2*n-1,ei);
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
    if(r<=a||b<=l) return ti;
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
  Int n,q;
  cin>>n>>q;
  SegmentTree<Int, Int>::F f=[](Int a,Int b){return min(a,b);};
  SegmentTree<Int, Int>::G g=[](Int a,Int b){return a+b;};
  const Int INF = 1e15;
  SegmentTree<Int, Int> seg(n,f,g,g,INF,0);
  seg.build(n,vector<Int>(n,0));
  for(Int i=0;i<q;i++){
    Int a,s,t,x;
    cin>>a>>s>>t;
    t++;
    if(a) cout<<seg.query(s,t)<<endl;
    if(!a){
      cin>>x;
      seg.update(s,t,x);
    }
  }
  return 0;
}
/*
  verified on 2018/03/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H&lang=jp
*/
