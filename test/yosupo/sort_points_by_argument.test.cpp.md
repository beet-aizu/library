---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/argsort.cpp
    title: geometry/argsort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/yosupo/sort_points_by_argument.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sort_points_by_argument\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"geometry/argsort.cpp\"\
    \n\n#line 3 \"geometry/argsort.cpp\"\nusing namespace std;\n#endif\n//BEGIN CUT\
    \ HERE\n// (-pi, pi], atan2(0, 0) = 0\ntemplate<typename P>\nvoid argsort(vector<P>\
    \ &ps){\n  auto getA=\n    [&](P p){\n      if(p.x>=0 and p.y>=0) return 0;\n\
    \      if(p.y>=0) return 1;\n      if(p.x<=0) return -2;\n      return -1;\n \
    \   };\n  auto cross=[&](P a,P b){return a.x*b.y-a.y*b.x;};\n  auto cmp=\n   \
    \ [&](P a,P b){\n      if(getA(a)!=getA(b)) return getA(a)<getA(b);\n      if(a.x==0\
    \ and a.y==0) return !(b.x==0 and b.y==0);\n      if(b.x==0 and b.y==0) return\
    \ false;\n      return cross(a,b)>0;\n    };\n  sort(ps.begin(),ps.end(),cmp);\n\
    }\n//END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/yosupo/sort_points_by_argument.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  using ll = long long;\n  struct Point{ll x,y;};\n \
    \ vector<Point> ps(n);\n  for(int i=0;i<n;i++) cin>>ps[i].x>>ps[i].y;\n\n  argsort(ps);\n\
    \n  for(int i=0;i<n;i++) cout<<ps[i].x<<\" \"<<ps[i].y<<\"\\n\";\n  cout<<flush;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/sort_points_by_argument\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../geometry/argsort.cpp\"\n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n\n  int n;\n  cin>>n;\n\n  using ll = long long;\n\
    \  struct Point{ll x,y;};\n  vector<Point> ps(n);\n  for(int i=0;i<n;i++) cin>>ps[i].x>>ps[i].y;\n\
    \n  argsort(ps);\n\n  for(int i=0;i<n;i++) cout<<ps[i].x<<\" \"<<ps[i].y<<\"\\\
    n\";\n  cout<<flush;\n  return 0;\n}\n"
  dependsOn:
  - geometry/argsort.cpp
  isVerificationFile: true
  path: test/yosupo/sort_points_by_argument.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sort_points_by_argument.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sort_points_by_argument.test.cpp
- /verify/test/yosupo/sort_points_by_argument.test.cpp.html
title: test/yosupo/sort_points_by_argument.test.cpp
---
