#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):
    f(f),g(g),d1(d1){
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
  void update(int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
};
//END CUT HERE
signed main(){
  int n,q;
  cin>>n>>q;
  SegmentTree<int,int> rmq(n,
			   [](int a,int b){return min(a,b);},
			   [](int a,int b){return b;},
			   INT_MAX);
  for(int i=0;i<q;i++){
    int c,x,y;
    cin>>c>>x>>y;
    if(c) cout<<rmq.query(x,y+1)<<endl;
    else rmq.update(x,y);
  }
  return 0;
}
/*
  verified on 2017/10/15
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
*/

