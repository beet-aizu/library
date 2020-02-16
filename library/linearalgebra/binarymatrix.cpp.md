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


# :heavy_check_mark: linearalgebra/binarymatrix.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#1bbf1d9f5340fa94bf2c5fb5ce73a5f5">linearalgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/linearalgebra/binarymatrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 16:09:50+09:00




## Depends on

* :heavy_check_mark: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1308.test.cpp.html">test/aoj/1308.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2624.test.cpp.html">test/aoj/2624.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
const int MAX = 2002;
using BS = bitset<MAX*2>;
using mat = vector<BS>;

void gauss(mat &v){
  int n=v.size();
  for(int i=0;i<n;i++){
    for(int k=i;k<n;k++){
      if(v[k][i]){
        swap(v[i],v[k]);
        break;
      }
    }
    for(int k=0;k<n;k++)
      if(i!=k&&v[k][i]) v[k]^=v[i];
  }
}

int mrank(mat v,int m){
  int n=v.size();
  int r=0,c=0;
  for(int i=0;i<n;i++){
    int s=-1;
    while(c<m){
      for(int j=i;j<n;j++){
        if(v[j][c]){
          s=j;
          break;
        }
      }
      if(~s) break;
      c++;
    }
    if(c>=m) break;

    swap(v[i],v[s]);
    for(int j=0;j<n;j++)
      if(i!=j&&v[j][c]) v[j]^=v[i];

    r++;c++;
  }
  return r;
}

mat mul(const mat &a,const mat &b){
  int n=a.size();
  vector<vector<int> > tmp(n,vector<int>(n,0));
  mat res(n,BS(0));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int k=0;k<n;k++)
        tmp[i][j]+=(a[i][k]&b[k][j]);

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      res[i][j]=tmp[i][j]&1;

  return res;
}

mat mat_pow(mat v,long long k){
  int n=v.size();
  mat res(n,BS(0));
  for(int i=0;i<n;i++)
    res[i][i]=1;
  while(k){
    if(k&1) res=mul(res,v);
    v=mul(v,v);
    k>>=1;
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#undef call_from_test

signed CFR382_D(){
  int n,m;
  cin>>n>>m;
  mat v(n,BS(0));
  for(int i=0;i<n;i++) v[i][n+i]=1;
  vector<int> as(m),bs(m);
  for(int i=0;i<m;i++){
    cin>>as[i]>>bs[i];
    as[i]--;bs[i]--;
    v[as[i]][bs[i]]=1;
  }
  gauss(v);
  for(int i=0;i<m;i++)
    cout<<(v[bs[i]][as[i]+n]?"NO":"YES")<<"\n";
  cout<<flush;
  return 0;
}
/*
  verified on 2019/12/17
  http://codeforces.com/contest/736/problem/D
*/

signed ARC054_D(){
  int n;
  cin>>n;
  mat v(n,BS(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char c;
      cin>>c;
      v[i][j]=c-'0';
    }
  }
  int ans=mrank(v,n);
  cout<<(ans==n?"Odd":"Even")<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://atcoder.jp/contests/arc054/tasks/arc054_c
*/

signed main(){
  //CFR382_D();
  //ARC054_D();
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linearalgebra/binarymatrix.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

