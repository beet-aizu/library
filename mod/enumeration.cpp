#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

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
  
  static Mint comb(long long n,int k){
    Mint num(1),dom(1);
    for(int i=0;i<k;i++){
      num*=Mint(n-i);
      dom*=Mint(i+1);
    }
    return num/dom;
  }
};

//BEGIN CUT HERE
template<typename M>
struct Enumeration{
  static vector<M> fact,finv,invs;
  
  static void init(int n){
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
    M num(1);
    for(int i=0;i<=n;i++) num*=t-M(i);
    M res;
    for(int i=0;i<=n;i++){
      M tmp=y[i]*num/(t-M(i))*finv[i]*finv[n-i];
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

signed DPL_5_A(){
  int n;
  Mint<int> k;
  scanf("%d %d",&n,&k.v);
  printf("%d\n",k.pow(n).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A&lang=jp
*/

signed DPL_5_B(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::P(k,n).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_B&lang=jp
*/

signed DPL_5_C(){
  int n,k;
  scanf("%d %d",&n,&k);
  Enumeration<Mint<int>>::init(k);  
  printf("%d\n",(Enumeration<Mint<int>>::S(n,k)*Enumeration<Mint<int>>::fact[k]).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C&lang=jp
*/

signed DPL_5_D(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::H(k,n).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_D&lang=jp
*/

signed DPL_5_E(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::C(k,n).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E&lang=jp
*/

signed DPL_5_F(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::C(n-1,k-1).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_F&lang=jp
*/

signed DPL_5_G(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::B(n,k).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=jp
*/

signed DPL_5_H(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",(n<=k));
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_H&lang=jp
*/

signed DPL_5_I(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::S(n,k).v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I&lang=jp
*/

signed DPL_5_J(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",Enumeration<Mint<int>>::D(n,k)[n][k].v);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=jp
*/

signed DPL_5_K(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",(n<=k));
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_K&lang=jp
*/

signed DPL_5_L(){
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%d\n",n>=k?Enumeration<Mint<int>>::D(n,k)[n-k][k].v:0);
  return 0;
}
/*
  verified on 2019/05/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_L&lang=jp
*/

signed ABC110_D(){
  int n;
  using M = Mint<int>;
  using E = Enumeration<M>;
  M m;
  scanf("%d %d",&n,&m.v);

  E::init(n+100);
  
  Mint<int> ans(1);
  auto x=factorize(m.v);
  for(auto p:x) ans*=E::H(n,p.second);

  printf("%d\n",ans.v);
  return 0;
}
/*
  verified on 2019/05/19
  https://beta.atcoder.jp/contests/abc110/tasks/abc110_d
*/

//montmort
signed ARC009_C(){
  Int n,k;
  scanf("%lld %lld",&n,&k);
  const int MOD = 1777777777;
  using M = Mint<long long, MOD>;  
  using E = Enumeration<M>;
  M a=E::montmort(k)*M::comb(n,k);
  printf("%lld\n",a.v);
  return 0;
}
/*
  verified on 2019/05/19
  https://beta.atcoder.jp/contests/arc009/tasks/arc009_3
*/

signed ARC033_D(){
  int n;
  scanf("%d",&n);
  using M = Mint<int>;  
  using E = Enumeration<M>;
  vector<M> y(n+1);
  for(Int i=0;i<=n;i++) scanf("%d",&y[i].v);
  int t;
  scanf("%d",&t);
  printf("%d\n",(t<=n?y[t]:E::LagrangePolynomial(y,M(t))).v);
  return 0;
}
/*
  verified on 2019/05/19
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed YUKI_117(){
  int T;
  scanf("%d\n",&T);
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(2e6+100);
  while(T--){
    char c;
    int n,k;
    scanf("%c(%d,%d)\n",&c,&n,&k);
    if(c=='C') printf("%d\n",E::C(n,k).v);
    if(c=='P') printf("%d\n",E::P(n,k).v);
    if(c=='H') printf("%d\n",E::H(n,k).v);
  }
  return 0;
}
/*
  verified on 2019/05/19
  https://yukicoder.me/problems/no/117
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;  
  using E = Enumeration<M>;
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
    M ans=E::LagrangePolynomial(y,M(m/500));
    printf("%d\n",ans.v);
  }
  return 0;
}
/*
  verified on 2019/05/19
  https://yukicoder.me/problems/no/42
*/

signed CFR315_B(){
  int n;
  cin>>n;
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(n+1);
  M res;
  for(int i=0;i<n;i++)
    res+=E::C(n,i)*E::B(i,i);  
  cout<<res.v<<endl;
  return 0;
}
/*
  verified on 2019/05/19
  https://codeforces.com/contest/568/problem/B
*/

signed main(){
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
  
  //ABC110_D();
  //ARC009_C();
  //ARC033_D();

  //YUKI_117();
  //YUKI_042();

  //CFR315_B();
  return 0;
}
