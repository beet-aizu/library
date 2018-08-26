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
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void update(int k,E a){
    k+=n;
    dat[k]=g(dat[k],a);
    while(k){
      k>>=1;
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
    }
  }
  inline T query(int a,int b){
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
  auto g=[](int a,int b){++a;return b;};
  SegmentTree<int,int> rmq(n,f,g,INT_MAX);
  
  for(int i=0;i<q;i++){
    int c,x,y;
    scanf("%d %d %d",&c,&x,&y);
    if(c) printf("%d\n",rmq.query(x,y+1));
    else rmq.update(x,y);
  }
  return 0;
}
/*
  verified on 2018/08/21
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
*/

signed ARC038_C(){
  Int n;
  scanf("%lld",&n);
  vector<Int> c(n,0),a(n,0);
  for(Int i=1;i<n;i++) scanf("%lld %lld",&c[i],&a[i]);
  
  auto f=[](Int a,Int b){return min(a,b);};
  auto g=[](Int a,Int b){return max(a,b);};
  SegmentTree<Int, Int> seg(n,f,g,-1);
  
  vector<Int> dp(n);
  dp[0]=0;
  seg.update(0,0);
  for(Int i=1;i<n;i++){
    auto check=[&](Int x){return x<i-c[i];};
    dp[i]=seg.find(0,n,check);
    seg.update(dp[i],i);
  }
  
  Int ans=0;
  for(Int i=1;i<n;i++)
    if(a[i]&1) ans^=dp[i];
  
  puts(ans?"First":"Second");
  return 0;
}

/*
  verified on 2018/08/21
  https://beta.atcoder.jp/contests/arc038/tasks/arc038_c
*/

signed KUPC2013_D(){
  int n;
  scanf("%d",&n);
  vector<int> a(n+2,0);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);

  const int INF = 1.1e9;
  auto f=[](int a,int b){return min(a,b);};
  SegmentTree<int, int> seg(n+2,f,f,INF);
  seg.build(n+2,a);

  using P = pair<int, int>;
  set<P> sp;
  for(int k=0;k<2;k++){
    for(int i=1;i<=n;i++){
      auto check=[&](int x){return x<a[i];};
      int l=seg.find(i,n+2,check);
      sp.emplace(k?n+2-l:l,a[i]);
    }
    reverse(a.begin(),a.end());
    seg.build(n+2,a);
  }

  printf("%d\n",(int)sp.size()/2);
  return 0;
}

/*
  verified on 2018/08/26
  https://beta.atcoder.jp/contests/kupc2013/tasks/kupc2013_d
*/

signed main(){
  //AOJ_DSL2A();
  //ARC038_C();
  KUPC2013_D();
  return 0;
}
