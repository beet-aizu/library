<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: mod/enumeration.cpp
* category: mod


[Back to top page](../../index.html)



## Dependencies
* :heavy_check_mark: [math/factorize.cpp](../math/factorize.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](mint.cpp.html)


## Required
* :heavy_check_mark: [convolution/arbitrarymodconvolution.cpp](../convolution/arbitrarymodconvolution.cpp.html)
* :heavy_check_mark: [convolution/arbitrarymodconvolution_with_garner.cpp](../convolution/arbitrarymodconvolution_with_garner.cpp.html)
* :heavy_check_mark: [graph/lowlink.cpp](../graph/lowlink.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/DPL_5_A.test.cpp](../../verify/test/aoj/DPL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_B.test.cpp](../../verify/test/aoj/DPL_5_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_C.test.cpp](../../verify/test/aoj/DPL_5_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_D.test.cpp](../../verify/test/aoj/DPL_5_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_E.test.cpp](../../verify/test/aoj/DPL_5_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_F.test.cpp](../../verify/test/aoj/DPL_5_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_G.test.cpp](../../verify/test/aoj/DPL_5_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_H.test.cpp](../../verify/test/aoj/DPL_5_H.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_I.test.cpp](../../verify/test/aoj/DPL_5_I.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_J.test.cpp](../../verify/test/aoj/DPL_5_J.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_K.test.cpp](../../verify/test/aoj/DPL_5_K.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_L.test.cpp](../../verify/test/aoj/DPL_5_L.test.cpp.html)


## Code
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
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
    init(k);
    M res(0);
    for(int i=1;i<=k;i++){
      M tmp=C(k,i)*M(i).pow(n);
      if((k-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res*=finv[k];
  }

  static vector< vector<M> > D(int n,int m){
    vector< vector<M> > dp(n+1,vector<M>(m+1,0));
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
    M res(0);
    for(int i=1;i<=k;i++)
      res+=M(i).pow(n)*finv[i]*dp[k-i];
    return res;
  }

  static M montmort(int n){
    init(n);
    M res(0);
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
    M res(0);
    for(int i=0;i<=n;i++){
      M tmp=y[i]*dp[i]*pd[i]*finv[i]*finv[n-i];
      if((n-i)&1) res-=tmp;
      else res+=tmp;
    }
    return res;
  }
};
template<typename M>
vector<M> Enumeration<M>::fact=vector<M>();
template<typename M>
vector<M> Enumeration<M>::finv=vector<M>();
template<typename M>
vector<M> Enumeration<M>::invs=vector<M>();
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../math/factorize.cpp"
#undef call_from_test

//INSERT ABOVE HERE

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
  verified on 2019/10/08
  https://atcoder.jp/contests/abc110/tasks/abc110_d
*/

//montmort
signed ARC009_C(){
  long long n,k;
  scanf("%lld %lld",&n,&k);
  const int MOD = 1777777777;
  using M = Mint<long long, MOD>;
  using E = Enumeration<M>;
  M a=E::montmort(k)*M::comb(n,k);
  printf("%lld\n",a.v);
  return 0;
}
/*
  verified on 2019/10/08
  https://atcoder.jp/contests/arc009/tasks/arc009_3
*/

signed ARC033_D(){
  int n;
  scanf("%d",&n);
  using M = Mint<int>;
  using E = Enumeration<M>;
  vector<M> y(n+1);
  for(int i=0;i<=n;i++) scanf("%d",&y[i].v);
  int t;
  scanf("%d",&t);
  printf("%d\n",E::LagrangePolynomial(y,M(t)).v);
  return 0;
}
/*
  verified on 2019/10/08
  https://atcoder.jp/contests/arc033/tasks/arc033_4
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
  verified on 2019/10/24
  https://yukicoder.me/problems/no/117
*/

signed YUKI_042(){
  using M = Mint<int, int(1e9+9)>;
  using E = Enumeration<M>;
  const int MAX = 666 * 6 + 10;
  vector<M> dp(MAX,0);
  dp[0]=M(1);

  for(int x:{1,5,10,50,100,500})
    for(int j=x;j<MAX;j++) dp[j]+=dp[j-x];

  int T;
  scanf("%d",&T);
  while(T--){
    using ll = long long;
    ll m;
    scanf("%lld",&m);
    vector<M> y(6);
    for(int i=0;i<6;i++) y[i]=dp[(m%500)+(i*500)];
    M ans=E::LagrangePolynomial(y,M(m/500));
    printf("%d\n",ans.v);
  }
  return 0;
}
/*
  verified on 2019/10/24
  https://yukicoder.me/problems/no/42
*/

signed CFR315_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

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
  verified on 2019/10/08
  https://codeforces.com/contest/568/problem/B
*/

signed main(){
  //ABC110_D();
  //ARC009_C();
  //ARC033_D();

  //YUKI_117();
  //YUKI_042();

  //CFR315_B();
  return 0;
}
#endif

```

[Back to top page](../../index.html)

