#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(int n_,G g,H h,T ti,E ei):
    g(g),h(h),ti(ti),ei(ei){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(n,ti);
    laz.clear();
    laz.resize(2*n-1,ei);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i]=v[i];
  }
  void eval(int k){
    if(k*2+1<2*n-1){
      laz[k*2+1]=h(laz[k*2+1],laz[k]);
      laz[k*2+2]=h(laz[k*2+2],laz[k]);
      laz[k]=ei;
    }
  }
  void update(int a,int b,E x,int k,int l,int r){
    eval(k);
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
  void eval2(int k){
    if(k) eval2((k-1)/2);
    eval(k);
  }  
  T query(int k){
    T c=dat[k];
    k+=n-1;
    eval2(k);
    return g(c,laz[k]);
  }
};
//END CUT HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,q;
  cin>>n>>q;
  SegmentTree<int,int> beet(n,
			    [&](int a,int b){ return b<0?a:b;},
			    [&](int a,int b){ return b<0?a:b;},
			    INT_MAX,-1);
  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c){
      int x;
      cin>>x;
      cout<<beet.query(x)<<endl;
    }else{
      int s,t,x;
      cin>>s>>t>>x;
      t++;
      beet.update(s,t,x);
    }
  }
  return 0;
}
/*
  verified on 2018/03/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&lang=jp
*/
