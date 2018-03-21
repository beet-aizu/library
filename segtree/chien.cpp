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
  SegmentTree(int n_,F f,G g,H h,T ti,E ei,
	      P p=[](E a,size_t b){b++;return a;}):
    f(f),g(g),h(h),ti(ti),ei(ei),p(p){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.assign(2*n-1,ti);
    laz.assign(2*n-1,ei);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  inline void eval(int len,int k){
    if(laz[k]==ei) return;
    if(k*2+1<n*2-1){
      laz[k*2+1]=h(laz[k*2+1],laz[k]);
      laz[k*2+2]=h(laz[k*2+2],laz[k]);
    }
    dat[k]=g(dat[k],p(laz[k],len));
    laz[k]=ei;
  }
  T update(int a,int b,E x,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return dat[k];
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return g(dat[k],p(laz[k],r-l));
    }
    return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),
		    update(a,b,x,k*2+2,(l+r)/2,r));
  }
  T update(int a,int b,E x){
    return update(a,b,x,0,0,n);
  }
  T query(int a,int b,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return ti;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
  void update(int k,T x){
    query(k,k+1);//evaluate
    k+=n-1;
    dat[k]=x;
    while(k){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
};
//END CUT HERE
signed main(){
  int n,q;
  cin>>n>>q;
  SegmentTree<Int,Int> ch(n,
			  [](Int a,Int b){return a+b;},
			  [](Int a,Int b){return a+b;},
			  [](Int a,Int b){return a+b;},
			  0,0,
			  [](Int a,Int b){return a*b;});
  ch.build(n,vector<Int>(n,0));
  for(int i=0;i<q;i++){
    int c,s,t,x;
    cin>>c;
    if(c){
      cin>>s>>t;
      cout<<ch.query(s-1,t)<<endl;
    }else{
      cin>>s>>t>>x;
      ch.update(s-1,t,x);
    }
  }
}

/*
  verified on 2018/03/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=jp
*/
