---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/longestcommonprefix.cpp
    title: Longest Common Prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.test.cpp
    title: test lcp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3033.test.cpp
    title: test/aoj/3033.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3063.test.cpp
    title: test/aoj/3063.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test query
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/suffixarray.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct SuffixArray{\n  const string\
    \ s;\n  vector<int> sa,rev;\n\n  SuffixArray(const string &s_):s(s_+'$'){\n  \
    \  int n=s.size();\n    sa.resize(n);\n    iota(sa.begin(),sa.end(),0);\n    sort(sa.begin(),sa.end(),\n\
    \         [&](int a,int b){\n           if(s[a]==s[b]) return a>b;\n         \
    \  return s[a]<s[b];\n         });\n\n    vector<int> cs(n,0),rs(n);\n    for(int\
    \ i=0;i<n;i++) rs[i]=s[i];\n    for(int len=1;len<n;len*=2){\n      for(int i=0;i<n;i++){\n\
    \        cs[sa[i]]=i;\n        if(i==0) continue;\n        if(rs[sa[i-1]]!=rs[sa[i]])\
    \ continue;\n        if(sa[i-1]+len>=n) continue;\n        if(rs[sa[i-1]+len/2]!=rs[sa[i]+len/2])\
    \ continue;\n        cs[sa[i]]=cs[sa[i-1]];\n      }\n      vector<int> cnt(n);\n\
    \      iota(cnt.begin(),cnt.end(),0);\n      copy(sa.begin(),sa.end(),rs.begin());\n\
    \      for(int i=0;i<n;i++){\n        int s1=rs[i]-len;\n        if(s1>=0) sa[cnt[cs[s1]]++]=s1;\n\
    \      }\n      cs.swap(rs);\n    }\n    rev.resize(n);\n    for(int i=0;i<n;i++)\
    \ rev[sa[i]]=i;\n  }\n  int operator[](int i) const{return sa[i];}\n\n  bool lt_substr(string\
    \ &t,int si,int ti){\n    int sn=s.size(),tn=t.size();\n    while(si<sn and ti<tn){\n\
    \      if(s[si]<t[ti]) return 1;\n      if(s[si]>t[ti]) return 0;\n      si++;ti++;\n\
    \    }\n    return si==sn and ti<tn;\n  }\n\n  int lower_bound(string& t){\n \
    \   int l=0,r=s.size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(lt_substr(t,sa[m],0))\
    \ l=m;\n      else r=m;\n    }\n    return r;\n  }\n\n  int upper_bound(string&\
    \ t){\n    t.back()++;\n    int res=lower_bound(t);\n    t.back()--;\n    return\
    \ res;\n  }\n\n  // O(|T|*log|S|)\n  int count(string& T){\n    return upper_bound(T)-lower_bound(T);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n};\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct SuffixArray{\n  const string s;\n  vector<int>\
    \ sa,rev;\n\n  SuffixArray(const string &s_):s(s_+'$'){\n    int n=s.size();\n\
    \    sa.resize(n);\n    iota(sa.begin(),sa.end(),0);\n    sort(sa.begin(),sa.end(),\n\
    \         [&](int a,int b){\n           if(s[a]==s[b]) return a>b;\n         \
    \  return s[a]<s[b];\n         });\n\n    vector<int> cs(n,0),rs(n);\n    for(int\
    \ i=0;i<n;i++) rs[i]=s[i];\n    for(int len=1;len<n;len*=2){\n      for(int i=0;i<n;i++){\n\
    \        cs[sa[i]]=i;\n        if(i==0) continue;\n        if(rs[sa[i-1]]!=rs[sa[i]])\
    \ continue;\n        if(sa[i-1]+len>=n) continue;\n        if(rs[sa[i-1]+len/2]!=rs[sa[i]+len/2])\
    \ continue;\n        cs[sa[i]]=cs[sa[i-1]];\n      }\n      vector<int> cnt(n);\n\
    \      iota(cnt.begin(),cnt.end(),0);\n      copy(sa.begin(),sa.end(),rs.begin());\n\
    \      for(int i=0;i<n;i++){\n        int s1=rs[i]-len;\n        if(s1>=0) sa[cnt[cs[s1]]++]=s1;\n\
    \      }\n      cs.swap(rs);\n    }\n    rev.resize(n);\n    for(int i=0;i<n;i++)\
    \ rev[sa[i]]=i;\n  }\n  int operator[](int i) const{return sa[i];}\n\n  bool lt_substr(string\
    \ &t,int si,int ti){\n    int sn=s.size(),tn=t.size();\n    while(si<sn and ti<tn){\n\
    \      if(s[si]<t[ti]) return 1;\n      if(s[si]>t[ti]) return 0;\n      si++;ti++;\n\
    \    }\n    return si==sn and ti<tn;\n  }\n\n  int lower_bound(string& t){\n \
    \   int l=0,r=s.size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(lt_substr(t,sa[m],0))\
    \ l=m;\n      else r=m;\n    }\n    return r;\n  }\n\n  int upper_bound(string&\
    \ t){\n    t.back()++;\n    int res=lower_bound(t);\n    t.back()--;\n    return\
    \ res;\n  }\n\n  // O(|T|*log|S|)\n  int count(string& T){\n    return upper_bound(T)-lower_bound(T);\n\
    \  }\n};\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n};\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffixarray.cpp
  requiredBy:
  - string/longestcommonprefix.cpp
  timestamp: '2020-10-27 19:04:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3112.test.cpp
  - test/aoj/2644.test.cpp
  - test/aoj/2711.test.cpp
  - test/aoj/3033.test.cpp
  - test/aoj/3063.test.cpp
  - test/yosupo/number_of_substrings.test.cpp
  - test/yosupo/suffixarray.test.cpp
documentation_of: string/suffixarray.cpp
layout: document
title: Suffix Array
---

## できること
- `sa[i]` : $S$ の末尾辞の中で $i$ 番目に小さいものの位置
- `rev[i]` : $S[i:\|S\|]$ が辞書順で何番目か


## 計算量
$O(\|S\| \log \|S\|)$

## 注意
- 番兵として末尾に `$` を挿入している
- $S$ に記号が含まれている場合は注意が必要
- `sa[0]` は常に $\|S\|$ になる

## 解説記事
[ Suffix Array in O(N * logN) and LCP in O(N) ](https://sites.google.com/site/indy256/algo/suffix_array)