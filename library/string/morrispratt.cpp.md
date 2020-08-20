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


# :warning: string/morrispratt.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/morrispratt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 15:14:35+09:00


* see: <a href="https://snuke.hatenablog.com/entry/2014/12/01/235807">https://snuke.hatenablog.com/entry/2014/12/01/235807</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://snuke.hatenablog.com/entry/2014/12/01/235807
 */
//BEGIN CUT HERE
// longest prefix suffix matching of [0, i)
vector<int> morris_pratt(const string &s){
  int n=s.size();
  vector<int> mp(n+1,-1);
  for(int i=0,j=-1;i<n;i++){
    while(~j&&s[i]!=s[j]) j=mp[j];
    mp[i+1]=++j;
  }
  return mp;
}
// smallest d s.t. s[x] == s[x + d] for all x
vector<int> minimum_period(const string &s){
  auto mp=morris_pratt(s);
  for(int i=1;i<(int)mp.size();i++) mp[i]=i-mp[i];
  return mp;
}
//END CUT HERE
#ifndef call_from_test

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
// test minimum_period
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

  auto kmp=minimum_period(w);
  if(n%kmp[n]!=0||n==kmp[n]){
    cout<<1<<endl<<1<<endl;
    return 0;
  }

  string w_rev=w;
  reverse(w_rev.begin(),w_rev.end());
  auto kmp_rev=minimum_period(w_rev);

  int cnt=0;
  for(int i=1;i<n;i++){
    int j=n-i;
    if(i%kmp[i]==0&&i>kmp[i]) continue;
    if(j%kmp_rev[j]==0&&j>kmp_rev[j]) continue;
    cnt++;
  }
  cout<<2<<endl<<cnt<<endl;
  return 0;
}
/*
  verified on 2020/08/20
  https://atcoder.jp/contests/arc060/tasks/arc060_d
*/

signed main(){
  ARC060_F();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "string/morrispratt.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
/*
 * @see https://snuke.hatenablog.com/entry/2014/12/01/235807
 */
//BEGIN CUT HERE
// longest prefix suffix matching of [0, i)
vector<int> morris_pratt(const string &s){
  int n=s.size();
  vector<int> mp(n+1,-1);
  for(int i=0,j=-1;i<n;i++){
    while(~j&&s[i]!=s[j]) j=mp[j];
    mp[i+1]=++j;
  }
  return mp;
}
// smallest d s.t. s[x] == s[x + d] for all x
vector<int> minimum_period(const string &s){
  auto mp=morris_pratt(s);
  for(int i=1;i<(int)mp.size();i++) mp[i]=i-mp[i];
  return mp;
}
//END CUT HERE
#ifndef call_from_test

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
// test minimum_period
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

  auto kmp=minimum_period(w);
  if(n%kmp[n]!=0||n==kmp[n]){
    cout<<1<<endl<<1<<endl;
    return 0;
  }

  string w_rev=w;
  reverse(w_rev.begin(),w_rev.end());
  auto kmp_rev=minimum_period(w_rev);

  int cnt=0;
  for(int i=1;i<n;i++){
    int j=n-i;
    if(i%kmp[i]==0&&i>kmp[i]) continue;
    if(j%kmp_rev[j]==0&&j>kmp_rev[j]) continue;
    cnt++;
  }
  cout<<2<<endl<<cnt<<endl;
  return 0;
}
/*
  verified on 2020/08/20
  https://atcoder.jp/contests/arc060/tasks/arc060_d
*/

signed main(){
  ARC060_F();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

