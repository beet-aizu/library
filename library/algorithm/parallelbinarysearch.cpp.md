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


# :warning: algorithm/parallelbinarysearch.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/parallelbinarysearch.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-25 17:18:18 +0900




## Depends on

* :heavy_check_mark: <a href="../datastructure/unionfindtree.cpp.html">datastructure/unionfindtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> parallelbinarysearch(int n,int q,
                                 function<void(void)> init,
                                 function<void(int)> apply,
                                 function<bool(int)> check){
  vector<vector<int> > C(q);
  vector<int> L(n,-1),R(n,q);
  bool flg=1;
  while(flg){
    flg=0;
    init();
    for(int i=0;i<n;i++)
      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);
    for(int i=0;i<q;i++){
      flg|=!C[i].empty();
      apply(i);
      for(int j:C[i]){
        if(check(j)) R[j]=i;
        else L[j]=i;
      }
      C[i].clear();
    }
  }
  return R;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../datastructure/unionfindtree.cpp"
#undef call_from_test

signed CODETHANKSFESTIVAL2017_H(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) cin>>a[i]>>b[i];
  int q;
  cin>>q;
  vector<int> x(q),y(q);
  for(int i=0;i<q;i++) cin>>x[i]>>y[i];

  for(int i=0;i<m;i++) a[i]--,b[i]--;
  for(int i=0;i<q;i++) x[i]--,y[i]--;

  UnionFind uf;
  auto init=[&]{uf=UnionFind(n);};
  auto apply=[&](int i){uf.unite(a[i],b[i]);};
  auto check=[&](int i){return uf.same(x[i],y[i]);};

  auto ans=parallelbinarysearch(q,m,init,apply,check);

  for(int i=0;i<q;i++)
    cout<<(ans[i]==m?-1:ans[i]+1)<<endl;

  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
*/

signed main(){
  CODETHANKSFESTIVAL2017_H();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 173, in main
    subcommand_run(paths=[])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 70, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 87, in main
    exec_command(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/a.out', '-d', '.verify-helper/cache/c36a49005ac83bc17634badc8dd1bcb9/test', '-e', '\'"1e-8"\'']' returned non-zero exit status 2.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 345, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 125, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: algorithm/parallelbinarysearch.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

