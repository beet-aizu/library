---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/arc060/tasks/arc060_d
    - https://kopricky.github.io/code/String/kmp.html
    - https://snuke.hatenablog.com/entry/2014/12/01/235807
  bundledCode: "#line 2 \"string/morrispratt.cpp\"\n\n#ifndef call_from_test\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2014/12/01/235807\n\
    \ * @see https://kopricky.github.io/code/String/kmp.html\n */\n//BEGIN CUT HERE\n\
    // longest prefix suffix matching of [0, i)\nvector<int> morris_pratt(const string\
    \ &s){\n  int n=s.size();\n  vector<int> mp(n+1,-1);\n  for(int i=0,j=-1;i<n;i++){\n\
    \    while(~j&&s[i]!=s[j]) j=mp[j];\n    mp[i+1]=++j;\n  }\n  return mp;\n}\n\
    // smallest d s.t. s[x] == s[x + d] for all x\nvector<int> minimum_period(const\
    \ string &s){\n  auto mp=morris_pratt(s);\n  for(int i=1;i<(int)mp.size();i++)\
    \ mp[i]=i-mp[i];\n  return mp;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\n// test minimum_period\nsigned ARC060_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  string w;\n  cin>>w;\n\n  int n=w.size();\n  if(w==string(n,w[0])){\n    cout<<n<<endl<<1<<endl;\n\
    \    return 0;\n  }\n\n  auto kmp=minimum_period(w);\n  if(n%kmp[n]!=0||n==kmp[n]){\n\
    \    cout<<1<<endl<<1<<endl;\n    return 0;\n  }\n\n  string w_rev=w;\n  reverse(w_rev.begin(),w_rev.end());\n\
    \  auto kmp_rev=minimum_period(w_rev);\n\n  int cnt=0;\n  for(int i=1;i<n;i++){\n\
    \    int j=n-i;\n    if(i%kmp[i]==0&&i>kmp[i]) continue;\n    if(j%kmp_rev[j]==0&&j>kmp_rev[j])\
    \ continue;\n    cnt++;\n  }\n  cout<<2<<endl<<cnt<<endl;\n  return 0;\n}\n/*\n\
    \  verified on 2020/08/20\n  https://atcoder.jp/contests/arc060/tasks/arc060_d\n\
    */\n\nsigned main(){\n  ARC060_F();\n  return 0;\n}\n#endif\n"
  code: "#pragma once\n\n#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#endif\n/*\n * @see https://snuke.hatenablog.com/entry/2014/12/01/235807\n\
    \ * @see https://kopricky.github.io/code/String/kmp.html\n */\n//BEGIN CUT HERE\n\
    // longest prefix suffix matching of [0, i)\nvector<int> morris_pratt(const string\
    \ &s){\n  int n=s.size();\n  vector<int> mp(n+1,-1);\n  for(int i=0,j=-1;i<n;i++){\n\
    \    while(~j&&s[i]!=s[j]) j=mp[j];\n    mp[i+1]=++j;\n  }\n  return mp;\n}\n\
    // smallest d s.t. s[x] == s[x + d] for all x\nvector<int> minimum_period(const\
    \ string &s){\n  auto mp=morris_pratt(s);\n  for(int i=1;i<(int)mp.size();i++)\
    \ mp[i]=i-mp[i];\n  return mp;\n}\n//END CUT HERE\n#ifndef call_from_test\n//INSERT\
    \ ABOVE HERE\n// test minimum_period\nsigned ARC060_F(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  string w;\n  cin>>w;\n\n  int n=w.size();\n  if(w==string(n,w[0])){\n    cout<<n<<endl<<1<<endl;\n\
    \    return 0;\n  }\n\n  auto kmp=minimum_period(w);\n  if(n%kmp[n]!=0||n==kmp[n]){\n\
    \    cout<<1<<endl<<1<<endl;\n    return 0;\n  }\n\n  string w_rev=w;\n  reverse(w_rev.begin(),w_rev.end());\n\
    \  auto kmp_rev=minimum_period(w_rev);\n\n  int cnt=0;\n  for(int i=1;i<n;i++){\n\
    \    int j=n-i;\n    if(i%kmp[i]==0&&i>kmp[i]) continue;\n    if(j%kmp_rev[j]==0&&j>kmp_rev[j])\
    \ continue;\n    cnt++;\n  }\n  cout<<2<<endl<<cnt<<endl;\n  return 0;\n}\n/*\n\
    \  verified on 2020/08/20\n  https://atcoder.jp/contests/arc060/tasks/arc060_d\n\
    */\n\nsigned main(){\n  ARC060_F();\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/morrispratt.cpp
  requiredBy: []
  timestamp: '2020-08-20 15:23:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/morrispratt.cpp
layout: document
redirect_from:
- /library/string/morrispratt.cpp
- /library/string/morrispratt.cpp.html
title: string/morrispratt.cpp
---
