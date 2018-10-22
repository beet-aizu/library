#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct Kitamasa{
  using VT = vector<T>;
  VT a,c;
  vector<VT > rs;
  int m,base;
  using F = function<T(T,T)>;
  F pl,ml;
  T d0,d1;
  
  Kitamasa(VT& A,VT &C,F pl,F ml,T d0,T d1)
    :a(A),c(C),rs(1),m(c.size()),base(1),pl(pl),ml(ml),d0(d0),d1(d1){
    a.insert(a.begin(),d0);
    rs[0].assign(2*m+1,d0);
    rs[0][1]=d1;
  }

  void form(VT &x){
    for(int i=2*m;i>m;i--){
      for(int j=1;j<m+1;j++)
        x[i-j]=pl(x[i-j],ml(c[m-j],x[i]));
      x[i]=d0;
    }
  }

  void add(VT x,VT y,VT &z){
    z.assign(2*m+1,d0);
    for(int i=1;i<m+1;i++)
      for(int j=1;j<m+1;j++)
        z[i+j]=pl(z[i+j],ml(x[i],y[j]));
    form(z);
  }
  
  void ensure_base(int nbase){
    if(nbase<=base) return;
    rs.resize(nbase);
    for(int i=base;i<nbase;i++)
      add(rs[i-1],rs[i-1],rs[i]);
    base=nbase;
  }

  T calc(long long n){
    VT tmp,res(rs[0]);
    for(int i=0;n;i++,n>>=1){
      ensure_base(i+1);
      if(~n&1) continue;
      swap(tmp,res);
      add(tmp,rs[i],res);
    }
    T ans=d0;
    for(int i=1;i<m+1;i++) ans=pl(ans,ml(res[i],a[i]));
    return ans;
  }
  
};
//END CUT HERE

signed TDPC_F(){
  Int n,k;
  cin>>n>>k;
  const Int MOD = 1e9+7;
  
  vector<Int> a(n,1),c(n,1);
  Kitamasa<Int>::F pl=[](Int a,Int b){return (a+b)%MOD;};
  Kitamasa<Int>::F ml=[](Int a,Int b){return (a*b)%MOD;};
  Kitamasa<Int> fib(a,c,pl,ml,0,1);

  cout<<fib.calc(--k)<<endl;
  return 0;
}
/*
  verified on 2018/03/06
  https://beta.atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci 
*/

signed ARC009_D(){
  Int k,m;
  cin>>k>>m;
  
  vector<unsigned> a(k),c(k);
  for(int i=0;i<k;i++) cin>>a[i];
  for(int i=0;i<k;i++) cin>>c[k-(i+1)];
  Kitamasa<unsigned>::F pl=[](unsigned a,unsigned b){return a^b;};
  Kitamasa<unsigned>::F ml=[](unsigned a,unsigned b){return a&b;};
  Kitamasa<unsigned> v(a,c,pl,ml,0u,~0u);

  cout<<v.calc(--m)<<endl;
  return 0;
}
/*
  verified on 2018/03/06
  https://beta.atcoder.jp/contests/abc009/tasks/abc009_4
*/
signed main(){
  TDPC_F();
  ARC009_D();
  return 0;
}
