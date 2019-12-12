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


# :warning: string/trie.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/trie.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-28 00:24:39 +0900




## Required By
* :warning: <a href="ahocorasick.cpp.html">string/ahocorasick.cpp</a>


## Verified With
* :heavy_check_mark: <a href="../../verify/test/aoj/2212.test.cpp.html">test/aoj/2212.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2257.test.cpp.html">test/aoj/2257.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3073.test.cpp.html">test/aoj/3073.test.cpp</a>


## Code
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
template<size_t X>
struct Trie{
  struct Node{
    char c;
    array<int, X> nxt;
    vector<int> idxs;
    int idx;
    Node(char c):c(c),idx(-1){fill(nxt.begin(),nxt.end(),-1);}
  };

  using F = function<int(char)>;
  vector<Node> vs;
  F conv;

  Trie(F conv,char c='$'):conv(conv){vs.emplace_back(c);}

  inline int &next(int i,int j){
    return vs[i].nxt[j];
  }

  void add(const string &s,int x){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(~next(pos,k)){
        pos=next(pos,k);
        continue;
      }
      int npos=vs.size();
      next(pos,k)=npos;
      vs.emplace_back(s[i]);
      pos=npos;
    }
    vs[pos].idx=x;
    vs[pos].idxs.emplace_back(x);
  }

  int find(const string &s){
    int pos=0;
    for(int i=0;i<(int)s.size();i++){
      int k=conv(s[i]);
      if(next(pos,k)<0) return -1;
      pos=next(pos,k);
    }
    return pos;
  }

  int move(int pos,char c){
    assert(pos<(int)vs.size());
    return pos<0?-1:next(pos,conv(c));
  }

  int size(){return vs.size();}

  int idx(int pos){
    return pos<0?-1:vs[pos].idx;
  }

  vector<int> idxs(int pos){
    return pos<0?vector<int>():vs[pos].idxs;
  }

};
//END CUT HERE
#ifndef call_from_test
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed tenka1_2016_final_C(){
  string s;
  cin>>s;
  int m;
  cin>>m;
  vector<string> p(m);
  for(int i=0;i<m;i++) cin>>p[i];

  vector<int> w(m);
  for(int i=0;i<m;i++) cin>>w[i];

  Trie<26>::F f=[](char c){return c-'a';};
  Trie<26> trie(f);

  for(int i=0;i<m;i++) trie.add(p[i],i);

  int n=s.size();
  vector<int> dp(n+1,0);
  int ans=0;
  for(int i=0;i<n;i++){
    chmax(ans,dp[i]);
    int pos=0;
    for(int j=0;j<222&&i+j<n;j++){
      pos=trie.move(pos,s[i+j]);
      if(pos<0) break;
      int k=trie.idx(pos);
      if(~k) chmax(dp[i+p[k].size()],ans+w[k]);
    }
  }
  chmax(ans,dp[n]);
  cout<<ans<<endl;
  return 0;
}

/*
  verified on 2019/10/28
  https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c
*/

signed main(){
  tenka1_2016_final_C();
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

