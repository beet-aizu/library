---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/sum_of_floor.cpp
    title: math/sum_of_floor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"math/sum_of_floor.cpp\"\
    \n\n#line 3 \"math/sum_of_floor.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT\
    \ HERE\n// sum_{i=0}^{n-1} (ai + b) // m\n// 0 <= a, b\ntemplate<typename T>\n\
    T sum_of_floor(T n,T m,T a,T b){\n  T res=0;\n  if(a>=m){\n    res+=(n-1)*n*(a/m)/2;\n\
    \    a%=m;\n  }\n  if(b>=m){\n    res+=n*(b/m);\n    b%=m;\n  }\n  T y=(a*n+b)/m;\n\
    \  T x=y*m-b;\n  if(y==0) return res;\n  res+=(n-(x+a-1)/a)*y;\n  res+=sum_of_floor(y,a,m,(a-x%a)%a);\n\
    \  return res;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\n\
    signed main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int T;\n  cin>>T;\n  for(int t=0;t<T;t++){\n    long long n,m,a,b;\n    cin>>n>>m>>a>>b;\n\
    \    cout<<sum_of_floor(n,m,a,b)<<\"\\n\";\n  }\n  cout<<flush;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../math/sum_of_floor.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n  int T;\n  cin>>T;\n  for(int t=0;t<T;t++){\n\
    \    long long n,m,a,b;\n    cin>>n>>m>>a>>b;\n    cout<<sum_of_floor(n,m,a,b)<<\"\
    \\n\";\n  }\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - math/sum_of_floor.cpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2020-03-05 21:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
