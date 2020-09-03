---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 58, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/twosatisfiability.cpp: line 6: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n\n\
    #define call_from_test\n#include \"stronglyconnectedcomponent.cpp\"\n#undef call_from_test\n\
    \n#endif\n//BEGIN CUT HERE\nstruct TwoSat{\n  int n;\n  SCC scc;\n  TwoSat(int\
    \ n):n(n),scc(n*2){}\n  int negate(int v){return (n+v)%(n*2);}\n  void add_if(int\
    \ u,int v){\n    // u -> v <=> !v -> !u\n    scc.add_edge(u,v);\n    scc.add_edge(negate(v),negate(u));\n\
    \  }\n  void add_or(int u,int v){\n    // u or v <=> !u -> v\n    add_if(negate(u),v);\n\
    \  }\n  void add_nand(int u,int v){\n    // u nand v <=> u -> !v\n    add_if(u,negate(v));\n\
    \  }\n  void set_true(int v){\n    //  v <=> !v ->  v\n    scc.add_edge(negate(v),v);\n\
    \  }\n  void set_false(int v){\n    // !v <=>  v -> !v\n    scc.add_edge(v,negate(v));\n\
    \  }\n  vector<int> build(){\n    scc.build();\n    vector<int> res(n);\n    for(int\
    \ i=0;i<n;i++){\n      if(scc[i]==scc[n+i]) return {};\n      res[i]=scc[i]>scc[n+i];\n\
    \    }\n    return res;\n  }\n};\n//END CUT HERE\n#ifndef call_from_test\n\n//\
    \ test add_if, set_true, set_false\nsigned CFR441_C(){\n  int n,m;\n  scanf(\"\
    %d %d\",&n,&m);\n\n  vector<vector<int>> G(n);\n  for(int i=0;i<n;i++){\n    int\
    \ k;\n    scanf(\"%d\",&k);\n    G[i].assign(k,0);\n    for(int &v:G[i]){\n  \
    \    scanf(\"%d\",&v);\n      v--;\n    }\n  }\n  auto NG=[](){puts(\"No\");exit(0);};\n\
    \n  TwoSat ts(m);\n  auto add_edge=\n    [&](vector<int> &as,vector<int> &bs){\n\
    \      int x=min(as.size(),bs.size());\n      int i;\n      for(i=0;i<x;i++){\n\
    \        if(as[i]==bs[i]) continue;\n        if(as[i]<bs[i]){\n          ts.add_if(bs[i],as[i]);\n\
    \        }else{\n          ts.set_true(as[i]);\n          ts.set_false(bs[i]);\n\
    \        }\n        break;\n      }\n      if((i==x)&&(as.size()>bs.size())) NG();\n\
    \    };\n\n  for(int i=0;i+1<n;i++)\n    add_edge(G[i],G[i+1]);\n\n  auto vs=ts.build();\n\
    \  if(vs.empty()) NG();\n\n  vector<int> ans;\n  for(int i=0;i<m;i++)\n    if(vs[i])\
    \ ans.emplace_back(i);\n\n  puts(\"Yes\");\n  printf(\"%d\\n\",(int)ans.size());\n\
    \  for(int i=0;i<(int)ans.size();i++){\n    if(i) printf(\" \");\n    printf(\"\
    %d\",ans[i]+1);\n  }\n  puts(\"\");\n\n  return 0;\n}\n/*\n  verified 2019/06/20\n\
    \  http://codeforces.com/contest/875/problem/C\n*/\n\n// test add_nand\nsigned\
    \ YUKI_470(){\n  int n;\n  cin>>n;\n  vector<string> u(n);\n  for(int i=0;i<n;i++)\
    \ cin>>u[i];\n\n  auto NO=[](){cout<<\"Impossible\"<<endl;exit(0);};\n\n  if(n>=100)\
    \ NO();\n\n  TwoSat ts(n);\n  for(int i=0;i<n;i++){\n    for(int j=0;j<i;j++){\n\
    \      auto &as=u[i];\n      auto &bs=u[j];\n      if(as[0]==bs[0]&&as[1]==bs[1])\n\
    \        ts.add_nand(i,j);\n\n      if(as[0]==bs[1]&&as[1]==bs[2])\n        ts.add_nand(i,ts.negate(j));\n\
    \n      if(as[1]==bs[0]&&as[2]==bs[1])\n        ts.add_nand(ts.negate(i),j);\n\
    \n      if(as[1]==bs[1]&&as[2]==bs[2])\n        ts.add_nand(ts.negate(i),ts.negate(j));\n\
    \n      if(as[0]==bs[0]) ts.add_nand(ts.negate(i),ts.negate(j));\n      if(as[0]==bs[2])\
    \ ts.add_nand(ts.negate(i),j);\n      if(as[2]==bs[0]) ts.add_nand(i,ts.negate(j));\n\
    \      if(as[2]==bs[2]) ts.add_nand(i,j);\n    }\n  }\n\n  auto res=ts.build();\n\
    \  if(res.empty()) NO();\n\n  for(int i=0;i<n;i++){\n    if(res[i])\n      cout<<u[i][0]<<u[i][1]<<\"\
    \ \"<<u[i][2]<<endl;\n    else\n      cout<<u[i][0]<<\" \"<<u[i][1]<<u[i][2]<<endl;\n\
    \  }\n  return 0;\n}\n/*\n  verified 2019/10/24\n  https://yukicoder.me/problems/no/470\n\
    */\n\nsigned main(){\n  //CFR441_C();\n  //YUKI_470();\n  return 0;\n}\n#endif\n"
  dependsOn:
  - graph/stronglyconnectedcomponent.cpp
  extendedDependsOn:
  - icon: ':warning:'
    path: graph/stronglyconnectedcomponent.cpp
    title: graph/stronglyconnectedcomponent.cpp
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3102.test.cpp
    title: test/aoj/3102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/twosatisfiability.cpp
  requiredBy:
  - test/aoj/3102.test.cpp
  - test/yosupo/two_sat.test.cpp
  timestamp: '2019-12-27 08:35:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/twosatisfiability.cpp
layout: document
redirect_from:
- /library/graph/twosatisfiability.cpp
- /library/graph/twosatisfiability.cpp.html
title: graph/twosatisfiability.cpp
---
