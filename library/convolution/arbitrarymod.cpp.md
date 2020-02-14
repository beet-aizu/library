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


# :heavy_check_mark: convolution/arbitrarymod.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/arbitrarymod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-23 19:42:36+09:00




## Depends on

* :heavy_check_mark: <a href="fastfouriertransform.cpp.html">convolution/fastfouriertransform.cpp</a>


## Required by

* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.test.cpp.html">test/yosupo/convolution_mod_1000000007.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "fastfouriertransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
struct ArbitraryMod{
  using dbl=FFT::dbl;
  using num=FFT::num;

  vector<T> multiply(vector<T> as,vector<T> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    vector<num> fa(sz),fb(sz);
    for(int i=0;i<(int)as.size();i++)
      fa[i]=num(as[i].v&((1<<15)-1),as[i].v>>15);
    for(int i=0;i<(int)bs.size();i++)
      fb[i]=num(bs[i].v&((1<<15)-1),bs[i].v>>15);

    fft(fa);fft(fb);

    dbl ratio=0.25/sz;
    num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num a1=(fa[i]+conj(fa[j]));
      num a2=(fa[i]-conj(fa[j]))*r2;
      num b1=(fb[i]+conj(fb[j]))*r3;
      num b2=(fb[i]-conj(fb[j]))*r4;
      if(i!=j){
        num c1=(fa[j]+conj(fa[i]));
        num c2=(fa[j]-conj(fa[i]))*r2;
        num d1=(fb[j]+conj(fb[i]))*r3;
        num d2=(fb[j]-conj(fb[i]))*r4;
        fa[i]=c1*d1+c2*d2*r5;
        fb[i]=c1*d2+c2*d1;
      }
      fa[j]=a1*b1+a2*b2*r5;
      fb[j]=a1*b2+a2*b1;
    }
    fft(fa);fft(fb);

    vector<T> cs(need);
    using ll = long long;
    for(int i=0;i<need;i++){
      ll aa=T(llround(fa[i].x)).v;
      ll bb=T(llround(fb[i].x)).v;
      ll cc=T(llround(fa[i].y)).v;
      cs[i]=T(aa+(bb<<15)+(cc<<30));
    }
    return cs;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 181, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 59, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 116, in main
    verified = verify_file(path, compilers=compilers, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 70, in verify_file
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 28, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'download', '--system', '-d', '.verify-helper/cache/ad454c14bfdd77526dd7c6bc932b431e/test', 'https://yukicoder.me/problems/1948']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 343, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 182, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: convolution/fastfouriertransform.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

