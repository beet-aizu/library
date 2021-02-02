---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cumulativesum.cpp
    title: datastructure/cumulativesum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/static_range_sum\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"datastructure/cumulativesum.cpp\"\
    \n\n#line 3 \"datastructure/cumulativesum.cpp\"\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\ntemplate<typename T>\nstruct CumulativeSum{\n  vector<T> sm;\n\
    \  CumulativeSum(const vector<T> &as){\n    int n=as.size();\n    sm.resize(n+1);\n\
    \    sm[0]=T();\n    for(int i=0;i<n;i++)\n      sm[i+1]=sm[i]+as[i];\n  }\n \
    \ // [l, r)\n  T query(int l,int r){return -sm[l]+sm[r];}\n};\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n\
    #endif\n#line 8 \"test/yosupo/static_range_sum.test.cpp\"\n#undef call_from_test\n\
    \nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl\
    \ = '\\n';\n\n  using ll = long long;\n\n  int n,q;\n  cin>>n>>q;\n  vector<ll>\
    \ as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n  CumulativeSum cs(as);\n  for(int\
    \ i=0;i<q;i++){\n    int l,r;\n    cin>>l>>r;\n    cout<<cs.query(l,r)<<newl;\n\
    \  }\n  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_sum\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/cumulativesum.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  using\
    \ ll = long long;\n\n  int n,q;\n  cin>>n>>q;\n  vector<ll> as(n);\n  for(int\
    \ i=0;i<n;i++) cin>>as[i];\n\n  CumulativeSum cs(as);\n  for(int i=0;i<q;i++){\n\
    \    int l,r;\n    cin>>l>>r;\n    cout<<cs.query(l,r)<<newl;\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - datastructure/cumulativesum.cpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 16:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---
