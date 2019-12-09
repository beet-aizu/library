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


# :warning: convolution/fastfouriertransform.cpp
* category: convolution


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [convolution/arbitrarymodconvolution.cpp](arbitrarymodconvolution.cpp.html)
* :heavy_check_mark: [polynomial/formalpowerseries.cpp](../polynomial/formalpowerseries.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/2985.test.cpp](../../verify/test/aoj/2985.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
namespace FFT{
  using dbl = double;

  struct num{
    dbl x,y;
    num(){x=y=0;}
    num(dbl x,dbl y):x(x),y(y){}
  };

  inline num operator+(num a,num b){
    return num(a.x+b.x,a.y+b.y);
  }
  inline num operator-(num a,num b){
    return num(a.x-b.x,a.y-b.y);
  }
  inline num operator*(num a,num b){
    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
  }
  inline num conj(num a){
    return num(a.x,-a.y);
  }

  int base=1;
  vector<num> rts={{0,0},{1,0}};
  vector<int> rev={0,1};

  const dbl PI=asinl(1)*2;

  void ensure_base(int nbase){
    if(nbase<=base) return;

    rev.resize(1<<nbase);
    for(int i=0;i<(1<<nbase);i++)
      rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));

    rts.resize(1<<nbase);
    while(base<nbase){
      dbl angle=2*PI/(1<<(base+1));
      for(int i=1<<(base-1);i<(1<<base);i++){
        rts[i<<1]=rts[i];
        dbl angle_i=angle*(2*i+1-(1<<base));
        rts[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &as){
    int n=as.size();
    assert((n&(n-1))==0);

    int zeros=__builtin_ctz(n);
    ensure_base(zeros);
    int shift=base-zeros;
    for(int i=0;i<n;i++)
      if(i<(rev[i]>>shift))
        swap(as[i],as[rev[i]>>shift]);

    for(int k=1;k<n;k<<=1){
      for(int i=0;i<n;i+=2*k){
        for(int j=0;j<k;j++){
          num z=as[i+j+k]*rts[j+k];
          as[i+j+k]=as[i+j]-z;
          as[i+j]=as[i+j]+z;
        }
      }
    }
  }

  vector<long long> multiply(vector<int> &as,vector<int> &bs){
    int need=as.size()+bs.size()-1;
    int nbase=0;
    while((1<<nbase)<need) nbase++;
    ensure_base(nbase);

    int sz=1<<nbase;
    vector<num> fa(sz);
    for(int i=0;i<sz;i++){
      int x=(i<(int)as.size()?as[i]:0);
      int y=(i<(int)bs.size()?bs[i]:0);
      fa[i]=num(x,y);
    }
    fft(fa);

    num r(0,-0.25/sz);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
      if(i!=j)
        fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
      fa[i]=z;
    }
    fft(fa);

    vector<long long> res(need);
    for(int i=0;i<need;i++)
      res[i]=round(fa[i].x);

    return res;
  }

};
//END CUT HERE
#ifndef call_from_test
signed main(){
  int n;
  scanf("%d",&n);
  vector<int> as(n+1,0),bs(n+1,0);
  for(int i=1;i<=n;i++) scanf("%d %d",&as[i],&bs[i]);
  auto cs=FFT::multiply(as,bs);
  for(int i=1;i<=n*2;i++) printf("%lld\n",cs[i]);
  return 0;
}
/*
  verified on 2019/11/26
  https://atcoder.jp/contests/atc001/tasks/fft_c
*/
#endif

```
{% endraw %}

[Back to top page](../../index.html)

