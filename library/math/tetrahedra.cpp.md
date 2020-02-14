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


# :heavy_check_mark: math/tetrahedra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/tetrahedra.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-29 12:01:20+09:00




## Depends on

* :heavy_check_mark: <a href="../linearalgebra/matrix.cpp.html">linearalgebra/matrix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2060.test.cpp.html">test/aoj/2060.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../linearalgebra/matrix.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
bool isTriangle(double a1,double a2,double a3){
  if(a1+a2<=a3||a2+a3<=a1||a3+a1<=a2) return 0;
  return 1;
}

double tetrahedra(double OA,double OB,double OC,
                  double AB,double AC,double BC){
  if(!isTriangle(OA,OB,AB)) return 0;
  if(!isTriangle(OB,OC,BC)) return 0;
  if(!isTriangle(OC,OA,AC)) return 0;
  if(!isTriangle(AB,AC,BC)) return 0;
  Matrix<double> A(5,5);
  A[0][0]=    0;A[0][1]=AB*AB;A[0][2]=AC*AC;A[0][3]=OA*OA;A[0][4]=1;
  A[1][0]=AB*AB;A[1][1]=    0;A[1][2]=BC*BC;A[1][3]=OB*OB;A[1][4]=1;
  A[2][0]=AC*AC;A[2][1]=BC*BC;A[2][2]=    0;A[2][3]=OC*OC;A[2][4]=1;
  A[3][0]=OA*OA;A[3][1]=OB*OB;A[3][2]=OC*OC;A[3][3]=    0;A[3][4]=1;
  A[4][0]=    1;A[4][1]=    1;A[4][2]=    1;A[4][3]=    1;A[4][4]=0;
  double res=A.determinant();
  if(res<=0) return 0;
  return sqrt(res/288.0);
}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: linearalgebra/matrix.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

