---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rollinghash.cpp
    title: string/rollinghash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.test.cpp\"\n// verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#line\
    \ 1 \"string/rollinghash.cpp\"\n\n#line 3 \"string/rollinghash.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename T,T MOD,T B>\nstruct RollingHash{\n\
    \  using ll = long long;\n  vector<T> hash,po;\n  RollingHash(){}\n  RollingHash(vector<T>\
    \ vs){init(vs);}\n  RollingHash(string &s){\n    vector<T> vs;\n    for(char c:s)\
    \ vs.emplace_back(c);\n    init(vs);\n  }\n  void init(vector<T> vs){\n    int\
    \ n=vs.size();\n    hash.assign(n+1,0);\n    po.assign(n+1,1);\n    for(int i=0;i<n;i++){\n\
    \      hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;\n      po[i+1]=(ll)po[i]*B%MOD;\n\
    \    }\n  }\n  //S[l, r)\n  T find(int l,int r){\n    T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;\n\
    \    return res>=MOD?res-MOD:res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    //INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/aoj/ALDS1_14_B.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  string t,p;\n  cin>>t>>p;\n  using ll = long long;\n  const ll MOD = 1e9+7;\n\
    \  const ll B = 1777771;\n  using RH = RollingHash<ll, MOD, B>;\n\n  RH rt(t),rp(p);\n\
    \  for(int i=0;i<(int)t.size()-(int)p.size()+1;i++)\n    if(rt.find(i,i+p.size())==rp.find(0,p.size()))\
    \ cout<<i<<\"\\n\";\n\n  cout<<flush;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/rollinghash.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string t,p;\n  cin>>t>>p;\n  using\
    \ ll = long long;\n  const ll MOD = 1e9+7;\n  const ll B = 1777771;\n  using RH\
    \ = RollingHash<ll, MOD, B>;\n\n  RH rt(t),rp(p);\n  for(int i=0;i<(int)t.size()-(int)p.size()+1;i++)\n\
    \    if(rt.find(i,i+p.size())==rp.find(0,p.size())) cout<<i<<\"\\n\";\n\n  cout<<flush;\n\
    \  return 0;\n}\n"
  dependsOn:
  - string/rollinghash.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 14:33:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1_14_B.test.cpp
---
