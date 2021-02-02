---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558.test.cpp
    title: test/aoj/0558.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/gridbfs.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nvector< vector<int> >\ngridbfs(vector<string>\
    \ &st,int sy,int sx,char wall,int dir){\n  int h=st.size(),w=st.front().size();\n\
    \  vector<vector<int> > dp(h,vector<int>(w,-1));\n  using P = pair<int, int>;\n\
    \  queue<P> qu;\n\n  dp[sy][sx]=0;\n  qu.emplace(sy,sx);\n\n  int dy[]={1,-1,0,0,1,1,-1,-1};\n\
    \  int dx[]={0,0,1,-1,1,-1,1,-1};\n  auto in=[&](int y,int x){return 0<=y and\
    \ y<h and 0<=x and x<w;};\n\n  while(!qu.empty()){\n    int y,x;\n    tie(y,x)=qu.front();qu.pop();\n\
    \    for(int k=0;k<dir;k++){\n      int ny=y+dy[k],nx=x+dx[k];\n      if(!in(ny,nx)\
    \ or st[ny][nx]==wall) continue;\n      if(~dp[ny][nx]) continue;\n      dp[ny][nx]=dp[y][x]+1;\n\
    \      qu.emplace(ny,nx);\n    }\n  }\n\n  return dp;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include<bits/stdc++.h>\nusing namespace std;\n#endif\n\
    //BEGIN CUT HERE\nvector< vector<int> >\ngridbfs(vector<string> &st,int sy,int\
    \ sx,char wall,int dir){\n  int h=st.size(),w=st.front().size();\n  vector<vector<int>\
    \ > dp(h,vector<int>(w,-1));\n  using P = pair<int, int>;\n  queue<P> qu;\n\n\
    \  dp[sy][sx]=0;\n  qu.emplace(sy,sx);\n\n  int dy[]={1,-1,0,0,1,1,-1,-1};\n \
    \ int dx[]={0,0,1,-1,1,-1,1,-1};\n  auto in=[&](int y,int x){return 0<=y and y<h\
    \ and 0<=x and x<w;};\n\n  while(!qu.empty()){\n    int y,x;\n    tie(y,x)=qu.front();qu.pop();\n\
    \    for(int k=0;k<dir;k++){\n      int ny=y+dy[k],nx=x+dx[k];\n      if(!in(ny,nx)\
    \ or st[ny][nx]==wall) continue;\n      if(~dp[ny][nx]) continue;\n      dp[ny][nx]=dp[y][x]+1;\n\
    \      qu.emplace(ny,nx);\n    }\n  }\n\n  return dp;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/gridbfs.cpp
  requiredBy: []
  timestamp: '2020-09-30 16:50:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558.test.cpp
documentation_of: tools/gridbfs.cpp
layout: document
redirect_from:
- /library/tools/gridbfs.cpp
- /library/tools/gridbfs.cpp.html
title: tools/gridbfs.cpp
---
