#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T>
T mod_pow(T a,long long n,T mod){
  using ll = long long;
  T res(1);
  while(n){
    if(n&1) res=(ll)res*a%mod;
    a=(ll)a*a%mod;
    n>>=1;
  }
  return res;
}
#endif
//BEGIN CUT HERE
// find x s.t. a^x = b
template<typename T>
T mod_log(T a,T b,T mod){
  using ll = long long;
  const T sq=sqrt(mod);
  unordered_map<T, T> dp;
  dp.reserve(sq);
  T res(1);
  for(int r=0;r<sq;r++){
    if(!dp.count(res)) dp[res]=r;
    res=(ll)res*a%mod;
  }
  T p=mod_pow(a,(ll)(mod-2)*sq,mod);
  res=b;
  for(int q=0;q<=mod/sq+1;q++){
    if(dp.count(res)){
      T idx=q*sq+dp[res];
      if(idx>0) return idx;
    }
    res=(ll)res*p%mod;
  }
  assert(0);
  return T(-1);
}
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

template<typename R>
struct Kitamasa{
  using VR = vector<R>;
  VR c;
  vector<VR> rs;
  int m;

  Kitamasa(const VR &C)
    :c(C),rs(1),m(c.size()){
    rs[0].assign(2*m+1,R::add_identity());
    rs[0][1]=R::mul_identity();
  }

  VR merge(const VR &x,const VR &y){
    VR z(2*m+1,R::add_identity());
    for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
        z[i+j]=z[i+j]+(x[i]*y[j]);

    for(int i=2*m;i>m;z[i--]=R::add_identity())
      for(int j=1;j<=m;j++)
        z[i-j]=z[i-j]+(c[m-j]*z[i]);
    return z;
  }

  R calc(const VR &A,long long n){
    assert((int)A.size()==m);
    VR res(rs[0]);
    for(int i=0;n;i++,n>>=1){
      if(i>=(int)rs.size())
        rs.emplace_back(merge(rs[i-1],rs[i-1]));
      if(~n&1) continue;
      res=merge(res,rs[i]);
    }
    R ans=R::add_identity();
    for(int i=1;i<=m;i++) ans=ans+(res[i]*A[i-1]);
    return ans;
  }
};

template<typename T>
T extgcd(T a,T b,T& x,T& y){
  T d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

template<typename T>
T mod_inverse(T a,T mod){
  T x,y;
  extgcd(a,mod,x,y);
  return (x%mod+mod)%mod;
}

//INSERT ABOVE HERE
signed CFR536_F(){
  const int MOD = 998244353;
  using M = Mint<int, MOD>;
  using P = Mint<int, MOD-1>;

  cin.tie(0);
  ios::sync_with_stdio(0);

  int k;
  cin>>k;

  vector<P> bs(k);
  for(int i=0;i<k;i++){
    int b;
    cin>>b;
    bs[i]=P(b);
  }

  int n,m;
  cin>>n>>m;

  reverse(bs.begin(),bs.end());
  Kitamasa<P> ktms(bs);
  vector<P> as(k,0);
  as[k-1]=1;

  int v=ktms.calc(as,--n).v;
  int h=mod_log(3,m,MOD)%(MOD-1);

  if(v!=0||h!=0){
    int g=__gcd(v,h);
    v/=g;
    h/=g;
  }

  if(h!=0&&__gcd(v,MOD-1)!=1){
    cout<<-1<<endl;
    return 0;
  }

  cout<<M(3).pow((long long)h*mod_inverse(v,MOD-1))<<endl;
  return 0;
}
/*
  verified on 2019/10/08
  https://codeforces.com/contest/1106/problem/F
*/

signed main(){
  CFR536_F();
  return 0;
}
#endif
