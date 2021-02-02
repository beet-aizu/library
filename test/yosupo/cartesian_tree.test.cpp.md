---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/cartesiantree.cpp
    title: datastructure/cartesiantree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/yosupo/cartesian_tree.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/cartesian_tree\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 1 \"datastructure/cartesiantree.cpp\"\
    \n\n#line 3 \"datastructure/cartesiantree.cpp\"\nusing namespace std;\n#endif\n\
    \n//BEGIN CUT HERE\ntemplate<typename T>\nvector<int> cartesian_tree(const vector<T>\
    \ &vs){\n  int n=vs.size();\n  vector<int> ps(n,-1),ls(n,-1),rs(n,-1);\n  int\
    \ cur=0;\n  for(int i=1;i<n;i++){\n    if(vs[cur]<=vs[i]){\n      rs[cur]=i;\n\
    \      ps[i]=cur;\n      cur=i;\n      continue;\n    }\n    while(~ps[cur] and\
    \ vs[i]<vs[ps[cur]]) cur=ps[cur];\n    ps[i]=ps[cur];\n    if(~ps[i]) rs[ps[i]]=i;\n\
    \    ls[i]=cur;\n    ps[cur]=i;\n    cur=i;\n  }\n  return ps;\n}\n//END CUT HERE\n\
    \n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 8 \"test/yosupo/cartesian_tree.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  const char newl = '\\n';\n\n  int n;\n  cin>>n;\n\n  vector<int> as(n);\n \
    \ for(int i=0;i<n;i++) cin>>as[i];\n\n  auto ps=cartesian_tree(as);\n  for(int\
    \ i=0;i<n;i++){\n    if(i) cout<<' ';\n    cout<<(ps[i]<0?i:ps[i]);\n  }\n  cout<<newl;\n\
    \  return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../datastructure/cartesiantree.cpp\"\n#undef call_from_test\n\nsigned main(){\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  const char newl = '\\n';\n\n  int\
    \ n;\n  cin>>n;\n\n  vector<int> as(n);\n  for(int i=0;i<n;i++) cin>>as[i];\n\n\
    \  auto ps=cartesian_tree(as);\n  for(int i=0;i<n;i++){\n    if(i) cout<<' ';\n\
    \    cout<<(ps[i]<0?i:ps[i]);\n  }\n  cout<<newl;\n  return 0;\n}\n"
  dependsOn:
  - datastructure/cartesiantree.cpp
  isVerificationFile: true
  path: test/yosupo/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:52:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cartesian_tree.test.cpp
- /verify/test/yosupo/cartesian_tree.test.cpp.html
title: test/yosupo/cartesian_tree.test.cpp
---
