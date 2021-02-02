---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3213.test.cpp
    title: test/aoj/3213.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/defaultdict.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#endif\n//BEGIN CUT HERE\ntemplate<typename Key,typename T>\n\
    struct DefaultDict : map<Key, T>{\n  using super = map<Key, T>;\n  const T val;\n\
    \  DefaultDict(T val_):val(val_){}\n  T& operator[](const Key& key){\n    if(!super::count(key))\n\
    \      super::operator[](key)=val;\n    return super::operator[](key);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename Key,typename T>\nstruct DefaultDict\
    \ : map<Key, T>{\n  using super = map<Key, T>;\n  const T val;\n  DefaultDict(T\
    \ val_):val(val_){}\n  T& operator[](const Key& key){\n    if(!super::count(key))\n\
    \      super::operator[](key)=val;\n    return super::operator[](key);\n  }\n\
    };\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/defaultdict.cpp
  requiredBy: []
  timestamp: '2020-12-20 13:43:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3213.test.cpp
documentation_of: tools/defaultdict.cpp
layout: document
redirect_from:
- /library/tools/defaultdict.cpp
- /library/tools/defaultdict.cpp.html
title: tools/defaultdict.cpp
---
