#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
typedef vector<Int> arr;
typedef vector<arr> mat;
mat mul(mat& a,mat& b,Int mod){
  mat res(a.size(),arr(b[0].size(),0));
  for(Int i=0;i<(Int)a.size();i++)
    for(Int j=0;j<(Int)b[0].size();j++)
      for(Int k=0;k<(Int)b.size();k++)
	(res[i][j]+=a[i][k]*b[k][j])%=mod;
  return res;
}
mat mat_pow(mat a,Int n,Int mod){
  mat base(a);
  for(Int i=0;i<(Int)a.size();i++)
    for(Int j=0;j<(Int)a[i].size();j++)
      base[i][j]=(i==j);
  mat res(base);
  while(n){
    if(n&1) res=mul(a,res,mod);
    a=mul(a,a,mod);
    n>>=1;
  }
  return res;
}
Int sigma(Int x,Int n,Int m){
  mat A(2,arr(2,1));
  A[0][0]=x;A[0][1]=0;
  return mat_pow(A,n,m)[1][0];
}
//END CUT HERE

Int mod_pow(Int x,Int n,Int mod){
  Int res=1;
  while(n){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}

signed main(){
  Int a,b,m;
  cin>>a>>b>>m;
  Int c=__gcd(a,b);
  Int x=mod_pow(10,c,m);
  Int ans=sigma(x,a/c,m);
  ans*=sigma(10,b,m);
  ans%=m;
  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2018/01/03
  https://beta.atcoder.jp/contests/arc050/tasks/arc050_c
*/
