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


# :warning: bbst/persistent/ushi.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9c18e90622c99f987841c06d60e235e9">bbst/persistent</a>
* <a href="{{ site.github.repository_url }}/blob/master/bbst/persistent/ushi.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:56:59+09:00




## Depends on

* :heavy_check_mark: <a href="../basic/base.cpp.html">bbst/basic/base.cpp</a>
* :heavy_check_mark: <a href="../basic/ushi.cpp.html">bbst/basic/ushi.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../basic/base.cpp"
#include "../basic/ushi.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM>
struct PersistentUshi : Ushi<Node, LIM>{
  using super = Ushi<Node, LIM>;
  using super::super;
  using T = typename Node::T;

  inline Node* clone(Node* a){
    if(a==nullptr) return a;
    return super::create(*a);
  }

  Node* eval(Node* a){
    a=clone(a);
    if(a->rev){
      a->l=clone(a->l);
      a->r=clone(a->r);
    }
    return super::eval(a);
  }

  T query(Node *a,size_t l,size_t r){
    auto s=super::split(a,l);
    auto t=super::split(s.second,r-l);
    return super::query(t.first);
  }

  Node* rebuild(Node* a){
    auto v=super::dump(a);
    super::ptr=0;
    return super::build(v);
  }

  bool almost_full() const{
    return super::ptr>LIM*9/10;
  }
};
//END CUT HERE
//INSERT ABOVE HERE
#ifndef call_from_test
signed HAPPYQUERY_B(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  int ti=INT_MAX;

  using Node = NodeBase<int>;
  constexpr size_t LIM = 7e6;
  PersistentUshi<Node, LIM> G(f,ti);
  auto rt=G.build(vector<Node>(as.begin(),as.end()));

  vector<decltype(rt)> rts;
  rts.emplace_back(rt);

  int q1;
  cin>>q1;
  rts.reserve(q1+1);

  for(int i=0;i<q1;i++){
    int p,x;
    cin>>p>>x;
    p--;
    rt=G.set_val(rt,p,x);
    rts.emplace_back(rt);
  }

  int q2;
  cin>>q2;
  int x=0;
  for(int i=0;i<q2;i++){
    int a,b,c;
    cin>>a>>b>>c;
    int k=a^x;
    int l=(b^x)-1;
    int r=(c^x);
    assert(l<r);
    x=G.query(rts[k],l,r);
    cout<<x<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/10/22
  https://www.hackerrank.com/contests/happy-query-contest/challenges/minimum-history-query/problem
*/

signed main(){
  HAPPYQUERY_B();
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 154, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: bbst/basic/base.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

