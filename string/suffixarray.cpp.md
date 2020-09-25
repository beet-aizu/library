---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/longestcommonprefix.cpp
    title: string/longestcommonprefix.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3033.test.cpp
    title: test/aoj/3033.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2644.test.cpp
    title: test/aoj/2644.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3063.test.cpp
    title: test/aoj/3063.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2711.test.cpp
    title: test/aoj/2711.test.cpp
  - icon: ':x:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3112.test.cpp
    title: test/aoj/3112.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/suffixarray.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\nstruct SuffixArray{\n  string s;\n\
    \  vector<int> sa,rev;\n\n  SuffixArray(){}\n  SuffixArray(const string &S):s(S){\n\
    \    int n=s.size();\n    s.push_back('$');\n    sa.resize(n+1);\n    iota(sa.begin(),sa.end(),0);\n\
    \    sort(sa.begin(),sa.end(),\n         [&](int a,int b){\n           if(s[a]==s[b])\
    \ return a>b;\n           return s[a]<s[b];\n         });\n    vector<int> cs(n+1,0),rs(n+1),cnt(n+1);\n\
    \    for(int i=0;i<=n;i++) rs[i]=s[i];\n    for(int len=1;len<=n;len*=2){\n  \
    \    for(int i=0;i<=n;i++){\n        cs[sa[i]]=i;\n        if(i>0 &&\n       \
    \    rs[sa[i-1]]==rs[sa[i]] &&\n           sa[i-1]+len<=n &&\n           rs[sa[i-1]+len/2]==rs[sa[i]+len/2])\
    \ cs[sa[i]]=cs[sa[i-1]];\n      }\n      iota(cnt.begin(),cnt.end(),0);\n    \
    \  copy(sa.begin(),sa.end(),rs.begin());\n      for(int i=0;i<=n;i++){\n     \
    \   int s1=rs[i]-len;\n        if(s1>=0) sa[cnt[cs[s1]]++]=s1;\n      }\n    \
    \  cs.swap(rs);\n    }\n    rev.resize(n+1);\n    for(int i=0;i<=n;i++) rev[sa[i]]=i;\n\
    \  }\n  int operator[](int i) const{return sa[i];}\n\n  bool lt_substr(string\
    \ &t,int si,int ti){\n    int sn=s.size(),tn=t.size();\n    while(si<sn&&ti<tn){\n\
    \      if(s[si]<t[ti]) return 1;\n      if(s[si]>t[ti]) return 0;\n      si++;ti++;\n\
    \    }\n    return si==sn&&ti<tn;\n  }\n\n  int lower_bound(string& t){\n    int\
    \ l=0,r=s.size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(lt_substr(t,sa[m],0))\
    \ l=m;\n      else r=m;\n    }\n    return r;\n  }\n\n  int upper_bound(string&\
    \ t){\n    t.back()++;\n    int res=lower_bound(t);\n    t.back()--;\n    return\
    \ res;\n  }\n\n  // O(|T|*log|S|)\n  int count(string& T){\n    return upper_bound(T)-lower_bound(T);\n\
    \  }\n};\n//END CUT HERE\n\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n};\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nstruct SuffixArray{\n  string s;\n  vector<int> sa,rev;\n\n\
    \  SuffixArray(){}\n  SuffixArray(const string &S):s(S){\n    int n=s.size();\n\
    \    s.push_back('$');\n    sa.resize(n+1);\n    iota(sa.begin(),sa.end(),0);\n\
    \    sort(sa.begin(),sa.end(),\n         [&](int a,int b){\n           if(s[a]==s[b])\
    \ return a>b;\n           return s[a]<s[b];\n         });\n    vector<int> cs(n+1,0),rs(n+1),cnt(n+1);\n\
    \    for(int i=0;i<=n;i++) rs[i]=s[i];\n    for(int len=1;len<=n;len*=2){\n  \
    \    for(int i=0;i<=n;i++){\n        cs[sa[i]]=i;\n        if(i>0 &&\n       \
    \    rs[sa[i-1]]==rs[sa[i]] &&\n           sa[i-1]+len<=n &&\n           rs[sa[i-1]+len/2]==rs[sa[i]+len/2])\
    \ cs[sa[i]]=cs[sa[i-1]];\n      }\n      iota(cnt.begin(),cnt.end(),0);\n    \
    \  copy(sa.begin(),sa.end(),rs.begin());\n      for(int i=0;i<=n;i++){\n     \
    \   int s1=rs[i]-len;\n        if(s1>=0) sa[cnt[cs[s1]]++]=s1;\n      }\n    \
    \  cs.swap(rs);\n    }\n    rev.resize(n+1);\n    for(int i=0;i<=n;i++) rev[sa[i]]=i;\n\
    \  }\n  int operator[](int i) const{return sa[i];}\n\n  bool lt_substr(string\
    \ &t,int si,int ti){\n    int sn=s.size(),tn=t.size();\n    while(si<sn&&ti<tn){\n\
    \      if(s[si]<t[ti]) return 1;\n      if(s[si]>t[ti]) return 0;\n      si++;ti++;\n\
    \    }\n    return si==sn&&ti<tn;\n  }\n\n  int lower_bound(string& t){\n    int\
    \ l=0,r=s.size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n      if(lt_substr(t,sa[m],0))\
    \ l=m;\n      else r=m;\n    }\n    return r;\n  }\n\n  int upper_bound(string&\
    \ t){\n    t.back()++;\n    int res=lower_bound(t);\n    t.back()--;\n    return\
    \ res;\n  }\n\n  // O(|T|*log|S|)\n  int count(string& T){\n    return upper_bound(T)-lower_bound(T);\n\
    \  }\n};\n//END CUT HERE\n\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned\
    \ main(){\n  return 0;\n};\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffixarray.cpp
  requiredBy:
  - string/longestcommonprefix.cpp
  timestamp: '2019-12-26 23:10:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/3033.test.cpp
  - test/aoj/2644.test.cpp
  - test/aoj/3063.test.cpp
  - test/aoj/2711.test.cpp
  - test/aoj/ALDS1_14_D.test.cpp
  - test/aoj/3112.test.cpp
  - test/yosupo/suffixarray.test.cpp
  - test/yosupo/number_of_substrings.test.cpp
documentation_of: string/suffixarray.cpp
layout: document
redirect_from:
- /library/string/suffixarray.cpp
- /library/string/suffixarray.cpp.html
title: string/suffixarray.cpp
---
