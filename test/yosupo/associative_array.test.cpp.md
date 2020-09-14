---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cc_hash.cpp
    title: tools/cc_hash.cpp
  - icon: ':heavy_check_mark:'
    path: datastructure/pb_ds_cc_hash_table.cpp
    title: datastructure/pb_ds_cc_hash_table.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"tools/cc_hash.cpp\"\n\
    \n#ifndef call_from_test\n#line 5 \"tools/cc_hash.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\ntemplate<typename T>\nstruct cc_hash{\n  uint64_t operator()(T\
    \ x) const{\n    uint64_t y(x);\n    y += 0x9e3779b97f4a7c15;\n    y = (y ^ (y\
    \ >> 30)) * 0xbf58476d1ce4e5b9;\n    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;\n\
    \    return y ^ (y >> 31);\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 1 \"datastructure/pb_ds_cc_hash_table.cpp\"\
    \n\n#line 3 \"datastructure/pb_ds_cc_hash_table.cpp\"\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\n#include <ext/pb_ds/assoc_container.hpp>\nusing namespace\
    \ __gnu_pbds;\ntemplate<typename T,typename U, typename H=hash<T> >\nusing gmap\
    \ = cc_hash_table<T, U, H>;\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/associative_array.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using ll = long long;\n  gmap<ll, ll, cc_hash<ll>>\
    \ mp;\n\n  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      ll k,v;\n      cin>>k>>v;\n      mp[k]=v;\n    }\n    if(t==1){\n\
    \      ll k;\n      cin>>k;\n      cout<<mp[k]<<newl;\n    }\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../tools/cc_hash.cpp\"\n#include \"../../datastructure/pb_ds_cc_hash_table.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  using ll = long long;\n  gmap<ll, ll, cc_hash<ll>>\
    \ mp;\n\n  int q;\n  cin>>q;\n  for(int i=0;i<q;i++){\n    int t;\n    cin>>t;\n\
    \    if(t==0){\n      ll k,v;\n      cin>>k>>v;\n      mp[k]=v;\n    }\n    if(t==1){\n\
    \      ll k;\n      cin>>k;\n      cout<<mp[k]<<newl;\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/cc_hash.cpp
  - datastructure/pb_ds_cc_hash_table.cpp
  isVerificationFile: true
  path: test/yosupo/associative_array.test.cpp
  requiredBy: []
  timestamp: '2020-05-24 17:44:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/associative_array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/associative_array.test.cpp
- /verify/test/yosupo/associative_array.test.cpp.html
title: test/yosupo/associative_array.test.cpp
---
