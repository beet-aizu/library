#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  int n;
  F f;
  G g;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T ti):
    f(f),g(g),ti(ti){
    init(n_);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.assign(2*n-1,ti);
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
  inline T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[(l++)-1]);
      if(r&1) vr=f(dat[(--r)-1],vr);
    }
    return f(vl,vr);
  }

  int find(int a,int b,function<bool(T)> &check,int k,int l,int r){
    if(!check(dat[k])||r<=a||b<=l) return -1;
    if(k>=n-1) return k-(n-1);
    int m=(l+r)>>1;
    int vl=find(a,b,check,k*2+1,l,m);
    if(~vl) return vl;
    return find(a,b,check,k*2+2,m,r);
  }
  
  int find(int a,int b,function<bool(T)> &check){
    return find(a,b,check,0,0,n);
  }
  
};
//END CUT HERE
signed AOJ_DSL2A(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n,q;
  cin>>n>>q;
  SegmentTree<int,int> rmq(n,
			   [](int a,int b){return min(a,b);},
			   [](int a,int b){++a;return b;},
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
  verified on 2018/03/04
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
*/

signed ARC038_C(){
  Int n;
  cin>>n;
  vector<Int> c(n,0),a(n,0);
  for(Int i=1;i<n;i++) cin>>c[i]>>a[i];
  
  SegmentTree<Int, Int>::F f=[](Int a,Int b){return min(a,b);};
  SegmentTree<Int, Int>::G g=[](Int a,Int b){return max(a,b);};
  SegmentTree<Int, Int> seg(n,f,g,-1);
  
  vector<Int> dp(n);
  dp[0]=0;
  seg.update(0,0);
  for(Int i=1;i<n;i++){
    function<bool(Int)> check=[&](Int x){return x<i-c[i];};
    dp[i]=seg.find(0,n,check);
    seg.update(dp[i],i);
  }
  
  Int ans=0;
  for(Int i=1;i<n;i++)
    if(a[i]&1) ans^=dp[i];
  
  cout<<(ans?"First":"Second")<<endl;
  return 0;
}

/*
  verified on 2018/01/30
  https://beta.atcoder.jp/contests/arc038/tasks/arc038_c
*/

signed main(){
  //AOJ_DSL2A();
  ARC038_C();
  return 0;
}
