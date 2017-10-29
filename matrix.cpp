#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
Int MOD=1000000009LL; //<- alert!!!
typedef vector<Int> arr;
typedef vector<arr> mat;
inline arr mul(mat a,arr& b,Int mod){
  arr res(b.size(),0);
  for(int i=0;i<(int)b.size();i++)
    for(int j=0;j<(int)a[i].size();j++)
      (res[i]+=a[i][j]*b[j])%=mod;
  return res;
}
inline mat mul(mat& a,mat& b,Int mod){
  mat res(a.size(),arr(b[0].size(),0));
  for(int i=0;i<(int)a.size();i++)
    for(int j=0;j<(int)b[0].size();j++)
      for(int k=0;k<(int)b.size();k++)
	(res[i][j]+=a[i][k]*b[k][j])%=mod;
  return res;
}
mat base;
inline mat mat_pow(mat a,Int n,Int mod){
  if(base.empty()){
    base=mat(a);
    for(int i=0;i<(int)a.size();i++)
      for(int j=0;j<(int)a[i].size();j++)
	base[i][j]=(i==j);
  }
  mat res(base);
  while(n){
    if(n&1) res=mul(a,res,mod);
    a=mul(a,a,mod);
    n>>=1;
  }
  return res;
}
mat memo[100];
void init(mat a,Int mod){
  base=mat(a);
  for(int i=0;i<(int)base.size();i++)
    for(int j=0;j<(int)base.size();j++)
      base[i][j]=i==j;
  memo[0]=a;
  for(int k=1;k<70;k++)
    memo[k]=mul(memo[k-1],memo[k-1],mod);
}
inline mat mat_pow2(Int n,Int mod){
  mat res(base);
  int k=0;
  while(n){
    if(n&1) res=mul(memo[k],res,mod);
    n>>=1;
    k++;
  }
  return res;
}
//END CUT HERE

typedef pair<Int,Int> P;
signed main(){
  Int w,h,n,cnt=0;
  while(cin>>w>>h>>n,w||h||n){
    Int x[n],y[n];
    for(Int i=0;i<n;i++) cin>>x[i]>>y[i];
    P p[n];
    for(Int i=0;i<n;i++) p[i]=P(y[i],x[i]);
    sort(p,p+n);
    for(Int i=0;i<n;i++) x[i]=p[i].second,y[i]=p[i].first;
    arr a(w,0);
    a[0]=1;
    mat b(w,arr(w,0));
    for(Int i=0;i<w;i++){
      for(Int j=0;j<w;j++) b[i][j]=0;
      b[i][i]=1;
      if(i-1>=0) b[i][i-1]=1;
      if(i+1<w)  b[i][i+1]=1;
    }
    init(b,MOD);
    Int d=1;
    for(Int k=0;k<n;k++){
      if(y[k]==d) continue;
      a=mul(mat_pow2(y[k]-d-1,MOD),a,MOD);
      Int j=k;
      mat c=b;
      while(j<n&&y[k]==y[j]){
	for(Int i=0;i<w;i++) c[x[j]-1][i]=0;
	j++;
      }
      a=mul(c,a,MOD);
      d=y[k];
    }
    a=mul(mat_pow2(h-d,MOD),a,MOD);
    cout<<"Case "<<++cnt<<": "<<a[w-1]<<endl;
  }
  return 0;
}

/*
verified on 2017/10/29
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2397
*/
