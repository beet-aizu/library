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


# :heavy_check_mark: string/knuth_morris_pratt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/knuth_morris_pratt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 22:01:05+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp.html">test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// longest prefix suffix matching of [0, i)
vector<int> knuth_morris_pratt(const string &s){
  int n=s.size();
  vector<int> kmp(n+1,-1),mp(n+1,-1);
  for(int i=0,j=-1;i<n;i++){
    while(~j&&s[i]!=s[j]) j=kmp[j];
    kmp[i+1]=mp[i+1]=++j;
    if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];
  }
  return mp;
}
// smallest d s.t. s[x] == s[x + d] for all x
vector<int> minimum_period(const string &s){
  auto mp=knuth_morris_pratt(s);
  for(int i=1;i<(int)mp.size();i++) mp[i]=i-mp[i];
  return mp;
}
// positions for t that match s
vector<int> pattern_match(string s,string t){
  int n=s.size(),m=t.size();
  vector<int> kmp=knuth_morris_pratt(s);

  vector<int> res;
  int i=0,j=0;
  while(i+j<m){
    if(s[j]==t[i+j]){
      if(++j!=n) continue;
      res.emplace_back(i);
    }
    i+=j-kmp[j];
    j=max(kmp[j],0);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed ABC135_D(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s,t;
  cin>>s>>t;

  int n=s.size(),m=t.size();

  string b;
  while(b.size()<t.size()) b+=s;
  auto mp=knuth_morris_pratt(t+'$'+b+b);

  vector<int> match(n);
  for(int i=m+1;i<=m+n;i++)
    match[i-(m+1)]=mp[i+m]==m;

  vector< vector<int> > G(n);
  for(int i=0;i<n;i++)
    if(match[i]) G[i].emplace_back((i+m)%n);

  vector<int> indeg(n,0);
  for(int i=0;i<n;i++)
    for(int j:G[i]) indeg[j]++;

  queue<int> que;
  for(int i=0;i<n;i++)
    if(indeg[i]==0) que.emplace(i);

  vector<int> dp(n,0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      chmax(dp[u],dp[v]+1);
      indeg[u]--;
      if(indeg[u]==0) que.emplace(u);
    }
  }

  for(int i=0;i<n;i++){
    if(indeg[i]!=0){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<*max_element(dp.begin(),dp.end())<<endl;
  return 0;
}
/*
  verified on 2019/08/21
  https://atcoder.jp/contests/abc135/tasks/abc135_f
*/

signed ARC060_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string w;
  cin>>w;

  int n=w.size();
  if(w==string(n,w[0])){
    cout<<n<<endl<<1<<endl;
    return 0;
  }

  auto mp=minimum_period(w);
  if(n%mp[n]!=0||n==mp[n]){
    cout<<1<<endl<<1<<endl;
    return 0;
  }

  string w_rev=w;
  reverse(w_rev.begin(),w_rev.end());
  auto mp_rev=minimum_period(w_rev);

  int cnt=0;
  for(int i=1;i<n;i++){
    int j=n-i;
    if(i%mp[i]==0&&i>mp[i]) continue;
    if(j%mp_rev[j]==0&&j>mp_rev[j]) continue;
    cnt++;
  }
  cout<<2<<endl<<cnt<<endl;
  return 0;
}
/*
  verified on 2019/08/21
  https://atcoder.jp/contests/arc060/tasks/arc060_d
*/

signed main(){
  //ABC135_D();
  //ARC060_F();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: string/knuth_morris_pratt.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

