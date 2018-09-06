#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE

template<Int MOD = 1000000007>
struct Mod{
  Int prev=0;
  vector<Int> fact,inv,finv;
  Mod(){}
  Mod(Int n){init(n);}
  
  Int pow(Int x,Int n){
    Int res=1;
    while(n){
      if(n&1) (res*=x)%=MOD;
      (x*=x)%=MOD;
      n>>=1;
    }
    return res;
  }
  
  Int inverse(Int a){
    return pow(a,MOD-2);
  }
  
  void init(Int n){
    if(prev>=n) return;
    prev=n;
    fact=inv=finv=vector<Int>(n);
    
    fact[0]=1;
    for(Int i=1;i<n;i++)
      fact[i]=(fact[i-1]*i)%MOD;
    
    inv[1]=1;
    for(Int i=2;i<n;i++)
      inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    
    finv[0]=1;
    for(Int i=1;i<n;i++)
      finv[i]=finv[i-1]*inv[i]%MOD;
  }
  
  Int comb(Int n,Int k){
    Int res=1;
    for(Int i=0;i<k;i++){
      res*=(n-i)%MOD;
      res%=MOD;
      res*=inverse(i+1);
      res%=MOD;
    }
    return res;
  }
  
  //only for prime MOD
  Int C(Int n,Int k){
    if(k<0||k>n) return 0;
    return fact[n]*finv[k]%MOD*finv[n-k]%MOD;
  }
  
  Int P(int n,int k){
    if(k<0||k>n) return 0;
    return fact[n]*finv[n-k]%MOD;    
  }

  Int H(Int n,Int k){
    if(n<0||k<0) return 0;
    if(!n&&!k) return 1;
    return C(n+k-1,n);
  }

  Int S(Int n,Int k){
    Int res=0;
    for(Int i=1;i<=k;i++){
      Int tmp=C(k,i)*pow(i,n)%MOD;
      if((k-i)&1) res+=MOD-tmp;
      else res+=tmp;
      res%=MOD;
    }
    res=res*finv[k]%MOD;
    return res;
  }
  
  Int B(Int n,Int k){
    Int res=0;
    for(Int j=1;j<=k;j++){
      res+=S(n,j);
      res%=MOD;
    }
    return res;
  }
  
  vector<vector<Int> > D(Int n,Int m){
    vector<vector<Int> > dp(n+1,vector<Int>(m+1,0));
    dp[0][0]=1;
    for(Int i=0;i<=n;i++){
      for(Int j=1;j<=m;j++){
	if(i-j>=0) dp[i][j]=(dp[i][j-1]+dp[i-j][j])%MOD;
	else dp[i][j]=dp[i][j-1];
      }
    }
    return dp;
  }
  
  Int montmort(Int n){
    Int res=0,rinv=1;
    for(Int k=2;k<=n;k++){
      rinv=rinv*inverse(k)%MOD;
      if(k%2) res+=MOD-rinv;
      else res+=rinv;
      res%=MOD;
    }
    for(Int i=1;i<=n;i++) res=res*i%MOD;
    return res;
  }
  
  // calculate P(t) from given points in [0,N]
  Int LagrangePolynomial(vector<Int> &y,Int t){
    Int n=y.size()-1;
    init(n+1);
    Int num=1;
    for(Int i=0;i<=n;i++)
      num=num*((t-i)%MOD)%MOD;
    Int res=0;
    for(Int i=0;i<=n;i++){
      Int tmp=(y[i]*num%MOD)*inverse((t-i)%MOD)%MOD;
      tmp=tmp*finv[i]%MOD;
      tmp=tmp*finv[n-i]%MOD;
      if((n-i)&1) tmp=MOD-tmp;
      res=(res+tmp)%MOD;
    }
    return res;
  }
};

//END CUT HERE
  
//mod_pow
signed AOJ_NTL1B(){
  Int n,m;
  cin>>m>>n;
  Mod<> mod;
  cout<<mod.pow(m,n)<<endl;
  return 0;
}
/*
  verified on 2018/07/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
*/


//montmort
signed ARC009_C(){
  Int n,k;
  cin>>n>>k;
  const Int MMOD = 1777777777;
  Mod<MMOD> mod;
  Int a=mod.montmort(k);
  a=a*mod.comb(n,k)%MMOD;
  cout<<a<<endl;
  return 0;
}
/*
  verified on 2018/07/19
  https://beta.atcoder.jp/contests/arc009/tasks/arc009_3
*/


signed yuki_665(){
  Int n,k;
  cin>>n>>k;
  vector<Int> y(k+2,0);
  const Int MOD = 1e9+7;
  Mod<MOD> mod;
  for(Int i=1;i<=k+1;i++) y[i]=(y[i-1]+mod.pow(i,k))%MOD;
  if(n<=k+1) cout<<y[n]<<endl;
  else cout<<mod.LagrangePolynomial(y,n)<<endl;
  return 0;
}
/*
  verified on 2018/07/19
  https://yukicoder.me/problems/no/665
*/

signed ARC033_D(){
  Int n;
  cin>>n;
  vector<Int> y(n+1);
  for(Int i=0;i<=n;i++) cin>>y[i];
  Int t;
  cin>>t;
  const Int MOD = 1e9+7;
  Mod<MOD> mod;
  if(t<=n) cout<<y[t]<<endl;
  else cout<<mod.LagrangePolynomial(y,t)<<endl;
  return 0;
}
/*
  verified on 2018/07/19
  https://beta.atcoder.jp/contests/arc033/tasks/arc033_4
*/

signed main(){
  //AOJ_NTL1B();
  //ARC009_C();
  //yuki_665();
  //ARC033_D();
  return 0;
}
