---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffixarray.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/yosupo/suffixarray.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/suffixarray\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"string/suffixarray.cpp\"\
    \n\n#line 3 \"string/suffixarray.cpp\"\nusing namespace std;\n#endif\n//BEGIN\
    \ CUT HERE\ntemplate<typename Seq = string>\nstruct SuffixArray{\n  const Seq\
    \ s;\n  vector<int> sa,rev;\n\n  SuffixArray(const Seq &s_,int guard='$'):\n \
    \   s([](Seq x,int y){return x.push_back(y),x;}(s_,guard)){\n    int n=s.size();\n\
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
    \ rev[sa[i]]=i;\n  }\n\n  int operator[](int i) const{return sa[i];}\n\n  bool\
    \ lt_substr(const Seq &t,int si,int ti){\n    int sn=s.size(),tn=t.size();\n \
    \   while(si<sn and ti<tn){\n      if(s[si]<t[ti]) return 1;\n      if(s[si]>t[ti])\
    \ return 0;\n      si++;ti++;\n    }\n    return si==sn and ti<tn;\n  }\n\n  int\
    \ lower_bound(Seq t){\n    int l=0,r=s.size();\n    while(l+1<r){\n      int m=(l+r)>>1;\n\
    \      if(lt_substr(t,sa[m],0)) l=m;\n      else r=m;\n    }\n    return r;\n\
    \  }\n\n  int upper_bound(Seq t){\n    t.back()++;\n    int res=lower_bound(t);\n\
    \    t.back()--;\n    return res;\n  }\n\n  // O(|t| \\log|s|)\n  int count(Seq\
    \ t){\n    return upper_bound(t)-lower_bound(t);\n  }\n};\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  vector<int> vs({1, 2,\
    \ 3, 1, 2, 1});\n  SuffixArray sa(vs, -1);\n  for(int i=0;i<=(int)vs.size();i++)\
    \ cout<<sa[i]<<endl;\n\n  cout<<sa.count({1})<<endl;\n  cout<<sa.count({1, 2})<<endl;\n\
    \  cout<<sa.count({1, 2, 3})<<endl;\n  cout<<sa.count({1, 2, 3, 4})<<endl;\n \
    \ return 0;\n}\n#endif\n#line 8 \"test/yosupo/suffixarray.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string s;\n \
    \ cin>>s;\n\n  SuffixArray sa(s);\n  for(int i=0;i<(int)s.size();i++){\n    if(i)\
    \ cout<<\" \";\n    cout<<sa[i+1];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/suffixarray\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/suffixarray.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string s;\n  cin>>s;\n\n  SuffixArray\
    \ sa(s);\n  for(int i=0;i<(int)s.size();i++){\n    if(i) cout<<\" \";\n    cout<<sa[i+1];\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - string/suffixarray.cpp
  isVerificationFile: true
  path: test/yosupo/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2020-12-28 13:49:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/suffixarray.test.cpp
- /verify/test/yosupo/suffixarray.test.cpp.html
title: test/yosupo/suffixarray.test.cpp
---
