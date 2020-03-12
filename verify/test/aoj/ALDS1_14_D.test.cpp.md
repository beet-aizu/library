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


# :heavy_check_mark: test/aoj/ALDS1_14_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-26 23:10:12+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D</a>


## Depends on

* :question: <a href="../../../library/string/suffixarray.cpp.html">string/suffixarray.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/suffixarray.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string t;
  cin>>t;
  int q;
  cin>>q;
  SuffixArray sa(t);
  while(q--){
    string p;
    cin>>p;
    cout<<!!sa.count(p)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "test/aoj/../../string/suffixarray.cpp"

#line 3 "test/aoj/../../string/suffixarray.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct SuffixArray{
  string s;
  vector<int> sa,rev;

  SuffixArray(){}
  SuffixArray(const string &S):s(S){
    int n=s.size();
    s.push_back('$');
    sa.resize(n+1);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
         [&](int a,int b){
           if(s[a]==s[b]) return a>b;
           return s[a]<s[b];
         });
    vector<int> cs(n+1,0),rs(n+1),cnt(n+1);
    for(int i=0;i<=n;i++) rs[i]=s[i];
    for(int len=1;len<=n;len*=2){
      for(int i=0;i<=n;i++){
        cs[sa[i]]=i;
        if(i>0 &&
           rs[sa[i-1]]==rs[sa[i]] &&
           sa[i-1]+len<=n &&
           rs[sa[i-1]+len/2]==rs[sa[i]+len/2]) cs[sa[i]]=cs[sa[i-1]];
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),rs.begin());
      for(int i=0;i<=n;i++){
        int s1=rs[i]-len;
        if(s1>=0) sa[cnt[cs[s1]]++]=s1;
      }
      cs.swap(rs);
    }
    rev.resize(n+1);
    for(int i=0;i<=n;i++) rev[sa[i]]=i;
  }
  int operator[](int i) const{return sa[i];}

  bool lt_substr(string &t,int si,int ti){
    int sn=s.size(),tn=t.size();
    while(si<sn&&ti<tn){
      if(s[si]<t[ti]) return 1;
      if(s[si]>t[ti]) return 0;
      si++;ti++;
    }
    return si==sn&&ti<tn;
  }

  int lower_bound(string& t){
    int l=0,r=s.size();
    while(l+1<r){
      int m=(l+r)>>1;
      if(lt_substr(t,sa[m],0)) l=m;
      else r=m;
    }
    return r;
  }

  int upper_bound(string& t){
    t.back()++;
    int res=lower_bound(t);
    t.back()--;
    return res;
  }

  // O(|T|*log|S|)
  int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
};
//END CUT HERE

#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
};
#endif
#line 8 "test/aoj/ALDS1_14_D.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string t;
  cin>>t;
  int q;
  cin>>q;
  SuffixArray sa(t);
  while(q--){
    string p;
    cin>>p;
    cout<<!!sa.count(p)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

