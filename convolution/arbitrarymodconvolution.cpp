#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

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
};
#endif
//BEGIN CUT HERE
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

  // find x s.t. a^x = b
  static T log(T a,T b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(int r=0;r<sq;r++){
      if(!dp.count(res.v)) dp[res.v]=r;
      res*=a;
    }
    Mint p=Mint(a).inv().pow(sq);
    res=b;
    for(int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res.v)){
        T idx=q*sq+dp[res.v];
        if(idx>0) return idx;
      }
      res*=p;
    }
    assert(0);
    return T(-1);
  }

  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};
template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
template<typename T,T MOD>
ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}


template<typename M>
class Enumeration{
private:
  static vector<M> fact,finv,invs;
public:
  static void init(int n){
    n=min<decltype(M::mod)>(n,M::mod-1);

    int m=fact.size();
    if(n<m) return;

    fact.resize(n+1,1);
    finv.resize(n+1,1);
    invs.resize(n+1,1);

    if(m==0) m=1;
    for(int i=m;i<=n;i++) fact[i]=fact[i-1]*M(i);
    finv[n]=M(1)/fact[n];
    for(int i=n;i>=m;i--) finv[i-1]=finv[i]*M(i);
    for(int i=m;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static M Fact(int n){
    init(n);
    return fact[n];
  }
  static M Finv(int n){
    init(n);
    return finv[n];
  }
  static M Invs(int n){
    init(n);
    return invs[n];
  }

  static M C(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static M P(int n,int k){
    if(n<k||k<0) return M(0);
    init(n);
    return fact[n]*finv[n-k];
  }

  static M H(int n,int k){
    if(n<0||k<0) return M(0);
    if(!n&&!k) return M(1);
    init(n+k-1);
    return C(n+k-1,k);
  }

  static M S(int n,int k){
    M res;
    init(k);
    for(int i=1;i<=k;i++){
      M tmp=C(k,i)*M(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res*=finv[k];
  }

  static vector<vector<M> > D(int n,int m){
    vector<vector<M> > dp(n+1,vector<M>(m+1,0));
    dp[0][0]=M(1);
    for(int i=0;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  static M B(int n,int k){
    if(n==0) return M(1);
    k=min(k,n);
    init(k);
    vector<M> dp(k+1);
    dp[0]=M(1);
    for(int i=1;i<=k;i++)
      dp[i]=dp[i-1]+((i&1)?-finv[i]:finv[i]);
    M res;
    for(int i=1;i<=k;i++)
      res+=M(i).pow(n)*finv[i]*dp[k-i];
    return res;
  }

  static M montmort(int n){
    M res;
    init(n);
    for(int k=2;k<=n;k++){
      if(k&1) res-=finv[k];
      else res+=finv[k];
    }
    return res*=fact[n];
  }

  static M LagrangePolynomial(vector<M> &y,M t){
    int n=y.size()-1;
    if(t.v<=n) return y[t.v];
    init(n+1);
    vector<M> dp(n+1,1),pd(n+1,1);
    for(int i=0;i<n;i++) dp[i+1]=dp[i]*(t-M(i));
    for(int i=n;i>0;i--) pd[i-1]=pd[i]*(t-M(i));
    M res{0};
    for(int i=0;i<=n;i++){
      M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename M>
vector<M> Enumeration<M>::fact = vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv = vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs = vector<M>();

//INSERT ABOVE HERE
signed YUKI_829(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,b;
  cin>>n>>b;
  vector<int> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(3e5);

  vector<int> cnt(n,0);
  for(int i=0;i<n;i++) cnt[s[i]]++;

  using P = pair<int, vector<M> > ;
  priority_queue<P> pq;
  pq.emplace(-1,vector<M>(1,1));

  int sum=0;
  for(int i=n-1;i>=0;i--){
    if(cnt[i]==0) continue;
    M x=E::H(sum,cnt[i]);
    M y=E::H(sum+1,cnt[i])-x;
    x*=E::Fact(cnt[i]);
    y*=E::Fact(cnt[i]);

    pq.emplace(-2,vector<M>({x,y}));
    sum+=cnt[i];
  }

  ArbitraryModConvolution<M> arb;
  while(pq.size()>1u){
    auto as=pq.top().second;pq.pop();
    auto bs=pq.top().second;pq.pop();
    auto cs=arb.multiply(as,bs);
    pq.emplace(-(int)cs.size(),cs);
  }

  auto dp=pq.top().second;
  M ans(0),res(1);
  for(int j=0;j<(int)dp.size();j++){
    ans+=M(j)*dp[j]*res;
    res*=M(b);
  }
  cout<<ans.v<<endl;
  return 0;
}
/*
  verified on 2019/09/08
  https://yukicoder.me/problems/no/829
*/

signed main(){
  //YUKI_829();
  return 0;
}
#endif
