---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"icpc/hash_gen.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @ignore\n */\n//BEGIN CUT HERE\nsigned main(){\n  const int MOD\
    \ = 1e9+7,B=1e8+7;\n  long long res=0;\n  string s;\n  while(getline(cin,s)){\n\
    \    if(s.find(\"//\")!=string::npos)\n      s=s.substr(0,s.find(\"//\"));\n \
    \   for(char c:s){\n      if(c==' ') continue;\n      res=(res*B+c)%MOD;\n   \
    \ }\n  }\n  cout<<res<<endl;\n  return 0;\n}\n//END CUT HERE\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\n/**\n * @ignore\n */\n//BEGIN\
    \ CUT HERE\nsigned main(){\n  const int MOD = 1e9+7,B=1e8+7;\n  long long res=0;\n\
    \  string s;\n  while(getline(cin,s)){\n    if(s.find(\"//\")!=string::npos)\n\
    \      s=s.substr(0,s.find(\"//\"));\n    for(char c:s){\n      if(c==' ') continue;\n\
    \      res=(res*B+c)%MOD;\n    }\n  }\n  cout<<res<<endl;\n  return 0;\n}\n//END\
    \ CUT HERE\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: icpc/hash_gen.cpp
  requiredBy: []
  timestamp: '2020-03-10 22:18:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: icpc/hash_gen.cpp
layout: document
redirect_from:
- /library/icpc/hash_gen.cpp
- /library/icpc/hash_gen.cpp.html
title: icpc/hash_gen.cpp
---
