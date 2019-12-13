---
layout: default
---

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


# :warning: mod/factorial.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/factorial.cpp">View this file on GitHub</a>
    - Last commit date: 2019-06-17 15:36:46 +0900




## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

constexpr int bmds(int x){
  const int v[] = {1012924417, 924844033, 998244353,
                   897581057, 645922817};
  return v[x];
}
constexpr int brts(int x){
  const int v[] = {5, 5, 3, 3, 3};
  return v[x];
}

template<int X>
struct NTT{
  static constexpr int md = bmds(X);
  static constexpr int rt = brts(X);

  inline int add(int a,int b){
    a+=b;
    if(a>=md) a-=md;
    return a;
  }

  inline int mul(int a,int b){
    return 1LL*a*b%md;
  }

  inline int pow(int a,int b){
    int res=1;
    while(b){
      if(b&1) res=mul(res,a);
      a=mul(a,a);
      b>>=1;
    }
    return res;
  }

  inline int inv(int x){
    return pow(x,md-2);
  }

  vector<vector<int> > rts,rrts;

  void ensure_base(int n){
    if((int)rts.size()>=n) return;
    rts.resize(n);rrts.resize(n);
    for(int i=1;i<n;i<<=1){
      if(!rts[i].empty()) continue;
      int w=pow(rt,(md-1)/(i<<1));
      int rw=inv(w);
      rts[i].resize(i);rrts[i].resize(i);
      rts[i][0]=1;rrts[i][0]=1;
      for(int k=1;k<i;k++){
        rts[i][k]=mul(rts[i][k-1],w);
        rrts[i][k]=mul(rrts[i][k-1],rw);
      }
    }
  }

  void ntt(vector<int> &a,bool f,int n=-1){
    if(n==-1) n=a.size();
    assert((n&(n-1))==0);

    for(int i=0,j=1;j+1<n;j++){
      for(int k=n>>1;k>(i^=k);k>>=1);
      if(i>j) swap(a[i],a[j]);
    }

    for(int i=1;i<n;i<<=1){
      for(int j=0;j<n;j+=i*2){
        for(int k=0;k<i;k++){
          int z=mul(a[i+j+k],f?rrts[i][k]:rts[i][k]);
          a[i+j+k]=add(a[j+k],md-z);
          a[j+k]=add(a[j+k],z);
        }
      }
    }

    if(f){
      int tmp=inv(n);
      for(Int i=0;i<n;i++) a[i]=mul(a[i],tmp);
    }
  }

  vector<int> multiply(const vector<int> &a,const vector<int> &b){
    int need=a.size()+b.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    ensure_base(sz);

    vector<int> f(sz),g(sz);
    for(int i=0;i<(int)a.size();i++) f[i]=a[i];
    for(int i=0;i<(int)b.size();i++) g[i]=b[i];
    ntt(f,0);ntt(g,0);
    for(int i=0;i<sz;i++) f[i]=mul(f[i],g[i]);
    ntt(f,1);

    f.resize(need);
    return f;
  }

};

struct ArbitraryModConvolution{
  using ll = long long;
  static NTT<0> ntt0;
  static NTT<1> ntt1;
  static NTT<2> ntt2;

  static constexpr int pow(int a,int b,int md){
    int res=1;
    a=a%md;
    while(b){
      if(b&1) res=(ll)res*a%md;
      a=(ll)a*a%md;
      b>>=1;
    }
    return res;
  }

  static constexpr int inv(int x,int md){
    return pow(x,md-2,md);
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    size_t sz=cs[0].size();
    for(size_t i=0;i<sz;i++){
      cs[1][i]=(ll)(cs[1][i]-cs[0][i])*r01%ntt1.md;
      if(cs[1][i]<0) cs[1][i]+=ntt1.md;

      cs[2][i]=(ll)(cs[2][i]-cs[0][i])*r02%ntt2.md;
      cs[2][i]=(ll)(cs[2][i]-cs[1][i])*r12%ntt2.md;
      if(cs[2][i]<0) cs[2][i]+=ntt2.md;

      cs[0][i]+=(ll)cs[1][i]*ntt0.md%MOD;
      if(cs[0][i]>=MOD) cs[0][i]-=MOD;
      cs[0][i]+=(ll)cs[2][i]*m01%MOD;
      if(cs[0][i]>=MOD) cs[0][i]-=MOD;
    }
  }

  vector<int> multiply(vector<int> a,vector<int> b,int MOD){
    for(int& x:a) x%=MOD;
    for(int& x:b) x%=MOD;
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(a,b);
    cs[1]=ntt1.multiply(a,b);
    cs[2]=ntt2.multiply(a,b);
    size_t sz=a.size()+b.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }
};
NTT<0> ArbitraryModConvolution::ntt0;
NTT<1> ArbitraryModConvolution::ntt1;
NTT<2> ArbitraryModConvolution::ntt2;

//BEGIN CUT HERE
int factorial(int n,int MOD){
  if(n>=MOD) return 0;
  ArbitraryModConvolution arb;
  auto inv=[&](int a){return ArbitraryModConvolution::inv(a,MOD);};

  using ll = long long;
  auto add=[&](int a,int b){return a+b>=MOD?a+b-MOD:a+b;};
  auto sub=[&](int a,int b){return a-b<0?a-b+MOD:a-b;};
  auto mul=[&](int a,int b){return (ll)a*b%MOD;};
  auto div=[&](int a,int b){return mul(a,inv(b));};

  int d=1<<15;
  vector<int> fact(d*2+1,1),finv(d*2+1,1);
  for(int i=1;i<=d*2;i++) fact[i]=mul(fact[i-1],i);
  finv[d*2]=inv(fact[d*2]);
  for(int i=d*2-1;i>=0;i--) finv[i]=mul(finv[i+1],i+1);

  vector<int> seq({1,d+1});
  seq.reserve(d+1);

  int sz=1;
  while(sz<d){
    vector<int> aux(sz,1);
    vector<int> f(sz*4,0),g(sz*4,0);
    for(int i=0;i<=sz;i++){
      f[i]=mul(mul(finv[i],finv[sz-i]),seq[i]);
      if(((sz+i)&1)&&(f[i]!=0)) f[i]=MOD-f[i];
    }

    vector<int> pf(f);
    vector<int> as;
    as.emplace_back(sz+1);
    as.emplace_back(div(sz,d));
    as.emplace_back(add(div(sz,d),sz+1));

    for(int idx=0;idx<3;idx++){
      for(int i=0;i<sz*4;i++) f[i]=pf[i];
      for(int i=1;i<sz*2+2;i++)
        g[i]=inv(as[idx]+MOD-sz+i-1);
      f=arb.multiply(f,g,MOD);
      f.resize(sz*4);

      int prod=1;
      for(int i=0;i<=sz;i++) prod=mul(prod,sub(as[idx],i));

      for(int i=0;i<=sz;i++){
        f[sz+i+1]=mul(f[sz+i+1],prod);
        prod=mul(prod,add(as[idx],i+1));
        prod=div(prod,sub(as[idx],sz-i));
      }
      if(idx==0){
        for(int i=0;i<sz;i++)
          aux[i]=f[sz+i+1];
      }
      if(idx==1){
        for(int i=0;i<=sz;i++)
          seq[i]=mul(seq[i],f[sz+i+1]);
      }
      if(idx==2){
        for(int i=0;i<sz;i++)
          aux[i]=mul(aux[i],f[sz+i+1]);
      }
    }
    for(int x:aux) seq.emplace_back(x);
    sz<<=1;
  }

  int res=1;
  int l=min(d,(n+1)/d);
  for(int i=0;i<l;i++) res=mul(res,seq[i]);
  for(int i=l*d+1;i<=n;i++) res=mul(res,i);
  return res;
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  const int MOD = 1e9+7;
  int n;
  cin>>n;
  cout<<factorial(n,MOD)<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

