---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"graph/multipleeuleriantrail.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\n// no muliple edge\ntemplate<typename\
    \ Graph>\nbool hasMultipleEulerianTrail(Graph &G){\n  int n=G.size();\n  vector<int>\
    \ ind(n,0),outd(n,0),pre(n,-1),loop(n,0);\n  for(int v=0;v<n;v++){\n    for(int\
    \ u:G[v]){\n      ind[u]++,outd[v]++;\n      if(u==v) loop[v]=1;\n      if(u!=v)\
    \ pre[u]=v;\n    }\n  }\n\n  int st=-1,en=-1,sz=0;\n  for(int i=0;i<n;i++){\n\
    \    if(ind[i]>=3||outd[i]>=3) return true;\n    if(ind[i]<outd[i]) st=i;\n  \
    \  if(ind[i]>outd[i]) en=i;\n    if(ind[i]+outd[i]) sz++;\n  }\n  if(sz<2) return\
    \ false;\n  if(st<0) return true;\n\n  while(ind[en]==1+loop[en]&&st!=en) en=pre[en];\n\
    \  if(st==en) return false;\n\n  queue<int> que;\n  vector<int> rs(n,0);\n  que.emplace(st);\n\
    \  rs[st]=1;\n  while(!que.empty()){\n    int v=que.front();que.pop();\n    for(int\
    \ u:G[v]){\n      if(u==en||rs[u]) continue;\n      rs[u]=1;\n      que.emplace(u);\n\
    \    }\n  }\n\n  vector<int> us(n,0);\n  que.emplace(en);\n  us[en]=1;\n  while(!que.empty()){\n\
    \    int v=que.front();que.pop();\n    if(rs[v]) return true;\n    for(int u:G[v]){\n\
    \      if(u==en||us[u]) continue;\n      us[u]=1;\n      que.emplace(u);\n   \
    \ }\n  }\n  return false;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\n// no muliple edge\ntemplate<typename Graph>\nbool hasMultipleEulerianTrail(Graph\
    \ &G){\n  int n=G.size();\n  vector<int> ind(n,0),outd(n,0),pre(n,-1),loop(n,0);\n\
    \  for(int v=0;v<n;v++){\n    for(int u:G[v]){\n      ind[u]++,outd[v]++;\n  \
    \    if(u==v) loop[v]=1;\n      if(u!=v) pre[u]=v;\n    }\n  }\n\n  int st=-1,en=-1,sz=0;\n\
    \  for(int i=0;i<n;i++){\n    if(ind[i]>=3||outd[i]>=3) return true;\n    if(ind[i]<outd[i])\
    \ st=i;\n    if(ind[i]>outd[i]) en=i;\n    if(ind[i]+outd[i]) sz++;\n  }\n  if(sz<2)\
    \ return false;\n  if(st<0) return true;\n\n  while(ind[en]==1+loop[en]&&st!=en)\
    \ en=pre[en];\n  if(st==en) return false;\n\n  queue<int> que;\n  vector<int>\
    \ rs(n,0);\n  que.emplace(st);\n  rs[st]=1;\n  while(!que.empty()){\n    int v=que.front();que.pop();\n\
    \    for(int u:G[v]){\n      if(u==en||rs[u]) continue;\n      rs[u]=1;\n    \
    \  que.emplace(u);\n    }\n  }\n\n  vector<int> us(n,0);\n  que.emplace(en);\n\
    \  us[en]=1;\n  while(!que.empty()){\n    int v=que.front();que.pop();\n    if(rs[v])\
    \ return true;\n    for(int u:G[v]){\n      if(u==en||us[u]) continue;\n     \
    \ us[u]=1;\n      que.emplace(u);\n    }\n  }\n  return false;\n}\n//END CUT HERE\n\
    #ifndef call_from_test\n//INSERT ABOVE HERE\n#endif\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2324.test.cpp
    title: test/aoj/2324.test.cpp
  extendedVerifiedWith: []
  isVerificationFile: false
  path: graph/multipleeuleriantrail.cpp
  requiredBy:
  - test/aoj/2324.test.cpp
  timestamp: '2019-09-22 14:49:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: graph/multipleeuleriantrail.cpp
layout: document
redirect_from:
- /library/graph/multipleeuleriantrail.cpp
- /library/graph/multipleeuleriantrail.cpp.html
title: graph/multipleeuleriantrail.cpp
---
