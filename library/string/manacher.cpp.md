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


# :heavy_check_mark: string/manacher.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-11 16:39:56 +0900




## Depends on

* :heavy_check_mark: <a href="../datastructure/sparsetable.cpp.html">datastructure/sparsetable.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2934.test.cpp.html">test/aoj/2934.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> manacher(string s){
  int n=s.size();
  vector<int> vs(n);
  for(int i=0,j=0;i<n;){
    while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) j++;
    vs[i]=j;
    int k=1;
    while(i-k>=0&&i+k<n&&k+vs[i-k]<j) vs[i+k]=vs[i-k],k++;
    i+=k;j-=k;
  }
  return vs;
}
//END CUT HERE
#ifndef call_from_test

//INSERT ABOVE HERE
signed SPOJ_LPS(){
  int n;
  string s;
  cin>>n>>s;
  string t="$";
  for(int i=0;i<n;i++){
    t.push_back(s[i]);
    t.push_back('$');
  }
  auto vs=manacher(t);
  cout<<*max_element(vs.begin(),vs.end())-1<<endl;
  return 0;
}
/*
  verified on 2019/10/29
  http://www.spoj.com/problems/LPS/
*/

#define call_from_test
#include "../datastructure/sparsetable.cpp"
#undef call_from_test

signed ukuku09_D(){
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;

  auto f=[](int a,int b){return max(a,b);};
  SparseTable<int> sp(f);
  sp.build(manacher(s));

  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    int L=0,R=n;
    while(L+1<R){
      int M=(L+R)>>1;
      if(l+(M-1)<r-(M-1)&&sp.query(l+(M-1),r-(M-1))>=M) L=M;
      else R=M;
    }
    cout<<L*2-1<<endl;
  }
  return 0;
}
/*
  verified on 2019/10/29
  https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
*/

signed main(){
  //SPOJ_LPS();
  //ukuku09_D();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 339, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 119, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: string/manacher.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

