#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
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
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  template<typename C>
  int find(int a,int b,C &check,int k,int l,int r){
    if(!check(dat[k])||r<=a||b<=l) return -1;
    if(k>=n) return k-n;
    int m=(l+r)>>1;
    int vl=find(a,b,check,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(a,b,check,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int a,int b,C &check){
    return find(a,b,check,1,0,n);
  }
};
//END CUT HERE
signed AOJ_DSL2A(){
  int n,q;
  scanf("%d %d",&n,&q);
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int> rmq(f,INT_MAX);
  rmq.init(n);
  
  for(int i=0;i<q;i++){
    int c,x,y;
    scanf("%d %d %d",&c,&x,&y);
    if(c) printf("%d\n",rmq.query(x,y+1));
    else rmq.set_val(x,y);
  }
  return 0;
}
/*
  verified on 2019/01/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
*/

signed ARC038_C(){
  Int n;
  scanf("%lld",&n);
  vector<Int> c(n,0),a(n,0);
  for(Int i=1;i<n;i++) scanf("%lld %lld",&c[i],&a[i]);
  
  auto f=[](Int a,Int b){return min(a,b);};
  SegmentTree<Int> seg(f,-1);
  seg.init(n);
  
  vector<Int> dp(n);
  dp[0]=0;
  seg.set_val(0,0);
  for(Int i=1;i<n;i++){
    auto check=[&](Int x){return x<i-c[i];};
    dp[i]=seg.find(0,n,check);    
    seg.set_val(dp[i],max(seg.query(dp[i],dp[i]+1),i));
  }
  
  Int ans=0;
  for(Int i=1;i<n;i++)
    if(a[i]&1) ans^=dp[i];
  
  puts(ans?"First":"Second");
  return 0;
}

/*
  verified on 2019/01/16
  https://beta.atcoder.jp/contests/arc038/tasks/arc038_c
*/

signed KUPC2013_D(){
  int n;
  scanf("%d",&n);
  vector<int> a(n+2,0);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);

  const int INF = 1.1e9;
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int> seg(f,INF);
  seg.build(a);

  using P = pair<int, int>;
  set<P> sp;
  for(int k=0;k<2;k++){
    for(int i=1;i<=n;i++){
      auto check=[&](int x){return x<a[i];};
      int l=seg.find(i,n+2,check);
      sp.emplace(k?n+2-l:l,a[i]);
    }
    reverse(a.begin(),a.end());
    seg.build(a);
  }

  printf("%d\n",(int)sp.size()/2);
  return 0;
}

/*
  verified on 2019/01/16
  https://beta.atcoder.jp/contests/kupc2013/tasks/kupc2013_d
*/

signed main(){
  //AOJ_DSL2A();
  //ARC038_C();
  //KUPC2013_D();
  return 0;
}
