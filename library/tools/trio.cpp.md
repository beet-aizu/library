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


# :warning: tools/trio.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/trio.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16 +0900




## Depends on

* :heavy_check_mark: <a href="chminmax.cpp.html">tools/chminmax.cpp</a>
* :warning: <a href="fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="fixpoint.cpp.html">tools/fixpoint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, typename U, typename V>
struct trio{
  T first;
  U second;
  V third;
  trio(){}
  trio(T first,U second,V third):
    first(first),second(second),third(third){}
  operator tuple<T&, U&, V&>(){
    return forward_as_tuple(first,second,third);
  }
  using X = tuple<T, U, V>;
  operator X() const{return make_tuple(first,second,third);}
  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}
  bool operator!=(const trio&a) const{return (X)(*this)!=(X)a;}
  bool operator< (const trio&a) const{return (X)(*this)< (X)a;}
  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}
  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}
  bool operator>=(const trio&a) const{return (X)(*this)>=(X)a;}
};
template<typename T, typename U, typename V>
trio<T, U, V> make_trio(T first,U second,V third){
  return trio<T, U, V>(first,second,third);
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "fastio.cpp"
#include "fixpoint.cpp"
#include "chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CPSCO2019_SESSION1_H(){
  using ll = long long;

  int n,sum;
  cin>>n>>sum;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  const int MAX = 1e5+10;
  ll ans=0;
  MFP([&](auto dfs,int l,int r)->void{
        if(l+1==r){
          if(as[l]*3==sum) ans++;
          return;
        }
        int m=(l+r)>>1;
        dfs(l,m);
        dfs(m,r);
        using T = trio<int, int, int>;
        vector<T> vx,vy;
        {
          vx.reserve(r-m);
          int res=-1,cnt=0;
          for(int i=m;i<r;i++){
            if(res<as[i]) res=as[i],cnt=0;
            if(res==as[i]) cnt++;
            vx.emplace_back(res,cnt,as[i]);
          }
        }
        {
          vy.reserve(m-l);
          int res=-1,cnt=0;
          for(int i=m-1;i>=l;i--){
            if(res<as[i]) res=as[i],cnt=0;
            if(res==as[i]) cnt++;
            vy.emplace_back(res,cnt,as[i]);
          }
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());

        map<int, int> cx,cy;
        int sx=vx.size(),sy=vy.size();
        int i=0,j=0;
        while(i<sx||j<sy){
          int k=MAX;
          if(i<sx) chmin(k,vx[i].first);
          if(j<sy) chmin(k,vy[j].first);

          vector<int> tx,ty;
          while(i<sx&&k==vx[i].first){
            cx[vx[i].third]++;
            tx.emplace_back(i++);
          }
          while(j<sy&&k==vy[j].first){
            cy[vy[j].third]++;
            ty.emplace_back(j++);
          }

          for(int x:tx)
            ans+=(ll)vx[x].second*cy[sum-(k+vx[x].third)];

          for(int y:ty)
            ans+=(ll)vy[y].second*cx[sum-(k+vy[y].third)];
        }
      })(0,n);

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/05/09
  https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_h
*/

signed main(){
  //CPSCO2019_SESSION1_H();
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
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: tools/trio.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

