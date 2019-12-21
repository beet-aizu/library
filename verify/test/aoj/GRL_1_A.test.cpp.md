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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/GRL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/radixheap.cpp.html">datastructure/radixheap.cpp</a>
* :warning: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/radixheap.cpp"
#undef call_from_test

signed main(){
  int n,m,r;
  cin>>n>>m>>r;

  using P = pair<int, int>;
  vector< vector<P> > G(n);
  for(int i=0;i<m;i++){
    int s,t,d;
    cin>>s>>t>>d;
    G[s].emplace_back(t,d);
  }

  const int INF = numeric_limits<int>::max();
  RadixHeap<int, int> pq;
  vector<int> dist(n,INF);
  dist[r]=0;
  pq.emplace(dist[r],r);
  while(!pq.empty()){
    P p=pq.pop();
    int v=p.second;
    if(dist[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first,c=e.second;
      if(dist[u]>dist[v]+c){
        dist[u]=dist[v]+c;
        pq.emplace(dist[u],u);
      }
    }
  }

  for(int i=0;i<n;i++){
    if(dist[i]==INF) cout<<"INF\n";
    else cout<<dist[i]<<"\n";
  }
  cout<<flush;
  return 0;
}

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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 154, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: tools/fastio.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

