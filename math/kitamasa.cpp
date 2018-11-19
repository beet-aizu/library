#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
struct Kitamasa{
  using VT = vector<T>;
  using F = function<T(T,T)>;
  VT c;
  vector<VT> rs;
  int m;
  F add;
  F mul;
  T d0,d1;
  
  Kitamasa(const VT &C,F add,F mul,T d0,T d1)
    :c(C),rs(1),m(c.size()),add(add),mul(mul),d0(d0),d1(d1){
    rs[0].assign(2*m+1,d0);
    rs[0][1]=d1;
  }

  VT merge(const VT &x,const VT &y){
    VT z(2*m+1,d0);
    for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
        z[i+j]=add(z[i+j],mul(x[i],y[j]));
    
    for(int i=2*m;i>m;z[i--]=d0)
      for(int j=1;j<=m;j++)
        z[i-j]=add(z[i-j],mul(c[m-j],z[i]));
    
    return z;
  }

  T calc(const VT &A,long long n){
    assert((int)A.size()==m);
    VT res(rs[0]);
    for(int i=0;n;i++,n>>=1){
      if(i>=(int)rs.size())
        rs.emplace_back(merge(rs[i-1],rs[i-1]));
      if(~n&1) continue;
      res=merge(res,rs[i]);
    }
    T ans=d0;
    for(int i=1;i<=m;i++) ans=add(ans,mul(res[i],A[i-1]));
    return ans;
  }
  
};
//END CUT HERE

signed TDPC_F(){
  using ll = long long;
  int n;
  ll k;
  scanf("%d %lld",&n,&k);
  constexpr ll MOD = 1e9+7;
  
  vector<int> a(n,1),c(n,1);
  auto add=[](int a,int b){return (a+b)%MOD;};
  auto mul=[](int a,int b){return ((ll)a*b)%MOD;};
  Kitamasa<int> fib(c,add,mul,0,1);

  printf("%d\n",fib.calc(a,--k));
  return 0;
}
/*
  verified on 2018/11/19
  https://beta.atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci 
*/

signed ARC009_D(){
  int k,m;
  scanf("%d %d",&k,&m);
  
  vector<unsigned> a(k),c(k);
  for(int i=0;i<k;i++) scanf("%u",&a[i]);
  for(int i=0;i<k;i++) scanf("%u",&c[k-(i+1)]);
  auto add=[](unsigned a,unsigned b){return a^b;};
  auto mul=[](unsigned a,unsigned b){return a&b;};
  Kitamasa<unsigned> v(c,add,mul,0u,~0u);

  printf("%u\n",v.calc(a,--m));
  return 0;
}
/*
  verified on 2018/11/19
  https://beta.atcoder.jp/contests/abc009/tasks/abc009_4
*/
signed main(){
  //TDPC_F();
  //ARC009_D();
  return 0;
}
