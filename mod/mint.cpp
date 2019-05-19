#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
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
  static T log(Mint a,Mint b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(int r=0;r<sq;r++){
      if(!dp.count(res.v)) dp[res.v]=r;
      res*=a;
    }
    Mint p=a.inv().pow(sq);
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
    Mint res(1);
    for(int i=0;i<k;i++){
      res*=Mint(n-i);
      res/=Mint(i+1);
    }
    return res;
  }
};
//END CUT HERE


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

Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}

Int mod_inverse(Int a,Int mod){
  Int x,y;
  extgcd(a,mod,x,y);
  return (mod+x%mod)%mod;
}

//INSERT ABOVE HERE
signed CFR536_F(){
  const Int MOD = 998244353;
  using M = Mint<Int, MOD>;
  using P = Mint<Int, MOD-1>;

  cin.tie(0);
  ios::sync_with_stdio(0);

  Int k;
  cin>>k;

  vector<P> bs(k);
  for(Int i=0;i<k;i++){
    Int b;
    cin>>b;
    bs[i]=P(b);
  }

  Int n,m;
  cin>>n>>m;

  reverse(bs.begin(),bs.end());
  Kitamasa<P> ktms(bs);
  vector<P> as(k,0);
  as[k-1]=1;
  
  Int v=ktms.calc(as,--n).v;
  Int h=M::log(M(3),M(m))%(MOD-1);  

  if(v!=0||h!=0){
    Int g=__gcd(v,h);
    v/=g;
    h/=g;
  }
  
  if(h!=0&&__gcd(v,MOD-1)!=1){
    cout<<-1<<endl;
    return 0;
  }
  
  cout<<M(3).pow(h*mod_inverse(v,MOD-1)).v<<endl;  
  return 0;
}
/*
  verified on 2019/05/19
  https://codeforces.com/contest/1106/problem/F
*/

signed main(){
  CFR536_F();
  return 0;
}
