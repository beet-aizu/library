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


# :heavy_check_mark: string/zalgorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/zalgorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 22:01:05+09:00




## Depends on

* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest common prefix of s and s[i:n]
vector<int> zalgorithm(string s){
  int n=s.size();
  vector<int> as(n,0);
  as[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n&&s[j]==s[i+j]) j++;
    as[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<n&&k+as[k]<j) as[i+k]=as[k],k++;
    i+=k;
    j-=k;
  }
  return as;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../datastructure/binaryindexedtree.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CFR432_D(){
  string s;
  cin>>s;
  vector<int> as=zalgorithm(s);
  int n=s.size();
  set<int> ss;
  BIT<int> bit(n+100);
  for(int i=0;i<n;i++){
    bit.add0(as[i],1);
    if(i+as[i]!=n) continue;
    ss.emplace(as[i]);
  }
  cout<<ss.size()<<"\n";
  for(auto x:ss) cout<<x<<" "<<bit.query0(x,n+100)<<"\n";
  return 0;
}
/*
  verified on 2019/12/17
  http://codeforces.com/problemset/problem/432/D
*/

signed main(){
  CFR432_D();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 169, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 66, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 88, in main
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/73173ca12efecaabc50e0858435d10fb/a.out', '-d', '.verify-helper/cache/73173ca12efecaabc50e0858435d10fb/test', '--tle', '60', '--judge-command', '.verify-helper/cache/73173ca12efecaabc50e0858435d10fb/checker.out', '-j', '2']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: string/zalgorithm.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

