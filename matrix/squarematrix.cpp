#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//BEGIN CUT HERE
template<typename K, size_t N>
struct SquareMatrix{
  typedef array<K, N> arr;
  typedef array<arr, N> mat;
  mat dat;

  SquareMatrix(){
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        dat[i][j]=K(0);
  }
  
  size_t size() const{return N;};
  arr& operator[](size_t k){return dat[k];};
  const arr& operator[](size_t k) const {return dat[k];};
  
  static SquareMatrix cross(const SquareMatrix &A,const SquareMatrix &B){
    SquareMatrix res;
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        for(size_t k=0;k<N;k++)
          res[i][j]+=A[i][k]*B[k][j];
    return res;
  }

  static SquareMatrix identity(){
    SquareMatrix res;    
    for(size_t i=0;i<N;i++) res[i][i]=K(1);
    return res;
  }
  
  SquareMatrix pow(long long n) const{
    SquareMatrix a,res=identity();    
    for(size_t i=0;i<N;i++)
      for(size_t j=0;j<N;j++)
        a[i][j]=dat[i][j];
    
    while(n){
      if(n&1) res=cross(res,a);
      a=cross(a,a);      
      n>>=1;
    }
    return res;
  }
};
//END CUT HERE

template<typename T,T MOD = 1000000007>
struct Mint{
  T v;
  Mint():v(0){}
  Mint(signed v):v(v){}
  Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}

  Mint pow(long long k){
    Mint res(1),tmp(v);
    while(k){
      if(k&1) res*=tmp;
      tmp*=tmp;
      k>>=1;
    }
    return res;
  }
  
  Mint inv(){return pow(MOD-2);}
  
  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}
  
  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-(){return v?MOD-v:v;}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}
};


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, Int> dict(const vector<T> &v){
  map<T, Int> res;
  for(Int i=0;i<(Int)v.size();i++)
    res[v[i]]=i;
  return res;
}

template <typename T, typename F>
struct SegmentTree{
  Int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(Int n_){    
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    Int n_=v.size();
    init(n_);
    for(Int i=0;i<n_;i++) dat[n+i]=v[i];
    for(Int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void set_val(Int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);    
  }
  T query(Int a,Int b){
    T vl=ti,vr=ti;
    for(Int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};

//INSERT ABOVE HERE
signed YAHOO2019_FINAL_D(){
  using M = Mint<Int>;
  using MM = SquareMatrix<M, 2>;
  Int n,q;
  cin>>n>>q;
  vector<Int> ts(q),ls(q),rs(q),ps(q);
  for(Int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==1) cin>>ps[i];
    if(ts[i]==2) cin>>ls[i]>>rs[i];
  }
  vector<Int> vs;
  for(Int i=0;i<q;i++){
    if(ts[i]==1){
      vs.emplace_back(ps[i]);
      vs.emplace_back(ps[i]+1);  
      vs.emplace_back(ps[i]+2);   
      vs.emplace_back(ps[i]+3);      
    }
    if(ts[i]==2){
      vs.emplace_back(ls[i]);
      vs.emplace_back(ls[i]+1);
      vs.emplace_back(rs[i]);
      vs.emplace_back(rs[i]+1);
    }
  }
  vs.emplace_back(0);
  vs.emplace_back(n+1);
  vs=compress(vs);
  auto ms=dict(vs);
  
  MM A;
  A[0][0]=M(1);A[0][1]=M(1);
  A[1][0]=M(1);A[1][1]=M(0);

  vector<MM> vt(vs.size()-1,A);
  for(Int i=0;i+1<(Int)vs.size();i++){
    vt[i]=A.pow(vs[i+1]-vs[i]);
  }

  MM I=MM::identity();
  auto f=[&](MM a,MM b){return MM::cross(b,a);};
  SegmentTree<MM, decltype(f)> seg(f,I);
  seg.build(vt);
  
  vector<Int> used(vs.size(),0);  
  for(Int i=0;i<q;i++){
    if(ts[i]==1){
      Int k=ms[ps[i]];
      used[k]^=1;
      MM B;
      for(Int j=k;j<=k+2;j++){
        if(used[j]){
          B[0][0]=M(0);B[0][1]=M(0);
          B[1][0]=M(1);B[1][1]=M(0);        
        }else{
          B[0][0]=M(!used[j-1]);B[0][1]=M(!used[j-2]);
          B[1][0]=M(1);B[1][1]=M(0);
        }
        seg.set_val(j,B);   
      }
    }
    if(ts[i]==2){    
      Int l=ms[ls[i]],r=ms[rs[i]];
      if(used[l]){
        cout<<0<<"\n";
        continue;
      }
      auto B=seg.query(l+1,r+1);
      cout<<B[0][0].v<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/02/23
  https://atcoder.jp/contests/yahoo-procon2019-final/tasks/yahoo_procon2019_final_d
*/

signed DDCC2019_FINAL_D(){
  string s;
  cin>>s;
  using M = SquareMatrix<unsigned, 6>;
 
  auto f=[](M a,M b){return M::cross(a,b);};
  M ti=M::identity();
  SegmentTree<M, decltype(f)> seg(f,ti);
  vector<M> vt(s.size(),ti);
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='D') vt[i][0][1]=1;
    if(s[i]=='I') vt[i][1][2]=1;
    if(s[i]=='S') vt[i][2][3]=1;
    if(s[i]=='C') vt[i][3][4]=1;
    if(s[i]=='O') vt[i][4][5]=1;
  }
  seg.build(vt);
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    cout<<seg.query(l,r)[0][5]<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/02/23
  https://atcoder.jp/contests/ddcc2019-final/tasks/ddcc2019_final_d
*/

struct HLDecomposition {
  int n,pos;
  vector<vector<int> > G;
  vector<int> vid, head, sub, par, dep, inv, type;
  
  HLDecomposition(){}
  HLDecomposition(int n):
    n(n),pos(0),G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}
  
  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0;
    for(int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++);
    }
  }
  
  void dfs_sz(int v) {
    for(int &u:G[v]){
      if(u==par[v]) continue;
      par[u]=v;
      dep[u]=dep[v]+1;
      dfs_sz(u);      
      sub[v]+=sub[u];      
      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
    }
  }

  void dfs_hld(int v,int c) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c);
    }    
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  template<typename F>
  void for_each_edge(int u, int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]);
        break;
      }
    }
  }
  
  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }
};

signed YUKI_650(){
  using M = Mint<int>;
  using MM = SquareMatrix<M, 2>;
  auto f=[](MM a,MM b){return MM::cross(a,b);};
  
  int n;
  cin>>n;
  HLDecomposition hld(n);
  vector<int> X,Y;
  
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    X.emplace_back(a);
    Y.emplace_back(b);
    hld.add_edge(a,b);    
  }
  hld.build();
  
  MM ti=MM::identity();
  SegmentTree<MM, decltype(f)> seg(f,ti);
  seg.build(vector<MM>(n,ti));
    
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    char c;
    cin>>c;
    if(c=='x'){
      int v,a,b,c,d;
      cin>>v>>a>>b>>c>>d;
      int x=max(hld.vid[X[v]],hld.vid[Y[v]]);
      MM tmp;
      tmp[0][0]=M(a);tmp[0][1]=M(b);
      tmp[1][0]=M(c);tmp[1][1]=M(d);
      seg.set_val(x,tmp);
    }
    if(c=='g'){
      int x,y;
      cin>>x>>y;
      MM ans(ti);
      auto q=[&](int l,int r){ans=f(seg.query(l,r+1),ans);};
      hld.for_each_edge(x,y,q);  
      cout<<ans[0][0].v<<" "<<ans[0][1].v<<" ";
      cout<<ans[1][0].v<<" "<<ans[1][1].v<<"\n";
    }
  }
  cout<<flush;
  return 0;
}


signed main(){  
  //YAHOO2019_FINAL_D();
  //DDCC2019_FINAL_D();
  //YUKI_650();
  return 0;
}
