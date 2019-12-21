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


# :warning: tools/iskado.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/iskado.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16+09:00




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
bool is_kado(T a,T b,T c){
  if(a==b||b==c||c==a) return 0;
  if(a<b&&b>c) return 1;
  if(a>b&&b<c) return 1;
  return 0;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE

signed main(){
  int w,h;
  cin>>w>>h;
  vector<vector<int>> st(h,vector<int>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>st[i][j];

  using T = tuple<int, int, int, int>;
  map<T, int> dp;
  queue<T> qu;
  if(st[0][0]!=st[0][1]){
    dp[T(0,0,0,1)]=1;
    qu.emplace(0,0,0,1);
  }
  if(st[0][0]!=st[1][0]){
    dp[T(0,0,1,0)]=1;
    qu.emplace(0,0,1,0);
  }

  int dy[]={0,0,1,-1};
  int dx[]={1,-1,0,0};
  auto in=[&](int y,int x){return 0<=y&&y<h&&0<=x&&x<w;};

  int ans=-1;
  while(!qu.empty()){
    int py,px,cy,cx;
    tie(py,px,cy,cx)=qu.front();qu.pop();
    if(cy==h-1&&cx==w-1){
      ans=dp[T(py,px,cy,cx)];
      break;
    }
    for(int k=0;k<4;k++){
      int ny=cy+dy[k],nx=cx+dx[k];
      if(!in(ny,nx)) continue;
      if(!is_kado(st[py][px],st[cy][cx],st[ny][nx])) continue;
      if(dp.count(T(cy,cx,ny,nx))) continue;
      dp[T(cy,cx,ny,nx)]=dp[T(py,px,cy,cx)]+1;
      qu.emplace(cy,cx,ny,nx);
    }
  }

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/12/17
  https://yukicoder.me/problems/no/124
*/
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
onlinejudge_verify.bundle.BundleError: tools/iskado.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

