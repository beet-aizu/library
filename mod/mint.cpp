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

  // find x s.t. a^x = b
  static T log(Mint a,Mint b){
    const T sq=40000;
    unordered_map<T, T> dp;
    dp.reserve(sq);
    Mint res(1);
    for(int r=0;r<sq;r++){
      if(!dp.count(res)) dp[res]=r;
      res*=a;
    }
    Mint p=pow(a.inv(),sq);
    res=b;
    for(int q=0;q<=MOD/sq+1;q++){
      if(dp.count(res)){
        T idx=q*sq+dp[res];
        if(idx>0) return idx;
      }
      res*=p;
    }    
    return T(-1);
  }

  static vector<Mint> fact,finv,invs;
  
  static void init(int n){
    if(n+1<=(signed)fact.size()) return;
    fact.assign(n+1,1);
    finv.assign(n+1,1);
    invs.assign(n+1,1);
    
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*Mint(i);
    finv[n]=Mint(1)/fact[n];
    for(int i=n;i>=1;i--) finv[i-1]=finv[i]*Mint(i);
    for(int i=1;i<=n;i++) invs[i]=finv[i]*fact[i-1];
  }

  static Mint comb(long long n,int k){
    Mint res(1);
    for(int i=0;i<k;i++){
      res*=Mint(n-i);
      res/=Mint(i+1);
    }
    return res;
  }
  
  static Mint C(int n,int k){
    if(n<k||k<0) return Mint(0);
    init(n);
    return fact[n]*finv[n-k]*finv[k];
  }

  static Mint P(int n,int k){
    if(n<k||k<0) return Mint(0);
    init(n);
    return fact[n]*finv[n-k];
  }
  
  static Mint H(int n,int k){
    if(n<0||k<0) return Mint(0);
    if(!n&&!k) return Mint(1);
    init(n+k-1);
    return C(n+k-1,k);
  }

  static Mint S(int n,int k){
    Mint res;
    init(k);
    for(int i=1;i<=k;i++){
      Mint tmp=C(k,i)*Mint(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }    
    return res*=finv[k];
  }

  static vector<vector<Mint> > D(int n,int m){
    vector<vector<Mint> > dp(n+1,vector<Mint>(m+1,0));
    dp[0][0]=Mint(1);
    for(int i=0;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(i-j>=0) dp[i][j]=dp[i][j-1]+dp[i-j][j];
        else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }

  static Mint B(int n,int k){
    Mint res;
    for(int j=1;j<=k;j++) res+=S(n,j);
    return res;
  }

  static Mint montmort(int n){
    Mint res;
    init(n);
    for(int k=2;k<=n;k++){
      if(k&1) res-=finv[k];
      else res+=finv[k];
    }
    return res*=fact[n];
  }

  static Mint LagrangePolynomial(vector<Mint> &y,Mint t){
    int n=y.size()-1;    
    if(t.v<=n) return y[t.v];
    init(n+1);
    Mint num(1);
    for(int i=0;i<=n;i++) num*=t-Mint(i);
    Mint res;
    for(int i=0;i<=n;i++){
      Mint tmp=y[i]*num/(t-Mint(i))*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::fact = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::finv = vector<Mint<T, MOD> >();
template<typename T,T MOD>
vector<Mint<T, MOD> > Mint<T, MOD>::invs = vector<Mint<T, MOD> >();
//END CUT HERE

template<typename T> 
map<T, int> factorize(T x){
  map<T, int> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

//INSERT ABOVE HERE
signed ABC110_D(){
  int n;
  using M = Mint<int>;
  M m;
  scanf("%d %d",&n,&m.v);

  M::init(n+100);
  
  Mint<int> ans(1);
  auto x=factorize(m.v);
  for(auto p:x) ans*=M::H(n,p.second);

  printf("%d\n",ans.v);
  return 0;
}
/*
  verified on 2018/09/24
  https://beta.atcoder.jp/contests/abc110/tasks/abc110_d
*/


//montmort
signed ARC009_C(){
  Int n,k;
  scanf("%lld %lld",&n,&k);
  const int MMOD = 1777777777;
  using MM = Mint<long long, MMOD>;
  MM a=MM::montmort(k)*MM::comb(n,k);
  printf("%lld\n",a.v);
  return 0;
}
/*
  verified on 2018/09/24
  https://beta.atcoder.jp/contests/arc009/tasks/arc009_3
*/


signed ARC033_D(){
  int n;
  scanf("%d",&n);
  using M = Mint<int>;
  vector<M> y(n+1);
  for(Int i=0;i<=n;i++) scanf("%d",&y[i].v);
  int t;
  scanf("%d",&t);
  printf("%d\n",(t<=n?y[t]:M::LagrangePolynomial(y,M(t))).v);
  return 0;
}
/*
  verified on 2018/09/24
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed DPL_5_A(){
  int n;
  Mint<int> k;
  scanf("%d %d",&n,&k.v);
  printf("%d\n",k.pow(n).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=jp
*/

signed DPL_5_B(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::P(k,n).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B&lang=jp
*/

signed DPL_5_C(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",(Mint<int>::S(n,k)*Mint<int>::fact[k]).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C&lang=jp
*/

signed DPL_5_D(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::H(k,n).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=jp
*/

signed DPL_5_E(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::C(k,n).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E&lang=jp
*/

signed DPL_5_F(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::C(n-1,k-1).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F&lang=jp
*/

signed DPL_5_G(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::B(n,k).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=jp
*/

signed DPL_5_H(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",(n<=k));
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H&lang=jp
*/

signed DPL_5_I(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::S(n,k).v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I&lang=jp
*/

signed DPL_5_J(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Mint<int>::D(n,k)[n][k].v);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=jp
*/

signed DPL_5_K(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",(n<=k));
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_K&lang=jp
*/

signed DPL_5_L(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",n>=k?Mint<int>::D(n,k)[n-k][k].v:0);
  return 0;
}
/*
  verified on 2018/09/24
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L&lang=jp
*/


signed YUKI_117(){
  int T;
  scanf("%d\n",&T);
  using M = Mint<int>;
  M::init(2e6+100);
  while(T--){
    char c;
    int n,k;
    scanf("%c(%d,%d)\n",&c,&n,&k);
    if(c=='C') printf("%d\n",M::C(n,k).v);
    if(c=='P') printf("%d\n",M::P(n,k).v);
    if(c=='H') printf("%d\n",M::H(n,k).v);
  }
  return 0;
}
/*
  verified on 2018/11/10
  https://yukicoder.me/problems/no/117
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;
  const int MAX = 666 * 6 + 10;
  M dp[MAX];
  for(int j=0;j<MAX;j++) dp[j]=M(0);
  dp[0]=M(1);
  
  vector<int> a({1,5,10,50,100,500});
  for(int x:a)
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];
  
  int T;
  scanf("%d",&T);
  while(T--){
    Int m;
    scanf("%lld",&m);
    vector<M> y(6);
    for(int i=0;i<6;i++) y[i]=dp[(m%500)+(i*500)];
    M ans=M::LagrangePolynomial(y,M(m/500));
    printf("%d\n",ans.v);
  }
  return 0;
}
/*
  verified on 2018/11/10
  https://yukicoder.me/problems/no/42
*/

signed main(){
  //ABC110_D();
  //ARC009_C();
  //ARC033_D();

  //DPL_5_A();
  //DPL_5_B();
  //DPL_5_C();
  //DPL_5_D();
  //DPL_5_E();
  //DPL_5_F();
  //DPL_5_G();
  //DPL_5_H();
  //DPL_5_I();
  //DPL_5_J();
  //DPL_5_K();
  //DPL_5_L();

  //YUKI_117();
  //YUKI_042();
  return 0;
}
