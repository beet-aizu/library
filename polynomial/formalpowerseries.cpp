#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T>
struct FormalPowerSeries{
  using Poly = vector<T>;
  using Conv = function<Poly(Poly, Poly)>;
  Conv conv;
  FormalPowerSeries(Conv conv):conv(conv){}

  Poly add(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]+=bs[i];
    return cs;
  }

  Poly sub(Poly as,Poly bs){
    int sz=max(as.size(),bs.size());
    Poly cs(sz,T(0));
    for(int i=0;i<(int)as.size();i++) cs[i]+=as[i];
    for(int i=0;i<(int)bs.size();i++) cs[i]-=bs[i];
    return cs;
  }

  Poly mul(Poly as,Poly bs){
    return conv(as,bs);
  }

  Poly mul(Poly as,T k){
    for(auto &a:as) a*=k;
    return as;
  }

  // F(0) must not be 0
  Poly inv(Poly as,int deg){
    assert(as[0]!=T(0));
    Poly rs({T(1)/as[0]});
    int sz=1;
    while(sz<deg){
      sz<<=1;
      Poly ts(min(sz,(int)as.size()));
      for(int i=0;i<(int)ts.size();i++) ts[i]=as[i];
      rs=sub(add(rs,rs),mul(mul(rs,rs),ts));
      rs.resize(sz);
    }
    return rs;
  }

  // not zero
  Poly div(Poly as,Poly bs){
    while(as.back()==T(0)) as.pop_back();
    while(bs.back()==T(0)) bs.pop_back();
    if(bs.size()>as.size()) return Poly();
    reverse(as.begin(),as.end());
    reverse(bs.begin(),bs.end());
    int need=as.size()-bs.size()+1;
    Poly ds=mul(as,inv(bs,need));
    ds.resize(need);
    reverse(ds.begin(),ds.end());
    return ds;
  }

  // F(0) must be 1
  Poly sqrt(Poly as,int deg){
    assert(as[0]==T(1));

    int sz=1;
    T inv2=T(1)/T(2);
    Poly ss({T(1)});
    while(sz<deg){
      sz<<=1;
      Poly ts(min(sz,(int)as.size()));
      for(int i=0;i<(int)ts.size();i++) ts[i]=as[i];
      ss=add(ss,mul(ts,inv(ss,sz)));
      ss.resize(sz);
      for(T &x:ss) x*=inv2;
    }
    return ss;
  }

  Poly diff(Poly as){
    int n=as.size();
    Poly res(n-1);
    for(int i=1;i<n;i++) res[i-1]=as[i]*T(i);
    return res;
  }

  Poly integral(Poly as){
    int n=as.size();
    Poly res(n+1);
    res[0]=T(0);
    for(int i=0;i<n;i++) res[i+1]=as[i]/T(i+1);
    return res;
  }

  // F(0) must be 0
  Poly exp(Poly as,int deg){
    Poly f({T(1)}),g({T(1)});

    int sz=1;
    while(sz<deg){
      g=sub(mul(g,T(2)),mul(f,mul(g,g)));
      g.resize(sz+1);
      Poly q=diff(as);
      q.resize(sz);
      Poly w=add(q,mul(g,sub(diff(f),mul(f,q))));
      w.resize(2*sz);
      f=add(f,mul(f,sub(as,integral(w))));
      f.resize(2*sz+1);
      sz<<=1;
    }
    return f;
  }

  // F(0) must be 1
  Poly log(Poly as,int deg){
    Poly rs=integral(mul(diff(as),inv(as,deg)));
    rs.resize(deg);
    return rs;
  }

  Poly partition(int n){
    Poly rs(n+1);
    rs[0]=T(1);
    for(int k=1;k<=n;k++){
      if(1LL*k*(3*k+1)/2<=n) rs[k*(3*k+1)/2]+=T(k%2?-1LL:1LL);
      if(1LL*k*(3*k-1)/2<=n) rs[k*(3*k-1)/2]+=T(k%2?-1LL:1LL);
    }
    return inv(rs,n+1);
  }
};
//END CUT HERE
#ifndef call_from_test
template<typename T,T MOD = 1000000007>
struct Mint{
  static constexpr T mod = MOD;
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

  static Mint add_identity(){return Mint(0);}
  static Mint mul_identity(){return Mint(1);}

  Mint inv(){return pow(MOD-2);}

  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
  Mint& operator/=(Mint a){return (*this)*=a.inv();}

  Mint operator+(Mint a) const{return Mint(v)+=a;};
  Mint operator-(Mint a) const{return Mint(v)-=a;};
  Mint operator*(Mint a) const{return Mint(v)*=a;};
  Mint operator/(Mint a) const{return Mint(v)/=a;};

  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}

  bool operator==(const Mint a)const{return v==a.v;}
  bool operator!=(const Mint a)const{return v!=a.v;}
  bool operator <(const Mint a)const{return v <a.v;}

};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}

constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);
  using M = Mint<int, md>;
  vector< vector<M> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      M w=M(rt).pow((md-1)/(i<<1));
      M rw=w.inv();
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=M(1);rrts[i][0]=M(1);
      for(int k=1;k<i;k++){
        rts[i][k]=rts[i][k-1]*w;
        rrts[i][k]=rrts[i][k-1]*rw;
      }
    }
  }

  void ntt(vector<M> &as,bool f,int n=-1){
    if(n==-1) n=as.size();
    assert((n&(n-1))==0);
    ensure_base(n);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(as[i],as[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          M z=as[i+j+k]*(f?rrts[i][k]:rts[i][k]);
          as[i+j+k]=as[j+k]-z;
          as[j+k]+=z;
        }
      }
    }

    if(f){
      M tmp=M(n).inv();
      for(int i=0;i<n;i++) as[i]*=tmp;
    }
  }

  vector<M> multiply(vector<M> as,vector<M> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    as.resize(sz,M(0));
    bs.resize(sz,M(0));

    ntt(as,0);ntt(bs,0);
    for(int i=0;i<sz;i++) as[i]*=bs[i];
    ntt(as,1);

    as.resize(need);
    return as;
  }

  vector<int> multiply(vector<int> as,vector<int> bs){
    vector<M> am(as.size()),bm(bs.size());
    for(int i=0;i<(int)am.size();i++) am[i]=M(as[i]);
    for(int i=0;i<(int)bm.size();i++) bm[i]=M(bs[i]);
    vector<M> cm=multiply(am,bm);
    vector<int> cs(cm.size());
    for(int i=0;i<(int)cs.size();i++) cs[i]=cm[i].v;
    return cs;
  }
};
template<int X> constexpr int NTT<X>::md;
template<int X> constexpr int NTT<X>::rt;


namespace FFT{
  using dbl = double;

  struct num{
    dbl x,y;
    num(){x=y=0;}
    num(dbl x,dbl y):x(x),y(y){}
  };

  inline num operator+(num a,num b){
    return num(a.x+b.x,a.y+b.y);
  }
  inline num operator-(num a,num b){
    return num(a.x-b.x,a.y-b.y);
  }
  inline num operator*(num a,num b){
    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
  }
  inline num conj(num a){
    return num(a.x,-a.y);
  }

  int base=1;
  vector<num> rts={{0,0},{1,0}};
  vector<int> rev={0,1};

  const dbl PI=acosl(-1.0);

  void ensure_base(int nbase){
    if(nbase<=base) return;

    rev.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++)
      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));

    rts.resize(1<<nbase);
    while(base<nbase){
      dbl angle=2*PI/(1<<(base+1));
      for(int i=1<<(base-1);i<(1<<base);i++){
        rts[i<<1]=rts[i];
        dbl angle_i=angle*(2*i+1-(1<<base));
        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &a,int n=-1){
    if(n==-1) n=a.size();
    assert((n&(n-1))==0);

    int zeros=__builtin_ctz(n);
    ensure_base(zeros);
    int shift=base-zeros;
    for(int i=0;i<n;i++)
      if(i<(rev[i]>>shift))
        swap(a[i],a[rev[i]>>shift]);

    for(int k=1;k<n;k<<=1){
      for(int i=0;i<n;i+=2*k){
        for(int j=0;j<k;j++){
          num z=a[i+j+k]*rts[j+k];
          a[i+j+k]=a[i+j]-z;
          a[i+j]=a[i+j]+z;
        }
      }
    }
  }

  vector<num> fa;

  vector<Int> multiply(vector<int> &a,vector<int> &b){
    int need=a.size()+b.size()-1;
    int nbase=0;
    while((1<<nbase)<need) nbase++;
    ensure_base(nbase);

    int sz=1<<nbase;
    if(sz>(int)fa.size()) fa.resize(sz);
    for(int i=0;i<sz;i++){
      int x=(i<(int)a.size()?a[i]:0);
      int y=(i<(int)b.size()?b[i]:0);
      fa[i]=num(x,y);
    }
    fft(fa,sz);

    num r(0,-0.25/sz);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
      if(i!=j)
        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
      fa[i]=z;
    }
    fft(fa,sz);

    vector<Int> res(need);
    for(int i=0;i<need;i++)
      res[i]=fa[i].x+0.5;

    return res;
  }

};


template<typename T>
struct ArbitraryModConvolution{
  using dbl=FFT::dbl;
  using num=FFT::num;

  vector<T> multiply(vector<T> as,vector<T> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    vector<num> fa(sz),fb(sz);
    for(int i=0;i<(int)as.size();i++)
      fa[i]=num(as[i].v&((1<<15)-1),as[i].v>>15);
    for(int i=0;i<(int)bs.size();i++)
      fb[i]=num(bs[i].v&((1<<15)-1),bs[i].v>>15);

    fft(fa,sz);fft(fb,sz);

    dbl ratio=0.25/sz;
    num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num a1=(fa[i]+conj(fa[j]));
      num a2=(fa[i]-conj(fa[j]))*r2;
      num b1=(fb[i]+conj(fb[j]))*r3;
      num b2=(fb[i]-conj(fb[j]))*r4;
      if(i!=j){
        num c1=(fa[j]+conj(fa[i]));
        num c2=(fa[j]-conj(fa[i]))*r2;
        num d1=(fb[j]+conj(fb[i]))*r3;
        num d2=(fb[j]-conj(fb[i]))*r4;
        fa[i]=c1*d1+c2*d2*r5;
        fb[i]=c1*d2+c2*d1;
      }
      fa[j]=a1*b1+a2*b2*r5;
      fb[j]=a1*b2+a2*b1;
    }
    fft(fa,sz);fft(fb,sz);

    vector<T> cs(need);
    using ll = long long;
    for(int i=0;i<need;i++){
      ll aa=T(llround(fa[i].x)).v;
      ll bb=T(llround(fb[i].x)).v;
      ll cc=T(llround(fa[i].y)).v;
      cs[i]=T(aa+(bb<<15)+(cc<<30));
    }
    return cs;
  }
};

//INSERT ABOVE HERE

signed HAPPYQUERY_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,q;
  cin>>n>>m>>q;
  vector<int> ls(q),rs(q);
  for(int i=0;i<q;i++) cin>>ls[i]>>rs[i],ls[i]--;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  if(as==vector<int>(n,0)){
    for(int i=0;i<m;i++){
      if(i) cout<<" ";
      cout<<0;
    }
    cout<<endl;
    return 0;
  }

  vector<int> cs(n-m+1,0);
  for(int l:ls) cs[l]++;

  NTT<0> ntt;
  using M = NTT<0>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  vector<M> ps(as.size()),qs(cs.size());
  for(int i=0;i<(int)ps.size();i++) ps[i]=M(as[i]);
  for(int i=0;i<(int)qs.size();i++) qs[i]=M(cs[i]);

  auto bs=FPS.div(ps,qs);
  for(int i=0;i<m;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/09/17
  https://www.hackerrank.com/contests/happy-query-contest/challenges/array-restoring
*/

signed CFR250_E(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m;
  cin>>n>>m;
  vector<int> cs(n);
  for(int i=0;i<n;i++) cin>>cs[i];

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  const int deg=1<<18;
  vector<M> as(deg,0);
  as[0]=M(1);
  for(int c:cs) as[c]-=M(4);

  auto bs=FPS.sqrt(as,deg);
  bs[0]+=M(1);

  vector<M> vs({2});

  auto ans=FPS.mul(vs,FPS.inv(bs,deg));
  for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
  cout<<flush;

  return 0;
}
/*
  verified on 2019/09/17
  https://codeforces.com/contest/438/problem/E
*/

signed YUKI_3046(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int k,n;
  cin>>k>>n;
  vector<int> xs(n);
  for(int i=0;i<n;i++) cin>>xs[i];

  using M = Mint<int>;
  ArbitraryModConvolution<M> arb;
  auto conv=[&](auto as,auto bs){return arb.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  const int sz=1<<17;
  vector<M> bs(sz,M(0));
  bs[0]=1;
  for(int x:xs) bs[x]-=M(1);
  cout<<FPS.inv(bs,k+1)[k]<<endl;
  return 0;
}
/*
  verified on 2019/09/17
  https://yukicoder.me/problems/no/3046
*/

const int md = 998244353;
inline int add(int a,int b){
  a+=b;
  if(a>=md) a-=md;
  return a;
}

inline int mul(int a,int b){
  return 1LL*a*b%md;
}

inline int pow(int a,int b){
  int res=1;
  while(b){
    if(b&1) res=mul(res,a);
    a=mul(a,a);
    b>>=1;
  }
  return res;
}

inline int sqrt(int a){
  if(a==0) return 0;
  if(pow(a,(md-1)/2)!=1) return -1;
  int q=md-1,m=0;
  while(~q&1) q>>=1,m++;
  mt19937 mt;
  int z=mt()%md;
  while(pow(z,(md-1)/2)!=md-1) z=mt()%md;
  int c=pow(z,q),t=pow(a,q),r=pow(a,(q+1)/2);
  while(m>1){
    if(pow(t,1<<(m-2))!=1)
      r=mul(r,c),t=mul(t,mul(c,c));
    c=mul(c,c);
    m--;
  }
  return min(r,md-r);
}

signed LOJ_150(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  int n,k;
  cin>>n>>k;

  vector<M> F(n+1);
  for(int i=0;i<=n;i++) cin>>F[i].v;

  const int deg = 1<<17;
  auto as=FPS.log(FPS.mul(F,F[0].inv()),deg);
  auto bs=FPS.exp(FPS.mul(as,M((md-1)/2)),deg);
  M s(sqrt(F[0].v));
  auto cs=FPS.integral(FPS.mul(bs,s.inv()));
  auto ds=FPS.exp(cs,deg);
  auto es=FPS.sub(F,ds);
  es[0]+=M(2);
  es[0]-=F[0];
  auto fs=FPS.log(es,deg);
  fs[0]+=M(1);
  auto gs=FPS.log(fs,deg);
  auto hs=FPS.mul(gs,M(k));
  auto is=FPS.exp(hs,deg);
  auto G=FPS.diff(is);

  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/09/17
  https://loj.ac/problem/150
*/

signed main(){
  //HAPPYQUERY_E();
  //CFR250_E();
  //YUKI_3046();
  LOJ_150();
  return 0;
}
#endif
