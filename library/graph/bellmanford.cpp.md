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


# :heavy_check_mark: graph/bellmanford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellmanford.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-22 13:11:34 +0900




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2872.test.cpp.html">test/aoj/2872.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#endif
//BEGIN CUT HERE
template<typename T>
struct BellmanFord{
  static constexpr T INF = numeric_limits<T>::max();

  struct edge{
    int u,v;
    T w;
    edge(){}
    edge(int u,int v,T w):u(u),v(v),w(w){}
  };

  int n;
  vector< vector<int> > G;
  vector<int> used,reach;
  BellmanFord(int n):n(n),G(n),used(n,0),reach(n,1){}

  vector<edge> es;
  void add_edge(int u,int v,T c){
    es.emplace_back(u,v,c);
    G[u].emplace_back(v);
  }

  vector<T> build(int from,int &neg_loop){
    vector<T> ds(n,INF);
    ds[from]=0;
    for(int j=0;j<n;j++){
      bool update=0;
      for(auto e:es){
        if(!reach[e.u]||!reach[e.v]||ds[e.u]==INF) continue;
        if(ds[e.v]>ds[e.u]+e.w){
          ds[e.v]=ds[e.u]+e.w;
          update=1;
        }
      }
      if(!update) break;
      if(j==n-1){
        neg_loop=1;
        return ds;
      }
    }
    neg_loop=0;
    return ds;
  }

  void dfs(int v){
    if(used[v]) return;
    used[v]=1;
    for(int u:G[v]) dfs(u);
  }

  T shortest_path(int from,int to,int &neg_loop){
    for(int i=0;i<n;i++){
      fill(used.begin(),used.end(),0);
      dfs(i);
      reach[i]=used[to];
    }
    return build(from,neg_loop)[to];
  }
};
template<typename T>
constexpr T BellmanFord<T>::INF;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  int n,m,p;
  cin>>n>>m>>p;
  BellmanFord<int> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    G.add_edge(a,b,p-c);
  }
  int neg_loop;
  int res=G.shortest_path(0,n-1,neg_loop);
  if(neg_loop){
    cout<<-1<<endl;
    return 0;
  }
  cout<<max(-res,0)<<endl;
  return 0;
}
/*
  verified on 2019/08/10
  https://atcoder.jp/contests/abc137/tasks/abc137_e
*/
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
subprocess.CalledProcessError: Command '['oj', 'test', '-c', '.verify-helper/cache/b645b11408d085ff850a88e829fefff4/a.out', '-d', '.verify-helper/cache/b645b11408d085ff850a88e829fefff4/test', '-j', '2']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: graph/bellmanford.cpp: line 8: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

