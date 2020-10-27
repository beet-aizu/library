---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/zalgorithm.cpp
    title: string/zalgorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"string/zalgorithm.cpp\"\
    \n\n#line 3 \"string/zalgorithm.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT\
    \ HERE\n// longest common prefix of s and s[i:n]\ntemplate<typename T>\nvector<int>\
    \ zalgorithm(vector<T> vs){\n  int n=vs.size();\n  vector<int> as(n+1,0);\n  as[0]=n;\n\
    \  int i=1,j=0;\n  while(i<n){\n    while(i+j<n and vs[j]==vs[i+j]) j++;\n   \
    \ as[i]=j;\n    if(j==0){\n      i++;\n      continue;\n    }\n    int k=1;\n\
    \    while(i+k<n and k+as[k]<j) as[i+k]=as[k],k++;\n    i+=k;\n    j-=k;\n  }\n\
    \  return as;\n}\nvector<int> zalgorithm(string s){\n  return zalgorithm(vector<char>(s.begin(),s.end()));\n\
    }\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n\
    #line 8 \"test/yosupo/zalgorithm.test.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string s;\n  cin>>s;\n\n  auto\
    \ zs=zalgorithm(s);\n  for(int i=0;i<(int)s.size();i++){\n    if(i) cout<<\" \"\
    ;\n    cout<<zs[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../string/zalgorithm.cpp\"\n#undef call_from_test\n\nsigned main(){\n \
    \ cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  string s;\n  cin>>s;\n\n  auto\
    \ zs=zalgorithm(s);\n  for(int i=0;i<(int)s.size();i++){\n    if(i) cout<<\" \"\
    ;\n    cout<<zs[i];\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - string/zalgorithm.cpp
  isVerificationFile: true
  path: test/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 13:26:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
