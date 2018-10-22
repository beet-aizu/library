#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
vector<int> parallelbinarysearch(int n,int q,
                                 function<void(void)> init,
                                 function<void(int)> apply,
                                 function<bool(int)> check){
  vector<vector<int> > C(q);
  vector<int> L(n,-1),R(n,q);
  bool flg=1;
  while(flg){
    flg=0;
    init();
    for(int i=0;i<n;i++)
      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);
    for(int i=0;i<q;i++){
      flg|=!C[i].empty();
      apply(i);
      for(int j:C[i]){
        if(check(j)) R[j]=i;
        else L[j]=i;
      }
      C[i].clear();
    }
  }
  return R;
}
//END CUT HERE

template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,E)> G;
  typedef function<T(E,E)> H;
  Int n;
  G g;
  H h;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(){};
  SegmentTree(Int n_,G g,H h,T d1,E d0,
              vector<T> v=vector<T>()):
    g(g),h(h),d1(d1),d0(d0){
    init(n_);
    if(n_==(Int)v.size()) build(n_,v);
  }
  void init(Int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(n,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(Int n_, vector<T> v){
    for(Int i=0;i<n_;i++) dat[i]=v[i];
  }
  void update(Int a,Int b,E x,Int k,Int l,Int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
  }
  void update(Int a,Int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(Int k){
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

signed SPOJ_METEORS(){
  Int n,m;
  cin>>n>>m;
  vector<Int> o(m),p(n);
  for(Int i=0;i<m;i++) cin>>o[i];
  for(Int i=0;i<n;i++) cin>>p[i];
  Int q;
  cin>>q;
  vector<Int> l(q),r(q),a(q);
  for(Int i=0;i<q;i++) cin>>l[i]>>r[i]>>a[i];
  for(Int i=0;i<q;i++) l[i]--,r[i]--;
  
  vector<vector<Int> > x(n);
  for(Int i=0;i<m;i++) x[--o[i]].emplace_back(i);

  auto g=[](Int a,Int b){return a+b;};
  SegmentTree<Int, Int> seg;
  
  auto init=[&]{seg=SegmentTree<Int, Int>(m,g,g,0,0);};
  
  auto apply=[&](Int i){
               if(l[i]<=r[i]) seg.update(l[i],r[i]+1,a[i]);
               else{
                 seg.update(0,r[i]+1,a[i]);
                 seg.update(l[i],m,a[i]);
               }
             };
  
  auto check=[&](Int i){
               Int s=0;
               for(Int j:x[i]){
                 s+=seg.query(j);
                 if(s>=p[i]) break;
               }
               return s>=p[i];
             };
  
  vector<int> R=parallelbinarysearch(n,q,init,apply,check);

  init();
  for(Int i=0;i<q;i++) apply(i);
  
  for(Int i=0;i<n;i++){
    if(!check(i)) R[i]=q+1;
    if(R[i]>q) cout<<"NIE"<<endl;
    else cout<<R[i]+1<<endl;
  }
  
  return 0;
};


struct UnionFind{
  int n;
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};

signed CODETHANKSFESTIVAL2017_H(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) cin>>a[i]>>b[i];
  int q;
  cin>>q;
  vector<int> x(q),y(q);
  for(int i=0;i<q;i++) cin>>x[i]>>y[i];
  
  for(int i=0;i<m;i++) a[i]--,b[i]--;
  for(int i=0;i<q;i++) x[i]--,y[i]--;

  UnionFind uf;
  auto init=[&]{uf=UnionFind(n);};
  auto apply=[&](int i){uf.unite(a[i],b[i]);};
  auto check=[&](int i){return uf.same(x[i],y[i]);};

  auto ans=parallelbinarysearch(q,m,init,apply,check);

  for(int i=0;i<q;i++)
    cout<<(ans[i]==m?-1:ans[i]+1)<<endl;
  
  return 0;
}

signed main(){
  //SPOJ_METEORS();
  CODETHANKSFESTIVAL2017_H();
}
/*
  verified on 2017/12/31
  http://www.spoj.com/problems/METEORS/
  https://beta.atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
*/
