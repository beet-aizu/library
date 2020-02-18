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


# :warning: convolution/fastwalshhadamardtransform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/fastwalshhadamardtransform.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:09:50+09:00




## Depends on

* :heavy_check_mark: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
void FWT(vector<T> &a){
  int n=a.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=a[i+j],y=a[i+j+d];
        a[i+j]=x+y;
        a[i+j+d]=x-y;
      }
    }
  }
}

template<typename T>
void multiply(vector<T> &a,const vector<T> &b){
  for(int i=0;i<(int)a.size();i++)
    a[i]=a[i]*b[i];
}

template<typename T>
void UFWT(vector<T> &a,T rev2){
  int n=a.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=a[i+j],y=a[i+j+d];
        a[i+j]=(x+y)*rev2;
        a[i+j+d]=(x-y)*rev2;
      }
    }
  }
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../mod/mint.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CGR002_H(){
  using ll = long long;
  const int MOD = 998244353;
  using M = Mint<int, MOD>;

  int n,k;
  cin>>n>>k;

  ll p,q,r;
  cin>>p>>q>>r;

  int ofs=0;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
    ofs^=a[i];
    b[i]^=a[i];
    c[i]^=a[i];
    a[i]=0;
  }

  vector<vector<ll> > vm((1<<k),vector<ll>(4,0));
  for(int t=0;t<4;t++){
    vector<ll> vs(1<<k,0);
    for(int i=0;i<n;i++){
      vs[a[i]]+=(t==0);
      vs[b[i]]+=(t==1);
      vs[c[i]]+=(t==2);
      vs[b[i]^c[i]]+=(t==3);
    }
    FWT(vs);
    for(int i=0;i<(1<<k);i++) vm[i][t]=vs[i];
  }

  vector<M> vs(1<<k,1);
  for(int i=0;i<(1<<k);i++){
    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;
    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;
    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;
    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;

    vs[i]*=M(p+q+r).pow(x);
    vs[i]*=M(p+q-r).pow(y);
    vs[i]*=M(p-q+r).pow(z);
    vs[i]*=M(p-q-r).pow(w);
  }

  M rev2=M(2).inv();
  UFWT(vs,rev2);
  for(int i=0;i<(1<<k);i++){
    if(i) cout<<" ";
    cout<<vs[ofs^i].v;
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2019/10/25
  https://codeforces.com/contest/1119/problem/H
*/

signed main(){
  CGR002_H();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: convolution/fastwalshhadamardtransform.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

