---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"string/suffixarray.cpp\"\n\n#line 3 \"string/suffixarray.cpp\"\nusing\
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
    \ main(){\n  return 0;\n};\n#endif\n#line 8 \"test/aoj/ALDS1_14_D.test.cpp\"\n\
    #undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  string t;\n  cin>>t;\n  int q;\n  cin>>q;\n  SuffixArray sa(t);\n  while(q--){\n\
    \    string p;\n    cin>>p;\n    cout<<!!sa.count(p)<<\"\\n\";\n  }\n  cout<<flush;\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../string/suffixarray.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  string t;\n  cin>>t;\n  int q;\n\
    \  cin>>q;\n  SuffixArray sa(t);\n  while(q--){\n    string p;\n    cin>>p;\n\
    \    cout<<!!sa.count(p)<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - string/suffixarray.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: string/suffixarray.cpp
    title: string/suffixarray.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/aoj/ALDS1_14_D.test.cpp
  requiredBy: []
  timestamp: '2019-12-26 23:10:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_D.test.cpp
- /verify/test/aoj/ALDS1_14_D.test.cpp.html
title: test/aoj/ALDS1_14_D.test.cpp
---
