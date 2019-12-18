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


# :heavy_check_mark: convolution/arbitrarymodconvolution_with_garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/arbitrarymodconvolution_with_garner.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-18 10:44:32 +0900




## Depends on

* :warning: <a href="numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../mod/enumeration.cpp.html">mod/enumeration.cpp</a>
* :warning: <a href="../mod/mint.cpp.html">mod/mint.cpp</a>
* :warning: <a href="../tools/fastio.cpp.html">tools/fastio.cpp</a>


## Required by

* :warning: <a href="../mod/factorial.cpp.html">mod/factorial.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../mod/mint.cpp"
#include "numbertheoretictransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
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

  inline void garner(int &c0,int c1,int c2,int m01,int MOD){
    static constexpr int r01=inv(ntt0.md,ntt1.md);
    static constexpr int r02=inv(ntt0.md,ntt2.md);
    static constexpr int r12=inv(ntt1.md,ntt2.md);

    c1=(ll)(c1-c0)*r01%ntt1.md;
    if(c1<0) c1+=ntt1.md;

    c2=(ll)(c2-c0)*r02%ntt2.md;
    c2=(ll)(c2-c1)*r12%ntt2.md;
    if(c2<0) c2+=ntt2.md;

    c0+=(ll)c1*ntt0.md%MOD;
    if(c0>=MOD) c0-=MOD;
    c0+=(ll)c2*m01%MOD;
    if(c0>=MOD) c0-=MOD;
  }

  inline void garner(vector< vector<int> > &cs,int MOD){
    int m01 =(ll)ntt0.md*ntt1.md%MOD;
    int sz=cs[0].size();
    for(int i=0;i<sz;i++) garner(cs[0][i],cs[1][i],cs[2][i],m01,MOD);
  }

  vector<int> multiply(vector<int> as,vector<int> bs,int MOD){
    vector< vector<int> > cs(3);
    cs[0]=ntt0.multiply(as,bs);
    cs[1]=ntt1.multiply(as,bs);
    cs[2]=ntt2.multiply(as,bs);
    size_t sz=as.size()+bs.size()-1;
    for(auto& v:cs) v.resize(sz);
    garner(cs,MOD);
    return cs[0];
  }

  template<typename T,T MOD>
  decltype(auto) multiply(vector< Mint<T, MOD> > am,
                          vector< Mint<T, MOD> > bm){
    using M = Mint<T, MOD>;
    vector<int> as(am.size()),bs(bm.size());
    for(int i=0;i<(int)as.size();i++) as[i]=am[i].v;
    for(int i=0;i<(int)bs.size();i++) bs[i]=bm[i].v;
    vector<int> cs=multiply(as,bs,MOD);
    vector<M> cm(cs.size());
    for(int i=0;i<(int)cm.size();i++) cm[i]=M(cs[i]);
    return cm;
  }
};
NTT<0> ArbitraryModConvolution::ntt0;
NTT<1> ArbitraryModConvolution::ntt1;
NTT<2> ArbitraryModConvolution::ntt2;
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../tools/fastio.cpp"
#include "../mod/enumeration.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed YUKI_829(){
  using ll = long long;
  int n,b;
  cin>>n>>b;
  vector<int> s(n);
  for(int i=0;i<n;i++) cin>>s[i];
  using M = Mint<int>;
  using E = Enumeration<M>;
  E::init(3e5);

  vector<int> cnt(n,0);
  for(int i=0;i<n;i++) cnt[s[i]]++;

  using P = pair<int, vector<int> > ;
  priority_queue<P> pq;
  pq.emplace(-1,vector<int>(1,1));

  int sum=0;
  for(int i=n-1;i>=0;i--){
    if(cnt[i]==0) continue;
    M x=E::H(sum,cnt[i]);
    M y=E::H(sum+1,cnt[i])-x;
    x*=E::Fact(cnt[i]);
    y*=E::Fact(cnt[i]);

    pq.emplace(-2,vector<int>({x.v,y.v}));
    sum+=cnt[i];
  }

  const int MOD = 1e9+7;
  ArbitraryModConvolution arb;
  while(pq.size()>1u){
    auto as=pq.top().second;pq.pop();
    auto bs=pq.top().second;pq.pop();
    auto cs=arb.multiply(as,bs,MOD);
    pq.emplace(-(int)cs.size(),cs);
  }

  auto dp=pq.top().second;
  M ans(0),res(1);
  for(int j=0;j<(int)dp.size();j++){
    ans+=M((ll)j*(ll)dp[j])*res;
    res*=M(b);
  }
  cout<<ans.v<<endl;
  return 0;
}
/*
  verified on 2019/09/08
  https://yukicoder.me/problems/no/829
*/

signed main(){
  YUKI_829();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 175, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 72, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 89, in main
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/1112bf5aedcf80f614b3e755249be9a3/a.out', '-d', '.verify-helper/cache/1112bf5aedcf80f614b3e755249be9a3/test', '--judge-command', '.verify-helper/cache/1112bf5aedcf80f614b3e755249be9a3/checker.out', '-j', '2']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 150, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 52, in _resolve
    raise BundleError(path, -1, "no such header")
onlinejudge_verify.bundle.BundleError: ../mod/mint.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

